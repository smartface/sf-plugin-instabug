#ifndef __SpratIOS__SpEventArgumentLocationResult__
#define __SpratIOS__SpEventArgumentLocationResult__

#include "SpEventArgument.h"
#include <vector>
#include <string>

class SpBrBase;

class SpEventArgumentLocationResult : public SpEventArgument {
private:
	SpBrBase* baseData;
public:
	SpEventArgumentLocationResult(SpBrBase* baseData);
	~SpEventArgumentLocationResult();

	int GetPropertyType(const char* property);
	int GetIntProperty(const char* property);
	float GetFloatProperty(const char* property);
    std::vector<std::string> GetPropertyNames(SpJsObject object);
};

#endif
