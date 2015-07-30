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
 *
 * DO NOT MODIFY. THIS CODE IS MACHINE GENERATED BY THE SECTION6 HEAVY COMPILER.
 */

/*
 * System Includes
 */

#include <assert.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>
#include "HvContext_ExamplePatch1.h"
#include "HeavyMath.h"


/*
 * Function Declarations
 */

static void cTabhead_Ji7pw_sendMessage(HvBase *, int, const HvMessage *const);
static void cBinop_OMovE_sendMessage(HvBase *, int, const HvMessage *const);
static void cCast_wTivW_sendMessage(HvBase *, int, const HvMessage *const);
static void cBinop_o0vf6_sendMessage(HvBase *, int, const HvMessage *const);
static void cSystem_mPZMj_sendMessage(HvBase *, int, const HvMessage *const);
static void cBinop_yDxXV_sendMessage(HvBase *, int, const HvMessage *const);
static void cMsg_HpI4l_sendMessage(HvBase *, int, const HvMessage *const);
static void cDelay_mgpqj_sendMessage(HvBase *, int, const HvMessage *const);
static void cBinop_UCT4O_sendMessage(HvBase *, int, const HvMessage *const);
static void cCast_bDyRP_sendMessage(HvBase *, int, const HvMessage *const);
static void cIf_Hchwi_sendMessage(HvBase *, int, const HvMessage *const);
static void cBinop_RxWyq_sendMessage(HvBase *, int, const HvMessage *const);
static void cCast_hFL72_sendMessage(HvBase *, int, const HvMessage *const);
static void cMsg_nEzhO_sendMessage(HvBase *, int, const HvMessage *const);
static void cBinop_X0bNe_sendMessage(HvBase *, int, const HvMessage *const);
static void cLoadbang_UGTjI_sendMessage(HvBase *, int, const HvMessage *const);
static void cMsg_suMGW_sendMessage(HvBase *, int, const HvMessage *const);
static void cSystem_5IsZr_sendMessage(HvBase *, int, const HvMessage *const);
static void cDelay_DNLQl_sendMessage(HvBase *, int, const HvMessage *const);
static void cBinop_hduOb_sendMessage(HvBase *, int, const HvMessage *const);
static void cVar_ntMXo_sendMessage(HvBase *, int, const HvMessage *const);
static void cCast_AUqyB_sendMessage(HvBase *, int, const HvMessage *const);
static void cCast_ikYXX_sendMessage(HvBase *, int, const HvMessage *const);
static void cLoadbang_2Bs9y_sendMessage(HvBase *, int, const HvMessage *const);
static void cCast_JmBAT_sendMessage(HvBase *, int, const HvMessage *const);
static void cDelay_6UqWb_sendMessage(HvBase *, int, const HvMessage *const);
static void cMsg_zkxmk_sendMessage(HvBase *, int, const HvMessage *const);
static void cBinop_byqqR_sendMessage(HvBase *, int, const HvMessage *const);
static void cBinop_7oAye_sendMessage(HvBase *, int, const HvMessage *const);
static void cMsg_2sDGt_sendMessage(HvBase *, int, const HvMessage *const);
static void cSystem_vaBCG_sendMessage(HvBase *, int, const HvMessage *const);
static void hTable_WKE6m_sendMessage(HvBase *, int, const HvMessage *const);



/*
 * Static Helper Functions
 */

static void ctx_intern_scheduleMessageForReceiver(HvBase *const _c, const char *name, HvMessage *m) {
  switch (msg_symbolToHash(name)) {

    default: return;
  }
}

static struct HvTable *ctx_intern_getTableForHash(HvBase *const _c, hv_uint32_t h) {
  switch (h) {
    case 0x52B9CED0: return &Context(_c)->hTable_WKE6m; // "del-delay"
    default: return NULL;
  }
}



/*
 * Context Include and Implementatons
 */

