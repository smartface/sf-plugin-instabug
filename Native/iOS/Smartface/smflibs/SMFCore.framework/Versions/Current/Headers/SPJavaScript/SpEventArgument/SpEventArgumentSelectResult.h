#ifndef __SpratIOS__SpEventArgumentSelectResult__
#define __SpratIOS__SpEventArgumentSelectResult__
#include "SpEventArgument.h"
#include <string>
#include <vector>

class SpEventArgumentSelectResult : public SpEventArgument {
private:
	int index;
public:
	SpEventArgumentSelectResult(int index);
	~SpEventArgumentSelectResult();

	int GetPropertyType(const char* property);
	int GetIntProperty(const char* property);
    std::vector <std::string> GetPropertyNames(SpJsObject object);
};

#endif
