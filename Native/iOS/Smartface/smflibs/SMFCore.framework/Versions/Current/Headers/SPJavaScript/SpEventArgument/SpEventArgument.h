#include <string.h>
#ifndef __SpratIOS__SpEventArgument__
#define __SpratIOS__SpEventArgument__

#include <vector>
#include <string>
#include "SpJsEngine/Core/SpJsEngine.h"

typedef enum {
    TEAPTNone=-1,
    TEAPTInt,
    TEAPTFloat,
    TEAPTCharPtr,
    TEAPTBool,
    TEAPTObject,
    TEAPTResultArray
} TEventArgumentPropertType;


class SpEventArgument {
public:
	SpEventArgument() { }
	virtual ~SpEventArgument() { }

	virtual int GetPropertyType(const char* property){ return -1; }

	virtual int GetIntProperty(const char* property){ return 0; }
	virtual float GetFloatProperty(const char* property){ return 0; }
	virtual char* GetCharPtrProperty(const char* property,bool &deleteAfterUse){ return 0; }
	virtual bool GetBoolProperty(const char* property){ return false; }
	virtual SpJsObject GetObjectProperty(const char* property){ return SpJsNullObject; }

	virtual int GetResultCount(const char* property){ return 0; }
	virtual SpJsValue GetResult(int index){ return SpJsNullValue; }
	virtual std::vector<std::string> GetPropertyNames(SpJsObject object) { return std::vector <std::string> {}; }

};

#endif
