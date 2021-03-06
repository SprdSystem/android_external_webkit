
/*
 * Copyright (C) 2011 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#if !ENABLE(SAMSUNG_WEBKIT_PERFORMANCE_PATCH)
// SAMSUNG CHANGE : Webkit Performance Patch Merge + r95157
// This is to avoid compilation error incase SAMSUNG_WEBKIT_PERFORMANCE_PATCH is disabled, as in that case 
// ExceptionCodes.h will not be included in V8ArrayBufferViewCustom.h which will give error
#include "ExceptionCode.h"
// SAMSUNG CHANGE : Webkit Performance Patch Merge -
#endif
#include "V8ArrayBufferViewCustom.h"

#include <v8.h>

namespace WebCore {

void copyElements(v8::Handle<v8::Object> destArray, v8::Handle<v8::Object> srcArray)
{
    v8::Handle<v8::String> key = v8::String::New("set");
    v8::Handle<v8::Function> set = destArray->Get(key).As<v8::Function>();
    v8::Handle<v8::Value> argument = srcArray;
    set->Call(destArray, 1, &argument);
}

}
