/**
 * Copyright (c) 2014,2015 Enzien Audio, Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, and/or
 * sublicense copies of the Software, strictly on a non-commercial basis,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#ifndef _HEAVY_SIGNAL_TABWRITE_H_
#define _HEAVY_SIGNAL_TABWRITE_H_

#include "HvBase.h"
#include "HvTable.h"

#define HV_TABWRITE_STOPPED -1 // ~0x0

typedef struct SignalTabwrite {
  HvTable *table;
  hv_uint32_t head; // local write head. Where this object has most recently written to the table.
} SignalTabwrite;

hv_size_t sTabwrite_init(SignalTabwrite *o, HvTable *table);

void sTabwrite_onMessage(HvBase *_c, SignalTabwrite *o, int letIn, const HvMessage *const m,
    void (*sendMessage)(HvBase *, int, const HvMessage *const));

// linear write to table
static inline void __hv_tabwrite_f(SignalTabwrite *o, hv_bInf_t bIn) {
  hv_assert((o->head + HV_N_SIMD) <= hTable_getSize(o->table)); // assert that the table bounds are respected
  hv_uint32_t head = o->head;
#if HV_SIMD_AVX
  _mm256_store_ps(hTable_getBuffer(o->table) + head, bIn);
#elif HV_SIMD_SSE
  _mm_store_ps(hTable_getBuffer(o->table) + head, bIn);
#elif HV_SIMD_NEON
  vst1q_f32(hTable_getBuffer(o->table) + head, bIn);
#else // HV_SIMD_NONE
  *(hTable_getBuffer(o->table) + head) = bIn;
#endif
  head += HV_N_SIMD;
  o->head = head; // update local write head
  hTable_setHead(o->table, head); // update the remote write head (e.g. for use by vd~)
}

// linear unaligned write to table
static inline void __hv_tabwriteu_f(SignalTabwrite *o, hv_bInf_t bIn) {
  hv_uint32_t head = o->head;
#if HV_SIMD_AVX
  _mm256_storeu_ps(hTable_getBuffer(o->table) + head, bIn);
#elif HV_SIMD_SSE
  _mm_storeu_ps(hTable_getBuffer(o->table) + head, bIn);
#elif HV_SIMD_NEON
  vst1q_f32(hTable_getBuffer(o->table) + head, bIn);
#else // HV_SIMD_NONE
  *(hTable_getBuffer(o->table) + head) = bIn;
#endif
  head += HV_N_SIMD;
  o->head = head; // update local write head
  hTable_setHead(o->table, head); // update remote write head
}

// this tabread can be instructed to stop. It is mainly intended for linear reads that only process a portion of a buffer.
// Stores are unaligned, which can be slow but allows any indicies to be written to.
// TODO(mhroth): this is not stopping!
static inline void __hv_tabwrite_stoppable_f(SignalTabwrite *o, hv_bInf_t bIn) {
  if (o->head != HV_TABWRITE_STOPPED) {
#if HV_SIMD_AVX
    _mm256_storeu_ps(hTable_getBuffer(o->table) + o->head, bIn);
#elif HV_SIMD_SSE
    _mm_storeu_ps(hTable_getBuffer(o->table) + o->head, bIn);
#elif HV_SIMD_NEON
    vst1q_f32(hTable_getBuffer(o->table) + o->head, bIn);
#else // HV_SIMD_NONE
    *(hTable_getBuffer(o->table) + o->head) = bIn;
#endif
    o->head += HV_N_SIMD;
  }
}

// random write to table
static inline void __hv_tabwrite_if(SignalTabwrite *o, hv_bIni_t bIn0, hv_bInf_t bIn1) {
  float *const b = hTable_getBuffer(o->table);
#if HV_SIMD_AVX
  b[bIn0[0]] = bIn1[0];
  b[bIn0[1]] = bIn1[1];
  b[bIn0[2]] = bIn1[2];
  b[bIn0[3]] = bIn1[3];
  b[bIn0[4]] = bIn1[4];
  b[bIn0[5]] = bIn1[5];
  b[bIn0[6]] = bIn1[6];
  b[bIn0[7]] = bIn1[7];
#elif HV_SIMD_SSE
  b[bIn0[0]] = bIn1[0];
  b[bIn0[1]] = bIn1[1];
  b[bIn0[2]] = bIn1[2];
  b[bIn0[3]] = bIn1[3];
#elif HV_SIMD_NEON
  hv_assert((vgetq_lane_s32(bIn0,0) >= 0) && (vgetq_lane_s32(bIn0,0) < hTable_getSize(o->table)));
  hv_assert((vgetq_lane_s32(bIn0,1) >= 0) && (vgetq_lane_s32(bIn0,1) < hTable_getSize(o->table)));
  hv_assert((vgetq_lane_s32(bIn0,2) >= 0) && (vgetq_lane_s32(bIn0,2) < hTable_getSize(o->table)));
  hv_assert((vgetq_lane_s32(bIn0,3) >= 0) && (vgetq_lane_s32(bIn0,3) < hTable_getSize(o->table)));

  vst1q_lane_f32(b + vgetq_lane_s32(bIn0, 0), bIn1, 0);
  vst1q_lane_f32(b + vgetq_lane_s32(bIn0, 1), bIn1, 1);
  vst1q_lane_f32(b + vgetq_lane_s32(bIn0, 2), bIn1, 2);
  vst1q_lane_f32(b + vgetq_lane_s32(bIn0, 3), bIn1, 3);
#else // HV_SIMD_NONE
  b[bIn0] = bIn1;
#endif
}

#endif // _HEAVY_SIGNAL_TABWRITE_H_
