/* -*- C -*-
 *
 * Copyright 2011 Sandia Corporation. Under the terms of Contract
 * DE-AC04-94AL85000 with Sandia Corporation, the U.S.  Government
 * retains certain rights in this software.
 *
 * Copyright (c) 2016 Intel Corporation. All rights reserved.
 * This software is available to you under the BSD license.
 *
 * This file is part of the Sandia OpenSHMEM software package. For license
 * information, see the LICENSE file in the top level directory of the
 * distribution.
 *
 */

/*
 * This is a generated file, do not edit directly.
 */



#ifndef SHMEMX_H
#define SHMEMX_H

#include <stddef.h>
#include <stdint.h>
#include <shmem-def.h>
#include <shmemx-def.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifndef SHMEM_FUNCTION_ATTRIBUTES
#  if SHMEM_HAVE_ATTRIBUTE_VISIBILITY == 1
#     define SHMEM_FUNCTION_ATTRIBUTES __attribute__((visibility("default")))
#  else
#     define SHMEM_FUNCTION_ATTRIBUTES
#  endif
#endif

SHMEM_FUNCTION_ATTRIBUTES double shmemx_wtime(void);
SHMEM_FUNCTION_ATTRIBUTES char* shmemx_nodename(void);

SHMEM_FUNCTION_ATTRIBUTES void shmemx_getmem_ct(shmemx_ct_t ct, void *target, const void *source, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_putmem_ct(shmemx_ct_t ct, void *target, const void *source, size_t len, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ct_create(shmemx_ct_t *ct);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ct_free(shmemx_ct_t *ct);
SHMEM_FUNCTION_ATTRIBUTES long shmemx_ct_get(shmemx_ct_t ct);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ct_set(shmemx_ct_t ct, long value);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ct_wait(shmemx_ct_t ct, long wait_for);

SHMEM_FUNCTION_ATTRIBUTES void shmemx_pcontrol(int level, ...);

SHMEM_FUNCTION_ATTRIBUTES void shmemx_register_gettid(uint64_t (*gettid_fn)(void));

/* Performance Counter Query Routines */
SHMEM_FUNCTION_ATTRIBUTES void shmemx_pcntr_get_issued_write(shmem_ctx_t ctx, uint64_t *cntr_value);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_pcntr_get_issued_read(shmem_ctx_t ctx, uint64_t *cntr_value);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_pcntr_get_completed_write(shmem_ctx_t ctx, uint64_t *cntr_value);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_pcntr_get_completed_read(shmem_ctx_t ctx, uint64_t *cntr_value);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_pcntr_get_completed_target(uint64_t *cntr_value);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_pcntr_get_all(shmem_ctx_t ctx, shmemx_pcntr_t *pcntr);

/* Wait_until and test any/all/some point-to-point API, proposed for OpenSHMEM 1.5 */
SHMEM_FUNCTION_ATTRIBUTES void shmemx_short_wait_until_all(short *vars, size_t nelems, int cmp, short value);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_int_wait_until_all(int *vars, size_t nelems, int cmp, int value);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_long_wait_until_all(long *vars, size_t nelems, int cmp, long value);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_longlong_wait_until_all(long long *vars, size_t nelems, int cmp, long long value);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ushort_wait_until_all(unsigned short *vars, size_t nelems, int cmp, unsigned short value);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint_wait_until_all(unsigned int *vars, size_t nelems, int cmp, unsigned int value);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ulong_wait_until_all(unsigned long *vars, size_t nelems, int cmp, unsigned long value);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ulonglong_wait_until_all(unsigned long long *vars, size_t nelems, int cmp, unsigned long long value);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_int32_wait_until_all(int32_t *vars, size_t nelems, int cmp, int32_t value);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_int64_wait_until_all(int64_t *vars, size_t nelems, int cmp, int64_t value);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint32_wait_until_all(uint32_t *vars, size_t nelems, int cmp, uint32_t value);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint64_wait_until_all(uint64_t *vars, size_t nelems, int cmp, uint64_t value);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_size_wait_until_all(size_t *vars, size_t nelems, int cmp, size_t value);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ptrdiff_wait_until_all(ptrdiff_t *vars, size_t nelems, int cmp, ptrdiff_t value);

SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_short_wait_until_any(short *vars, size_t nelems, int *status, int cmp, short value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_int_wait_until_any(int *vars, size_t nelems, int *status, int cmp, int value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_long_wait_until_any(long *vars, size_t nelems, int *status, int cmp, long value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_longlong_wait_until_any(long long *vars, size_t nelems, int *status, int cmp, long long value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_ushort_wait_until_any(unsigned short *vars, size_t nelems, int *status, int cmp, unsigned short value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_uint_wait_until_any(unsigned int *vars, size_t nelems, int *status, int cmp, unsigned int value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_ulong_wait_until_any(unsigned long *vars, size_t nelems, int *status, int cmp, unsigned long value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_ulonglong_wait_until_any(unsigned long long *vars, size_t nelems, int *status, int cmp, unsigned long long value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_int32_wait_until_any(int32_t *vars, size_t nelems, int *status, int cmp, int32_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_int64_wait_until_any(int64_t *vars, size_t nelems, int *status, int cmp, int64_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_uint32_wait_until_any(uint32_t *vars, size_t nelems, int *status, int cmp, uint32_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_uint64_wait_until_any(uint64_t *vars, size_t nelems, int *status, int cmp, uint64_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_size_wait_until_any(size_t *vars, size_t nelems, int *status, int cmp, size_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_ptrdiff_wait_until_any(ptrdiff_t *vars, size_t nelems, int *status, int cmp, ptrdiff_t value);

SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_short_wait_until_some(short *vars, size_t nelems, size_t *indices, int *status, int cmp, short value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_int_wait_until_some(int *vars, size_t nelems, size_t *indices, int *status, int cmp, int value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_long_wait_until_some(long *vars, size_t nelems, size_t *indices, int *status, int cmp, long value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_longlong_wait_until_some(long long *vars, size_t nelems, size_t *indices, int *status, int cmp, long long value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_ushort_wait_until_some(unsigned short *vars, size_t nelems, size_t *indices, int *status, int cmp, unsigned short value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_uint_wait_until_some(unsigned int *vars, size_t nelems, size_t *indices, int *status, int cmp, unsigned int value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_ulong_wait_until_some(unsigned long *vars, size_t nelems, size_t *indices, int *status, int cmp, unsigned long value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_ulonglong_wait_until_some(unsigned long long *vars, size_t nelems, size_t *indices, int *status, int cmp, unsigned long long value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_int32_wait_until_some(int32_t *vars, size_t nelems, size_t *indices, int *status, int cmp, int32_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_int64_wait_until_some(int64_t *vars, size_t nelems, size_t *indices, int *status, int cmp, int64_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_uint32_wait_until_some(uint32_t *vars, size_t nelems, size_t *indices, int *status, int cmp, uint32_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_uint64_wait_until_some(uint64_t *vars, size_t nelems, size_t *indices, int *status, int cmp, uint64_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_size_wait_until_some(size_t *vars, size_t nelems, size_t *indices, int *status, int cmp, size_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_ptrdiff_wait_until_some(ptrdiff_t *vars, size_t nelems, size_t *indices, int *status, int cmp, ptrdiff_t value);

SHMEM_FUNCTION_ATTRIBUTES int shmemx_short_test_all(short *vars, size_t nelems, int cmp, short value);
SHMEM_FUNCTION_ATTRIBUTES int shmemx_int_test_all(int *vars, size_t nelems, int cmp, int value);
SHMEM_FUNCTION_ATTRIBUTES int shmemx_long_test_all(long *vars, size_t nelems, int cmp, long value);
SHMEM_FUNCTION_ATTRIBUTES int shmemx_longlong_test_all(long long *vars, size_t nelems, int cmp, long long value);
SHMEM_FUNCTION_ATTRIBUTES int shmemx_ushort_test_all(unsigned short *vars, size_t nelems, int cmp, unsigned short value);
SHMEM_FUNCTION_ATTRIBUTES int shmemx_uint_test_all(unsigned int *vars, size_t nelems, int cmp, unsigned int value);
SHMEM_FUNCTION_ATTRIBUTES int shmemx_ulong_test_all(unsigned long *vars, size_t nelems, int cmp, unsigned long value);
SHMEM_FUNCTION_ATTRIBUTES int shmemx_ulonglong_test_all(unsigned long long *vars, size_t nelems, int cmp, unsigned long long value);
SHMEM_FUNCTION_ATTRIBUTES int shmemx_int32_test_all(int32_t *vars, size_t nelems, int cmp, int32_t value);
SHMEM_FUNCTION_ATTRIBUTES int shmemx_int64_test_all(int64_t *vars, size_t nelems, int cmp, int64_t value);
SHMEM_FUNCTION_ATTRIBUTES int shmemx_uint32_test_all(uint32_t *vars, size_t nelems, int cmp, uint32_t value);
SHMEM_FUNCTION_ATTRIBUTES int shmemx_uint64_test_all(uint64_t *vars, size_t nelems, int cmp, uint64_t value);
SHMEM_FUNCTION_ATTRIBUTES int shmemx_size_test_all(size_t *vars, size_t nelems, int cmp, size_t value);
SHMEM_FUNCTION_ATTRIBUTES int shmemx_ptrdiff_test_all(ptrdiff_t *vars, size_t nelems, int cmp, ptrdiff_t value);

SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_short_test_any(short *vars, size_t nelems, int *status, int cmp, short value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_int_test_any(int *vars, size_t nelems, int *status, int cmp, int value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_long_test_any(long *vars, size_t nelems, int *status, int cmp, long value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_longlong_test_any(long long *vars, size_t nelems, int *status, int cmp, long long value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_ushort_test_any(unsigned short *vars, size_t nelems, int *status, int cmp, unsigned short value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_uint_test_any(unsigned int *vars, size_t nelems, int *status, int cmp, unsigned int value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_ulong_test_any(unsigned long *vars, size_t nelems, int *status, int cmp, unsigned long value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_ulonglong_test_any(unsigned long long *vars, size_t nelems, int *status, int cmp, unsigned long long value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_int32_test_any(int32_t *vars, size_t nelems, int *status, int cmp, int32_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_int64_test_any(int64_t *vars, size_t nelems, int *status, int cmp, int64_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_uint32_test_any(uint32_t *vars, size_t nelems, int *status, int cmp, uint32_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_uint64_test_any(uint64_t *vars, size_t nelems, int *status, int cmp, uint64_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_size_test_any(size_t *vars, size_t nelems, int *status, int cmp, size_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_ptrdiff_test_any(ptrdiff_t *vars, size_t nelems, int *status, int cmp, ptrdiff_t value);

SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_short_test_some(short *vars, size_t nelems, size_t *indices, int *status, int cmp, short value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_int_test_some(int *vars, size_t nelems, size_t *indices, int *status, int cmp, int value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_long_test_some(long *vars, size_t nelems, size_t *indices, int *status, int cmp, long value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_longlong_test_some(long long *vars, size_t nelems, size_t *indices, int *status, int cmp, long long value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_ushort_test_some(unsigned short *vars, size_t nelems, size_t *indices, int *status, int cmp, unsigned short value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_uint_test_some(unsigned int *vars, size_t nelems, size_t *indices, int *status, int cmp, unsigned int value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_ulong_test_some(unsigned long *vars, size_t nelems, size_t *indices, int *status, int cmp, unsigned long value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_ulonglong_test_some(unsigned long long *vars, size_t nelems, size_t *indices, int *status, int cmp, unsigned long long value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_int32_test_some(int32_t *vars, size_t nelems, size_t *indices, int *status, int cmp, int32_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_int64_test_some(int64_t *vars, size_t nelems, size_t *indices, int *status, int cmp, int64_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_uint32_test_some(uint32_t *vars, size_t nelems, size_t *indices, int *status, int cmp, uint32_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_uint64_test_some(uint64_t *vars, size_t nelems, size_t *indices, int *status, int cmp, uint64_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_size_test_some(size_t *vars, size_t nelems, size_t *indices, int *status, int cmp, size_t value);
SHMEM_FUNCTION_ATTRIBUTES size_t shmemx_ptrdiff_test_some(ptrdiff_t *vars, size_t nelems, size_t *indices, int *status, int cmp, ptrdiff_t value);

/* Nonblocking swap operations, proposed for OpenSHMEM 1.5 */
SHMEM_FUNCTION_ATTRIBUTES void shmemx_int_atomic_swap_nbi(int *fetch, int *dest, int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_long_atomic_swap_nbi(long *fetch, long *dest, long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_longlong_atomic_swap_nbi(long long *fetch, long long *dest, long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint_atomic_swap_nbi(unsigned int *fetch, unsigned int *dest, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ulong_atomic_swap_nbi(unsigned long *fetch, unsigned long *dest, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ulonglong_atomic_swap_nbi(unsigned long long *fetch, unsigned long long *dest, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_int32_atomic_swap_nbi(int32_t *fetch, int32_t *dest, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_int64_atomic_swap_nbi(int64_t *fetch, int64_t *dest, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint32_atomic_swap_nbi(uint32_t *fetch, uint32_t *dest, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint64_atomic_swap_nbi(uint64_t *fetch, uint64_t *dest, uint64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_size_atomic_swap_nbi(size_t *fetch, size_t *dest, size_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ptrdiff_atomic_swap_nbi(ptrdiff_t *fetch, ptrdiff_t *dest, ptrdiff_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_float_atomic_swap_nbi(float *fetch, float *dest, float value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_double_atomic_swap_nbi(double *fetch, double *dest, double value, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_int_atomic_swap_nbi(shmem_ctx_t ctx, int *fetch, int *dest, int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_long_atomic_swap_nbi(shmem_ctx_t ctx, long *fetch, long *dest, long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_longlong_atomic_swap_nbi(shmem_ctx_t ctx, long long *fetch, long long *dest, long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_uint_atomic_swap_nbi(shmem_ctx_t ctx, unsigned int *fetch, unsigned int *dest, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_ulong_atomic_swap_nbi(shmem_ctx_t ctx, unsigned long *fetch, unsigned long *dest, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_ulonglong_atomic_swap_nbi(shmem_ctx_t ctx, unsigned long long *fetch, unsigned long long *dest, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_int32_atomic_swap_nbi(shmem_ctx_t ctx, int32_t *fetch, int32_t *dest, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_int64_atomic_swap_nbi(shmem_ctx_t ctx, int64_t *fetch, int64_t *dest, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_uint32_atomic_swap_nbi(shmem_ctx_t ctx, uint32_t *fetch, uint32_t *dest, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_uint64_atomic_swap_nbi(shmem_ctx_t ctx, uint64_t *fetch, uint64_t *dest, uint64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_size_atomic_swap_nbi(shmem_ctx_t ctx, size_t *fetch, size_t *dest, size_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_ptrdiff_atomic_swap_nbi(shmem_ctx_t ctx, ptrdiff_t *fetch, ptrdiff_t *dest, ptrdiff_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_float_atomic_swap_nbi(shmem_ctx_t ctx, float *fetch, float *dest, float value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_double_atomic_swap_nbi(shmem_ctx_t ctx, double *fetch, double *dest, double value, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmemx_int_atomic_compare_swap_nbi(int *fetch, int *dest, int cond, int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_long_atomic_compare_swap_nbi(long *fetch, long *dest, long cond, long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_longlong_atomic_compare_swap_nbi(long long *fetch, long long *dest, long long cond, long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint_atomic_compare_swap_nbi(unsigned int *fetch, unsigned int *dest, unsigned int cond, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ulong_atomic_compare_swap_nbi(unsigned long *fetch, unsigned long *dest, unsigned long cond, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ulonglong_atomic_compare_swap_nbi(unsigned long long *fetch, unsigned long long *dest, unsigned long long cond, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_int32_atomic_compare_swap_nbi(int32_t *fetch, int32_t *dest, int32_t cond, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_int64_atomic_compare_swap_nbi(int64_t *fetch, int64_t *dest, int64_t cond, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint32_atomic_compare_swap_nbi(uint32_t *fetch, uint32_t *dest, uint32_t cond, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint64_atomic_compare_swap_nbi(uint64_t *fetch, uint64_t *dest, uint64_t cond, uint64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_size_atomic_compare_swap_nbi(size_t *fetch, size_t *dest, size_t cond, size_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ptrdiff_atomic_compare_swap_nbi(ptrdiff_t *fetch, ptrdiff_t *dest, ptrdiff_t cond, ptrdiff_t value, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_int_atomic_compare_swap_nbi(shmem_ctx_t ctx, int *fetch, int *dest, int cond, int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_long_atomic_compare_swap_nbi(shmem_ctx_t ctx, long *fetch, long *dest, long cond, long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_longlong_atomic_compare_swap_nbi(shmem_ctx_t ctx, long long *fetch, long long *dest, long long cond, long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_uint_atomic_compare_swap_nbi(shmem_ctx_t ctx, unsigned int *fetch, unsigned int *dest, unsigned int cond, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_ulong_atomic_compare_swap_nbi(shmem_ctx_t ctx, unsigned long *fetch, unsigned long *dest, unsigned long cond, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_ulonglong_atomic_compare_swap_nbi(shmem_ctx_t ctx, unsigned long long *fetch, unsigned long long *dest, unsigned long long cond, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_int32_atomic_compare_swap_nbi(shmem_ctx_t ctx, int32_t *fetch, int32_t *dest, int32_t cond, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_int64_atomic_compare_swap_nbi(shmem_ctx_t ctx, int64_t *fetch, int64_t *dest, int64_t cond, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_uint32_atomic_compare_swap_nbi(shmem_ctx_t ctx, uint32_t *fetch, uint32_t *dest, uint32_t cond, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_uint64_atomic_compare_swap_nbi(shmem_ctx_t ctx, uint64_t *fetch, uint64_t *dest, uint64_t cond, uint64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_size_atomic_compare_swap_nbi(shmem_ctx_t ctx, size_t *fetch, size_t *dest, size_t cond, size_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_ptrdiff_atomic_compare_swap_nbi(shmem_ctx_t ctx, ptrdiff_t *fetch, ptrdiff_t *dest, ptrdiff_t cond, ptrdiff_t value, int pe);

/* Nonblocking fetching AMOs, proposed for OpenSHMEM 1.5 */
SHMEM_FUNCTION_ATTRIBUTES void shmemx_int_atomic_fetch_nbi(int *fetch, const int *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_long_atomic_fetch_nbi(long *fetch, const long *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_longlong_atomic_fetch_nbi(long long *fetch, const long long *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint_atomic_fetch_nbi(unsigned int *fetch, const unsigned int *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ulong_atomic_fetch_nbi(unsigned long *fetch, const unsigned long *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ulonglong_atomic_fetch_nbi(unsigned long long *fetch, const unsigned long long *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_int32_atomic_fetch_nbi(int32_t *fetch, const int32_t *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_int64_atomic_fetch_nbi(int64_t *fetch, const int64_t *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint32_atomic_fetch_nbi(uint32_t *fetch, const uint32_t *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint64_atomic_fetch_nbi(uint64_t *fetch, const uint64_t *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_size_atomic_fetch_nbi(size_t *fetch, const size_t *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ptrdiff_atomic_fetch_nbi(ptrdiff_t *fetch, const ptrdiff_t *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_float_atomic_fetch_nbi(float *fetch, const float *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_double_atomic_fetch_nbi(double *fetch, const double *target, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_int_atomic_fetch_nbi(shmem_ctx_t ctx, int *fetch, const int *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_long_atomic_fetch_nbi(shmem_ctx_t ctx, long *fetch, const long *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_longlong_atomic_fetch_nbi(shmem_ctx_t ctx, long long *fetch, const long long *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_uint_atomic_fetch_nbi(shmem_ctx_t ctx, unsigned int *fetch, const unsigned int *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_ulong_atomic_fetch_nbi(shmem_ctx_t ctx, unsigned long *fetch, const unsigned long *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_ulonglong_atomic_fetch_nbi(shmem_ctx_t ctx, unsigned long long *fetch, const unsigned long long *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_int32_atomic_fetch_nbi(shmem_ctx_t ctx, int32_t *fetch, const int32_t *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_int64_atomic_fetch_nbi(shmem_ctx_t ctx, int64_t *fetch, const int64_t *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_uint32_atomic_fetch_nbi(shmem_ctx_t ctx, uint32_t *fetch, const uint32_t *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_uint64_atomic_fetch_nbi(shmem_ctx_t ctx, uint64_t *fetch, const uint64_t *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_size_atomic_fetch_nbi(shmem_ctx_t ctx, size_t *fetch, const size_t *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_ptrdiff_atomic_fetch_nbi(shmem_ctx_t ctx, ptrdiff_t *fetch, const ptrdiff_t *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_float_atomic_fetch_nbi(shmem_ctx_t ctx, float *fetch, const float *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_double_atomic_fetch_nbi(shmem_ctx_t ctx, double *fetch, const double *target, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmemx_int_atomic_fetch_inc_nbi(int *fetch, int *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_long_atomic_fetch_inc_nbi(long *fetch, long *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_longlong_atomic_fetch_inc_nbi(long long *fetch, long long *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint_atomic_fetch_inc_nbi(unsigned int *fetch, unsigned int *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ulong_atomic_fetch_inc_nbi(unsigned long *fetch, unsigned long *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ulonglong_atomic_fetch_inc_nbi(unsigned long long *fetch, unsigned long long *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_int32_atomic_fetch_inc_nbi(int32_t *fetch, int32_t *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_int64_atomic_fetch_inc_nbi(int64_t *fetch, int64_t *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint32_atomic_fetch_inc_nbi(uint32_t *fetch, uint32_t *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint64_atomic_fetch_inc_nbi(uint64_t *fetch, uint64_t *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_size_atomic_fetch_inc_nbi(size_t *fetch, size_t *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ptrdiff_atomic_fetch_inc_nbi(ptrdiff_t *fetch, ptrdiff_t *target, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_int_atomic_fetch_inc_nbi(shmem_ctx_t ctx, int *fetch, int *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_long_atomic_fetch_inc_nbi(shmem_ctx_t ctx, long *fetch, long *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_longlong_atomic_fetch_inc_nbi(shmem_ctx_t ctx, long long *fetch, long long *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_uint_atomic_fetch_inc_nbi(shmem_ctx_t ctx, unsigned int *fetch, unsigned int *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_ulong_atomic_fetch_inc_nbi(shmem_ctx_t ctx, unsigned long *fetch, unsigned long *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_ulonglong_atomic_fetch_inc_nbi(shmem_ctx_t ctx, unsigned long long *fetch, unsigned long long *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_int32_atomic_fetch_inc_nbi(shmem_ctx_t ctx, int32_t *fetch, int32_t *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_int64_atomic_fetch_inc_nbi(shmem_ctx_t ctx, int64_t *fetch, int64_t *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_uint32_atomic_fetch_inc_nbi(shmem_ctx_t ctx, uint32_t *fetch, uint32_t *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_uint64_atomic_fetch_inc_nbi(shmem_ctx_t ctx, uint64_t *fetch, uint64_t *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_size_atomic_fetch_inc_nbi(shmem_ctx_t ctx, size_t *fetch, size_t *target, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_ptrdiff_atomic_fetch_inc_nbi(shmem_ctx_t ctx, ptrdiff_t *fetch, ptrdiff_t *target, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmemx_int_atomic_fetch_add_nbi(int *fetch, int *target, int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_long_atomic_fetch_add_nbi(long *fetch, long *target, long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_longlong_atomic_fetch_add_nbi(long long *fetch, long long *target, long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint_atomic_fetch_add_nbi(unsigned int *fetch, unsigned int *target, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ulong_atomic_fetch_add_nbi(unsigned long *fetch, unsigned long *target, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ulonglong_atomic_fetch_add_nbi(unsigned long long *fetch, unsigned long long *target, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_int32_atomic_fetch_add_nbi(int32_t *fetch, int32_t *target, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_int64_atomic_fetch_add_nbi(int64_t *fetch, int64_t *target, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint32_atomic_fetch_add_nbi(uint32_t *fetch, uint32_t *target, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint64_atomic_fetch_add_nbi(uint64_t *fetch, uint64_t *target, uint64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_size_atomic_fetch_add_nbi(size_t *fetch, size_t *target, size_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ptrdiff_atomic_fetch_add_nbi(ptrdiff_t *fetch, ptrdiff_t *target, ptrdiff_t value, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_int_atomic_fetch_add_nbi(shmem_ctx_t ctx, int *fetch, int *target, int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_long_atomic_fetch_add_nbi(shmem_ctx_t ctx, long *fetch, long *target, long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_longlong_atomic_fetch_add_nbi(shmem_ctx_t ctx, long long *fetch, long long *target, long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_uint_atomic_fetch_add_nbi(shmem_ctx_t ctx, unsigned int *fetch, unsigned int *target, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_ulong_atomic_fetch_add_nbi(shmem_ctx_t ctx, unsigned long *fetch, unsigned long *target, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_ulonglong_atomic_fetch_add_nbi(shmem_ctx_t ctx, unsigned long long *fetch, unsigned long long *target, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_int32_atomic_fetch_add_nbi(shmem_ctx_t ctx, int32_t *fetch, int32_t *target, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_int64_atomic_fetch_add_nbi(shmem_ctx_t ctx, int64_t *fetch, int64_t *target, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_uint32_atomic_fetch_add_nbi(shmem_ctx_t ctx, uint32_t *fetch, uint32_t *target, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_uint64_atomic_fetch_add_nbi(shmem_ctx_t ctx, uint64_t *fetch, uint64_t *target, uint64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_size_atomic_fetch_add_nbi(shmem_ctx_t ctx, size_t *fetch, size_t *target, size_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_ptrdiff_atomic_fetch_add_nbi(shmem_ctx_t ctx, ptrdiff_t *fetch, ptrdiff_t *target, ptrdiff_t value, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint_atomic_fetch_xor_nbi(unsigned int *fetch, unsigned int *target, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ulong_atomic_fetch_xor_nbi(unsigned long *fetch, unsigned long *target, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ulonglong_atomic_fetch_xor_nbi(unsigned long long *fetch, unsigned long long *target, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_int32_atomic_fetch_xor_nbi(int32_t *fetch, int32_t *target, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_int64_atomic_fetch_xor_nbi(int64_t *fetch, int64_t *target, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint32_atomic_fetch_xor_nbi(uint32_t *fetch, uint32_t *target, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint64_atomic_fetch_xor_nbi(uint64_t *fetch, uint64_t *target, uint64_t value, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_uint_atomic_fetch_xor_nbi(shmem_ctx_t ctx, unsigned int *fetch, unsigned int *target, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_ulong_atomic_fetch_xor_nbi(shmem_ctx_t ctx, unsigned long *fetch, unsigned long *target, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_ulonglong_atomic_fetch_xor_nbi(shmem_ctx_t ctx, unsigned long long *fetch, unsigned long long *target, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_int32_atomic_fetch_xor_nbi(shmem_ctx_t ctx, int32_t *fetch, int32_t *target, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_int64_atomic_fetch_xor_nbi(shmem_ctx_t ctx, int64_t *fetch, int64_t *target, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_uint32_atomic_fetch_xor_nbi(shmem_ctx_t ctx, uint32_t *fetch, uint32_t *target, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_uint64_atomic_fetch_xor_nbi(shmem_ctx_t ctx, uint64_t *fetch, uint64_t *target, uint64_t value, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint_atomic_fetch_and_nbi(unsigned int *fetch, unsigned int *target, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ulong_atomic_fetch_and_nbi(unsigned long *fetch, unsigned long *target, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ulonglong_atomic_fetch_and_nbi(unsigned long long *fetch, unsigned long long *target, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_int32_atomic_fetch_and_nbi(int32_t *fetch, int32_t *target, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_int64_atomic_fetch_and_nbi(int64_t *fetch, int64_t *target, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint32_atomic_fetch_and_nbi(uint32_t *fetch, uint32_t *target, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint64_atomic_fetch_and_nbi(uint64_t *fetch, uint64_t *target, uint64_t value, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_uint_atomic_fetch_and_nbi(shmem_ctx_t ctx, unsigned int *fetch, unsigned int *target, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_ulong_atomic_fetch_and_nbi(shmem_ctx_t ctx, unsigned long *fetch, unsigned long *target, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_ulonglong_atomic_fetch_and_nbi(shmem_ctx_t ctx, unsigned long long *fetch, unsigned long long *target, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_int32_atomic_fetch_and_nbi(shmem_ctx_t ctx, int32_t *fetch, int32_t *target, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_int64_atomic_fetch_and_nbi(shmem_ctx_t ctx, int64_t *fetch, int64_t *target, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_uint32_atomic_fetch_and_nbi(shmem_ctx_t ctx, uint32_t *fetch, uint32_t *target, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_uint64_atomic_fetch_and_nbi(shmem_ctx_t ctx, uint64_t *fetch, uint64_t *target, uint64_t value, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint_atomic_fetch_or_nbi(unsigned int *fetch, unsigned int *target, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ulong_atomic_fetch_or_nbi(unsigned long *fetch, unsigned long *target, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ulonglong_atomic_fetch_or_nbi(unsigned long long *fetch, unsigned long long *target, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_int32_atomic_fetch_or_nbi(int32_t *fetch, int32_t *target, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_int64_atomic_fetch_or_nbi(int64_t *fetch, int64_t *target, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint32_atomic_fetch_or_nbi(uint32_t *fetch, uint32_t *target, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint64_atomic_fetch_or_nbi(uint64_t *fetch, uint64_t *target, uint64_t value, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_uint_atomic_fetch_or_nbi(shmem_ctx_t ctx, unsigned int *fetch, unsigned int *target, unsigned int value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_ulong_atomic_fetch_or_nbi(shmem_ctx_t ctx, unsigned long *fetch, unsigned long *target, unsigned long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_ulonglong_atomic_fetch_or_nbi(shmem_ctx_t ctx, unsigned long long *fetch, unsigned long long *target, unsigned long long value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_int32_atomic_fetch_or_nbi(shmem_ctx_t ctx, int32_t *fetch, int32_t *target, int32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_int64_atomic_fetch_or_nbi(shmem_ctx_t ctx, int64_t *fetch, int64_t *target, int64_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_uint32_atomic_fetch_or_nbi(shmem_ctx_t ctx, uint32_t *fetch, uint32_t *target, uint32_t value, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_uint64_atomic_fetch_or_nbi(shmem_ctx_t ctx, uint64_t *fetch, uint64_t *target, uint64_t value, int pe);

/* Blocking put with signal */
SHMEM_FUNCTION_ATTRIBUTES void shmemx_float_put_signal(float *target, const float *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_double_put_signal(double *target, const double *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_longdouble_put_signal(long double *target, const long double *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_char_put_signal(char *target, const char *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_schar_put_signal(signed char *target, const signed char *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_short_put_signal(short *target, const short *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_int_put_signal(int *target, const int *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_long_put_signal(long *target, const long *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_longlong_put_signal(long long *target, const long long *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_uchar_put_signal(unsigned char *target, const unsigned char *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ushort_put_signal(unsigned short *target, const unsigned short *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint_put_signal(unsigned int *target, const unsigned int *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ulong_put_signal(unsigned long *target, const unsigned long *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ulonglong_put_signal(unsigned long long *target, const unsigned long long *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_int8_put_signal(int8_t *target, const int8_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_int16_put_signal(int16_t *target, const int16_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_int32_put_signal(int32_t *target, const int32_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_int64_put_signal(int64_t *target, const int64_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint8_put_signal(uint8_t *target, const uint8_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint16_put_signal(uint16_t *target, const uint16_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint32_put_signal(uint32_t *target, const uint32_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint64_put_signal(uint64_t *target, const uint64_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_size_put_signal(size_t *target, const size_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ptrdiff_put_signal(ptrdiff_t *target, const ptrdiff_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_float_put_signal(shmem_ctx_t ctx, float *target, const float *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_double_put_signal(shmem_ctx_t ctx, double *target, const double *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_longdouble_put_signal(shmem_ctx_t ctx, long double *target, const long double *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_char_put_signal(shmem_ctx_t ctx, char *target, const char *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_schar_put_signal(shmem_ctx_t ctx, signed char *target, const signed char *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_short_put_signal(shmem_ctx_t ctx, short *target, const short *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_int_put_signal(shmem_ctx_t ctx, int *target, const int *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_long_put_signal(shmem_ctx_t ctx, long *target, const long *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_longlong_put_signal(shmem_ctx_t ctx, long long *target, const long long *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_uchar_put_signal(shmem_ctx_t ctx, unsigned char *target, const unsigned char *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_ushort_put_signal(shmem_ctx_t ctx, unsigned short *target, const unsigned short *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_uint_put_signal(shmem_ctx_t ctx, unsigned int *target, const unsigned int *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_ulong_put_signal(shmem_ctx_t ctx, unsigned long *target, const unsigned long *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_ulonglong_put_signal(shmem_ctx_t ctx, unsigned long long *target, const unsigned long long *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_int8_put_signal(shmem_ctx_t ctx, int8_t *target, const int8_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_int16_put_signal(shmem_ctx_t ctx, int16_t *target, const int16_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_int32_put_signal(shmem_ctx_t ctx, int32_t *target, const int32_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_int64_put_signal(shmem_ctx_t ctx, int64_t *target, const int64_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_uint8_put_signal(shmem_ctx_t ctx, uint8_t *target, const uint8_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_uint16_put_signal(shmem_ctx_t ctx, uint16_t *target, const uint16_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_uint32_put_signal(shmem_ctx_t ctx, uint32_t *target, const uint32_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_uint64_put_signal(shmem_ctx_t ctx, uint64_t *target, const uint64_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_size_put_signal(shmem_ctx_t ctx, size_t *target, const size_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_ptrdiff_put_signal(shmem_ctx_t ctx, ptrdiff_t *target, const ptrdiff_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmemx_put8_signal(void* target, const void *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_put16_signal(void* target, const void *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_put32_signal(void* target, const void *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_put64_signal(void* target, const void *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_put128_signal(void* target, const void *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_putmem_signal(void* target, const void *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_put8_signal(shmem_ctx_t ctx, void* target, const void *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_put16_signal(shmem_ctx_t ctx, void* target, const void *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_put32_signal(shmem_ctx_t ctx, void* target, const void *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_put64_signal(shmem_ctx_t ctx, void* target, const void *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_put128_signal(shmem_ctx_t ctx, void* target, const void *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_putmem_signal(shmem_ctx_t ctx, void* target, const void *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);

/* Non-blocking put with signal */
SHMEM_FUNCTION_ATTRIBUTES void shmemx_float_put_signal_nbi(float *target, const float *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_double_put_signal_nbi(double *target, const double *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_longdouble_put_signal_nbi(long double *target, const long double *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_char_put_signal_nbi(char *target, const char *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_schar_put_signal_nbi(signed char *target, const signed char *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_short_put_signal_nbi(short *target, const short *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_int_put_signal_nbi(int *target, const int *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_long_put_signal_nbi(long *target, const long *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_longlong_put_signal_nbi(long long *target, const long long *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_uchar_put_signal_nbi(unsigned char *target, const unsigned char *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ushort_put_signal_nbi(unsigned short *target, const unsigned short *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint_put_signal_nbi(unsigned int *target, const unsigned int *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ulong_put_signal_nbi(unsigned long *target, const unsigned long *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ulonglong_put_signal_nbi(unsigned long long *target, const unsigned long long *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_int8_put_signal_nbi(int8_t *target, const int8_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_int16_put_signal_nbi(int16_t *target, const int16_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_int32_put_signal_nbi(int32_t *target, const int32_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_int64_put_signal_nbi(int64_t *target, const int64_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint8_put_signal_nbi(uint8_t *target, const uint8_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint16_put_signal_nbi(uint16_t *target, const uint16_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint32_put_signal_nbi(uint32_t *target, const uint32_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_uint64_put_signal_nbi(uint64_t *target, const uint64_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_size_put_signal_nbi(size_t *target, const size_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ptrdiff_put_signal_nbi(ptrdiff_t *target, const ptrdiff_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_float_put_signal_nbi(shmem_ctx_t ctx, float *target, const float *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_double_put_signal_nbi(shmem_ctx_t ctx, double *target, const double *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_longdouble_put_signal_nbi(shmem_ctx_t ctx, long double *target, const long double *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_char_put_signal_nbi(shmem_ctx_t ctx, char *target, const char *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_schar_put_signal_nbi(shmem_ctx_t ctx, signed char *target, const signed char *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_short_put_signal_nbi(shmem_ctx_t ctx, short *target, const short *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_int_put_signal_nbi(shmem_ctx_t ctx, int *target, const int *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_long_put_signal_nbi(shmem_ctx_t ctx, long *target, const long *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_longlong_put_signal_nbi(shmem_ctx_t ctx, long long *target, const long long *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_uchar_put_signal_nbi(shmem_ctx_t ctx, unsigned char *target, const unsigned char *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_ushort_put_signal_nbi(shmem_ctx_t ctx, unsigned short *target, const unsigned short *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_uint_put_signal_nbi(shmem_ctx_t ctx, unsigned int *target, const unsigned int *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_ulong_put_signal_nbi(shmem_ctx_t ctx, unsigned long *target, const unsigned long *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_ulonglong_put_signal_nbi(shmem_ctx_t ctx, unsigned long long *target, const unsigned long long *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_int8_put_signal_nbi(shmem_ctx_t ctx, int8_t *target, const int8_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_int16_put_signal_nbi(shmem_ctx_t ctx, int16_t *target, const int16_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_int32_put_signal_nbi(shmem_ctx_t ctx, int32_t *target, const int32_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_int64_put_signal_nbi(shmem_ctx_t ctx, int64_t *target, const int64_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_uint8_put_signal_nbi(shmem_ctx_t ctx, uint8_t *target, const uint8_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_uint16_put_signal_nbi(shmem_ctx_t ctx, uint16_t *target, const uint16_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_uint32_put_signal_nbi(shmem_ctx_t ctx, uint32_t *target, const uint32_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_uint64_put_signal_nbi(shmem_ctx_t ctx, uint64_t *target, const uint64_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_size_put_signal_nbi(shmem_ctx_t ctx, size_t *target, const size_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_ptrdiff_put_signal_nbi(shmem_ctx_t ctx, ptrdiff_t *target, const ptrdiff_t *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmemx_put8_signal_nbi(void* target, const void *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_put16_signal_nbi(void* target, const void *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_put32_signal_nbi(void* target, const void *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_put64_signal_nbi(void* target, const void *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_put128_signal_nbi(void* target, const void *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_putmem_signal_nbi(void* target, const void *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);

SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_put8_signal_nbi(shmem_ctx_t ctx, void* target, const void *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_put16_signal_nbi(shmem_ctx_t ctx, void* target, const void *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_put32_signal_nbi(shmem_ctx_t ctx, void* target, const void *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_put64_signal_nbi(shmem_ctx_t ctx, void* target, const void *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_put128_signal_nbi(shmem_ctx_t ctx, void* target, const void *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);
SHMEM_FUNCTION_ATTRIBUTES void shmemx_ctx_putmem_signal_nbi(shmem_ctx_t ctx, void* target, const void *source, size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe);


/* Option to enable bounce buffering on a given context */
#define SHMEMX_CTX_BOUNCE_BUFFER  (1l<<31)

/* C++ overloaded declarations */
#ifdef __cplusplus
} /* extern "C" */

static inline void shmemx_wait_until_all(short *ivars, size_t nelems, int cmp, short cmp_value) {
    shmemx_short_wait_until_all(ivars, nelems, cmp, cmp_value);
}
static inline void shmemx_wait_until_all(int *ivars, size_t nelems, int cmp, int cmp_value) {
    shmemx_int_wait_until_all(ivars, nelems, cmp, cmp_value);
}
static inline void shmemx_wait_until_all(long *ivars, size_t nelems, int cmp, long cmp_value) {
    shmemx_long_wait_until_all(ivars, nelems, cmp, cmp_value);
}
static inline void shmemx_wait_until_all(long long *ivars, size_t nelems, int cmp, long long cmp_value) {
    shmemx_longlong_wait_until_all(ivars, nelems, cmp, cmp_value);
}
static inline void shmemx_wait_until_all(unsigned short *ivars, size_t nelems, int cmp, unsigned short cmp_value) {
    shmemx_ushort_wait_until_all(ivars, nelems, cmp, cmp_value);
}
static inline void shmemx_wait_until_all(unsigned int *ivars, size_t nelems, int cmp, unsigned int cmp_value) {
    shmemx_uint_wait_until_all(ivars, nelems, cmp, cmp_value);
}
static inline void shmemx_wait_until_all(unsigned long *ivars, size_t nelems, int cmp, unsigned long cmp_value) {
    shmemx_ulong_wait_until_all(ivars, nelems, cmp, cmp_value);
}
static inline void shmemx_wait_until_all(unsigned long long *ivars, size_t nelems, int cmp, unsigned long long cmp_value) {
    shmemx_ulonglong_wait_until_all(ivars, nelems, cmp, cmp_value);
}

static inline size_t shmemx_wait_until_any(short *ivars, size_t nelems, int *status, int cmp, short cmp_value) {
    return shmemx_short_wait_until_any(ivars, nelems, status, cmp, cmp_value);
}
static inline size_t shmemx_wait_until_any(int *ivars, size_t nelems, int *status, int cmp, int cmp_value) {
    return shmemx_int_wait_until_any(ivars, nelems, status, cmp, cmp_value);
}
static inline size_t shmemx_wait_until_any(long *ivars, size_t nelems, int *status, int cmp, long cmp_value) {
    return shmemx_long_wait_until_any(ivars, nelems, status, cmp, cmp_value);
}
static inline size_t shmemx_wait_until_any(long long *ivars, size_t nelems, int *status, int cmp, long long cmp_value) {
    return shmemx_longlong_wait_until_any(ivars, nelems, status, cmp, cmp_value);
}
static inline size_t shmemx_wait_until_any(unsigned short *ivars, size_t nelems, int *status, int cmp, unsigned short cmp_value) {
    return shmemx_ushort_wait_until_any(ivars, nelems, status, cmp, cmp_value);
}
static inline size_t shmemx_wait_until_any(unsigned int *ivars, size_t nelems, int *status, int cmp, unsigned int cmp_value) {
    return shmemx_uint_wait_until_any(ivars, nelems, status, cmp, cmp_value);
}
static inline size_t shmemx_wait_until_any(unsigned long *ivars, size_t nelems, int *status, int cmp, unsigned long cmp_value) {
    return shmemx_ulong_wait_until_any(ivars, nelems, status, cmp, cmp_value);
}
static inline size_t shmemx_wait_until_any(unsigned long long *ivars, size_t nelems, int *status, int cmp, unsigned long long cmp_value) {
    return shmemx_ulonglong_wait_until_any(ivars, nelems, status, cmp, cmp_value);
}

static inline size_t shmemx_wait_until_some(short *ivars, size_t nelems, size_t *indices, int *status, int cmp, short cmp_value) {
    return shmemx_short_wait_until_some(ivars, nelems, indices, status, cmp, cmp_value);
}
static inline size_t shmemx_wait_until_some(int *ivars, size_t nelems, size_t *indices, int *status, int cmp, int cmp_value) {
    return shmemx_int_wait_until_some(ivars, nelems, indices, status, cmp, cmp_value);
}
static inline size_t shmemx_wait_until_some(long *ivars, size_t nelems, size_t *indices, int *status, int cmp, long cmp_value) {
    return shmemx_long_wait_until_some(ivars, nelems, indices, status, cmp, cmp_value);
}
static inline size_t shmemx_wait_until_some(long long *ivars, size_t nelems, size_t *indices, int *status, int cmp, long long cmp_value) {
    return shmemx_longlong_wait_until_some(ivars, nelems, indices, status, cmp, cmp_value);
}
static inline size_t shmemx_wait_until_some(unsigned short *ivars, size_t nelems, size_t *indices, int *status, int cmp, unsigned short cmp_value) {
    return shmemx_ushort_wait_until_some(ivars, nelems, indices, status, cmp, cmp_value);
}
static inline size_t shmemx_wait_until_some(unsigned int *ivars, size_t nelems, size_t *indices, int *status, int cmp, unsigned int cmp_value) {
    return shmemx_uint_wait_until_some(ivars, nelems, indices, status, cmp, cmp_value);
}
static inline size_t shmemx_wait_until_some(unsigned long *ivars, size_t nelems, size_t *indices, int *status, int cmp, unsigned long cmp_value) {
    return shmemx_ulong_wait_until_some(ivars, nelems, indices, status, cmp, cmp_value);
}
static inline size_t shmemx_wait_until_some(unsigned long long *ivars, size_t nelems, size_t *indices, int *status, int cmp, unsigned long long cmp_value) {
    return shmemx_ulonglong_wait_until_some(ivars, nelems, indices, status, cmp, cmp_value);
}

static inline int shmemx_test_all(short *ivars, size_t nelems, int cmp, short cmp_value) {
    return shmemx_short_test_all(ivars, nelems, cmp, cmp_value);
}
static inline int shmemx_test_all(int *ivars, size_t nelems, int cmp, int cmp_value) {
    return shmemx_int_test_all(ivars, nelems, cmp, cmp_value);
}
static inline int shmemx_test_all(long *ivars, size_t nelems, int cmp, long cmp_value) {
    return shmemx_long_test_all(ivars, nelems, cmp, cmp_value);
}
static inline int shmemx_test_all(long long *ivars, size_t nelems, int cmp, long long cmp_value) {
    return shmemx_longlong_test_all(ivars, nelems, cmp, cmp_value);
}
static inline int shmemx_test_all(unsigned short *ivars, size_t nelems, int cmp, unsigned short cmp_value) {
    return shmemx_ushort_test_all(ivars, nelems, cmp, cmp_value);
}
static inline int shmemx_test_all(unsigned int *ivars, size_t nelems, int cmp, unsigned int cmp_value) {
    return shmemx_uint_test_all(ivars, nelems, cmp, cmp_value);
}
static inline int shmemx_test_all(unsigned long *ivars, size_t nelems, int cmp, unsigned long cmp_value) {
    return shmemx_ulong_test_all(ivars, nelems, cmp, cmp_value);
}
static inline int shmemx_test_all(unsigned long long *ivars, size_t nelems, int cmp, unsigned long long cmp_value) {
    return shmemx_ulonglong_test_all(ivars, nelems, cmp, cmp_value);
}

static inline size_t shmemx_test_any(short *ivars, size_t nelems, int *status, int cmp, short cmp_value) {
    return shmemx_short_test_any(ivars, nelems, status, cmp, cmp_value);
}
static inline size_t shmemx_test_any(int *ivars, size_t nelems, int *status, int cmp, int cmp_value) {
    return shmemx_int_test_any(ivars, nelems, status, cmp, cmp_value);
}
static inline size_t shmemx_test_any(long *ivars, size_t nelems, int *status, int cmp, long cmp_value) {
    return shmemx_long_test_any(ivars, nelems, status, cmp, cmp_value);
}
static inline size_t shmemx_test_any(long long *ivars, size_t nelems, int *status, int cmp, long long cmp_value) {
    return shmemx_longlong_test_any(ivars, nelems, status, cmp, cmp_value);
}
static inline size_t shmemx_test_any(unsigned short *ivars, size_t nelems, int *status, int cmp, unsigned short cmp_value) {
    return shmemx_ushort_test_any(ivars, nelems, status, cmp, cmp_value);
}
static inline size_t shmemx_test_any(unsigned int *ivars, size_t nelems, int *status, int cmp, unsigned int cmp_value) {
    return shmemx_uint_test_any(ivars, nelems, status, cmp, cmp_value);
}
static inline size_t shmemx_test_any(unsigned long *ivars, size_t nelems, int *status, int cmp, unsigned long cmp_value) {
    return shmemx_ulong_test_any(ivars, nelems, status, cmp, cmp_value);
}
static inline size_t shmemx_test_any(unsigned long long *ivars, size_t nelems, int *status, int cmp, unsigned long long cmp_value) {
    return shmemx_ulonglong_test_any(ivars, nelems, status, cmp, cmp_value);
}

static inline size_t shmemx_test_some(short *ivars, size_t nelems, size_t *indices, int *status, int cmp, short cmp_value) {
    return shmemx_short_test_some(ivars, nelems, indices, status, cmp, cmp_value);
}
static inline size_t shmemx_test_some(int *ivars, size_t nelems, size_t *indices, int *status, int cmp, int cmp_value) {
    return shmemx_int_test_some(ivars, nelems, indices, status, cmp, cmp_value);
}
static inline size_t shmemx_test_some(long *ivars, size_t nelems, size_t *indices, int *status, int cmp, long cmp_value) {
    return shmemx_long_test_some(ivars, nelems, indices, status, cmp, cmp_value);
}
static inline size_t shmemx_test_some(long long *ivars, size_t nelems, size_t *indices, int *status, int cmp, long long cmp_value) {
    return shmemx_longlong_test_some(ivars, nelems, indices, status, cmp, cmp_value);
}
static inline size_t shmemx_test_some(unsigned short *ivars, size_t nelems, size_t *indices, int *status, int cmp, unsigned short cmp_value) {
    return shmemx_ushort_test_some(ivars, nelems, indices, status, cmp, cmp_value);
}
static inline size_t shmemx_test_some(unsigned int *ivars, size_t nelems, size_t *indices, int *status, int cmp, unsigned int cmp_value) {
    return shmemx_uint_test_some(ivars, nelems, indices, status, cmp, cmp_value);
}
static inline size_t shmemx_test_some(unsigned long *ivars, size_t nelems, size_t *indices, int *status, int cmp, unsigned long cmp_value) {
    return shmemx_ulong_test_some(ivars, nelems, indices, status, cmp, cmp_value);
}
static inline size_t shmemx_test_some(unsigned long long *ivars, size_t nelems, size_t *indices, int *status, int cmp, unsigned long long cmp_value) {
    return shmemx_ulonglong_test_some(ivars, nelems, indices, status, cmp, cmp_value);
}

static inline void shmemx_atomic_swap_nbi(int *fetch, int *target, int value, int pe) {
    shmemx_int_atomic_swap_nbi(fetch, target, value, pe);
}
static inline void shmemx_atomic_swap_nbi(shmem_ctx_t ctx, int *fetch, int *target, int value, int pe) {
    shmemx_ctx_int_atomic_swap_nbi(ctx, fetch, target, value, pe);
}
static inline void shmemx_atomic_swap_nbi(long *fetch, long *target, long value, int pe) {
    shmemx_long_atomic_swap_nbi(fetch, target, value, pe);
}
static inline void shmemx_atomic_swap_nbi(shmem_ctx_t ctx, long *fetch, long *target, long value, int pe) {
    shmemx_ctx_long_atomic_swap_nbi(ctx, fetch, target, value, pe);
}
static inline void shmemx_atomic_swap_nbi(long long *fetch, long long *target, long long value, int pe) {
    shmemx_longlong_atomic_swap_nbi(fetch, target, value, pe);
}
static inline void shmemx_atomic_swap_nbi(shmem_ctx_t ctx, long long *fetch, long long *target, long long value, int pe) {
    shmemx_ctx_longlong_atomic_swap_nbi(ctx, fetch, target, value, pe);
}
static inline void shmemx_atomic_swap_nbi(unsigned int *fetch, unsigned int *target, unsigned int value, int pe) {
    shmemx_uint_atomic_swap_nbi(fetch, target, value, pe);
}
static inline void shmemx_atomic_swap_nbi(shmem_ctx_t ctx, unsigned int *fetch, unsigned int *target, unsigned int value, int pe) {
    shmemx_ctx_uint_atomic_swap_nbi(ctx, fetch, target, value, pe);
}
static inline void shmemx_atomic_swap_nbi(unsigned long *fetch, unsigned long *target, unsigned long value, int pe) {
    shmemx_ulong_atomic_swap_nbi(fetch, target, value, pe);
}
static inline void shmemx_atomic_swap_nbi(shmem_ctx_t ctx, unsigned long *fetch, unsigned long *target, unsigned long value, int pe) {
    shmemx_ctx_ulong_atomic_swap_nbi(ctx, fetch, target, value, pe);
}
static inline void shmemx_atomic_swap_nbi(unsigned long long *fetch, unsigned long long *target, unsigned long long value, int pe) {
    shmemx_ulonglong_atomic_swap_nbi(fetch, target, value, pe);
}
static inline void shmemx_atomic_swap_nbi(shmem_ctx_t ctx, unsigned long long *fetch, unsigned long long *target, unsigned long long value, int pe) {
    shmemx_ctx_ulonglong_atomic_swap_nbi(ctx, fetch, target, value, pe);
}
static inline void shmemx_atomic_swap_nbi(float *fetch, float *target, float value, int pe) {
    shmemx_float_atomic_swap_nbi(fetch, target, value, pe);
}
static inline void shmemx_atomic_swap_nbi(shmem_ctx_t ctx, float *fetch, float *target, float value, int pe) {
    shmemx_ctx_float_atomic_swap_nbi(ctx, fetch, target, value, pe);
}
static inline void shmemx_atomic_swap_nbi(double *fetch, double *target, double value, int pe) {
    shmemx_double_atomic_swap_nbi(fetch, target, value, pe);
}
static inline void shmemx_atomic_swap_nbi(shmem_ctx_t ctx, double *fetch, double *target, double value, int pe) {
    shmemx_ctx_double_atomic_swap_nbi(ctx, fetch, target, value, pe);
}

static inline void shmemx_atomic_compare_swap_nbi(int *fetch, int *target, int cond, int value, int pe) {
    shmemx_int_atomic_compare_swap_nbi(fetch, target, cond, value, pe);
}
static inline void shmemx_atomic_compare_swap_nbi(shmem_ctx_t ctx, int *fetch, int *target, int cond, int value, int pe) {
    shmemx_ctx_int_atomic_compare_swap_nbi(ctx, fetch, target, cond, value, pe);
}
static inline void shmemx_atomic_compare_swap_nbi(long *fetch, long *target, long cond, long value, int pe) {
    shmemx_long_atomic_compare_swap_nbi(fetch, target, cond, value, pe);
}
static inline void shmemx_atomic_compare_swap_nbi(shmem_ctx_t ctx, long *fetch, long *target, long cond, long value, int pe) {
    shmemx_ctx_long_atomic_compare_swap_nbi(ctx, fetch, target, cond, value, pe);
}
static inline void shmemx_atomic_compare_swap_nbi(long long *fetch, long long *target, long long cond, long long value, int pe) {
    shmemx_longlong_atomic_compare_swap_nbi(fetch, target, cond, value, pe);
}
static inline void shmemx_atomic_compare_swap_nbi(shmem_ctx_t ctx, long long *fetch, long long *target, long long cond, long long value, int pe) {
    shmemx_ctx_longlong_atomic_compare_swap_nbi(ctx, fetch, target, cond, value, pe);
}
static inline void shmemx_atomic_compare_swap_nbi(unsigned int *fetch, unsigned int *target, unsigned int cond, unsigned int value, int pe) {
    shmemx_uint_atomic_compare_swap_nbi(fetch, target, cond, value, pe);
}
static inline void shmemx_atomic_compare_swap_nbi(shmem_ctx_t ctx, unsigned int *fetch, unsigned int *target, unsigned int cond, unsigned int value, int pe) {
    shmemx_ctx_uint_atomic_compare_swap_nbi(ctx, fetch, target, cond, value, pe);
}
static inline void shmemx_atomic_compare_swap_nbi(unsigned long *fetch, unsigned long *target, unsigned long cond, unsigned long value, int pe) {
    shmemx_ulong_atomic_compare_swap_nbi(fetch, target, cond, value, pe);
}
static inline void shmemx_atomic_compare_swap_nbi(shmem_ctx_t ctx, unsigned long *fetch, unsigned long *target, unsigned long cond, unsigned long value, int pe) {
    shmemx_ctx_ulong_atomic_compare_swap_nbi(ctx, fetch, target, cond, value, pe);
}
static inline void shmemx_atomic_compare_swap_nbi(unsigned long long *fetch, unsigned long long *target, unsigned long long cond, unsigned long long value, int pe) {
    shmemx_ulonglong_atomic_compare_swap_nbi(fetch, target, cond, value, pe);
}
static inline void shmemx_atomic_compare_swap_nbi(shmem_ctx_t ctx, unsigned long long *fetch, unsigned long long *target, unsigned long long cond, unsigned long long value, int pe) {
    shmemx_ctx_ulonglong_atomic_compare_swap_nbi(ctx, fetch, target, cond, value, pe);
}

static inline void shmemx_atomic_fetch_nbi(int *fetch, const int *target, int pe) {
    shmemx_int_atomic_fetch_nbi(fetch, target, pe);
}
static inline void shmemx_atomic_fetch_nbi(shmem_ctx_t ctx, int *fetch, const int *target, int pe) {
    shmemx_ctx_int_atomic_fetch_nbi(ctx, fetch, target, pe);
}
static inline void shmemx_atomic_fetch_nbi(long *fetch, const long *target, int pe) {
    shmemx_long_atomic_fetch_nbi(fetch, target, pe);
}
static inline void shmemx_atomic_fetch_nbi(shmem_ctx_t ctx, long *fetch, const long *target, int pe) {
    shmemx_ctx_long_atomic_fetch_nbi(ctx, fetch, target, pe);
}
static inline void shmemx_atomic_fetch_nbi(long long *fetch, const long long *target, int pe) {
    shmemx_longlong_atomic_fetch_nbi(fetch, target, pe);
}
static inline void shmemx_atomic_fetch_nbi(shmem_ctx_t ctx, long long *fetch, const long long *target, int pe) {
    shmemx_ctx_longlong_atomic_fetch_nbi(ctx, fetch, target, pe);
}
static inline void shmemx_atomic_fetch_nbi(unsigned int *fetch, const unsigned int *target, int pe) {
    shmemx_uint_atomic_fetch_nbi(fetch, target, pe);
}
static inline void shmemx_atomic_fetch_nbi(shmem_ctx_t ctx, unsigned int *fetch, const unsigned int *target, int pe) {
    shmemx_ctx_uint_atomic_fetch_nbi(ctx, fetch, target, pe);
}
static inline void shmemx_atomic_fetch_nbi(unsigned long *fetch, const unsigned long *target, int pe) {
    shmemx_ulong_atomic_fetch_nbi(fetch, target, pe);
}
static inline void shmemx_atomic_fetch_nbi(shmem_ctx_t ctx, unsigned long *fetch, const unsigned long *target, int pe) {
    shmemx_ctx_ulong_atomic_fetch_nbi(ctx, fetch, target, pe);
}
static inline void shmemx_atomic_fetch_nbi(unsigned long long *fetch, const unsigned long long *target, int pe) {
    shmemx_ulonglong_atomic_fetch_nbi(fetch, target, pe);
}
static inline void shmemx_atomic_fetch_nbi(shmem_ctx_t ctx, unsigned long long *fetch, const unsigned long long *target, int pe) {
    shmemx_ctx_ulonglong_atomic_fetch_nbi(ctx, fetch, target, pe);
}
static inline void shmemx_atomic_fetch_nbi(float *fetch, const float *target, int pe) {
    shmemx_float_atomic_fetch_nbi(fetch, target, pe);
}
static inline void shmemx_atomic_fetch_nbi(shmem_ctx_t ctx, float *fetch, const float *target, int pe) {
    shmemx_ctx_float_atomic_fetch_nbi(ctx, fetch, target, pe);
}
static inline void shmemx_atomic_fetch_nbi(double *fetch, const double *target, int pe) {
    shmemx_double_atomic_fetch_nbi(fetch, target, pe);
}
static inline void shmemx_atomic_fetch_nbi(shmem_ctx_t ctx, double *fetch, const double *target, int pe) {
    shmemx_ctx_double_atomic_fetch_nbi(ctx, fetch, target, pe);
}

static inline void shmemx_atomic_fetch_inc_nbi(int *fetch, int *target, int pe) {
    shmemx_int_atomic_fetch_inc_nbi(fetch, target, pe);
}
static inline void shmemx_atomic_fetch_inc_nbi(shmem_ctx_t ctx, int *fetch, int *target, int pe) {
    shmemx_ctx_int_atomic_fetch_inc_nbi(ctx, fetch, target, pe);
}
static inline void shmemx_atomic_fetch_inc_nbi(long *fetch, long *target, int pe) {
    shmemx_long_atomic_fetch_inc_nbi(fetch, target, pe);
}
static inline void shmemx_atomic_fetch_inc_nbi(shmem_ctx_t ctx, long *fetch, long *target, int pe) {
    shmemx_ctx_long_atomic_fetch_inc_nbi(ctx, fetch, target, pe);
}
static inline void shmemx_atomic_fetch_inc_nbi(long long *fetch, long long *target, int pe) {
    shmemx_longlong_atomic_fetch_inc_nbi(fetch, target, pe);
}
static inline void shmemx_atomic_fetch_inc_nbi(shmem_ctx_t ctx, long long *fetch, long long *target, int pe) {
    shmemx_ctx_longlong_atomic_fetch_inc_nbi(ctx, fetch, target, pe);
}
static inline void shmemx_atomic_fetch_inc_nbi(unsigned int *fetch, unsigned int *target, int pe) {
    shmemx_uint_atomic_fetch_inc_nbi(fetch, target, pe);
}
static inline void shmemx_atomic_fetch_inc_nbi(shmem_ctx_t ctx, unsigned int *fetch, unsigned int *target, int pe) {
    shmemx_ctx_uint_atomic_fetch_inc_nbi(ctx, fetch, target, pe);
}
static inline void shmemx_atomic_fetch_inc_nbi(unsigned long *fetch, unsigned long *target, int pe) {
    shmemx_ulong_atomic_fetch_inc_nbi(fetch, target, pe);
}
static inline void shmemx_atomic_fetch_inc_nbi(shmem_ctx_t ctx, unsigned long *fetch, unsigned long *target, int pe) {
    shmemx_ctx_ulong_atomic_fetch_inc_nbi(ctx, fetch, target, pe);
}
static inline void shmemx_atomic_fetch_inc_nbi(unsigned long long *fetch, unsigned long long *target, int pe) {
    shmemx_ulonglong_atomic_fetch_inc_nbi(fetch, target, pe);
}
static inline void shmemx_atomic_fetch_inc_nbi(shmem_ctx_t ctx, unsigned long long *fetch, unsigned long long *target, int pe) {
    shmemx_ctx_ulonglong_atomic_fetch_inc_nbi(ctx, fetch, target, pe);
}

static inline void shmemx_atomic_fetch_add_nbi(int *fetch, int *target, int value, int pe) {
    shmemx_int_atomic_fetch_add_nbi(fetch, target, value, pe);
}
static inline void shmemx_atomic_fetch_add_nbi(shmem_ctx_t ctx, int *fetch, int *target, int value, int pe) {
    shmemx_ctx_int_atomic_fetch_add_nbi(ctx, fetch, target, value, pe);
}
static inline void shmemx_atomic_fetch_add_nbi(long *fetch, long *target, long value, int pe) {
    shmemx_long_atomic_fetch_add_nbi(fetch, target, value, pe);
}
static inline void shmemx_atomic_fetch_add_nbi(shmem_ctx_t ctx, long *fetch, long *target, long value, int pe) {
    shmemx_ctx_long_atomic_fetch_add_nbi(ctx, fetch, target, value, pe);
}
static inline void shmemx_atomic_fetch_add_nbi(long long *fetch, long long *target, long long value, int pe) {
    shmemx_longlong_atomic_fetch_add_nbi(fetch, target, value, pe);
}
static inline void shmemx_atomic_fetch_add_nbi(shmem_ctx_t ctx, long long *fetch, long long *target, long long value, int pe) {
    shmemx_ctx_longlong_atomic_fetch_add_nbi(ctx, fetch, target, value, pe);
}
static inline void shmemx_atomic_fetch_add_nbi(unsigned int *fetch, unsigned int *target, unsigned int value, int pe) {
    shmemx_uint_atomic_fetch_add_nbi(fetch, target, value, pe);
}
static inline void shmemx_atomic_fetch_add_nbi(shmem_ctx_t ctx, unsigned int *fetch, unsigned int *target, unsigned int value, int pe) {
    shmemx_ctx_uint_atomic_fetch_add_nbi(ctx, fetch, target, value, pe);
}
static inline void shmemx_atomic_fetch_add_nbi(unsigned long *fetch, unsigned long *target, unsigned long value, int pe) {
    shmemx_ulong_atomic_fetch_add_nbi(fetch, target, value, pe);
}
static inline void shmemx_atomic_fetch_add_nbi(shmem_ctx_t ctx, unsigned long *fetch, unsigned long *target, unsigned long value, int pe) {
    shmemx_ctx_ulong_atomic_fetch_add_nbi(ctx, fetch, target, value, pe);
}
static inline void shmemx_atomic_fetch_add_nbi(unsigned long long *fetch, unsigned long long *target, unsigned long long value, int pe) {
    shmemx_ulonglong_atomic_fetch_add_nbi(fetch, target, value, pe);
}
static inline void shmemx_atomic_fetch_add_nbi(shmem_ctx_t ctx, unsigned long long *fetch, unsigned long long *target, unsigned long long value, int pe) {
    shmemx_ctx_ulonglong_atomic_fetch_add_nbi(ctx, fetch, target, value, pe);
}

static inline void shmemx_atomic_fetch_and_nbi(int32_t *fetch, int32_t *dest, int32_t value, int pe) {
    shmemx_int32_atomic_fetch_and_nbi(fetch, dest, value, pe);
}
static inline void shmemx_atomic_fetch_and_nbi(shmem_ctx_t ctx, int32_t *fetch, int32_t *dest, int32_t value, int pe) {
    shmemx_ctx_int32_atomic_fetch_and_nbi(ctx, fetch, dest, value, pe);
}
static inline void shmemx_atomic_fetch_and_nbi(int64_t *fetch, int64_t *dest, int64_t value, int pe) {
    shmemx_int64_atomic_fetch_and_nbi(fetch, dest, value, pe);
}
static inline void shmemx_atomic_fetch_and_nbi(shmem_ctx_t ctx, int64_t *fetch, int64_t *dest, int64_t value, int pe) {
    shmemx_ctx_int64_atomic_fetch_and_nbi(ctx, fetch, dest, value, pe);
}
static inline void shmemx_atomic_fetch_and_nbi(unsigned int *fetch, unsigned int *dest, unsigned int value, int pe) {
    shmemx_uint_atomic_fetch_and_nbi(fetch, dest, value, pe);
}
static inline void shmemx_atomic_fetch_and_nbi(shmem_ctx_t ctx, unsigned int *fetch, unsigned int *dest, unsigned int value, int pe) {
    shmemx_ctx_uint_atomic_fetch_and_nbi(ctx, fetch, dest, value, pe);
}
static inline void shmemx_atomic_fetch_and_nbi(unsigned long *fetch, unsigned long *dest, unsigned long value, int pe) {
    shmemx_ulong_atomic_fetch_and_nbi(fetch, dest, value, pe);
}
static inline void shmemx_atomic_fetch_and_nbi(shmem_ctx_t ctx, unsigned long *fetch, unsigned long *dest, unsigned long value, int pe) {
    shmemx_ctx_ulong_atomic_fetch_and_nbi(ctx, fetch, dest, value, pe);
}
static inline void shmemx_atomic_fetch_and_nbi(unsigned long long *fetch, unsigned long long *dest, unsigned long long value, int pe) {
    shmemx_ulonglong_atomic_fetch_and_nbi(fetch, dest, value, pe);
}
static inline void shmemx_atomic_fetch_and_nbi(shmem_ctx_t ctx, unsigned long long *fetch, unsigned long long *dest, unsigned long long value, int pe) {
    shmemx_ctx_ulonglong_atomic_fetch_and_nbi(ctx, fetch, dest, value, pe);
}

static inline void shmemx_atomic_fetch_or_nbi(int32_t *fetch, int32_t *dest, int32_t value, int pe) {
    shmemx_int32_atomic_fetch_or_nbi(fetch, dest, value, pe);
}
static inline void shmemx_atomic_fetch_or_nbi(shmem_ctx_t ctx, int32_t *fetch, int32_t *dest, int32_t value, int pe) {
    shmemx_ctx_int32_atomic_fetch_or_nbi(ctx, fetch, dest, value, pe);
}
static inline void shmemx_atomic_fetch_or_nbi(int64_t *fetch, int64_t *dest, int64_t value, int pe) {
    shmemx_int64_atomic_fetch_or_nbi(fetch, dest, value, pe);
}
static inline void shmemx_atomic_fetch_or_nbi(shmem_ctx_t ctx, int64_t *fetch, int64_t *dest, int64_t value, int pe) {
    shmemx_ctx_int64_atomic_fetch_or_nbi(ctx, fetch, dest, value, pe);
}
static inline void shmemx_atomic_fetch_or_nbi(unsigned int *fetch, unsigned int *dest, unsigned int value, int pe) {
    shmemx_uint_atomic_fetch_or_nbi(fetch, dest, value, pe);
}
static inline void shmemx_atomic_fetch_or_nbi(shmem_ctx_t ctx, unsigned int *fetch, unsigned int *dest, unsigned int value, int pe) {
    shmemx_ctx_uint_atomic_fetch_or_nbi(ctx, fetch, dest, value, pe);
}
static inline void shmemx_atomic_fetch_or_nbi(unsigned long *fetch, unsigned long *dest, unsigned long value, int pe) {
    shmemx_ulong_atomic_fetch_or_nbi(fetch, dest, value, pe);
}
static inline void shmemx_atomic_fetch_or_nbi(shmem_ctx_t ctx, unsigned long *fetch, unsigned long *dest, unsigned long value, int pe) {
    shmemx_ctx_ulong_atomic_fetch_or_nbi(ctx, fetch, dest, value, pe);
}
static inline void shmemx_atomic_fetch_or_nbi(unsigned long long *fetch, unsigned long long *dest, unsigned long long value, int pe) {
    shmemx_ulonglong_atomic_fetch_or_nbi(fetch, dest, value, pe);
}
static inline void shmemx_atomic_fetch_or_nbi(shmem_ctx_t ctx, unsigned long long *fetch, unsigned long long *dest, unsigned long long value, int pe) {
    shmemx_ctx_ulonglong_atomic_fetch_or_nbi(ctx, fetch, dest, value, pe);
}

static inline void shmemx_atomic_fetch_xor_nbi(int32_t *fetch, int32_t *dest, int32_t value, int pe) {
    shmemx_int32_atomic_fetch_xor_nbi(fetch, dest, value, pe);
}
static inline void shmemx_atomic_fetch_xor_nbi(shmem_ctx_t ctx, int32_t *fetch, int32_t *dest, int32_t value, int pe) {
    shmemx_ctx_int32_atomic_fetch_xor_nbi(ctx, fetch, dest, value, pe);
}
static inline void shmemx_atomic_fetch_xor_nbi(int64_t *fetch, int64_t *dest, int64_t value, int pe) {
    shmemx_int64_atomic_fetch_xor_nbi(fetch, dest, value, pe);
}
static inline void shmemx_atomic_fetch_xor_nbi(shmem_ctx_t ctx, int64_t *fetch, int64_t *dest, int64_t value, int pe) {
    shmemx_ctx_int64_atomic_fetch_xor_nbi(ctx, fetch, dest, value, pe);
}
static inline void shmemx_atomic_fetch_xor_nbi(unsigned int *fetch, unsigned int *dest, unsigned int value, int pe) {
    shmemx_uint_atomic_fetch_xor_nbi(fetch, dest, value, pe);
}
static inline void shmemx_atomic_fetch_xor_nbi(shmem_ctx_t ctx, unsigned int *fetch, unsigned int *dest, unsigned int value, int pe) {
    shmemx_ctx_uint_atomic_fetch_xor_nbi(ctx, fetch, dest, value, pe);
}
static inline void shmemx_atomic_fetch_xor_nbi(unsigned long *fetch, unsigned long *dest, unsigned long value, int pe) {
    shmemx_ulong_atomic_fetch_xor_nbi(fetch, dest, value, pe);
}
static inline void shmemx_atomic_fetch_xor_nbi(shmem_ctx_t ctx, unsigned long *fetch, unsigned long *dest, unsigned long value, int pe) {
    shmemx_ctx_ulong_atomic_fetch_xor_nbi(ctx, fetch, dest, value, pe);
}
static inline void shmemx_atomic_fetch_xor_nbi(unsigned long long *fetch, unsigned long long *dest, unsigned long long value, int pe) {
    shmemx_ulonglong_atomic_fetch_xor_nbi(fetch, dest, value, pe);
}
static inline void shmemx_atomic_fetch_xor_nbi(shmem_ctx_t ctx, unsigned long long *fetch, unsigned long long *dest, unsigned long long value, int pe) {
    shmemx_ctx_ulonglong_atomic_fetch_xor_nbi(ctx, fetch, dest, value, pe);
}

/* Blocking put with signal */
static inline void shmemx_put_signal(float* dest, const float* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_float_put_signal(dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal(shmem_ctx_t ctx, float* dest, const float* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_ctx_float_put_signal(ctx, dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal(double* dest, const double* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_double_put_signal(dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal(shmem_ctx_t ctx, double* dest, const double* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_ctx_double_put_signal(ctx, dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal(long double* dest, const long double* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_longdouble_put_signal(dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal(shmem_ctx_t ctx, long double* dest, const long double* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_ctx_longdouble_put_signal(ctx, dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal(char* dest, const char* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_char_put_signal(dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal(shmem_ctx_t ctx, char* dest, const char* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_ctx_char_put_signal(ctx, dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal(signed char* dest, const signed char* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_schar_put_signal(dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal(shmem_ctx_t ctx, signed char* dest, const signed char* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_ctx_schar_put_signal(ctx, dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal(short* dest, const short* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_short_put_signal(dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal(shmem_ctx_t ctx, short* dest, const short* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_ctx_short_put_signal(ctx, dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal(int* dest, const int* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_int_put_signal(dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal(shmem_ctx_t ctx, int* dest, const int* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_ctx_int_put_signal(ctx, dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal(long* dest, const long* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_long_put_signal(dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal(shmem_ctx_t ctx, long* dest, const long* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_ctx_long_put_signal(ctx, dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal(long long* dest, const long long* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_longlong_put_signal(dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal(shmem_ctx_t ctx, long long* dest, const long long* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_ctx_longlong_put_signal(ctx, dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal(unsigned char* dest, const unsigned char* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_uchar_put_signal(dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal(shmem_ctx_t ctx, unsigned char* dest, const unsigned char* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_ctx_uchar_put_signal(ctx, dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal(unsigned short* dest, const unsigned short* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_ushort_put_signal(dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal(shmem_ctx_t ctx, unsigned short* dest, const unsigned short* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_ctx_ushort_put_signal(ctx, dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal(unsigned int* dest, const unsigned int* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_uint_put_signal(dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal(shmem_ctx_t ctx, unsigned int* dest, const unsigned int* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_ctx_uint_put_signal(ctx, dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal(unsigned long* dest, const unsigned long* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_ulong_put_signal(dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal(shmem_ctx_t ctx, unsigned long* dest, const unsigned long* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_ctx_ulong_put_signal(ctx, dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal(unsigned long long* dest, const unsigned long long* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_ulonglong_put_signal(dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal(shmem_ctx_t ctx, unsigned long long* dest, const unsigned long long* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_ctx_ulonglong_put_signal(ctx, dest, source, nelems, sig_addr, signal, pe);
}

/* Non-blocking put with signal */
static inline void shmemx_put_signal_nbi(float* dest, const float* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_float_put_signal_nbi(dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal_nbi(shmem_ctx_t ctx, float* dest, const float* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_ctx_float_put_signal_nbi(ctx, dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal_nbi(double* dest, const double* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_double_put_signal_nbi(dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal_nbi(shmem_ctx_t ctx, double* dest, const double* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_ctx_double_put_signal_nbi(ctx, dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal_nbi(long double* dest, const long double* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_longdouble_put_signal_nbi(dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal_nbi(shmem_ctx_t ctx, long double* dest, const long double* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_ctx_longdouble_put_signal_nbi(ctx, dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal_nbi(char* dest, const char* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_char_put_signal_nbi(dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal_nbi(shmem_ctx_t ctx, char* dest, const char* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_ctx_char_put_signal_nbi(ctx, dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal_nbi(signed char* dest, const signed char* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_schar_put_signal_nbi(dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal_nbi(shmem_ctx_t ctx, signed char* dest, const signed char* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_ctx_schar_put_signal_nbi(ctx, dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal_nbi(short* dest, const short* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_short_put_signal_nbi(dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal_nbi(shmem_ctx_t ctx, short* dest, const short* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_ctx_short_put_signal_nbi(ctx, dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal_nbi(int* dest, const int* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_int_put_signal_nbi(dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal_nbi(shmem_ctx_t ctx, int* dest, const int* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_ctx_int_put_signal_nbi(ctx, dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal_nbi(long* dest, const long* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_long_put_signal_nbi(dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal_nbi(shmem_ctx_t ctx, long* dest, const long* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_ctx_long_put_signal_nbi(ctx, dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal_nbi(long long* dest, const long long* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_longlong_put_signal_nbi(dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal_nbi(shmem_ctx_t ctx, long long* dest, const long long* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_ctx_longlong_put_signal_nbi(ctx, dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal_nbi(unsigned char* dest, const unsigned char* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_uchar_put_signal_nbi(dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal_nbi(shmem_ctx_t ctx, unsigned char* dest, const unsigned char* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_ctx_uchar_put_signal_nbi(ctx, dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal_nbi(unsigned short* dest, const unsigned short* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_ushort_put_signal_nbi(dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal_nbi(shmem_ctx_t ctx, unsigned short* dest, const unsigned short* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_ctx_ushort_put_signal_nbi(ctx, dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal_nbi(unsigned int* dest, const unsigned int* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_uint_put_signal_nbi(dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal_nbi(shmem_ctx_t ctx, unsigned int* dest, const unsigned int* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_ctx_uint_put_signal_nbi(ctx, dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal_nbi(unsigned long* dest, const unsigned long* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_ulong_put_signal_nbi(dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal_nbi(shmem_ctx_t ctx, unsigned long* dest, const unsigned long* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_ctx_ulong_put_signal_nbi(ctx, dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal_nbi(unsigned long long* dest, const unsigned long long* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_ulonglong_put_signal_nbi(dest, source, nelems, sig_addr, signal, pe);
}
static inline void shmemx_put_signal_nbi(shmem_ctx_t ctx, unsigned long long* dest, const unsigned long long* source,
                             size_t nelems, uint64_t *sig_addr, uint64_t signal, int pe) {
    shmemx_ctx_ulonglong_put_signal_nbi(ctx, dest, source, nelems, sig_addr, signal, pe);
}

/* C11 Generic Macros */
#elif (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L && !defined(SHMEM_INTERNAL_INCLUDE))

/* Wait_until and test any/all/some point-to-point API */
#define shmemx_wait_until_all(...) \
    _Generic(SHMEM_C11_TYPE_EVAL_PTR(SHMEM_C11_ARG0(__VA_ARGS__)), \
             default: shmem_ctx_c11_generic_selection_failed, \
        short*: shmemx_short_wait_until_all, \
        int*: shmemx_int_wait_until_all, \
        long*: shmemx_long_wait_until_all, \
        long long*: shmemx_longlong_wait_until_all, \
        unsigned short*: shmemx_ushort_wait_until_all, \
        unsigned int*: shmemx_uint_wait_until_all, \
        unsigned long*: shmemx_ulong_wait_until_all, \
        unsigned long long*: shmemx_ulonglong_wait_until_all \
    )(__VA_ARGS__)

#define shmemx_wait_until_any(...) \
    _Generic(SHMEM_C11_TYPE_EVAL_PTR(SHMEM_C11_ARG0(__VA_ARGS__)), \
             default: shmem_ctx_c11_generic_selection_failed, \
        short*: shmemx_short_wait_until_any, \
        int*: shmemx_int_wait_until_any, \
        long*: shmemx_long_wait_until_any, \
        long long*: shmemx_longlong_wait_until_any, \
        unsigned short*: shmemx_ushort_wait_until_any, \
        unsigned int*: shmemx_uint_wait_until_any, \
        unsigned long*: shmemx_ulong_wait_until_any, \
        unsigned long long*: shmemx_ulonglong_wait_until_any \
    )(__VA_ARGS__)

#define shmemx_wait_until_some(...) \
    _Generic(SHMEM_C11_TYPE_EVAL_PTR(SHMEM_C11_ARG0(__VA_ARGS__)), \
             default: shmem_ctx_c11_generic_selection_failed, \
        short*: shmemx_short_wait_until_some, \
        int*: shmemx_int_wait_until_some, \
        long*: shmemx_long_wait_until_some, \
        long long*: shmemx_longlong_wait_until_some, \
        unsigned short*: shmemx_ushort_wait_until_some, \
        unsigned int*: shmemx_uint_wait_until_some, \
        unsigned long*: shmemx_ulong_wait_until_some, \
        unsigned long long*: shmemx_ulonglong_wait_until_some \
    )(__VA_ARGS__)

#define shmemx_test_all(...) \
    _Generic(SHMEM_C11_TYPE_EVAL_PTR(SHMEM_C11_ARG0(__VA_ARGS__)), \
             default: shmem_ctx_c11_generic_selection_failed, \
        short*: shmemx_short_test_all, \
        int*: shmemx_int_test_all, \
        long*: shmemx_long_test_all, \
        long long*: shmemx_longlong_test_all, \
        unsigned short*: shmemx_ushort_test_all, \
        unsigned int*: shmemx_uint_test_all, \
        unsigned long*: shmemx_ulong_test_all, \
        unsigned long long*: shmemx_ulonglong_test_all \
    )(__VA_ARGS__)

#define shmemx_test_any(...) \
    _Generic(SHMEM_C11_TYPE_EVAL_PTR(SHMEM_C11_ARG0(__VA_ARGS__)), \
             default: shmem_ctx_c11_generic_selection_failed, \
        short*: shmemx_short_test_any, \
        int*: shmemx_int_test_any, \
        long*: shmemx_long_test_any, \
        long long*: shmemx_longlong_test_any, \
        unsigned short*: shmemx_ushort_test_any, \
        unsigned int*: shmemx_uint_test_any, \
        unsigned long*: shmemx_ulong_test_any, \
        unsigned long long*: shmemx_ulonglong_test_any \
    )(__VA_ARGS__)

#define shmemx_test_some(...) \
    _Generic(SHMEM_C11_TYPE_EVAL_PTR(SHMEM_C11_ARG0(__VA_ARGS__)), \
             default: shmem_ctx_c11_generic_selection_failed, \
        short*: shmemx_short_test_some, \
        int*: shmemx_int_test_some, \
        long*: shmemx_long_test_some, \
        long long*: shmemx_longlong_test_some, \
        unsigned short*: shmemx_ushort_test_some, \
        unsigned int*: shmemx_uint_test_some, \
        unsigned long*: shmemx_ulong_test_some, \
        unsigned long long*: shmemx_ulonglong_test_some \
    )(__VA_ARGS__)

/* Nonblocking fetching AMOs */
#define shmemx_atomic_swap_nbi(...) \
    _Generic(SHMEM_C11_TYPE_EVAL_PTR(SHMEM_C11_ARG0(__VA_ARGS__)), \
        shmem_ctx_t: \
        _Generic(SHMEM_C11_TYPE_EVAL_PTR_OR_SCALAR(SHMEM_C11_ARG1(__VA_ARGS__)), \
            int*: shmemx_ctx_int_atomic_swap_nbi, \
            long*: shmemx_ctx_long_atomic_swap_nbi, \
            long long*: shmemx_ctx_longlong_atomic_swap_nbi, \
            unsigned int*: shmemx_ctx_uint_atomic_swap_nbi, \
            unsigned long*: shmemx_ctx_ulong_atomic_swap_nbi, \
            unsigned long long*: shmemx_ctx_ulonglong_atomic_swap_nbi, \
            float*: shmemx_ctx_float_atomic_swap_nbi, \
            double*: shmemx_ctx_double_atomic_swap_nbi, \
            default: shmem_ctx_c11_generic_selection_failed \
        ), \
        int*: shmemx_int_atomic_swap_nbi, \
        long*: shmemx_long_atomic_swap_nbi, \
        long long*: shmemx_longlong_atomic_swap_nbi, \
        unsigned int*: shmemx_uint_atomic_swap_nbi, \
        unsigned long*: shmemx_ulong_atomic_swap_nbi, \
        unsigned long long*: shmemx_ulonglong_atomic_swap_nbi, \
        float*: shmemx_float_atomic_swap_nbi, \
        double*: shmemx_double_atomic_swap_nbi \
    )(__VA_ARGS__)

#define shmemx_atomic_compare_swap_nbi(...) \
    _Generic(SHMEM_C11_TYPE_EVAL_PTR(SHMEM_C11_ARG0(__VA_ARGS__)), \
        shmem_ctx_t: \
        _Generic(SHMEM_C11_TYPE_EVAL_PTR_OR_SCALAR(SHMEM_C11_ARG1(__VA_ARGS__)), \
            int*: shmemx_ctx_int_atomic_compare_swap_nbi, \
            long*: shmemx_ctx_long_atomic_compare_swap_nbi, \
            long long*: shmemx_ctx_longlong_atomic_compare_swap_nbi, \
            unsigned int*: shmemx_ctx_uint_atomic_compare_swap_nbi, \
            unsigned long*: shmemx_ctx_ulong_atomic_compare_swap_nbi, \
            unsigned long long*: shmemx_ctx_ulonglong_atomic_compare_swap_nbi, \
            default: shmem_ctx_c11_generic_selection_failed \
        ), \
        int*: shmemx_int_atomic_compare_swap_nbi, \
        long*: shmemx_long_atomic_compare_swap_nbi, \
        long long*: shmemx_longlong_atomic_compare_swap_nbi, \
        unsigned int*: shmemx_uint_atomic_compare_swap_nbi, \
        unsigned long*: shmemx_ulong_atomic_compare_swap_nbi, \
        unsigned long long*: shmemx_ulonglong_atomic_compare_swap_nbi \
    )(__VA_ARGS__)

#define shmemx_atomic_fetch_nbi(...) \
    _Generic(SHMEM_C11_TYPE_EVAL_PTR(SHMEM_C11_ARG0(__VA_ARGS__)), \
        shmem_ctx_t: \
        _Generic(SHMEM_C11_TYPE_EVAL_PTR_OR_SCALAR(SHMEM_C11_ARG1(__VA_ARGS__)), \
            int*: shmemx_ctx_int_atomic_fetch_nbi, \
            long*: shmemx_ctx_long_atomic_fetch_nbi, \
            long long*: shmemx_ctx_longlong_atomic_fetch_nbi, \
            unsigned int*: shmemx_ctx_uint_atomic_fetch_nbi, \
            unsigned long*: shmemx_ctx_ulong_atomic_fetch_nbi, \
            unsigned long long*: shmemx_ctx_ulonglong_atomic_fetch_nbi, \
            float*: shmemx_ctx_float_atomic_fetch_nbi, \
            double*: shmemx_ctx_double_atomic_fetch_nbi, \
            const int*: shmemx_ctx_int_atomic_fetch_nbi, \
            const long*: shmemx_ctx_long_atomic_fetch_nbi, \
            const long long*: shmemx_ctx_longlong_atomic_fetch_nbi, \
            const unsigned int*: shmemx_ctx_uint_atomic_fetch_nbi, \
            const unsigned long*: shmemx_ctx_ulong_atomic_fetch_nbi, \
            const unsigned long long*: shmemx_ctx_ulonglong_atomic_fetch_nbi, \
            const float*: shmemx_ctx_float_atomic_fetch_nbi, \
            const double*: shmemx_ctx_double_atomic_fetch_nbi, \
            default: shmem_ctx_c11_generic_selection_failed \
        ), \
        int*: shmemx_int_atomic_fetch_nbi, \
        long*: shmemx_long_atomic_fetch_nbi, \
        long long*: shmemx_longlong_atomic_fetch_nbi, \
        unsigned int*: shmemx_uint_atomic_fetch_nbi, \
        unsigned long*: shmemx_ulong_atomic_fetch_nbi, \
        unsigned long long*: shmemx_ulonglong_atomic_fetch_nbi, \
        float*: shmemx_float_atomic_fetch_nbi, \
        double*: shmemx_double_atomic_fetch_nbi, \
        const int*: shmemx_int_atomic_fetch_nbi, \
        const long*: shmemx_long_atomic_fetch_nbi, \
        const long long*: shmemx_longlong_atomic_fetch_nbi, \
        const unsigned int*: shmemx_uint_atomic_fetch_nbi, \
        const unsigned long*: shmemx_ulong_atomic_fetch_nbi, \
        const unsigned long long*: shmemx_ulonglong_atomic_fetch_nbi, \
        const float*: shmemx_float_atomic_fetch_nbi, \
        const double*: shmemx_double_atomic_fetch_nbi \
    )(__VA_ARGS__)

#define shmemx_atomic_fetch_add_nbi(...) \
    _Generic(SHMEM_C11_TYPE_EVAL_PTR(SHMEM_C11_ARG0(__VA_ARGS__)), \
        shmem_ctx_t: \
        _Generic(SHMEM_C11_TYPE_EVAL_PTR_OR_SCALAR(SHMEM_C11_ARG1(__VA_ARGS__)), \
            int*: shmemx_ctx_int_atomic_fetch_add_nbi, \
            long*: shmemx_ctx_long_atomic_fetch_add_nbi, \
            long long*: shmemx_ctx_longlong_atomic_fetch_add_nbi, \
            unsigned int*: shmemx_ctx_uint_atomic_fetch_add_nbi, \
            unsigned long*: shmemx_ctx_ulong_atomic_fetch_add_nbi, \
            unsigned long long*: shmemx_ctx_ulonglong_atomic_fetch_add_nbi, \
            default: shmem_ctx_c11_generic_selection_failed \
        ), \
        int*: shmemx_int_atomic_fetch_add_nbi, \
        long*: shmemx_long_atomic_fetch_add_nbi, \
        long long*: shmemx_longlong_atomic_fetch_add_nbi, \
        unsigned int*: shmemx_uint_atomic_fetch_add_nbi, \
        unsigned long*: shmemx_ulong_atomic_fetch_add_nbi, \
        unsigned long long*: shmemx_ulonglong_atomic_fetch_add_nbi \
    )(__VA_ARGS__)

#define shmemx_atomic_fetch_inc_nbi(...) \
    _Generic(SHMEM_C11_TYPE_EVAL_PTR(SHMEM_C11_ARG0(__VA_ARGS__)), \
        shmem_ctx_t: \
        _Generic(SHMEM_C11_TYPE_EVAL_PTR_OR_SCALAR(SHMEM_C11_ARG1(__VA_ARGS__)), \
            int*: shmemx_ctx_int_atomic_fetch_inc_nbi, \
            long*: shmemx_ctx_long_atomic_fetch_inc_nbi, \
            long long*: shmemx_ctx_longlong_atomic_fetch_inc_nbi, \
            unsigned int*: shmemx_ctx_uint_atomic_fetch_inc_nbi, \
            unsigned long*: shmemx_ctx_ulong_atomic_fetch_inc_nbi, \
            unsigned long long*: shmemx_ctx_ulonglong_atomic_fetch_inc_nbi, \
            default: shmem_ctx_c11_generic_selection_failed \
        ), \
        int*: shmemx_int_atomic_fetch_inc_nbi, \
        long*: shmemx_long_atomic_fetch_inc_nbi, \
        long long*: shmemx_longlong_atomic_fetch_inc_nbi, \
        unsigned int*: shmemx_uint_atomic_fetch_inc_nbi, \
        unsigned long*: shmemx_ulong_atomic_fetch_inc_nbi, \
        unsigned long long*: shmemx_ulonglong_atomic_fetch_inc_nbi \
    )(__VA_ARGS__)

#define shmemx_atomic_fetch_and_nbi(...) \
    _Generic(SHMEM_C11_TYPE_EVAL_PTR(SHMEM_C11_ARG0(__VA_ARGS__)), \
        shmem_ctx_t: \
        _Generic(SHMEM_C11_TYPE_EVAL_PTR_OR_SCALAR(SHMEM_C11_ARG1(__VA_ARGS__)), \
            int32_t*: shmemx_ctx_int32_atomic_fetch_and_nbi, \
            int64_t*: shmemx_ctx_int64_atomic_fetch_and_nbi, \
            unsigned int*: shmemx_ctx_uint_atomic_fetch_and_nbi, \
            unsigned long*: shmemx_ctx_ulong_atomic_fetch_and_nbi, \
            unsigned long long*: shmemx_ctx_ulonglong_atomic_fetch_and_nbi, \
            default: shmem_ctx_c11_generic_selection_failed \
        ), \
        int32_t*: shmemx_int32_atomic_fetch_and_nbi, \
        int64_t*: shmemx_int64_atomic_fetch_and_nbi, \
        unsigned int*: shmemx_uint_atomic_fetch_and_nbi, \
        unsigned long*: shmemx_ulong_atomic_fetch_and_nbi, \
        unsigned long long*: shmemx_ulonglong_atomic_fetch_and_nbi \
    )(__VA_ARGS__)

#define shmemx_atomic_fetch_or_nbi(...) \
    _Generic(SHMEM_C11_TYPE_EVAL_PTR(SHMEM_C11_ARG0(__VA_ARGS__)), \
        shmem_ctx_t: \
        _Generic(SHMEM_C11_TYPE_EVAL_PTR_OR_SCALAR(SHMEM_C11_ARG1(__VA_ARGS__)), \
            int32_t*: shmemx_ctx_int32_atomic_fetch_or_nbi, \
            int64_t*: shmemx_ctx_int64_atomic_fetch_or_nbi, \
            unsigned int*: shmemx_ctx_uint_atomic_fetch_or_nbi, \
            unsigned long*: shmemx_ctx_ulong_atomic_fetch_or_nbi, \
            unsigned long long*: shmemx_ctx_ulonglong_atomic_fetch_or_nbi, \
            default: shmem_ctx_c11_generic_selection_failed \
        ), \
        int32_t*: shmemx_int32_atomic_fetch_or_nbi, \
        int64_t*: shmemx_int64_atomic_fetch_or_nbi, \
        unsigned int*: shmemx_uint_atomic_fetch_or_nbi, \
        unsigned long*: shmemx_ulong_atomic_fetch_or_nbi, \
        unsigned long long*: shmemx_ulonglong_atomic_fetch_or_nbi \
    )(__VA_ARGS__)

#define shmemx_atomic_fetch_xor_nbi(...) \
    _Generic(SHMEM_C11_TYPE_EVAL_PTR(SHMEM_C11_ARG0(__VA_ARGS__)), \
        shmem_ctx_t: \
        _Generic(SHMEM_C11_TYPE_EVAL_PTR_OR_SCALAR(SHMEM_C11_ARG1(__VA_ARGS__)), \
            int32_t*: shmemx_ctx_int32_atomic_fetch_xor_nbi, \
            int64_t*: shmemx_ctx_int64_atomic_fetch_xor_nbi, \
            unsigned int*: shmemx_ctx_uint_atomic_fetch_xor_nbi, \
            unsigned long*: shmemx_ctx_ulong_atomic_fetch_xor_nbi, \
            unsigned long long*: shmemx_ctx_ulonglong_atomic_fetch_xor_nbi, \
            default: shmem_ctx_c11_generic_selection_failed \
        ), \
        int32_t*: shmemx_int32_atomic_fetch_xor_nbi, \
        int64_t*: shmemx_int64_atomic_fetch_xor_nbi, \
        unsigned int*: shmemx_uint_atomic_fetch_xor_nbi, \
        unsigned long*: shmemx_ulong_atomic_fetch_xor_nbi, \
        unsigned long long*: shmemx_ulonglong_atomic_fetch_xor_nbi \
    )(__VA_ARGS__)

/* Blocking put with signal */
#define shmemx_put_signal(...) \
    _Generic(SHMEM_C11_TYPE_EVAL_PTR(SHMEM_C11_ARG0(__VA_ARGS__)), \
        shmem_ctx_t: \
        _Generic(SHMEM_C11_TYPE_EVAL_PTR(SHMEM_C11_ARG1(__VA_ARGS__)), \
            float*: shmemx_ctx_float_put_signal, \
            double*: shmemx_ctx_double_put_signal, \
            long double*: shmemx_ctx_longdouble_put_signal, \
            char*: shmemx_ctx_char_put_signal, \
            signed char*: shmemx_ctx_schar_put_signal, \
            short*: shmemx_ctx_short_put_signal, \
            int*: shmemx_ctx_int_put_signal, \
            long*: shmemx_ctx_long_put_signal, \
            long long*: shmemx_ctx_longlong_put_signal, \
            unsigned char*: shmemx_ctx_uchar_put_signal, \
            unsigned short*: shmemx_ctx_ushort_put_signal, \
            unsigned int*: shmemx_ctx_uint_put_signal, \
            unsigned long*: shmemx_ctx_ulong_put_signal, \
            unsigned long long*: shmemx_ctx_ulonglong_put_signal \
            default: shmem_ctx_c11_generic_selection_failed \
        ), \
        float*: shmemx_float_put_signal, \
        double*: shmemx_double_put_signal, \
        long double*: shmemx_longdouble_put_signal, \
        char*: shmemx_char_put_signal, \
        signed char*: shmemx_schar_put_signal, \
        short*: shmemx_short_put_signal, \
        int*: shmemx_int_put_signal, \
        long*: shmemx_long_put_signal, \
        long long*: shmemx_longlong_put_signal, \
        unsigned char*: shmemx_uchar_put_signal, \
        unsigned short*: shmemx_ushort_put_signal, \
        unsigned int*: shmemx_uint_put_signal, \
        unsigned long*: shmemx_ulong_put_signal, \
        unsigned long long*: shmemx_ulonglong_put_signal \
    )(__VA_ARGS__)

/* Non-blocking put with signal */
#define shmemx_put_signal_nbi(...) \
    _Generic(SHMEM_C11_TYPE_EVAL_PTR(SHMEM_C11_ARG0(__VA_ARGS__)), \
        shmem_ctx_t: \
        _Generic(SHMEM_C11_TYPE_EVAL_PTR(SHMEM_C11_ARG1(__VA_ARGS__)), \
            float*: shmemx_ctx_float_put_signal_nbi, \
            double*: shmemx_ctx_double_put_signal_nbi, \
            long double*: shmemx_ctx_longdouble_put_signal_nbi, \
            char*: shmemx_ctx_char_put_signal_nbi, \
            signed char*: shmemx_ctx_schar_put_signal_nbi, \
            short*: shmemx_ctx_short_put_signal_nbi, \
            int*: shmemx_ctx_int_put_signal_nbi, \
            long*: shmemx_ctx_long_put_signal_nbi, \
            long long*: shmemx_ctx_longlong_put_signal_nbi, \
            unsigned char*: shmemx_ctx_uchar_put_signal_nbi, \
            unsigned short*: shmemx_ctx_ushort_put_signal_nbi, \
            unsigned int*: shmemx_ctx_uint_put_signal_nbi, \
            unsigned long*: shmemx_ctx_ulong_put_signal_nbi, \
            unsigned long long*: shmemx_ctx_ulonglong_put_signal_nbi \
            default: shmem_ctx_c11_generic_selection_failed \
        ), \
        float*: shmemx_float_put_signal_nbi, \
        double*: shmemx_double_put_signal_nbi, \
        long double*: shmemx_longdouble_put_signal_nbi, \
        char*: shmemx_char_put_signal_nbi, \
        signed char*: shmemx_schar_put_signal_nbi, \
        short*: shmemx_short_put_signal_nbi, \
        int*: shmemx_int_put_signal_nbi, \
        long*: shmemx_long_put_signal_nbi, \
        long long*: shmemx_longlong_put_signal_nbi, \
        unsigned char*: shmemx_uchar_put_signal_nbi, \
        unsigned short*: shmemx_ushort_put_signal_nbi, \
        unsigned int*: shmemx_uint_put_signal_nbi, \
        unsigned long*: shmemx_ulong_put_signal_nbi, \
        unsigned long long*: shmemx_ulonglong_put_signal_nbi \
    )(__VA_ARGS__)

#endif /* C11 */

#define SHMEM_HINT_NONE                 0
#define SHMEM_HINT_LOW_LAT_MEM          (1 << 0)
#define SHMEM_HINT_HIGH_BW_MEM          (1 << 1)
#define SHMEM_HINT_NEAR_NIC_MEM         (1 << 2)
#define SHMEM_HINT_DEVICE_GPU_MEM       (1 << 3)
#define SHMEM_HINT_DEVICE_NIC_MEM       (1 << 4)
#define SHMEM_HINT_PSYNC                (1 << 5)
#define SHMEM_HINT_PWORK                (1 << 6)
#define SHMEM_HINT_ATOMICS              (1 << 7)
void * shmemx_malloc_with_hints(size_t size, long hints);

#endif /* SHMEMX_H */
