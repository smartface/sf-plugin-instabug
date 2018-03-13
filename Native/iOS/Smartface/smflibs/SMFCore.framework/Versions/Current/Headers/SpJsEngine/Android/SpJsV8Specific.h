#ifndef __SMF_JS_V8_SPECIFIC_HDR__
#define __SMF_JS_V8_SPECIFIC_HDR__

#include <v8.h>
#include <libplatform/libplatform.h>
#include <functional>
#include <mutex>
#include <memory>
#include <atomic>
using std::shared_ptr;

typedef void (*V8UnusedCallback) ();
typedef void* V8UnusedProperty;
typedef int V8UnusedIntProperty;

// TODO(ewanas) for now, these are to avoid compilation errors as
// there was never such a thing in V8.
// However, maybe later we should honor this upon creation of the
// corresponding ObjectTemplate
enum {
    kJSClassAttributeNone = 0,
    kJSClassAttributeNoAutomaticPrototype = 1
};

typedef v8::Local<v8::Object>   SpJsInternalObject;
typedef v8::Local<v8::Value>    SpJsInternalValue;

typedef v8::CopyablePersistentTraits<v8::Object>::CopyablePersistent CopyableV8Object;
typedef v8::CopyablePersistentTraits<v8::Value>::CopyablePersistent  CopyableV8Value;

class SmfV8Value;

/**
 *  Wrapper class for CopyableV8Object. It holds pointer of CopyableV8Object, by doing that
 *  it prevents copy constructor of CopyableV8Object to be called when SpJsObjects passed by value.
 *  Also provides conversion to SmfV8Value since CopyableV8Object can convertible to CopyableV8Value.
 */
class SmfV8Object {
    private:
        shared_ptr<CopyableV8Object> inner;
    public:
        /**
         *  Simply creates an empty CopyableV8Object
         */
        SmfV8Object();
        /**
         *  Uses given CopyableV8Object as inner object
         */
        SmfV8Object(shared_ptr<CopyableV8Object> inner);
        /**
         *  Copies inner CopyableV8Object after locking V8 engine
         */
        SmfV8Object(const SmfV8Object& right);
        /**
         *  Move constructor
         */
        SmfV8Object(SmfV8Object&& toMove);

        /**
         *  Type conversion to SmfV8Value
         */
        operator SmfV8Value();
        /**
         *  Calls CopyableV8Object's operator == for comparing
         */
        bool operator==(const SmfV8Object& right) const;
        /**
         *  Works like copy constructor
         */
        SmfV8Object& operator=(const SmfV8Object& right);
        /**
         *  Copies the inner pointer, doesn't copy CopyableV8Object
         */
        SmfV8Object& operator=(SmfV8Object&& right);

        /**
         *  Forwards method calls to CopyableV8Object
         */
        shared_ptr<CopyableV8Object> operator->() {
            return inner;
        }

        /**
         *  Returns inner CopyableV8Object
         */
        CopyableV8Object& GetInner() const {
            return *inner;
        }
};

/**
 *  Wrapper class for CopyableV8Value. It holds pointer of CopyableV8Value, by doing that
 *  it prevents copy constructor of CopyableV8Value to be called when SpJsValue passed by value.
 *  Also provides conversion to SmfV8Object since CopyableV8Value can convertible to CopyableV8Object.
 */
class SmfV8Value {
    private:
        shared_ptr<CopyableV8Value> inner;
    public:
        /**
         *  Simply creates an empty CopyableV8Value
         */
        SmfV8Value();
        /**
         *  Uses given CopyableV8Value as inner object
         */
        SmfV8Value(shared_ptr<CopyableV8Value> inner);
        /**
         *  Copies inner CopyableV8Value after locking V8 engine
         */
        SmfV8Value(const SmfV8Value& toCopy);
        /**
         *  Move constructor
         */
        SmfV8Value(SmfV8Value&& toMove);

