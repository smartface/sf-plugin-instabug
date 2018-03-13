#ifndef __SHAREABLE_JS_OBJECT_HDR__
#define __SHAREABLE_JS_OBJECT_HDR__

#include "SpJsEngine/Core/SpJsEngine.h"

struct SharedJSObject {
    public:
        SharedJSObject (SpJsObject);
        SpJsObject internalObject;
};

struct SharedJSValue {
    public:
        SharedJSValue (SpJsValue);
        SpJsValue internalValue;
};

#endif
