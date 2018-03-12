/*
 * SpEventGroup.h
 *
 *  Created on: Aug 9, 2011
 *      Author: ugurkilic
 */

#ifndef SPEVENTGROUP_H_
#define SPEVENTGROUP_H_

#include <vector>
#include <map>
#include "SpBrBase.h"
#include "SpDefs.h"
#include "SpRefCounted.h"
#include "SpJsEngine/Core/SpJsEngine.h"

using namespace std;

class SpDataSource;
class SpBrParcelable;
class SpBrString;
class SpBrBase;
class SpEvent;

enum TEventID
{
    EEIDOnPress = 0,
    EEIDOnItemSelected,
    EEIDOn2nd,
    EEIDOnSuccess,
    EEIDOnFailure,
    EEIDOnDownloadFinished,
    EEIDOnPlayFinished,
    EEIDOn7th,
    EEIDOnError,
    EEIDOnTimerTick,
    EEIDOnShow = 10,
    EEIDOnHide,
    EEIDOnActivated,
    EEIDOnDeactivated,
    EEIDOnChange,
    EEIDOnSelect,
    EEIDOnDropDown,
    EEIDOnClose,
    EEIDOnStart,
    EEIDOnSuccess2 = 20,
    EEIDOnServerError,
    EEIDOnServerConnected,
    EEIDOnParameterSent,
    EEIDOn24th,
    EEIDOnSyndicationSuccess,
    EEIDOnUpdateReady,
    EEIDOnNoUpdate,
    EEIDOn28th,
    EEIDOn29th,
    EEIDOnKeyPressed = 30,
    EEIDOnOpenCompleted,
    EEIDOnInitCompleted,
    EEIDOnError2,
    EEIDOnParameterReceived,
    EEIDOnHttpReturn,
    EEIDOnPlayStarted,
    EEIDOnMaxValueOverFlow,
    EEIDOnCheckUpdateError,
    EEIDOnCameraStartSuccess = 40,
    EEIDOnCameraStartFailure,
    EEIDOnCameraCaptureSuccess,
    EEIDOnCameraCaptureFailure,
    EEIDOnEditEnter,
    EEIDOnEditChange, // this is obsolete!
    EEIDOnSimCardChanged,
    EEIDOnControlTrue,
    EEIDOnControlFalse,
    EEIDOnControlLoop,
    EEIDOnOtpWeakPinError = 50,
    EEIDOnOtpGenericError,
    EEIDOnOtpInvalidPinError,
    EEIDOnOtpActivationRequired,
    EEIDOnOtpReactivationRequired,
    EEIDOnOtpInvalidActivationCode,
    EEIDOnEditValidationFailed,
    EEIDOnOnTouchBegin,
    EEIDOnLoad,
    EEIDOnLongTouch,
    EEIDOnDynamicDoubleTap = 60,
    EEIDOnDragInside,
    EEIDOnDragOutside,
    EEIDOnDragEnter,
    EEIDOnDragExit,
    EEIDOnLinkClicked,
    EEIDOnCapture,
    EEIDOnCancel,
    EEIDOnFirstPress,
    EEIDOnSecondPress,
    EEIDOnThirdPress = 70,
    EEIDOnShake,
    EEIDOnOrientationChanged,
    EEIDOnAccelerate,
    EEIDOnLocationChanged,
    EEIDOnExit,
    EEIDOnReturnKey,
    EEIDOnAppMaximized,
    EEIDOnAppMinimized,
    EEIDOnRowRendered,
    EEIDOnPickerSelected = 80,
    EEIDOnScrollViewPageChanged,
    EEIDOnConnectionTypeChanged,
    EEIDOnAnimateFinished,
    EEIDOnPullDown,
    EEIDOnPullUp,
    EEIDOnSmsReceived,
    EEIDOnGlobalError,
    EEIDOnSwipe,
    EEIDOnPinSelected,
    EEIDOnOnTouchEnd = 90,
    EEIDOnPurchased,    // deprecated
    EEIDOnRestored,     // deprecated
    EEIDOnReceivedNotification,
    EEIDOnPinch,
    EEIDOnDeleted,  // for row deletion from repeatbox
    EEIDOnRowDeleting,
    EEIDOnURLChanged = 96,
    // Skip IDE Garbage
    EEIDOnApplicationCallReceived = 110,
    // Skip IDE Garbage
    EEIDOnPinDragStart = 124,
    EEIDOnPinDragEnd,
    EEIDOnMapRegionChanged,
    EEIDOnTouchMove,
    EEIDOnDraw = 128,
    EEIDOnNetworkProgress = 129,
    EEIDOnDatasetBeforeCommit = 130,
    EEIDOnDatasetBeforeRowDelete,
    EEIDOnDatasetBeforeSelected,
    EEIDGarbage,
    EEIDOnDatasetNewRow,
    EEIDOnDatasetRowCommit,
    EEIDOnDatasetRowIndexChanged,
    EEIDOnDatasetCommit,
    EEIDOnEditKeyDown,
    EEIDOnScroll = 140,
    EEIDOnSearchStart,
    EEIDOnSearchSubmit,
    EEIDOnTextChange,
    EEIDOnAdLoaded,
    EEIDOnAdFailedToLoad,
    EEIDOnAdOpened,
    EEIDOnAdClosed,
    EEIDOnAdLeftApplication,
    EEIDOnLoadFailure,
    EEIDOnRepeatBoxRowDeleting = 150,
    EEIDOnControlAdded,
    EEIDOnControlRemoved,
    
