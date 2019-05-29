/* -*- C -*-
 *
 * Copyright 2011 Sandia Corporation. Under the terms of Contract
 * DE-AC04-94AL85000 with Sandia Corporation, the U.S.  Government
 * retains certain rights in this software.
 *
 * Copyright (c) 2017 Intel Corporation. All rights reserved.
 * This software is available to you under the BSD license.
 *
 * This file is part of the Sandia OpenSHMEM software package. For license
 * information, see the LICENSE file in the top level directory of the
 * distribution.
 *
 */

#include "config.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <inttypes.h>
#include <errno.h>
#ifdef __linux__
#include <mntent.h>
#include <sys/vfs.h>
#endif

#define SHMEM_INTERNAL_INCLUDE
#include "shmem.h"
#include "shmem_internal.h"
#include "shmem_comm.h"
#include "shmem_collectives.h"

#ifdef ENABLE_PROFILING
#include "pshmem.h"

#pragma weak shmem_malloc = pshmem_malloc
#define shmem_malloc pshmem_malloc

#pragma weak shmem_calloc = pshmem_calloc
#define shmem_calloc pshmem_calloc

#pragma weak shmem_align = pshmem_align
#define shmem_align pshmem_align

#pragma weak shmem_realloc = pshmem_realloc
#define shmem_realloc pshmem_realloc

#pragma weak shmem_free = pshmem_free
#define shmem_free pshmem_free

#pragma weak shmalloc = pshmalloc
#define shmalloc pshmalloc

#pragma weak shmemalign = pshmemalign
#define shmemalign pshmemalign

#pragma weak shrealloc = pshrealloc
#define shrealloc pshrealloc

#pragma weak shfree = pshfree
#define shfree pshfree

#endif /* ENABLE_PROFILING */

static char *shmem_internal_heap_curr = NULL;

void* dlmalloc(size_t);
void* dlcalloc(size_t, size_t);
void  dlfree(void*);
void* dlrealloc(void*, size_t);
void* dlmemalign(size_t, size_t);


/*
 * scan /proc/mounts for a huge page file system with the
 * requested page size - on most Linux systems there will
 * only be a single 2MB pagesize present.
 * On success return 0, else -1.
 */

#ifdef __linux__
static int find_hugepage_dir(size_t page_size, char **directory)
{
    int ret = -1;
    struct statfs pg_size;
    struct mntent *mntent;
    FILE *fd;
    char *path;

    if (!directory || !page_size) {
        return ret;
    }

    fd = setmntent ("/proc/mounts", "r");
    if (fd == NULL) {
        return ret;
    }

    while ((mntent = getmntent(fd)) != NULL) {

        if (strcmp (mntent->mnt_type, "hugetlbfs") != 0) {
            continue;
        }

        path = mntent->mnt_dir;
        if (statfs(path, &pg_size) == 0) {
            if ((size_t) pg_size.f_bsize == page_size) {
                *directory = strdup(path);
                ret = 0;
                break;
            }
        }
    }

    endmntent(fd);
    return ret;
}
#endif /* __linux__ */

/* shmalloc and friends are defined to not be thread safe, so this is
   fine.  If they change that definition, this is no longer fine and
   needs to be made thread safe. */
void*
shmem_internal_get_next(intptr_t incr)
{
    char *orig = shmem_internal_heap_curr;

    shmem_internal_heap_curr += incr;
    if (shmem_internal_heap_curr < (char*) shmem_internal_heap_base) {
        RAISE_WARN_STR("symmetric heap pointer pushed below start");
        shmem_internal_heap_curr = (char*) shmem_internal_heap_base;
    } else if (shmem_internal_heap_curr - (char*) shmem_internal_heap_base >
               shmem_internal_heap_length) {
        RAISE_WARN_MSG("Out of symmetric memory, heap size %ld, overrun %"PRIdPTR"\n"
                       RAISE_PE_PREFIX "Try increasing SHMEM_SYMMETRIC_SIZE\n",
                       shmem_internal_heap_length, incr, shmem_internal_my_pe);
        shmem_internal_heap_curr = orig;
        orig = (void*) -1;
    }


    return orig;
}

#ifndef FLOOR
#define FLOOR(a,b)      ((uint64_t)(a) - ( ((uint64_t)(a)) % (uint64_t)(b)))
#endif
#ifndef CEILING
#define CEILING(a,b)    ((uint64_t)(a) <= 0LL ? 0 : (FLOOR((a)-1,b) + (b)))
#endif


