//
//  SpJSConsole.h
//  SpratIOS
//
//  Created by Antti Panula on 11.8.2014 -- 5.
//  Copyright (c) 2014 Bivium. All rights reserved.
//

#ifndef SpratIOS_SpJSConsole_h
#define SpratIOS_SpJSConsole_h

#include "Core/SpDefs.h"
#include "SpJsEngine/Core/SpJsEngine.h"

SpJsInit (console);
SpJsHasProperty (console);
SpJsGetProperty (console);
SpJsSetProperty (console);
SpJsGetPropertyNames (console);
SpJsFinalize (console);
SpJsFunction (cb_console_error);
SpJsFunction (cb_console_log);
SpJsFunction (cb_console_warn);
SpJsFunction (cb_console_info);

extern const SpJsClassDefinition console_def;

#endif
