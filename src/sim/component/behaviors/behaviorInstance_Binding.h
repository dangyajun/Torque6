﻿//-----------------------------------------------------------------------------
// Copyright (c) 2013 GarageGames, LLC
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//-----------------------------------------------------------------------------

#include "c-interface/c-interface.h"

ConsoleMethodGroupBeginWithDocs(BehaviorInstance, SimObject)

/*! Get the template name of this behavior
    @return (string name) The name of the template this behavior was created from
*/
ConsoleMethodWithDocs(BehaviorInstance, getTemplateName, ConsoleString, 2, 2, ())
{
   const char* pName = object->getTemplateName();
   return pName ? pName : StringTable->EmptyString;
}

ConsoleMethodGroupEndWithDocs(BehaviorInstance)

extern "C"{
   DLL_PUBLIC BehaviorInstance* BehaviorInstanceCreateInstance()
   {
      return new BehaviorInstance();
   }

   DLL_PUBLIC BehaviorTemplate* BehaviorInstanceGetTemplate(BehaviorInstance* instance)
   {
      return instance->getTemplate();
   }

   DLL_PUBLIC void BehaviorInstanceSetTemplate(BehaviorInstance* instance, BehaviorTemplate* temp)
   {
      instance->setTemplate(temp);
   }

   DLL_PUBLIC BehaviorComponent* BehaviorInstanceGetOwner(BehaviorInstance* instance)
   {
      return instance->getBehaviorOwner();
   }

   DLL_PUBLIC void BehaviorInstanceSetOwner(BehaviorInstance* instance, BehaviorComponent* val)
   {
      instance->setBehaviorOwner(val);
   }

   DLL_PUBLIC const char* BehaviorInstanceGetTemplateName(BehaviorInstance* instance)
   {
      return CInterface::GetMarshallableString(instance->getTemplateName());
   }
}