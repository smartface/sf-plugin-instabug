#include <vector>
#include <string>

#include "SpEventArgument.h"

class SpEventArgumentScrollViewOnPageChangedEvent : public SpEventArgument {
private:
	int pageIndex;
	int direction;
public:
	SpEventArgumentScrollViewOnPageChangedEvent(int pageIndex, int direction);
	~SpEventArgumentScrollViewOnPageChangedEvent();

	int GetPropertyType(const char* property);
	int GetIntProperty(const char* property);
    std::vector<std::string> GetPropertyNames(SpJsObject object);
};