Hv_ExamplePatch1 *hv_ExamplePatch1_new_with_pool(double sampleRate, int poolKb) {
  hv_assert(sampleRate > 0.0); // can't initialise with sampling rate of 0
  hv_assert(poolKb >= 1); // a message pool of some reasonable size is always needed
  Hv_ExamplePatch1 *const _c = (Hv_ExamplePatch1 *) hv_malloc(sizeof(Hv_ExamplePatch1));

  Base(_c)->numInputChannels = 1;
  Base(_c)->numOutputChannels = 1;
  Base(_c)->sampleRate = sampleRate;
  Base(_c)->blockStartTimestamp = 0;
  Base(_c)->f_scheduleMessageForReceiver = &ctx_intern_scheduleMessageForReceiver;
  Base(_c)->f_getTableForHash = &ctx_intern_getTableForHash;
  mq_initWithPoolSize(&Base(_c)->mq, poolKb);
  Base(_c)->basePath = NULL;
  Base(_c)->printHook = NULL;
  Base(_c)->sendHook = NULL;
  Base(_c)->userData = NULL;
  Base(_c)->name = "ExamplePatch1";

  Base(_c)->numBytes = sizeof(Hv_ExamplePatch1);
  Base(_c)->numBytes += sTabread_init(&_c->sTabread_Hqi5g, &_c->hTable_WKE6m, true);
  Base(_c)->numBytes += sTabwrite_init(&_c->sTabwrite_LZKYO, &_c->hTable_WKE6m);
  Base(_c)->numBytes += cTabhead_init(&_c->cTabhead_Ji7pw, &_c->hTable_WKE6m);
  Base(_c)->numBytes += cBinop_init(&_c->cBinop_OMovE, 0.0f); // __sub
  Base(_c)->numBytes += cBinop_init(&_c->cBinop_yDxXV, 0.0f); // __add
  Base(_c)->numBytes += cDelay_init(Base(_c), &_c->cDelay_mgpqj, 0.0f);
  Base(_c)->numBytes += cBinop_init(&_c->cBinop_UCT4O, 250.0f); // __mul
  Base(_c)->numBytes += cIf_init(&_c->cIf_Hchwi, false);
  Base(_c)->numBytes += cBinop_init(&_c->cBinop_RxWyq, 0.0f); // __gte
  Base(_c)->numBytes += cBinop_init(&_c->cBinop_X0bNe, 0.0f); // __sub
  Base(_c)->numBytes += cDelay_init(Base(_c), &_c->cDelay_DNLQl, 250.0f);
  Base(_c)->numBytes += cVar_init_s(&_c->cVar_ntMXo, "del-delay");
  Base(_c)->numBytes += cDelay_init(Base(_c), &_c->cDelay_6UqWb, 0.0f);
  Base(_c)->numBytes += hTable_init(&_c->hTable_WKE6m, 256);

  // loadbang
  ctx_scheduleMessage(Base(_c), msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0), &cLoadbang_2Bs9y_sendMessage, 0);
  ctx_scheduleMessage(Base(_c), msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0), &cLoadbang_UGTjI_sendMessage, 0);

  return _c;
}

Hv_ExamplePatch1 *hv_ExamplePatch1_new(double sampleRate) {
  return hv_ExamplePatch1_new_with_pool(sampleRate, 10); // default to 10KB MessagePool
}

void hv_ExamplePatch1_free(Hv_ExamplePatch1 *_c) {
  hTable_free(&_c->hTable_WKE6m);

  hv_free(Base(_c)->basePath);
  mq_free(&Base(_c)->mq); // free queue after all objects have been freed, messages may be cancelled

  hv_free(_c);
}



/*
 * Static Function Implementation
 */

