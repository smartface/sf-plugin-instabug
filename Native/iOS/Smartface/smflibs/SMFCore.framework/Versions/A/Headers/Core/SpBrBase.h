/*
 * SpBrBase.h
 *
 *  Created on: 26 Tem 2011
 *      Author: ugur
 */

#ifndef SPBRBASE_H_
#define SPBRBASE_H_

#include <vector>
#include <map>
#include <string>
#include <deque>
#include <string.h>

#include "SpDefs.h"
#include "SpBrString.h"
#include "SpDefs.h"
#include "SpJSCallbackGroup.h"
#include "SpJsEngine/Core/SpJsEngine.h"

class SpEventGroup;
class SpBrParcelable;
class SpBrString;
class SpApplication;
class SpJSCallbackGroup;

#ifdef TARGET_PLATFORM_IOS
#ifdef DEBUGGER_PLAYER
class FileChangeMonitor;
#endif
#endif

#ifdef TARGET_PLATFORM_ANDROID
#define tojboolean(x) ((jboolean)((x) ? 1 : 0))
#endif

class SpBrBase  {
    public:
        SpBrBase(SpApplication *owner);
        virtual ~SpBrBase();

    public:
        void CallApplication(SpBrString *app, std::vector<SpBrString*> keys, std::vector<SpBrString*> values);

        /**
         * fill all possible enum value.
         *
         * create new SpBrString* for every request
         * this will return without separator in the end!
         */
        SpBrString* GetFilePath(IOApplicationPath type);


        void* ShowAlertDialog(SpBrString *title, SpBrString *message, int alpha, int numberOfButtons, SpBrString *firstButtonText, SpBrString *secondButtonText, SpBrString *thirdButtonText, SpEventGroup *eventGroup, bool debugDialog = false);
        void closeAlertDialog(SpEventGroup *eventGroup);
        void CloseAlert(SpBrParcelable *alert);

        /**
         * it gives system variables.
         * most of variables depend os level. but some of them (bytes sent, receive) depend core.
         * so for now, it works only for os level. later core level keys must be implemented
         */

        void SetCallApplicationData(SpBrString *data, int resultCode, AppCallType type);
        void SetCallApplicationUrl(SpBrString *url);
        void SetRemoteNotificationData(SpBrString *data);

        SpBrString* pushNotificationData; // contain remote notification token

        // WE SHOULD PROTECT THESE DATA OR HOLD C STRINGS FOR THIS PURPOSE
        SpJsValue callApplicationData;
        SpBrString * callApplicationUrl;

        SpJsValue inAppRequestProductsData;
        SpJsValue onErrorWithMessageData;
        SpJsValue inAppRetrievePurchasesData;
        SpJsValue inAppBuyProductData;
        SpJsValue inAppConsumePurchaseData;

        int callApplicationResult;
        AppCallType callAppCallType;

        SpJsValue remoteNotificationData;
        NotificationType notificationType;
        /**
         * it gives device unique identifier.
         * it must be string that only decimal chars accepted
         * this value will be deleted
         *
         * @author adem.cayir
         */
        SpBrString* GetDeviceUniqueIdentifier();

    public:
        SpBrString* ApplicationName();
        SpBrString* ApplicationVersion();

        void GetData(char *dataLink, char **data1, char **data2);
        bool SetData(char *dataLink, char *data1, char *data2, int length1, int length2);

        void ProtectOnMainThread(SpJsObject obj);
        void UnprotectOnMainThread(SpJsObject obj);

        /**
         * it gives app identifier.
         *
         * for android, it is package
         * for ios, it is bundle id
         */
        SpBrString* GetApplicationIdentifier();

        void SetErrorDetails(int value,  SpBrString *message = NULL);
        void UpdateLatestInappKey(SpBrString *key);

    public:
        pthread_mutex_t globalErrorLockDetails;
#ifdef TARGET_PLATFORM_IOS
        void CallAppCallRecievedEvent();
        bool CanOpeniOSUrl(char* urlScheme);
        void clearDone();
        void invalidProtocolVersion(std::string emulatorVersion, std::string dispatcherVersion);
        void chunkReceived(unsigned char* chunk, int size, bool isFinal, int offset);
        void filesRecieved(uint8_t* bytes, int byteLength);
        void fileInfoReceived(int message);
        void errorhandler(std::string s);
        void timeOutException();
        void setEmulatorProjectName(std::string s);
        void saveEmulatorUrlToUserDefaults(std::string url);
        void resetTimeout();
        void setToDeleteFileList(const std::vector<std::string>& fileList);
        void deleteFiles();
#endif

        std::map<int,SpEventGroup*> eventGroupMap;

    public:
        SpApplication *application;
        void *systemVariableManager;

        SpEventGroup* pushNotificationEvent;

    private:
        SpBrString *lastErrorSourceName;
        SpBrString *lastErrorStatusMessage;
        int lastErrorCode;
        SpBrString *latestInAppKey;
#ifdef TARGET_PLATFORM_IOS
#ifdef DEBUGGER_PLAYER
        FileChangeMonitor* fm;
#endif
#endif

    public: // WUSWUG stuff
        int deviceDpi;
        float deviceXDpi;
        float deviceYDpi;
        int fixedDeviceDpiForiOS;
        int majorOSVersion;

        void setContextProperties();

    public:
#ifdef TARGET_PLATFORM_IOS
        void GlobalContextCreated();
        void RemoveRauFilesIfNeeded();
#endif

        static pthread_mutex_t jsExecutionMutex;

        //static bool jsLocked;
        static int jsCallFunctionCount;
#ifdef DEBUG_JSSCHEDULER
        __attribute__ ((visibility ("default"))) static SpJsValue JSObjectCallAsFunctionSafe
            (SpJsObject object,
             SpJsObject thisObject,
             size_t argumentCount,
             const SpJsValue arguments[]
             /*, SpJsValue* exception*/,
             std::string debugStr);
#else
        __attribute__ ((visibility ("default"))) static SpJsValue JSObjectCallAsFunctionSafe
            (SpJsObject object,
             SpJsObject thisObject,
             size_t argumentCount,
             SpJsArgumentsList arguments
             /*, SpJsValue* exception*/);
#endif

        static SpJsValue RunJavaScript(const char *jsCode,
                SpJsObject thisObject=SpJsNullObject,
                const char *sourceId = nullptr,
                bool ignoreError = false);

    public:
        SpBrString * GetApplicationBundlePath();

    /**
    * Called to set device orientation on native side.
    */
    void SetOrientations(bool isPortrait, bool isUpsideDown, bool isLandLeft, bool isLandRight);

    static void restartApplication();
    std::string GetSystemLanguage();
};

#endif /* SPBRBASE_H_ */