        /**
         *  Type conversion to SmfV8Object
         */
        operator SmfV8Object();
        /**
         *  Type conversion to SmfV8Object reference
         */
        operator SmfV8Object&() const;
        /**
         *  Calls CopyableV8Value's operator== for comparing
         */
        bool operator==(const SmfV8Value& right) const;
        /**
         *  Works like copy constructor
         */
        SmfV8Value& operator=(const SmfV8Value& right);
        /**
         *  Copies the inner pointer, doesn't copy CopyableV8Value
         */
        SmfV8Value& operator=(SmfV8Value&& right);

        /**
         *  Forwards method calls to CopyableV8Value
         */
        shared_ptr<CopyableV8Value> operator->() {
            return inner;
        }

        /**
         *  Returns inner CopyableV8Value reference
         */
        CopyableV8Value& GetInner() const {
            return *inner;
        }
};

typedef v8::CopyablePersistentTraits<v8::ObjectTemplate>::CopyablePersistent    SpJsTemplateInstance;
typedef SmfV8Object                                                             SpJsObject;
typedef SmfV8Value                                                              SpJsValue;
typedef SpJsValue                                                               SpJsArgumentsList[];

extern SpJsObject smf_empty_object;
extern SpJsValue smf_empty_value;

#define SpJsNullValue smf_empty_value
#define SpJsNullObject smf_empty_object

typedef v8::GenericNamedPropertyGetterCallback      V8GetterCallback;
typedef v8::GenericNamedPropertySetterCallback      V8SetterCallback;
typedef v8::GenericNamedPropertyQueryCallback       V8HasPropertyCallback;
typedef v8::GenericNamedPropertyEnumeratorCallback  V8GetPropertyNamesCallback;
typedef v8::FunctionCallback                        V8ConstructCallback;
typedef v8::FunctionCallback                        V8FunctionCallback;
typedef V8ConstructCallback SpJsConstructCallback;
typedef V8FunctionCallback SpJsFunctionCallback;

typedef void (*V8FinalizeCallback) (SpJsObject);
typedef void (*V8InitCallback) (SpJsObject);

typedef struct {
    int                     version;
    V8UnusedIntProperty     attributes;
    const char*             className;
    SpJsTemplateInstance*   parentClass;
    V8UnusedProperty        staticValues;
    V8UnusedProperty        staticFunctions;
    V8InitCallback          initialize;
    V8FinalizeCallback      finalize;
    V8HasPropertyCallback   hasProperty;
    V8GetterCallback        getProperty;
    V8SetterCallback        setProperty;
    V8UnusedCallback        deleteProperty;
    V8GetPropertyNamesCallback getPropertyNames;
    V8FunctionCallback      callAsFunction;
    V8ConstructCallback     callAsConstructor;
    V8UnusedCallback        hasInstance;
    V8UnusedCallback        convertToType;
} SpJsClassDefinition;
typedef const SpJsClassDefinition*    SpJsTemplate;

std::string V8NameToStdString (v8::Local<v8::Name>);
void SpJsThrowException       (std::string);
void SpJsThrowException       (SpJsObject&);
void SpJsThrowException       (SpJsValue&);
bool SpJsArgumentsEmpty       (SpJsArgumentsList);
std::string SpJsToString      (v8::Local<v8::Value>);
bool SpJsIsArray              (SpJsObject o);
std::string SpJsGetConstructorName(SpJsValue o);
int SpJsGetArrayLength(SpJsValue value);

SpJsValue& SpJsNothingValue ();
SpJsObject& SpJsNothingObject ();

// typedef void(* NamedPropertyEnumeratorCallback) (const PropertyCallbackInfo< Array > &info)
#define SpJsGetPropertyNames(obj)   void obj##_get_property_names_cb(const v8::PropertyCallbackInfo<v8::Array>& __smf_info__)
#  define SpJsGetPropertyNamesObject ([__smf_info__] () { \
            SpJsObject o; \
            o->Reset (__smf_info__.GetIsolate (), __smf_info__.This()); \
            return o; \
        })()
