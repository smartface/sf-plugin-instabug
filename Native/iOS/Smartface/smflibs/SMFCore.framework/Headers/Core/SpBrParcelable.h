/*
 * SpBrParcelable.h
 *
 *  Created on: 28 Tem 2011
 *      Author: ugur
 */

#ifndef SPBRPARCELABLE_H_
#define SPBRPARCELABLE_H_

#include <vector>
#include <pthread.h>
#include "SpDefs.h"
#include "SpEventGroup.h"
#include "SpBrObject.h"
#include "SpRefCounted.h"
#include <pthread.h>
#include "SpJsEngine/Core/SpJsEngine.h"


class SpDataSource;
class SpBrString;
class SpBrBase;


class SpBrParcelable : public SpBrObject, public SpRefCounted {
protected:
	SpBrString *name;
    SpBrString *fullname;
    bool isContainer;
    bool isWebObject;
public:
	SpBrParcelable();
	SpBrParcelable(SpBrParcelable* objectToCopy);
	virtual ~SpBrParcelable();
    SpBrString* GetName();
    SpBrString* GetFullName();
    void SetName(SpBrString*);
    bool IsContainer();
    bool IsWebObject();
	/**
	 * keeps type of object. it is assinged when object is creating.
	 * you can see all types in SpBrNuiFactory.h
	 */
	int typeOfObject;
	/**
	 * smf id that represt order of this item in whole project.
	 */
	int smfId;
    
    virtual void Protect();
    virtual void Unprotect();
    
    // important note:
    // 1. static objects grabbed on parse
    // 2. dynamic objects grabbed in constructor
    // 3. dynamic clones grabbed after constructor in factory
    //void grab();
    void release();
    //updated to use SpRefCounted. It will automatically grab on object creation
public:
	virtual void Parse(SpDataSource **datasourcePtr, std::vector<SpBrParcelable*> *objects) {};
    virtual void CloneCompleted(){};
    virtual void Reset(bool invalidate = true) {};
    void ChangeObjectValue(const char* targetAttribute, const char* value);
    virtual void ChangeObjectValue(SpBrString* targetAttribute, SpBrString* value);
    virtual bool ChangeObjectValuev2(const char *attribute, SpJsValue valueRef);
    virtual SpBrString* getObjectValue(SpBrString* targetAttribute){ return NULL; };
    virtual void UpdateNativeValue(const char *attribute) {} ;

    /**
	 * this function called when some event fires ending point.
	 * dont fire again any SpEventGroup.fireEvent
	 *
	 * just process events comes from ui to core
	 *
	 * @param eventID Id of events. eventIDs listed under SpEventGroup.TEventID
     * @param eventCode code of processed events. this keeps additiona info about this event. such as which number pressed
     *
     * @author adem.cayir
	 */
    virtual void firedEventOnThis(int eventID,int eventCode) { }
    
    virtual void CreateJSObject(bool protect = true);
    SpJsObject GetJSObjectRef();
    void UnloadJSObjectRef();
    void SetJSObjectRef(SpJsObject objRef);

    SpEventGroup* GetEventGroup();
public:
    int mRefCount;
    bool isDynamicObject;
    pthread_mutex_t refMutex;
    void *externalData;
protected:
    SpEventGroup *eventGroup;
};


#endif /* SPBRPARCELABLE_H_ */
