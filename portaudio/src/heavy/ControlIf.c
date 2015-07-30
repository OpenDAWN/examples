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

#include "ControlIf.h"

hv_size_t cIf_init(ControlIf *o, bool k) {
  o->k = k;
  return 0;
}

void cIf_onMessage(HvBase *_c, ControlIf *o, int letIn, const HvMessage *const m,
    void (*sendMessage)(HvBase *, int, const HvMessage *const)) {
  switch (letIn) {
    case 0: {
      // a "true" if will send the message from the right outlet
      // a "false" if gets sent out of the left outlet
      sendMessage(_c, o->k ? 1 : 0, m);
      break;
    }
    case 1: {
      if (msg_isFloat(m, 0)) {
        o->k = (msg_getFloat(m, 0) != 0.0f);
      }
      break;
    }
    default: return;
  }
}
