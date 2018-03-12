/*
 * SpJSCallbackGroup.h
 *
 *  Created on: Mar 6, 2014
 *      Author: adem
 */

#ifndef SPJSCALLBACKGROUP_H_
#define SPJSCALLBACKGROUP_H_

#include <vector>
#include <map>
#include "SpDefs.h"
#include "SpBrObject.h"
#include "SpBrBase.h"
#include "SpJsEngine/Core/SpJsEngine.h"

class SpBrBase;
class SpBrParcelable;

class SpJSCallbackGroup
{
private:
	int count;
	SpBrObject* sourceObject;
	SpBrBase* baseData;
	std::map<int,SpJsObject> callbacks;
	std::map<int,bool> callbacksIsKiller;
public:
	SpJSCallbackGroup(SpBrBase* baseData,SpBrObject* sourceObject=NULL);
	virtual ~SpJSCallbackGroup();
	int AddCallback(SpJsObject callback,bool isKiller);
	void Fire(int id,const char* json,bool forceToKill=false);
    void FireWithJSObject(int id,SpJsObject obj,bool forceToKill=false);
    void SetSourceObject(SpBrObject *object);

private:
    void CallFunctionSafe(SpJsObject func, SpJsObject thisRef, size_t argumentCount, SpJsArgumentsList arguments, bool killAfterUse);
};

#endif
