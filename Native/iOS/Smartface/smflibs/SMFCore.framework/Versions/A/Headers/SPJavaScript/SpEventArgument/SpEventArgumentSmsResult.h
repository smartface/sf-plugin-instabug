#ifndef __SpratIOS__SpEventArgumentSmsResult__
#define __SpratIOS__SpEventArgumentSmsResult__

#include "SpEventArgument.h"

#include <vector>
#include <string>

class SpBrBase;

class SpEventArgumentSmsResult : public SpEventArgument {
private:
	SpBrBase* baseData;
public:
	SpEventArgumentSmsResult(SpBrBase* baseData);
	~SpEventArgumentSmsResult();

	int GetPropertyType(const char* property);
	char* GetCharPtrProperty(const char* property,bool &deleteAfterUse);
    std::vector<std::string> GetPropertyNames(SpJsObject object);
};

#endif
