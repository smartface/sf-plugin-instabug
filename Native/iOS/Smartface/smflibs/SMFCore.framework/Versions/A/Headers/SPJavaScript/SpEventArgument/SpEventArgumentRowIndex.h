#ifndef __SpratIOS__SpEventArgumentRowIndex__
#define __SpratIOS__SpEventArgumentRowIndex__

#include "SpEventArgument.h"
#include <vector>
#include <string>

class SpEventArgumentRowIndex : public SpEventArgument {
private:
	int rowIndex;
	int groupIndex;
	int groupRowIndex;
public:
	SpEventArgumentRowIndex(int rowIndex,int gindex,int growindex);
	~SpEventArgumentRowIndex();

	int GetPropertyType(const char* property);
	int GetIntProperty(const char* property);
    std::vector<std::string> GetPropertyNames(SpJsObject object);
};

#endif