    /// Dynamic events must be added to end
    EEIDOnJsRunSuccess = 500,
    EEIDOnDynamicSwipeUp,
    EEIDOnDynamicSwipeRight,
    EEIDOnDynamicSwipeDown,
    EEIDOnDynamicSwipeLeft,
    EEIDOnGalleryPickSuccess,
    EEIDOnSaveToGallerySuccess,
    EEIDOnInAppBuyProductSuccess = 510,
    EEIDOnInAppRetrievePurchasesSuccess,
    EEIDOnInAppRequestProductsSuccess,
    EEIDOnInAppConsumePurchaseSuccess,
    EEIDOnErrorWithMessage,    
    EEIDOnDynamicPinch,
    EEIDOnCropSuccess,
    EEIDOnCropFail,
    EEIDOnCropCancel,
    EEIDCustom
};

class SpEventGroup : public SpRefCounted {
public:
	SpEventGroup(SpBrParcelable* boundedObject, SpBrBase *base);
	SpEventGroup(SpEventGroup* objectToCopy, SpBrParcelable *objectToBound);
	virtual ~SpEventGroup();
	int debugTreeSize;
    bool hasBoundedJSObject, availableForDeletion;
    
public:
    void Parse(SpDataSource **datasourcePtr, std::vector<SpBrParcelable*> *objects);
    int GetEventIndex(TEventID aEventID, int aOption = -1);
    
    void FireEventNew(TEventID aEventID, char *argumentString = NULL, SpBrParcelable *sourceObject = NULL, PropertyDict *argDict = NULL);
    void FireEventNew(bool synchronously, TEventID aEventID, char *argumentString = NULL, SpBrParcelable *sourceObject = NULL, PropertyDict *argDict = NULL);
    
    virtual void DoFireEventNew2(bool synchronously, TEventID aEventID, char *argumentString = NULL, SpBrParcelable *sourceObject = NULL, map<const char *, SpJsValue> *argDict = NULL);

    char* LoadEventArgs(TEventID aEventID);
    
    std::vector<int> GetEventCodes();
    /**
     * getter boundedObject.
     *
     * it can return NULL, if this event group not bounded with SpBrParcable object
     *
     * @author adem.cayir
     * @return boundedObject
     */
    SpBrParcelable* getBoundedObject();
    void NullBoundedObject();
    
    void PrintEvents();
    void AddJSCallbackEvent(int eventCode, SpJsObject callbackFunction);
    void AddCallbackEvent(int eventCode, void* (*foo)(void*),void* data);
    void RemoveCallbackEvent(int eventCode);
    SpJsObject GetCallbackFunctionObject(const char* eventName);
    SpJsObject GetCallbackFunctionObject(int eventCode);
    void BindDynamicJSCallbackEvent(int eventCode, SpJsObject callbackFunction);
    const char* GetEventFunctionName(int eventID);
    void SetEventFunctionName(int eventID, SpBrString* name);

private:
    bool hasJavaScriptFunction;
    std::vector<SpBrParcelable*> eventElements;
    
public:
    SpBrBase *baseData;
    
    /**
     * it keeps which object bounded to this event group.
     *
     * and, in fireEvent and FireEventAsync it calls SpBrParcelable.FiringEvent and SpBrParcelable.FiredEvent.
     * because, some ui component sends some info to core. like, combo send whick item is selected than core
     * changes dataset current row.
     *
     * @author adem.cayir
     */
    SpBrParcelable* boundedObject;
};

class SpMainThreadCall : public SpEventGroup {
public:
    SpMainThreadCall(SpBrParcelable* boundedObject, SpBrBase *base) : SpEventGroup(boundedObject, base) {
        // intentionally empty
    }

    virtual void DoFireEventNew2(bool synchronously, TEventID aEventID, char *argumentString = NULL, SpBrParcelable *sourceObject = NULL, map<const char *, SpJsValue> *argDict = NULL) {
        SpBrBase::JSObjectCallAsFunctionSafe(functionToCall, SpJsNullObject, argumentCount, args.get());
        SpJsUnprotect(functionToCall);
    }

    void setFunctionToCall(SpJsObject functionToCall, int argumentCount = 0, shared_ptr<SpJsValue> args = NULL) {
        this->functionToCall = functionToCall;
        this->args = args;
        this->argumentCount = argumentCount;
    }

    void call() {
        this->FireEventNew(EEIDCustom);
    }

private:
    SpJsObject functionToCall;
    shared_ptr<SpJsValue> args;
    int argumentCount;
};

#endif /* SPEVENTGROUP_H_ */