static void cTabhead_Ji7pw_sendMessage(HvBase *_c, int letIn, const HvMessage *const m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OMovE, HV_BINOP_SUBTRACT, 0, m, &cBinop_OMovE_sendMessage);
}
static void cBinop_OMovE_sendMessage(HvBase *_c, int letIn, const HvMessage *const m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RxWyq, HV_BINOP_GREATER_THAN_EQL, 0, m, &cBinop_RxWyq_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Hchwi, 0, m, &cIf_Hchwi_sendMessage);
}
static void cCast_wTivW_sendMessage(HvBase *_c, int letIn, const HvMessage *const m) {
  sTabread_onMessage(_c, &Context(_c)->sTabread_Hqi5g, 0, m);
  cBinop_onMessage(_c, &Context(_c)->cBinop_X0bNe, HV_BINOP_SUBTRACT, 0, m, &cBinop_X0bNe_sendMessage);
}
static void cBinop_o0vf6_sendMessage(HvBase *_c, int letIn, const HvMessage *const m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_DNLQl, 2, m, &cDelay_DNLQl_sendMessage);
}
static void cSystem_mPZMj_sendMessage(HvBase *_c, int letIn, const HvMessage *const m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yDxXV, HV_BINOP_ADD, 1, m, &cBinop_yDxXV_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mgpqj, 2, m, &cDelay_mgpqj_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_X0bNe, HV_BINOP_SUBTRACT, 1, m, &cBinop_X0bNe_sendMessage);
}
static void cBinop_yDxXV_sendMessage(HvBase *_c, int letIn, const HvMessage *const m) {
  cMsg_HpI4l_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wTivW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ikYXX_sendMessage);
}
static void cMsg_HpI4l_sendMessage(HvBase *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = NULL;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_DNLQl, 0, m, &cDelay_DNLQl_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mgpqj, 0, m, &cDelay_mgpqj_sendMessage);
}
static void cDelay_mgpqj_sendMessage(HvBase *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mgpqj, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Hqi5g, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mgpqj, 0, m, &cDelay_mgpqj_sendMessage);
}
static void cBinop_UCT4O_sendMessage(HvBase *_c, int letIn, const HvMessage *const m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OMovE, HV_BINOP_SUBTRACT, 1, m, &cBinop_OMovE_sendMessage);
}
static void cCast_bDyRP_sendMessage(HvBase *_c, int letIn, const HvMessage *const m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UCT4O, HV_BINOP_MULTIPLY, 1, m, &cBinop_UCT4O_sendMessage);
}
static void cIf_Hchwi_sendMessage(HvBase *_c, int letIn, const HvMessage *const m) {
  switch(letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_yDxXV, HV_BINOP_ADD, 0, m, &cBinop_yDxXV_sendMessage);
      break;
    }
    case 1: {
      cMsg_HpI4l_sendMessage(_c, 0, m);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wTivW_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ikYXX_sendMessage);
      break;
    }
    default: return;
  }
}
static void cBinop_RxWyq_sendMessage(HvBase *_c, int letIn, const HvMessage *const m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Hchwi, 1, m, &cIf_Hchwi_sendMessage);
}
static void cCast_hFL72_sendMessage(HvBase *_c, int letIn, const HvMessage *const m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ntMXo, 0, m, &cVar_ntMXo_sendMessage);
  cMsg_suMGW_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Ji7pw, 0, m, &cTabhead_Ji7pw_sendMessage);
}
static void cMsg_nEzhO_sendMessage(HvBase *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = NULL;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mPZMj_sendMessage);
}
static void cBinop_X0bNe_sendMessage(HvBase *_c, int letIn, const HvMessage *const m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_o0vf6_sendMessage);
}
static void cLoadbang_UGTjI_sendMessage(HvBase *_c, int letIn, const HvMessage *const m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ntMXo, 0, m, &cVar_ntMXo_sendMessage);
  cMsg_suMGW_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Ji7pw, 0, m, &cTabhead_Ji7pw_sendMessage);
}
static void cMsg_suMGW_sendMessage(HvBase *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = NULL;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5IsZr_sendMessage);
}
static void cSystem_5IsZr_sendMessage(HvBase *_c, int letIn, const HvMessage *const m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_hduOb_sendMessage);
}
static void cDelay_DNLQl_sendMessage(HvBase *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_DNLQl, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mgpqj, 0, m, &cDelay_mgpqj_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Hqi5g, 0, m);
}
static void cBinop_hduOb_sendMessage(HvBase *_c, int letIn, const HvMessage *const m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UCT4O, HV_BINOP_MULTIPLY, 0, m, &cBinop_UCT4O_sendMessage);
}
static void cVar_ntMXo_sendMessage(HvBase *_c, int letIn, const HvMessage *const m) {
  cMsg_nEzhO_sendMessage(_c, 0, m);
}
static void cCast_AUqyB_sendMessage(HvBase *_c, int letIn, const HvMessage *const m) {
}
static void cCast_ikYXX_sendMessage(HvBase *_c, int letIn, const HvMessage *const m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_DNLQl, 0, m, &cDelay_DNLQl_sendMessage);
}
static void cLoadbang_2Bs9y_sendMessage(HvBase *_c, int letIn, const HvMessage *const m) {
  cMsg_2sDGt_sendMessage(_c, 0, m);
}
static void cCast_JmBAT_sendMessage(HvBase *_c, int letIn, const HvMessage *const m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_6UqWb, 0, m, &cDelay_6UqWb_sendMessage);
}
static void cDelay_6UqWb_sendMessage(HvBase *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_6UqWb, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6UqWb, 0, m, &cDelay_6UqWb_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_LZKYO, 1, m, NULL);
}
static void cMsg_zkxmk_sendMessage(HvBase *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = NULL;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_WKE6m, 0, m, &hTable_WKE6m_sendMessage);
}
static void cBinop_byqqR_sendMessage(HvBase *_c, int letIn, const HvMessage *const m) {
  cMsg_zkxmk_sendMessage(_c, 0, m);
}
static void cBinop_7oAye_sendMessage(HvBase *_c, int letIn, const HvMessage *const m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 250.0f, 0, m, &cBinop_byqqR_sendMessage);
}
static void cMsg_2sDGt_sendMessage(HvBase *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = NULL;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vaBCG_sendMessage);
}
static void cSystem_vaBCG_sendMessage(HvBase *_c, int letIn, const HvMessage *const m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_7oAye_sendMessage);
}
static void hTable_WKE6m_sendMessage(HvBase *_c, int letIn, const HvMessage *const m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_6UqWb, 2, m, &cDelay_6UqWb_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JmBAT_sendMessage);
}