/* alloc VM space starting @ '_end' + 1GB */
#define ONEGIG (1024UL*1024UL*1024UL)
static void *mmap_alloc(size_t bytes)
{
    char *file_name = NULL;
    int fd = 0;
    char *directory = NULL;
    void *requested_base =
        (void*) (((unsigned long) shmem_internal_data_base +
                  shmem_internal_data_length + 2 * ONEGIG) & ~(ONEGIG - 1));
    void *ret;

#ifdef __linux__
    /* huge page support only on Linux for now, default is to use 2MB large pages */
    if (shmem_internal_params.SYMMETRIC_HEAP_USE_HUGE_PAGES) {
        const char basename[] = "hugepagefile.SOS";

        /* check what /proc/mounts has for explicit huge page support */
        if (find_hugepage_dir(shmem_internal_params.SYMMETRIC_HEAP_PAGE_SIZE,
                             &directory) == 0)
        {
            int size = snprintf(NULL, 0, "%s/%s.%d", directory, basename, getpid());

            if (size < 0) {
                RAISE_WARN_STR("snprintf returned error, cannot use huge pages");
            } else {
                file_name = malloc(size + 1);
                if (file_name) {
                    sprintf(file_name, "%s/%s.%d", directory, basename, getpid());
                    fd = open(file_name, O_CREAT | O_RDWR, 0755);
                    if (fd < 0) {
                        RAISE_WARN_STR("file open failed, cannot use huge pages");
                        fd = 0;
                    } else {
                        /* have to round up by the pagesize being used */
                        bytes = CEILING(bytes, shmem_internal_params.SYMMETRIC_HEAP_PAGE_SIZE);
                    }
                }
            }
        }
    }
#endif /* __linux__ */

    ret = mmap(requested_base,
               bytes,
               PROT_READ | PROT_WRITE,
               MAP_ANON | MAP_PRIVATE,
               fd,
               0);
    if (ret == MAP_FAILED) {
        RAISE_WARN_MSG("Unable to allocate sym. heap, size %zuB: %s\n"
                       RAISE_PE_PREFIX
                       "Try reducing SHMEM_SYMMETRIC_SIZE or number of PEs per node\n",
                       bytes, strerror(errno), shmem_internal_my_pe);
        ret = NULL;
    }
    if (fd) {
        if (file_name)
            unlink(file_name);
        close(fd);
    }
    if (directory) {
        free(directory);
    }
    if (file_name) {
        free(file_name);
    }
    return ret;
}


int
shmem_internal_symmetric_init(void)
{
    /* add library overhead such that the max can be shmalloc()'ed */
    shmem_internal_heap_length = shmem_internal_params.SYMMETRIC_SIZE +
                                 SHMEM_INTERNAL_HEAP_OVERHEAD;

    if (!shmem_internal_params.SYMMETRIC_HEAP_USE_MALLOC) {
        shmem_internal_heap_base =
            shmem_internal_heap_curr =
            mmap_alloc(shmem_internal_heap_length);
    } else {
        shmem_internal_heap_base =
            shmem_internal_heap_curr =
            malloc(shmem_internal_heap_length);
    }

    return (NULL == shmem_internal_heap_base) ? -1 : 0;
}


int
shmem_internal_symmetric_fini(void)
{
    if (NULL != shmem_internal_heap_base) {
        if (!shmem_internal_params.SYMMETRIC_HEAP_USE_MALLOC) {
            munmap( (void*)shmem_internal_heap_base, (size_t)shmem_internal_heap_length );
        } else {
            free(shmem_internal_heap_base);
        }
        shmem_internal_heap_length = 0;
        shmem_internal_heap_base = shmem_internal_heap_curr = NULL;
    }

    return 0;
}


void*
shmem_internal_shmalloc(size_t size)
{
    void *ret;

    SHMEM_MUTEX_LOCK(shmem_internal_mutex_alloc);
    ret = dlmalloc(size);
    SHMEM_MUTEX_UNLOCK(shmem_internal_mutex_alloc);

    return ret;
}


