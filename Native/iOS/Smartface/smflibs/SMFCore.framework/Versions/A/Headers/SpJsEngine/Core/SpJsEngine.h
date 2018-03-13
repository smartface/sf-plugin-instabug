#ifndef __SMF_JS_ENGINE__
#define __SMF_JS_ENGINE__

#include <functional>
#include <vector>
#include <map>
#include <string>

#ifndef SMF_V8_PLAYER
#include "SpJsEngine/iOS/SpJsJSCSpecific.h"
#else
#include "SpJsEngine/Android/SpJsV8Specific.h"
#endif

#ifdef TARGET_PLATFORM_ANDROID
#include <android/log.h>
#define smf_assert(cond,msg...) {if(!(cond)) {__android_log_assert(0,"SMF",msg);}}
#else
    #ifdef SPRAT_LOGGING
        #define smf_assert(cond,msg...) {if(!(cond)) {printf((msg), ##__VA_ARGS__); printf("\n");}}
    #else
        #define smf_assert(cond,msg...)
    #endif
#endif

typedef std::vector<std::string>    PropertyList;

typedef struct {
    /**
     * This is used to store which template was
     * used to create the object.
     */
    SpJsTemplate type;

    /**
     * This is used to store any internal data we care to keep track
     * of for some object.
     */
    void* data;
} SpJsObjectInfo;

extern SpJsObjectInfo   nullObject;

#ifdef SPRAT_LOGGING
#   ifdef TARGET_PLATFORM_ANDROID
#       include <android/log.h>
#       define jsclog(msg...) __android_log_print (ANDROID_LOG_INFO, "SMF", msg)
#   else
#       include <asl.h>
#       define jsclog(msg...) asl_log(NULL, NULL, ASL_LEVEL_INFO, msg)
#   endif
#else
    #ifdef SPRAT_LOGGING
        #define jsclog(msg,...) { printf((msg), ##__VA_ARGS__); printf("\n"); }
    #else
        #define jsclog(msg,...)
    #endif
#endif

#define SpJsGlobalObject (SpJsGetGlobalObject ())

typedef std::map<const char*, SpJsValue> PropertyDict;

SpJsTemplateInstance SpJsGetClass            (const SpJsTemplate, bool isPlugin = false);
SpJsObject  SpJsNewInstance         (SpJsTemplate, void* data=NULL, bool isPlugin = false);
void        SpJsSetGlobal           (const char*, SpJsValue);
void        SpJsSet                 (SpJsObject, const char*, SpJsValue);
void        SpJsSetAtIndex          (SpJsObject , unsigned index, SpJsValue value);
SpJsValue   SpJsGetGlobal           (const char*);
SpJsValue   SpJsGet                 (SpJsObject, const char*);
SpJsValue   SpJsGetAtIndex          (SpJsObject, unsigned);
SpJsValue   SpJSSetAtIndex          (SpJsObject, unsigned);
SpJsObject  SpJsNewConstructor      (const SpJsTemplate, SpJsConstructCallback);
SpJsObject  SpJsNewFunction         (SpJsFunctionCallback);
#ifdef TARGET_PLATFORM_IOS
//TODO(Android should implement this)
SpJsObject  SpJsNewFunctionWithName (std::string, SpJsFunctionCallback);
#endif
char*       SpJsGetTypeName         (SpJsValue);
void        SpJsClearClasses        ();
void        SpJsClearFunctions      ();
void        SpJsSetTemplateInstance (const SpJsTemplate, SpJsTemplateInstance);
SpJsValue   SpJsNewBoolean          (bool c);
bool        SpJsObjectInstanceOf    (SpJsValue, SpJsTemplate);
void        SpJsProtect             (SpJsValue);
void        SpJsUnprotect           (SpJsValue);
SpJsObject  SpJsEmptyObject         (void* data=NULL);
SpJsValue   SpJsEvaluate            (const char*, SpJsObject scope=SpJsEmptyObject(), const char* sourceId=NULL, int sourceLine=0, SpJsValue* exception=NULL);
SpJsObject  SpJsAsObject            (SpJsValue);
PropertyList SpJsProperties         (SpJsObject);
bool        SpJsHas                 (SpJsObject, const char* property);
std::string SpJsToString            (SpJsValue);
SpJsValue   SpJsCallFunction        (SpJsObject*, SpJsObject*, std::vector<SpJsValue> args=std::vector<SpJsValue> {}, SpJsValue* e=NULL);
SpJsValue   SpJsCallGlobalFunction  (SpJsObject, std::vector<SpJsValue> args=std::vector<SpJsValue> {}, SpJsValue* e=NULL);
SpJsObject  SpJsCallConstructor     (SpJsObject, std::vector<SpJsValue> args=std::vector<SpJsValue> {}, SpJsValue* e=NULL);
SpJsObjectInfo* SpJsGetInfo         (SpJsObject o);
bool        SpJsIsNumber            (SpJsValue v);
bool        SpJsIsUndefined         (SpJsValue v);
bool        SpJsIsBoolean           (SpJsValue v);
bool        SpJsIsNull              (SpJsValue v);
bool        SpJsIsObject            (SpJsValue v);
bool        SpJsIsString            (SpJsValue v);
bool        SpJsIsFunction          (SpJsObject o);
bool        SpJsIsConstructor       (SpJsObject o);
bool        SpJsIsConstructedFrom   (SpJsValue v, SpJsObject c);
double      SpJsDoubleValue         (SpJsValue v);
bool        SpJsBooleanValue        (SpJsValue v);
void*       SpJsGetPrivate          (SpJsObject o);
void        SpJsSetPrivate          (SpJsObject o, void* data);
SpJsValue   SpJsNull                ();
SpJsValue   SpJsUndefined           ();
SpJsObject  SpJsException           (const char* error);
SpJsObject  SpJsNewArray            (int count, SpJsValue* array);
SpJsValue   SpJsNewStringValue      (const char* str);
SpJsValue   SpJsNewNumber           (int);
SpJsValue   SpJsNewNumber           (long int);
SpJsValue   SpJsNewNumber           (long long int);
SpJsValue   SpJsNewNumber           (unsigned int);
SpJsValue   SpJsNewNumber           (unsigned long int);
SpJsValue   SpJsNewNumber           (unsigned long long int);
SpJsValue   SpJsNewNumber           (double);
SpJsObject  SpJsGetGlobalObject     ();
SpJsObject  SpJsNewObjectFromJSON   (char*);
bool        SpJsEngineReady         ();
SpJsValue   SpJsAsValue             (SpJsObject);
void*       SpJsInternalAddress     (SpJsObject&);
void*       SpJsInternalAddress     (SpJsValue&);
void        SpJsEngineReset         ();

// TODO(ewanas) plz check plugins init class before removing this it'll break the plugins
bool        SpJsIsEmpty             (const SpJsObject&);
bool        SpJsIsEmpty             (const SpJsValue&);

// Some utility function as we do this a lot
std::vector<SpJsValue> SpJsList     (const SpJsValue*, size_t);

extern bool SpJsBindingsDone;

#define fatal(m...)

#define fail_log(x)

// TODO(ewanas) figure out why std::to_string isn't visible. For now, we make our own.
namespace std {
    std::string to_string (int);
}

typedef std::function<void(std::string)> DebugMessageHandler;
const DebugMessageHandler emptyHandler = [](std::string m){};

void startDebugger (DebugMessageHandler handler = emptyHandler);
void stopDebugger (bool killApplication = true);
void sendDebugMessage (std::string msg);

#endif