/*
 * Context Process Implementation
 */

int hv_ExamplePatch1_process(Hv_ExamplePatch1 *const _c, float **const inputBuffers, float **const outputBuffers, int nx) {
  const int n4 = nx & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars
  hv_bufferf_t Bf0, Bf1;
  // no temporary integer buffers

  // input and output vars
  hv_bufferf_t I0;
  hv_bufferf_t O0;

  // declare and init the zero buffer
  hv_bufferf_t ZERO; __hv_zero_f(VOf(ZERO));

  hv_uint32_t nextBlock = Base(_c)->blockStartTimestamp;
  for (int n = 0; n < n4; n += HV_N_SIMD) {

    // process all of the messages for this block
    nextBlock += HV_N_SIMD;
    while (mq_hasMessageBefore(&Base(_c)->mq, nextBlock)) {
      MessageNode *const node = mq_peek(&Base(_c)->mq);
      node->sendMessage(Base(_c), node->let, node->m);
      mq_pop(&Base(_c)->mq);
    }

    __hv_load_f(inputBuffers[0]+n, VOf(I0));

    __hv_zero_f(VOf(O0));

    // process all signal functions
    __hv_tabread_f(&_c->sTabread_Hqi5g, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0);
    __hv_fma_f(VIf(Bf0), VIf(Bf1), VIf(I0), VOf(Bf1));
    __hv_tabwrite_f(&_c->sTabwrite_LZKYO, VIf(Bf1));
    __hv_add_f(VIf(Bf0), VIf(O0), VOf(O0));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
  }

  Base(_c)->blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed
}

int hv_ExamplePatch1_process_inline(Hv_ExamplePatch1 *c, float *const inputBuffers, float *const outputBuffers, int n4) {
  int i = ctx_getNumInputChannels(Base(c));
  float **bIn = (float **) hv_alloca(i*sizeof(float *));
  while (i--) bIn[i] = inputBuffers+(i*n4);

  i = ctx_getNumOutputChannels(Base(c));
  float **bOut = (float **) hv_alloca(i*sizeof(float *));
  while (i--) bOut[i] = outputBuffers+(i*n4);

  int n = hv_ExamplePatch1_process(c, bIn, bOut, n4);
  return n;
}