#ifndef __SMF_CLOUD_EMULATOR_HDR__
#define __SMF_CLOUD_EMULATOR_HDR__

#include <string>
#include <vector>
#include <memory>

#ifndef SMARTFACE_PRODUCTION
#include <Poco/JSON/Object.h>
#endif

#define DEFAULT_EMULATOR_PORT   8081 // Get this from Halit

using namespace std;

class CloudDebugger;

class SpEventManager;
class SpEventNotify;
class EventObserver;

class CloudEmulator {
    public:
        CloudEmulator (string info, string host, int port=DEFAULT_EMULATOR_PORT);
        virtual ~CloudEmulator ();

        void SetInfo (string info) {
            infoStr = info;
        }

        string GetInfo () {
            return infoStr;
        }

        /**
         * A reference to the debugger controller.
         */
        CloudDebugger* debugger;

        /**
         * If any of these parameters change across calls for GetInstance, it means a switch in project which should:
         *  - Clear the workspace.
         *  - Sync with an empty index.
         */
        static CloudEmulator* GetInstance (string info, string host, int port=DEFAULT_EMULATOR_PORT);

        /*
         * return the current instance
         */
        static CloudEmulator* GetInstance ();

        /**
         * Releases any resources acquired by any running instance of emulator and deletes the current instance.
         */
        static void ClearInstance ();

        /**
         * If "Control" socket is created, sends device info to server
         */
        void StartEmulatorFlow();

        /**
         * Given a JSON string, it checks with the server if there are any files
         * that are needed to be retrieved, and synchronizes. This function blocks
         * until synchronization is finished.
         */
        void Sync (string index="{}");

        /**
         * Called when the zip file information received
         */
        virtual void onFileInfoReceived (int msg);

        /*
         * parses the project.json info coming in index msg
         */
        static void ParseEmulatorProjectConfig();
    
        static void SuspendInstance();
        static CloudEmulator* ResumeInstance();

        /**
         * Returns user friendly error string matched with key
         */
        string GetErrorString (string key) const;

        /*
         * Sends a console.log message to Cloud
         */
        void LogToCloud(string message);

        /**
         * The data to be sent on the /control URI
         * during the "start project" message. This is a
         * platform-dependent setting, and may change soon.
         */
        string StartProjectData ();

        /**
        * Reset timeout on platforms. When dispatcher sends "resetTimeout" signal
        * on control socket, we should wait more.
        */
        void ResetTimeout ();
    private:
        static CloudEmulator* currentInstance;
        string infoStr = "{}";

        std::shared_ptr<EventObserver> eventObserver;

        void OnEventReceived (std::shared_ptr<SpEventNotify> event);

        /**
         * Called when the zip file containing all the URI's is received.
         */
        virtual void onChunkReceived (uint8_t* bytes, size_t byteCount, bool isFirst, bool isFinal, int offset);

       /**
         * Called when the zip file containing all the URI's is received.
         */
        virtual void onFilesReceived (uint8_t* bytes, size_t byteCount);

        /**
         * Called during any transmission upon catching any exception.
         */
        virtual void onError (string msg);

        /**
         * Called when the number of retries exceeds some maximum, upon connection or re-connection
         */
        virtual void onTimeout ();

        /**
         * requests all files in the received index json
         */
        void DownloadAllEmulatorRes(string json);

        /**
         * calls native to delete all emulator resources
         */
        virtual void ClearAllEmulatorRes();

        /**
         * calls native to delete all emulator resources
         */
        virtual void SetEmulatorProjectName(string name);

        /*
         * calls native to set version and version code for emulator
         */
        virtual void SetEmulatorAppAndBuildVersions(string version, int versionCode);

        /**
         * Checks index json if there is an error or not, if there is an error returns false.
         */
        bool IndexHasErrors (string index) const;

        /**
         * Reads and returns error string from json.
         */
        string GetErrorStringFromIndex (string index) const;

        /**
         * Saves URL that emulator currently works with
         */
        virtual void saveEmulatorUrl (string url) = 0;

        /**
         * Notifies native emulators about file list that to be deleted when an update is applied or
         * DeleteFiles method called. 
         */
        virtual void SetToDeleteFileList(const vector<string>& fileList);
        
        /**
         * Deletes files from emulator which are specified with the SetToDeleteFileList method.
         */
        virtual void DeleteFiles();

#ifndef SMARTFACE_PRODUCTION
        void CalculateProjectDiff(Poco::JSON::Object::Ptr indexJSON, bool& hasProject, vector<string>& fileDiffList, vector<string>& filesToDelete, bool& requiresIndexOverride);
        Poco::JSON::Object::Ptr ReadIndexJSON();
    
        /**
         * A file transfer will be processed, however, once the file
         * is completely transferred, onDataReceived is called with the
         * same URI, it's up to the iOS or Android specific implementation
         * to handle what happens then.
         */
        void RequestFiles(vector<string>& fileDiffList);
        void SaveEmulatorIndex(Poco::JSON::Object::Ptr indexJSON, bool isOverride);
        void SaveProjectJSON(Poco::JSON::Object::Ptr projectJSON);
#endif

};
#endif
