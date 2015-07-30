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

#ifndef _HEAVY_UTILS_H_
#define _HEAVY_UTILS_H_

// Type definitions
#if _WIN32 || _WIN64 || WINAPI_FAMILY
#define HV_WIN 1
#include <stddef.h>
#if defined (_MSC_VER)
#define HV_MSVC 1
#endif
#define hv_size_t unsigned long
#define hv_uint32_t unsigned int
#define hv_uint16_t unsigned short
#define hv_int32_t int
#elif __APPLE__ && __MACH__
#define HV_APPLE 1
#include <stddef.h>
#define hv_size_t size_t
#define hv_uint32_t unsigned int
#define hv_uint16_t unsigned short
#define hv_int32_t int
#elif __unix__ || __unix
#define HV_UNIX 1
#include <stddef.h>
#include <stdint.h>
#define hv_size_t size_t
#define hv_uint32_t uint32_t
#define hv_uint16_t uint16_t
#define hv_int32_t int32_t
#else
#error Unsupported platform
#endif

// Memory management
extern void *hv_alloca(hv_size_t numbytes);
extern void *hv_malloc(hv_size_t numbytes); // allocates memory on 16 byte boundaries and clears it to zero
extern void hv_free(void *ptr); // frees aligned memory
extern void *hv_realloc(void *ptr, hv_size_t numBytes);
extern void *hv_memcpy(void *dest, const void *src, hv_size_t numbytes);
extern void *hv_memset(void *ptr, hv_size_t numbytes); // sets everything to 0

// String handling
extern hv_size_t hv_strlen(const char *str);
extern char *hv_strncat(char *dest, const char *str, hv_size_t n);
extern char *hv_strncpy(char *dest, const char *str, hv_size_t n);
extern int hv_strcmp(const char *str1, const char *str2);
extern int hv_strncmp(const char *str1, const char *str2, hv_size_t n);
extern int hv_snprintf(char *dest, hv_size_t n, const char *format, ...);

// Math
extern int hv_max_i(int x, int y);
extern hv_size_t hv_max_ui(hv_size_t x, hv_size_t y);
extern int hv_min_i(int x, int y);
extern hv_size_t hv_min_ui(hv_size_t x, hv_size_t y);
extern float hv_max_f(float x, float y);
extern float hv_min_f(float x, float y);
extern double hv_max_d(double x, double y);
extern double hv_min_d(double x, double y);
extern float hv_sin_f(float x);
extern float hv_sinh_f(float x);
extern float hv_cos_f(float x);
extern float hv_cosh_f(float x);
extern float hv_tan_f(float x);
extern float hv_tanh_f(float x);
extern float hv_asin_f(float x);
extern float hv_asinh_f(float x);
extern float hv_acos_f(float x);
extern float hv_acosh_f(float x);
extern float hv_atan_f(float x);
extern float hv_atanh_f(float x);
extern float hv_atan2_f(float x, float y);
extern float hv_exp_f(float x);
extern float hv_abs_f(float x);
extern float hv_sqrt_f(float x);
extern float hv_log_f(float x);
extern float hv_log2_f(float x);
extern float hv_log10_f(float x);
extern float hv_ceil_f(float x);
extern float hv_floor_f(float x);
extern float hv_round_f(float x);
extern float hv_pow_f(float x, float y);
extern float hv_fma_f(float x, float y, float z);

// Utilities
extern void hv_assert(int e);
extern void hv_clear_buffer(float *b, int n);
extern hv_uint32_t hv_min_max_log2(hv_uint32_t x);

// SIMD
#ifndef HV_SIMD_NONE
  #define HV_SIMD_NEON __ARM_NEON__
  #define HV_SIMD_SSE (__SSE__ && __SSE2__ && __SSE3__ && __SSSE3__ && __SSE4_1__ && __SSE4_2__)
  #define HV_SIMD_AVX (__AVX__ && HV_SIMD_SSE) // it is required that if AVX exists then SSE will also be available
  #define HV_SIMD_FMA __FMA__
#endif

#ifdef HV_WIN
#include "Utils_windows.h"
#elif HV_APPLE
#include "Utils_mac.h"
#elif HV_UNIX
#include "Utils_unix.h"
#else
#error Unsupported platform
#endif

#if HV_SIMD_NEON // NEON
  #define HV_N_SIMD 4
  #define hv_bufferf_t float32x4_t
  #define hv_bufferi_t int32x4_t
  #define hv_bInf_t float32x4_t
  #define hv_bOutf_t float32x4_t*
  #define hv_bIni_t int32x4_t
  #define hv_bOuti_t int32x4_t*
  #define VIf(_x) (_x)
  #define VOf(_x) (&_x)
  #define VIi(_x) (_x)
  #define VOi(_x) (&_x)
#elif HV_SIMD_AVX // AVX
  #define HV_N_SIMD 8
  #define hv_bufferf_t __m256
  #define hv_bufferi_t __m256i
  #define hv_bInf_t __m256
  #define hv_bOutf_t __m256*
  #define hv_bIni_t __m256i
  #define hv_bOuti_t __m256i*
  #define VIf(_x) (_x)
  #define VOf(_x) (&_x)
  #define VIi(_x) (_x)
  #define VOi(_x) (&_x)
#elif HV_SIMD_SSE // SSE
  #define HV_N_SIMD 4
  #define hv_bufferf_t __m128
  #define hv_bufferi_t __m128i
  #define hv_bInf_t __m128
  #define hv_bOutf_t __m128*
  #define hv_bIni_t __m128i
  #define hv_bOuti_t __m128i*
  #define VIf(_x) (_x)
  #define VOf(_x) (&_x)
  #define VIi(_x) (_x)
  #define VOi(_x) (&_x)
#else // DEFAULT
  #define HV_N_SIMD 1
  #undef HV_SIMD_NONE
  #define HV_SIMD_NONE 1
  #define hv_bufferf_t float
  #define hv_bufferi_t int
  #define hv_bInf_t float
  #define hv_bOutf_t float*
  #define hv_bIni_t int
  #define hv_bOuti_t int*
  #define VIf(_x) (_x)
  #define VOf(_x) (&_x)
  #define VIi(_x) (_x)
  #define VOi(_x) (&_x)
#endif

#define HV_N_SIMD_MASK (HV_N_SIMD-1)

#endif // _HEAVY_UTILS_H_
