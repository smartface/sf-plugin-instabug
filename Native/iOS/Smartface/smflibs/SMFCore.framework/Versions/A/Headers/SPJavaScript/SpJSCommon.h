//
//  SpJSCommon.h
//  SpratIOS
//
//  Created by Antti Panula on 30.10.2012 -- 5.
//  Copyright (c) 2012 Bivium. All rights reserved.
//

#ifndef SpratIOS_SpJSCommon_h
#define SpratIOS_SpJSCommon_h

#include "Core/SpBrString.h"

#include "SpJsEngine/Core/SpJsEngine.h"

extern const SpJsClassDefinition smfsmfclass_def;

SpBrString* getJSArrayString(SpJsObject arrObject, const char* propertyName, const char* defaultValue);
int getJSArrayInt(SpJsObject arrObject, const char* propertyName, int defaultValue);
SpJsObject getJSArrayObject(SpJsObject arrObject, const char* propertyName);
bool hasJSArrayValueAsString(SpJsObject arrObject, const char* propertyName);
bool hasJSArrayValueAsObject(SpJsObject arrObject, const char* propertyName);
bool hasJSArrayProperty(SpJsObject arrObject, const char* propertyName);

#endif
