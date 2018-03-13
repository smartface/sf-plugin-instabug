//
//  SpEventArgumentZoomLevel.h
//  SpratIOS
//
//  Created by mehmet akyol on 7/17/13.
//  Copyright (c) 2013 Bivium. All rights reserved.
//

#ifndef SpratIOS_SpEventArgumentZoomLevel_h
#define SpratIOS_SpEventArgumentZoomLevel_h

#include <vector>
#include <string>

#include "SpEventArgument.h"

class SpEventArgumentZoomLevel : public SpEventArgument {
private:
	float zoomLevel;

public:
	SpEventArgumentZoomLevel(float zoom);
	~SpEventArgumentZoomLevel();

	int GetPropertyType(const char* property);
	int GetIntProperty(const char* property);
    float GetFloatProperty(const char* property);
    std::vector<std::string> GetPropertyNames(SpJsObject object);
};

#endif
