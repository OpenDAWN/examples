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

#include "SignalTabwrite.h"

hv_size_t sTabwrite_init(SignalTabwrite *o, HvTable *table) {
  o->table = table;
  o->head = 0;
  return 0;
}

void sTabwrite_onMessage(HvBase *_c, SignalTabwrite *o, int letIn, const HvMessage *const m,
    void (*sendMessage)(HvBase *, int, const HvMessage *const)) {
  switch (letIn) {
    // inlet 0 is the signal inlet
    case 1: {
      switch (msg_getType(m,0)) {
        case BANG: o->head = 0; break;
        case FLOAT: {
          o->head = (msg_getFloat(m,0) >= 0.0f) ? (hv_uint32_t) msg_getFloat(m,0) : HV_TABWRITE_STOPPED;
          break;
        }
        case SYMBOL: {
          if (msg_compareSymbol(m, 0, "stop")) {
            o->head = HV_TABWRITE_STOPPED;
          }
          break;
        }
        default: break;
      }
      break;
    }
    case 2: {
      if (msg_isHashLike(m,0)) {
        o->table = ctx_getTableForHash(_c, msg_getHash(m,0));
      }
      break;
    }
    default: break;
  }
}