#  define SpJsGetPropertyNamesPropertyNameAccumulator (__smf_info__.GetReturnValue())
#  define SpJsGetPropertyNamesInit() v8::Local<v8::Array> __smf_return_value__ = v8::Array::New (__smf_info__.GetIsolate ())
#  define SpJsGetPropertyNamesEnd() (__smf_info__.GetReturnValue().Set (__smf_return_value__))
#  define SpJsGetPropertiesAdd(propertyNames, name) \
    (__smf_return_value__->Set (__smf_return_value__->Length(), \
    v8::String::NewFromUtf8 (__smf_info__.GetIsolate (), name)))

// typedef void(* NamedPropertyQueryCallback) (Local< String > property, const PropertyCallbackInfo< Integer > &info)
#define SpJsHasProperty(obj)        void obj##_has_property_cb (v8::Local<v8::Name> __smf_property__, const v8::PropertyCallbackInfo<v8::Integer>&__smf_info__) 
#  define SpJsHasPropertyObject ([__smf_info__] () { \
            SpJsObject o; \
            o->Reset (__smf_info__.GetIsolate (), __smf_info__.This ()); \
            return o; \
        })()
#  define SpJsHasPropertyPropertyName (SpJsToString (__smf_property__))
#  define SpJsHasPropertyReturn(x) if (x) { (__smf_info__.GetReturnValue ().Set (v8::Integer::New (__smf_info__.GetIsolate (), v8::None))); }; return;

// typedef void(* NamedPropertyGetterCallback) (v8::Local< v8::String > property, const v8::PropertyCallbackInfo< v8::Value > &info)
#define SpJsGetProperty(obj)        void obj##_get_property_cb(v8::Local<v8::Name> __propertyName__, const v8::PropertyCallbackInfo<v8::Value>& __smf_info__)
#  define SpJsGetPropertyObject ([__smf_info__] () { \
            SpJsObject o; \
            o->Reset (__smf_info__.GetIsolate (), __smf_info__.This()); \
            return o; \
        })()
#  define SpJsGetPropertyPropertyName V8NameToStdString (__propertyName__)
#  define SpJsGetPropertyException exception
#  define SpJsGetPropertyReturn(x) \
    if (SpJsIsEmpty (x)) { \
        return; \
    } else { \
        __smf_info__.GetReturnValue().Set(x->Get (__smf_info__.GetIsolate ())); \
        return; \
    }

// typedef void(* GenericNamedPropertySetterCallback) (v8::Local< v8::Name > property, v8::Local< v8::Value > value, const v8::PropertyCallbackInfo< v8::Value > &info)
#define SpJsSetProperty(obj)        void obj##_set_property_cb(v8::Local<v8::Name> __propertyName__, v8::Local<v8::Value> __value__, const v8::PropertyCallbackInfo<v8::Value>& __smf_info__)
#  define SpJsSetPropertyPropertyName (V8NameToStdString(__propertyName__))
#  define SpJsSetPropertyObject ([__smf_info__] () { \
            SpJsObject o; \
            o->Reset (__smf_info__.GetIsolate (), __smf_info__.This()); \
            return o; \
        })()
#  define SpJsSetPropertyValue ([__smf_info__, __value__] () { \
            SpJsValue v; \
            v->Reset (__smf_info__.GetIsolate (), __value__); \
            return v; \
        })()
