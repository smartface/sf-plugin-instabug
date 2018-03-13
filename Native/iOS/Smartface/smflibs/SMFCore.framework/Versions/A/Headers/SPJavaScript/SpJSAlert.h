//
//  SpJSAlert.h
//  SpratIOS
//
//  Created by ugur kilic on 04/02/2014
//  Copyright (c) 2013 Smartface. All rights reserved.
//

#ifndef __SPJSALERT__
#define __SPJSALERT__

#include "Core/SpDefs.h"
#include "SpJsEngine/Core/SpJsEngine.h"

SpJsInit (spjsalert);
SpJsHasProperty (spjsalert);
SpJsGetProperty (spjsalert);
SpJsFinalize (spjsalert);

SpJsGetPropertyNames (spjsalert);


SpJsFunction (cb_alert_close);

extern const SpJsClassDefinition spjsalert_def;


#endif /* defined(__SPJSALERT__) */
