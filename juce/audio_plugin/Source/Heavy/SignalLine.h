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

#ifndef _SIGNAL_LINE_H_
#define _SIGNAL_LINE_H_

#include "HvBase.h"

typedef struct SignalLine {
#if HV_SIMD_AVX
  __m128i n; // remaining samples to target
#else
  hv_bufferi_t n; // remaining samples to target
#endif
  hv_bufferf_t x; // current output
  hv_bufferf_t m; // increment
  hv_bufferf_t t; // target value
} SignalLine;

hv_size_t sLine_init(SignalLine *o);

static inline void __hv_line_f(SignalLine *o, hv_bOutf_t bOut) {
#if HV_SIMD_AVX
  static const __m128i z = (__m128i) {0L, 0L};
  static const __m128i n_simd = (__m128i) {0x400000004L, 0x400000004L}; // (4 << 32 | 4)

  __m128i n = o->n;
  __m128i masklo = _mm_cmplt_epi32(n, z); // n < 0
  n = _mm_sub_epi32(n, n_simd); // subtract HV_N_SIMD from remaining samples
  __m128i maskhi = _mm_cmplt_epi32(n, z);
  o->n = _mm_sub_epi32(n, n_simd);
  __m256 mask = _mm256_insertf128_ps(_mm256_castps128_ps256(_mm_castsi128_ps(masklo)), _mm_castsi128_ps(maskhi), 1);

  __m256 x = o->x;
  *bOut = _mm256_or_ps(_mm256_and_ps(mask, o->t), _mm256_andnot_ps(mask, x));

  // add slope from sloped samples
  o->x = _mm256_add_ps(x, o->m);
#elif HV_SIMD_SSE
  static const __m128i z = (__m128i) {0L, 0L};
  static const __m128i n_simd = (__m128i) {0x400000004L, 0x400000004L}; // (4 << 32 | 4)

  __m128i n = o->n;
  __m128 mask = _mm_castsi128_ps(_mm_cmplt_epi32(n, z)); // n < 0

  __m128 x = o->x;
  *bOut = _mm_or_ps(_mm_and_ps(mask, o->t), _mm_andnot_ps(mask, x));

  // subtract HV_N_SIMD from remaining samples
  o->n = _mm_sub_epi32(n, n_simd);

  // add slope from sloped samples
  o->x = _mm_add_ps(x, o->m);
#elif HV_SIMD_NEON
  int32x4_t n = o->n;
  uint32x4_t mask = vcltq_s32(n, vdupq_n_s32(0));
  float32x4_t x = o->x;
  *bOut = vreinterpretq_f32_s32(vorrq_s32(
      vandq_s32(mask, vreinterpretq_s32_f32(o->t)),
      vbicq_s32(vreinterpretq_s32_f32(x), (int32x4_t) mask)));
  o->n = vsubq_s32(n, vdupq_n_s32(HV_N_SIMD));
  o->x = vaddq_f32(x, o->m);
#else // HV_SIMD_NONE
  *bOut = (o->n < 0) ? o->t : o->x;
  o->n -= HV_N_SIMD;
  o->x += o->m;
#endif
}

void sLine_onMessage(HvBase *_c, SignalLine *o, int letIndex,
    const HvMessage *const m, void *sendMessage);

#endif // _SIGNAL_LINE_H_
