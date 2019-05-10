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

#ifndef TRANSPORT_XPMEM_H
#define TRANSPORT_XPMEM_H

#include <string.h>
#include <inttypes.h>
#include <xpmem.h>

#include <shmem_internal.h>

struct share_info_t {
    xpmem_segid_t data_seg;
    size_t data_len;
    size_t data_off;
    xpmem_segid_t heap_seg;
    size_t heap_len;
    size_t heap_off;
};

struct shmem_transport_xpmem_peer_info_t {
    xpmem_apid_t data_apid;
    xpmem_apid_t *heap_apid;
    void *data_attach_ptr;
    void **heap_attach_ptr;
    void *data_ptr;
    void **heap_ptr;
    int nr_heaps;
};

extern struct shmem_transport_xpmem_peer_info_t *shmem_transport_xpmem_peers;
//extern struct memory_spaces * spaces;

#ifdef ENABLE_ERROR_CHECKING
#define XPMEM_GET_REMOTE_ACCESS(target, rank, ptr)                      \
    do {                                                                \
        if (((void*) target > shmem_internal_data_base) &&              \
            ((char*) target < (char*) shmem_internal_data_base + shmem_internal_data_length)) { \
            ptr = (char*) target - (char*) shmem_internal_data_base +   \
                (char*) shmem_transport_xpmem_peers[rank].data_ptr;     \
        } else if (((void*) target > shmem_internal_heap_base) &&       \
                   ((char*) target < (char*) shmem_internal_heap_base + shmem_internal_heap_length)) { \
            ptr = (char*) target - (char*) shmem_internal_heap_base +   \
                (char*) shmem_transport_xpmem_peers[rank].heap_ptr[0];     \
        } else {                                                        \
            ptr = NULL;                                                 \
        }                                                               \
    } while (0)
#else
/*    do {                                                                \
        if ((void *) target > shmem_internal_heap_base &&               \
            (void *) target <                                           \
                (shmem_internal_heap_base + shmem_internal_heap_length)) { \
            ptr = (char *
*/
#define XPMEM_GET_REMOTE_ACCESS(target, rank, ptr)                      \
    do {                                                                \
        if ((void*) target < shmem_internal_heap_base) {                \
            ptr = (char*) target - (char*) shmem_internal_data_base +   \
                (char*) shmem_transport_xpmem_peers[rank].data_ptr;     \
        } else {                                                        \
            ptr = (char*) target - (char*) shmem_internal_heap_base +   \
                (char*) shmem_transport_xpmem_peers[rank].heap_ptr[0];     \
        }                                                               \
    } while (0)
#endif

static inline void * _remote_access(const uint64_t target, int pe)
{
    int i = 0;
    void * addr = NULL;

    for (i = 0; i < nr_used_spaces; i++) {
        if ((target >= spaces[i].base) && (target < (spaces[i].base + spaces[i].size))) {
            size_t offset = target - spaces[i].base;
            if (i) {
                addr = (void *) (shmem_transport_xpmem_peers[pe].heap_ptr[i-1] + offset);
            } else {
                addr = (void *) (shmem_transport_xpmem_peers[pe].data_ptr + offset);
            }    
            break;
        }
    }
    printf("returning addr: %p\n");
    return addr;
}

int shmem_transport_xpmem_init(void);

int shmem_transport_xpmem_startup(void);

int shmem_transport_xpmem_fini(void);


static inline
void *
shmem_transport_xpmem_ptr(const void *target, int pe, int noderank)
{
    char *remote_ptr;

    XPMEM_GET_REMOTE_ACCESS(target, noderank, remote_ptr);
    return remote_ptr;
}


static inline
void
shmem_transport_xpmem_put(void *target, const void *source, size_t len,
                          int pe, int noderank)
{
    void *remote_ptr;

    remote_ptr = _remote_access((uint64_t) target, pe);
    //XPMEM_GET_REMOTE_ACCESS(target, noderank, remote_ptr);
#ifdef ENABLE_ERROR_CHECKING
    if (NULL == remote_ptr) {
        RAISE_ERROR_MSG("target (0x%"PRIXPTR") outside of symmetric areas\n",
                        (uintptr_t) target);
    }
#endif
    //printf("[debug] put called pe: %d noderank: %d\n", pe, noderank);
    memcpy(remote_ptr, source, len);
}


static inline
void
shmem_transport_xpmem_get(void *target, const void *source, size_t len,
                          int pe, int noderank)
{
    void *remote_ptr;

    remote_ptr = _remote_access((uint64_t) source, pe);
    //XPMEM_GET_REMOTE_ACCESS(source, noderank, remote_ptr);
#ifdef ENABLE_ERROR_CHECKING
    if (NULL == remote_ptr) {
        RAISE_ERROR_MSG("target (0x%"PRIXPTR") outside of symmetric areas\n",
                        (uintptr_t) target);
    }
#endif

    memcpy(target, remote_ptr, len);
}

#endif