// TODO(ewanas) deprecate this. setters and getters shouldn't be allowed to throw exceptions.
// We can "throw" an exception directly in both engines anyway
#  define SpJsSetPropertyException
// TODO(ewanas) figure out what to do with this
#  define SpJsSetPropertyReturn(x) \
    if (x) { \
        __smf_info__.GetReturnValue ().Set (__value__); \
        return; \
    } else { \
        auto obj = __smf_info__.This (); \
 \
        if (__propertyName__->IsSymbol()) { \
            /* nothing */ \
        } else if (obj->Has (__propertyName__) || \
                obj->HasRealNamedCallbackProperty (__propertyName__->ToString (__smf_info__.GetIsolate ())) || \
                obj->HasRealNamedProperty (__propertyName__->ToString (__smf_info__.GetIsolate ()))) { \
            __smf_info__.GetReturnValue ().Set (v8::Undefined (__smf_info__.GetIsolate ())); \
        } \
        return; \
    }

#define SpJsInit(obj)               void obj##_init_cb(SpJsObject object)
#  define SpJsInitObject object

#define SpJsFinalize(obj)           void obj##_finalize_cb(SpJsObject object)
#  define SpJsFinalizeObject object

// typedef void(* FunctionCallback) (const FunctionCallbackInfo< Value > &info)
#define SpJsConstructor(obj)        void obj##_construct_cb(const v8::FunctionCallbackInfo<v8::Value>& __smf_info__)
#  define SpJsConstructorConstructor ([__smf_info__] () { \
            SpJsObject v; \
            v->Reset (__smf_info__.GetIsolate (), __smf_info__.This ()); \
            return v; \
        })()
#  define SpJsConstructorArgumentCount (__smf_info__.Length ())
#  define SpJsConstructorArguments \
    (([__smf_info__] () { \
         int argc = __smf_info__.Length (); \
         std::vector<SpJsValue> argv (argc); \
         for (int i = 0; i < argc; i++) { \
            argv [i]->Reset (__smf_info__.GetIsolate (), __smf_info__[i]); \
         } \
         return argv; \
     })().data())

// TODO(ewanas) deprecate this
#  define SpJsConstructorException
#  define SpJsConstructorReturn(x) __smf_info__.GetReturnValue().Set(x->Get (__smf_info__.GetIsolate ())); return

// typedef void(* FunctionCallback) (const FunctionCallbackInfo< Value >& __smf_info__)
#define SpJsFunction(cb) void cb (const v8::FunctionCallbackInfo<v8::Value>& __smf_info__)
#  define SpJsFunctionFunction ([__smf_info__] () { \
            SpJsObject v; \
            v->Reset (__smf_info__.GetIsolate (), __smf_info__.Callee ()); \
            return v; \
        })()
#  define SpJsFunctionThisObject ([__smf_info__] () { \
            SpJsObject o; \
            o->Reset (__smf_info__.GetIsolate (), __smf_info__.This()); \
            return o; \
        })()
#  define SpJsFunctionArgumentCount (__smf_info__.Length ())
#  define SpJsFunctionArguments \
    (([__smf_info__] () { \
         int argc = __smf_info__.Length (); \
         std::vector<SpJsValue> argv (argc); \
         for (int i = 0; i < argc; i++) { \
            argv [i]->Reset (__smf_info__.GetIsolate (), __smf_info__[i]); \
         } \
         return argv; \
     })().data())
// TODO(ewanas) deprecate
#  define SpJsFunctionException
#  define SpJsFunctionReturn(x) { __smf_info__.GetReturnValue().Set(x->Get (__smf_info__.GetIsolate ())); return; }

#define SpJsGetPropsCb(obj)     obj##_get_property_names_cb
#define SpJsHasPropsCb(obj)     obj##_has_property_cb
#define SpJsGetPropCb(obj)      obj##_get_property_cb
#define SpJsSetPropCb(obj)      obj##_set_property_cb
#define SpJsInitCb(obj)         obj##_init_cb
#define SpJsFinalizeCb(obj)     obj##_finalize_cb
#define SpJsConstructCb(obj)    obj##_construct_cb

void setDebugging (bool state, std::function<void(std::string)> msgHandler = [](std::string m){});
void sendDebugMessage (std::string msg);
void resetDebugger ();
void breakDebugger ();

extern std::atomic<bool> isDebugging;

#endif