void SHMEM_FUNCTION_ATTRIBUTES *
shmem_malloc(size_t size)
{
    void *ret;

    SHMEM_ERR_CHECK_INITIALIZED();

    SHMEM_MUTEX_LOCK(shmem_internal_mutex_alloc);
    ret = dlmalloc(size);
    SHMEM_MUTEX_UNLOCK(shmem_internal_mutex_alloc);

    shmem_internal_barrier_all();

    printf("malloc return addr: %p\n", ret);
    return ret;
}

void SHMEM_FUNCTION_ATTRIBUTES *
shmem_calloc(size_t count, size_t size)
{
    void *ret;

    SHMEM_ERR_CHECK_INITIALIZED();

    SHMEM_MUTEX_LOCK(shmem_internal_mutex_alloc);
    ret = dlcalloc(count, size);
    SHMEM_MUTEX_UNLOCK(shmem_internal_mutex_alloc);

    shmem_internal_barrier_all();

    return ret;
}

void SHMEM_FUNCTION_ATTRIBUTES
shmem_free(void *ptr)
{
    SHMEM_ERR_CHECK_INITIALIZED();
    if (ptr != NULL) {
      SHMEM_ERR_CHECK_SYMMETRIC_HEAP(ptr);
    }

    shmem_internal_barrier_all();

    /* It's fine to call dlfree with NULL, but better to avoid unnecessarily
     * taking the mutex in the threaded case. */
    if (ptr != NULL) {
        SHMEM_MUTEX_LOCK(shmem_internal_mutex_alloc);
        dlfree(ptr);
        SHMEM_MUTEX_UNLOCK(shmem_internal_mutex_alloc);
    }
}


void SHMEM_FUNCTION_ATTRIBUTES *
shmem_realloc(void *ptr, size_t size)
{
    void *ret;

    SHMEM_ERR_CHECK_INITIALIZED();
    if (ptr != NULL) {
      SHMEM_ERR_CHECK_SYMMETRIC_HEAP(ptr);
    }

    shmem_internal_barrier_all();

    SHMEM_MUTEX_LOCK(shmem_internal_mutex_alloc);
    if (size == 0 && ptr != NULL) {
        dlfree(ptr);
        ret = NULL;
    } else {
        ret = dlrealloc(ptr, size);
    }
    SHMEM_MUTEX_UNLOCK(shmem_internal_mutex_alloc);

    shmem_internal_barrier_all();

    return ret;
}


void SHMEM_FUNCTION_ATTRIBUTES *
shmem_align(size_t alignment, size_t size)
{
    void *ret;

    SHMEM_ERR_CHECK_INITIALIZED();

    if (alignment == 0)
        return NULL;

    SHMEM_MUTEX_LOCK(shmem_internal_mutex_alloc);
    ret = dlmemalign(alignment, size);
    SHMEM_MUTEX_UNLOCK(shmem_internal_mutex_alloc);

    shmem_internal_barrier_all();

    return ret;
}


/* The following functions were renamed in OpenSHMEM 1.2 and the old names were
 * deprecated.  Note that if PROFILING_ENABLED, the profiling macros will cause
 * these functions to directly call the corresponding pshmem_* routine which
 * should make the up-call invsible to a profiling tool.
 */

void SHMEM_FUNCTION_ATTRIBUTES * shmalloc(size_t size)
{
    return shmem_malloc(size);
}


void SHMEM_FUNCTION_ATTRIBUTES shfree(void *ptr)
{
    shmem_free(ptr);
}


void SHMEM_FUNCTION_ATTRIBUTES * shrealloc(void *ptr, size_t size)
{
    return shmem_realloc(ptr, size);
}


void SHMEM_FUNCTION_ATTRIBUTES * shmemalign(size_t alignment, size_t size)
{
    return shmem_align(alignment, size);
}

/**** Malloc with hints interfaces ****/
//#ifdef USE_SHARP
//#include <sharp/sharp.h>
#include <sharp.h>
#include <mpi.h>

extern struct fid_domain * shmem_transport_ofi_domainfd;
extern struct fid_mr ** shmem_transport_ofi_target_heap_mrfd;
//extern uint64_t ** shmem_transport_ofi_target_heap_keys;
int is_initialized = 0;

int sharp_init(void) {
    is_initialized = 1;
    return sharp_create_node_info();
}

void sharp_finalize(void) {
    sharp_destroy_node_info();
}

#define FIND_BASE(ptr, page_size) ((char*) (((uintptr_t) ptr / page_size) * page_size))
#define FIND_LEN(ptr, len, page_size) ((((char*) ptr - FIND_BASE(ptr, page_size) + len - 1) / \
                                        page_size + 1) * page_size)

