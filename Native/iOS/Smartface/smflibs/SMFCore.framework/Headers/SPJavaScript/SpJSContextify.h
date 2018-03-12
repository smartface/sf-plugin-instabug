//
//  SpJSContextify.h
//
//  Created by M.Halit Karakis on 8/3/16.
//  Copyright © 2016 Smartface. All rights reserved.
//

#ifndef SpJSContextify_h
#define SpJSContextify_h

#include "Core/SpDefs.h"
#include "SpJsEngine/Core/SpJsEngine.h"

SpJsInit (smfcontextify);
SpJsHasProperty (smfcontextify);
SpJsGetProperty (smfcontextify);
SpJsSetProperty (smfcontextify);
SpJsGetPropertyNames (smfcontextify);
SpJsConstructor (smfcontextify);
SpJsFinalize (smfcontextify);

extern const SpJsClassDefinition smfcontextify_def;

class SpContextify {
public:
    string code;
    string filename;
    int lineOffset;
    bool displayErrors;
};

SpJsFunction(cb_contextify_runInThisContext);

#endif /* SpJSContextify_h */
