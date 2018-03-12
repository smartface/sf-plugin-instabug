//
//  SpJSApplication.h
//  SpratIOS
//
//  Created by Antti Panula on 11/6/12.
//  Copyright (c) 2012 Bivium. All rights reserved.
//

#ifndef SpratIOS_SpJSApplication_h
#define SpratIOS_SpJSApplication_h

#include "Core/SpDefs.h"
#include "SpJsEngine/Core/SpJsEngine.h"

SpJsInit (smfapplication);

SpJsHasProperty (smfapplication);

SpJsGetProperty (smfapplication);

SpJsSetProperty (smfapplication);

SpJsGetPropertyNames (smfapplication);

extern const SpJsClassDefinition smfapplication_def;


#endif