struct myshare_info_t {
    #ifdef USE_XPMEM
    xpmem_segid_t heap_seg;
    #endif
    size_t heap_len;
    size_t heap_off;
    uint64_t remote_addr; 
};

typedef void * mspace;
mspace create_mspace_with_base(void* base, size_t capacity, int locked);
void* mspace_malloc(mspace msp, size_t bytes);

struct alloc_obj_cache_t {
    sharp_allocator_obj_t * obj;
    sharp_hint_t hints;
    mspace * myspace;
};

struct alloc_obj_cache_t alloc_cache[10] = {
    {NULL, 0, NULL}, {NULL, 0, NULL}, {NULL, 0, NULL}, {NULL, 0, NULL}, {NULL, 0, NULL}, 
    {NULL, 0, NULL}, {NULL, 0, NULL}, {NULL, 0, NULL}, {NULL, 0, NULL}, {NULL, 0, NULL}};

int cache_size = 0;

void SHMEM_FUNCTION_ATTRIBUTES * shmemx_malloc_with_hints(size_t size, long hints)
{
    sharp_allocator_info_params_t info_obj;
    sharp_hint_t sharp_hints = 0;
    sharp_allocator_obj_t * a_obj;
    struct myshare_info_t part_info;
    struct myshare_info_t * part_info_array;
    void * ret = NULL;
    int err;
    uint64_t flags = 0;
    int i;
    long page_size = sysconf(_SC_PAGESIZE);
    char *base;
    size_t len;

    
    if (!is_initialized) {
        sharp_init();
    }

    printf("[debug] malloc_with_hints: size %lu and hints %d\n", size, hints);

    /* do we have a method to alloc memory on the nic? */
    if (hints == SHMEM_HINT_NONE || hints == SHMEM_HINT_DEVICE_NIC_MEM) {
        return shmem_malloc(size);
    }

    if (hints == SHMEM_HINT_DEVICE_GPU_MEM || hints == SHMEM_HINT_HIGH_BW_MEM) {
        sharp_hints |= SHARP_HINT_GPU;
    } else if (hints == SHMEM_HINT_LOW_LAT_MEM) {
        sharp_hints |= SHARP_HINT_CPU;
    }

    if (hints == SHMEM_HINT_NEAR_NIC_MEM) {
        sharp_hints |= SHARP_HINT_LATENCY_OPT;
    }

    char found = 0;
    for (i = 0; i < cache_size; i++) {
        if (sharp_hints == alloc_cache[i].hints /*&& alloc_cache[i].myspace != NULL*/) {
            //cache hit
            ret = mspace_malloc(alloc_cache[i].myspace, size);
            printf("found, breaking, i: %d, cache_size: %d\n", i, cache_size);
            found = 1;
            return ret;
        }
    }
    if (found == 0) {
        //cache miss
        info_obj.allocator_hints = sharp_hints;
        info_obj.allocator_constraints = 0;

        a_obj = sharp_init_allocator_obj(&info_obj);
        ret = sharp_allocator_alloc(a_obj, shmem_internal_params.SYMMETRIC_SIZE + (1<<20));

        // add to cache
        alloc_cache[cache_size].obj = a_obj;
        alloc_cache[cache_size].hints = sharp_hints;
        alloc_cache[cache_size].myspace = create_mspace_with_base(ret, shmem_internal_params.SYMMETRIC_SIZE + (1<<20), 1);
        ret = ret + (1<<20);
        printf("added at cache %d\n", cache_size);
        printf("\tobj: %p\n", alloc_cache[cache_size].obj);
        printf("\thints: %d\n", alloc_cache[cache_size].hints);
        printf("\tmyspace: %p\n", alloc_cache[cache_size].myspace);
//        printf("mycache.myspace: %p added at cache %d\n", alloc_cache[cache_size].myspace, cache_size);

        cache_size++;
    }
    printf("%d: ret: %p\n", shmem_internal_my_pe, ret);

    base = FIND_BASE(ret, page_size);
    len = FIND_LEN(ret, size, page_size);

    part_info.heap_off = (char *)ret - base;
    part_info.heap_len = len;

    // need to wire up here
    #ifdef USE_XPMEM
    // xpmem_make
    i = shmem_internal_my_pe;

    part_info.heap_seg = xpmem_make(base, len, XPMEM_PERMIT_MODE, (void *)0666);
    if (part_info.heap_seg == -1) {
        printf("make failed\n");
        return NULL;
    }
    printf("[%d] my segment is %lx\n", i, part_info.heap_seg);

    #endif /* USE_XPMEM */


    err = fi_mr_reg(shmem_transport_ofi_domainfd, ret,
            size,
            FI_REMOTE_READ | FI_REMOTE_WRITE, 0, 
            (unsigned long long) nr_used_spaces, flags,
            &shmem_transport_ofi_target_heap_mrfd[nr_used_spaces-1], 
            NULL);
    OFI_CHECK_RETURN_STR(err, "target memory (heap) registration failed");
#ifdef ENABLE_MR_RMA_EVENT
    if (shmem_transport_ofi_mr_rma_event) {
        ret = fi_mr_enable(shmem_transport_ofi_target_heap_mrfd[nr_used_spaces-1]);
        OFI_CHECK_RETURN_STR(ret, "target heap MR enable failed");
    }
#endif /* ENABLE_MR_RMA_EVENT */


    part_info.remote_addr = 
        fi_mr_key(shmem_transport_ofi_target_heap_mrfd[nr_used_spaces-1]);
  

    // use an MPI All gather here... 
    part_info_array = (struct myshare_info_t *) malloc(sizeof(struct myshare_info_t) * shmem_internal_num_pes); 
    
    MPI_Allgather(&part_info, sizeof(part_info), MPI_CHAR, part_info_array, sizeof(part_info), MPI_CHAR, MPI_COMM_WORLD);

    // exchange
    for (i = 0; i < shmem_internal_num_pes; i++) {
        #ifdef USE_XPMEM
        int peer_num = shmem_runtime_get_node_rank(i);
        #endif
        int err = 0;
//        if (-1 == peer_num) {
//            continue;

        if (shmem_internal_my_pe == i) {
            #ifdef USE_XPMEM
            shmem_transport_xpmem_peers[peer_num].heap_ptr[nr_used_spaces-1] =
                ret;
            #endif
//            shmem_transport_ofi_target_heap_keys[nr_used_spaces-1][i] = part_info.remote_addr;

        } else {
            memcpy(&part_info, &part_info_array[i], sizeof(part_info));

            #ifdef USE_XPMEM
            struct xpmem_addr addr;
            
            printf("[%d] %d's heap_seg is %lx\n", shmem_internal_my_pe, i, part_info.heap_seg);

            shmem_transport_xpmem_peers[peer_num].heap_apid[nr_used_spaces-1] =
                xpmem_get(part_info.heap_seg, 
                          XPMEM_RDWR, 
                          XPMEM_PERMIT_MODE, 
                          (void *)0666);
            addr.apid = shmem_transport_xpmem_peers[peer_num].heap_apid[nr_used_spaces-1]; 
            addr.offset = 0;
            if (addr.apid < 0) {
                printf("!!! %d FAILED TO GET XPMEM !!!\n", shmem_internal_my_pe);
                return NULL;
            }

            shmem_transport_xpmem_peers[peer_num].heap_attach_ptr[nr_used_spaces-1] = 
                xpmem_attach(addr, part_info.heap_len, NULL);
            printf("[%d] peer %d addr: 0x%lx\n", shmem_internal_my_pe, i, shmem_transport_xpmem_peers[peer_num].heap_attach_ptr[nr_used_spaces-1]); 
            shmem_transport_xpmem_peers[peer_num].heap_ptr[nr_used_spaces-1] =
                (char *) shmem_transport_xpmem_peers[peer_num].heap_attach_ptr[nr_used_spaces-1] + part_info.heap_off;
            #endif /* USE_XPMEM */

  //          shmem_transport_ofi_target_heap_keys[nr_used_spaces-1][i] = part_info.remote_addr;
            

        }
    }
    // xpmem_get
    // xpmem_attach
//    #endif
    spaces[nr_used_spaces].base = (uint64_t) ret;
    spaces[nr_used_spaces].size = size;
    nr_used_spaces++;


    return ret;
}
/*#else
void SHMEM_FUNCTION_ATTRIBUTES * shmemx_malloc_with_hints(size_t size, long hints)
{
    printf("I was called when I shouldn't be...\n");
    fflush(stdout);
    return NULL;
}
#endif*/
