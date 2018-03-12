/*
 * SpEvent.h
 *
 *  Created on: Aug 9, 2011
 *      Author: ugurkilic
 */

#ifndef SPEVENT_H_
#define SPEVENT_H_

#include "SpBrParcelable.h"
#include "SpRefCounted.h"
#include "SpEventGroup.h"
#include <vector>
#include "SpJsEngine/Core/SpJsEngine.h"

class SpDataSource;
class SpBrString;
class SpBrBase;


class SpEvent: public SpBrParcelable  {
public:
	int debugTreeSize;
    bool killerEvent;
	SpBrParcelable* boundedObject;
    SpEventGroup *parentEventGroup;
    bool javaScriptFunctionCallBackSet;

private:
    SpBrString* javaScriptFunctionName;
    SpJsObject javaScriptFunctionCallBack;
    void* (*functionCallback)(void*);
    void* functionCallbackData;

    bool functionCallBackPointerSet;
    int eventCode;

public:
    SpEvent(SpBrBase *base);
    SpEvent(SpEventGroup *parent, SpBrBase *base, int eventCode, SpJsObject callbackFunction);
    SpEvent(SpBrBase *base, int eventCode, void* (*f)(void*),void* functionCallbackData );
    virtual ~SpEvent();

    void Parse(SpDataSource **datasourcePtr, std::vector<SpBrParcelable*> *objects);
    int GetEventCode() const { return eventCode; };

    /**
     *  Fire Event new implementation. Fires the given event.
     *
     *  @param aEventID       Event ID
     *  @param argumentString Event argument string (e). It should have escape sequences itself.
     *  @param sourceObject   this Object
     *  @param argDict        Other event argument values which are not included in argumentString (e.g Objects)
     */
    void FireNew2(char *argumentString = NULL, SpBrParcelable *sourceObject = NULL, PropertyDict *argDict = NULL, bool synchronous = false);

    const char* GetEventFunctionName();
    SpJsObject& GetCallback();
    void SetJavaScriptFunctionName(SpBrString* name);
    char* LoadArgs();
};

#endif /* SPEVENT_H_ */
