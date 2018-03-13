//
//  SpAppUpdater.h
//  SpratIOS
//
//  Created by M.Halit Karakis on 7/12/16.
//  Copyright © 2016 Smartface. All rights reserved.
//

#ifndef SpAppUpdater_h
#define SpAppUpdater_h

#define APPUPDATER_CHECK_UPDATE_URL "https://portalapi.smartface.io/api/v1/rau/check"
#define APPUPDATER_GENERIC_ERROR "An error occured while checking update"

#include <functional>
#include <Poco/JSON/Object.h>
#include <thread>

using std::function;
using std::string;
using std::thread;
using Poco::JSON::Object;

class AppUpdater {
    public:
        // Constructors

        /**
         *  Default constructor, it reads rau.json for future needs of functions
         */
        AppUpdater();
        /**
         *  While destructing, if there is any, cancel operation
         */
        virtual ~AppUpdater();

        /**
         *  Returns an instance of AppUpdater, if there is no instance creates a new one
         */
        static AppUpdater* getInstance();

        /**
         *  Clears the shared instance of AppUpdater
         */
        static void clearInstance();
    
        // Getters

        /**
         *  Prepares proper JSON request for check update functionality. It fills JSON
         *  using project.json informations.
         */
        string getCheckUpdateRequest();
        /**
         *  If there is an update for application server gives 2 different urls holding
         *  update zip file. If first fails second url is used to download. This function
         *  returns first url for zip file.
         */
        string getFirstDownloadUrl();
        /**
         *  Returns second url
         */
        string getSecondaryDownloadUrl();
        /**
         *  Gives file path of update zip file on local environment
         */
        string getSavePath();
        /**
         *  Returns proper error message according to given status code and json
         */
        string getServerErrorMessage(int statusCode, Object::Ptr json);
        /**
         *  Returns update result got from checkUpdate service
         */
        Object::Ptr getUpdateResult();

        // Functions

        /**
         *  Checks if there is an update for application by asking to server
         */
        void checkUpdate(function<void(string, string, int, Object::Ptr)>);
        /**
         *  If there is an update downloads zip file from urls retrieved from check update
         *  service.
         */
        void downloadUpdate(function<void(string)>);
        /**
         *  Unzips and put updated files in proper places if there is an update zip file downloaded
         */
        void updateAll(function<void()>);

        /**
         *  Unzips and put updated files in proper places if there is an update zip file downloaded
         */
        void updateAll();

        /**
         *  Cancels running operation if there is any
         */
        void cancel();

        // Setters

        /**
         *  Sets first download url
         */
        void setFirstDownloadUrl(string);
        /**
         *  Sets second download url
         */
        void setSecondaryDownloadUrl(string);
        /**
         *  Sets file path to save zip
         */
        void setSavePath(string);
        /**
         *  Sets update result from checkUpdate service call
         */
        void setUpdateResult(Object::Ptr);
        void setUpdateResult(std::string);
    private:
        Object::Ptr projectJsonObj;
        Object::Ptr updateResult;

        string downloadPaths[2];
        string savePath;
        string platform;

        thread* operation;

        static AppUpdater* instance;
    
        void updateProjectJson();
};

#endif /* SpAppUpdater_h */
