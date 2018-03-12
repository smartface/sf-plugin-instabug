#ifndef __SMF_JS_JSC_SPECIFIC_HDR__
#define __SMF_JS_JSC_SPECIFIC_HDR__

#import <JavaScriptCore/JavaScriptCore.h>

extern JSGlobalContextRef _JSContext;

typedef JSObjectRef                 SpJsObject;
typedef JSStringRef                 SpJsString;
typedef JSValueRef                  SpJsValue;
typedef JSClassRef                  SpJsTemplateInstance;
typedef JSClassDefinition const*    SpJsTemplate;
typedef JSObjectRef                 (*SpJsConstructCallback) (JSContextRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
typedef JSValueRef                  (*SpJsFunctionCallback) (JSContextRef, JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
typedef SpJsValue                   (*SpJsInternalFunctionCallback) (JSObjectRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
typedef JSObjectRef                 (*SpJsInternalConstructCallback) (JSContextRef, JSObjectRef, size_t, const JSValueRef[], JSValueRef*);
typedef JSClassDefinition           SpJsClassDefinition;
typedef const SpJsValue             SpJsArgumentsList[];

#define SpJsGetPropertiesAdd(propertyNames, name) \
{ \
  JSStringRef str; \
  str = JSStringCreateWithUTF8CString(name); \
  JSPropertyNameAccumulatorAddName(propertyNames, str); \
  JSStringRelease(str); \
}

std::string JSStringRefToStdString (JSStringRef str);
bool SpJsArgumentsEmpty (SpJsArgumentsList);

static SpJsValue SpJsNullValue = NULL;
static SpJsObject SpJsNullObject = NULL;
#define SpJsNullClass NULL

#define SpJsGetPropertyNames(obj)   void obj##_get_property_names_cb(JSContextRef ctx, JSObjectRef object, JSPropertyNameAccumulatorRef propertyNames)
#  define SpJsGetPropertyNamesObject object
#  define SpJsGetPropertyNamesPropertyNameAccumulator propertyNames
#  define SpJsGetPropertyNamesInit()
#  define SpJsGetPropertyNamesEnd()

#define SpJsHasProperty(obj)        bool obj##_has_property_cb(JSContextRef ctx, JSObjectRef object, JSStringRef propertyName)
#  define SpJsHasPropertyObject object
#  define SpJsHasPropertyPropertyName JSStringRefToStdString (propertyName)
#  define SpJsHasPropertyReturn(x) return x

#define SpJsGetProperty(obj)        JSValueRef obj##_get_property_cb(JSContextRef ctx, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
#  define SpJsGetPropertyObject object
#  define SpJsGetPropertyPropertyName JSStringRefToStdString (propertyName)
#  define SpJsGetPropertyException exception
#  define SpJsGetPropertyReturn(x) return x

#define SpJsSetProperty(obj)        bool obj##_set_property_cb(JSContextRef ctx, JSObjectRef object, JSStringRef propertyName, JSValueRef value, JSValueRef* exception)
#  define SpJsSetPropertyPropertyName JSStringRefToStdString(propertyName)
#  define SpJsSetPropertyObject object
#  define SpJsSetPropertyValue value
#  define SpJsSetPropertyException exception
#  define SpJsSetPropertyReturn(x) return x

#define SpJsInit(obj)               void obj##_init_cb(JSContextRef ctx, JSObjectRef object)
#  define SpJsInitObject object

#define SpJsFinalize(obj)           void obj##_finalize_cb(JSObjectRef object)
#  define SpJsFinalizeObject object

#define SpJsConstructor(obj)        JSObjectRef obj##_construct_cb(JSContextRef ctx, JSObjectRef constructor, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
#  define SpJsConstructorConstructor constructor
#  define SpJsConstructorArgumentCount argumentCount
#  define SpJsConstructorArguments arguments
#  define SpJsConstructorException exception
#  define SpJsConstructorReturn(x) return x

#define SpJsFunction(cb) JSValueRef cb (JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
#  define SpJsFunctionFunction function
#  define SpJsFunctionThisObject thisObject
#  define SpJsFunctionArgumentCount argumentCount
#  define SpJsFunctionArguments arguments
#  define SpJsFunctionException exception
#  define SpJsFunctionReturn(x) return x

#define SpJsGetPropsCb(obj)     obj##_get_property_names_cb
#define SpJsHasPropsCb(obj)     obj##_has_property_cb
#define SpJsGetPropCb(obj)      obj##_get_property_cb
#define SpJsSetPropCb(obj)      obj##_set_property_cb
#define SpJsInitCb(obj)         obj##_init_cb
#define SpJsFinalizeCb(obj)     obj##_finalize_cb
#define SpJsConstructCb(obj)    obj##_construct_cb

#define SpJsThrowException(msg) { \
  *exception = SpJsException (msg); \
}

#endif
