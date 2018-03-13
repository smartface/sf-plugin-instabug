#ifndef __SMF_CLOUD_EMULATOR_ANDROID_HDR__
#define __SMF_CLOUD_EMULATOR_ANDROID_HDR__

#include "CloudEmulator/Core/CloudEmulator.h"
#include "CloudEmulator/Core/AsyncWebSocket.h"

class CloudEmulatorAndroid : public CloudEmulator {
    public:
        CloudEmulatorAndroid (std::string info, std::string host, int port);
        ~CloudEmulatorAndroid();
        void ClearAllEmulatorRes();
        void onChunkReceived (unsigned char* chunk, int size, bool isFirst, bool isFinal, int offset);
        void onFilesReceived (unsigned char* fileBinaries, int size);
        void onFileInfoReceived (int message);
        void SetEmulatorProjectName(std::string name);
        void SetEmulatorAppAndBuildVersions(std::string version, int versionCode);
        void onError (std::string s);
        void onTimeout ();

        /**
        * Reset timeout on platforms. When dispatcher sends "resetTimeout" signal
        * on control socket, we should wait more.
        */
        void ResetTimeout ();

        /**
        * Stop timeout on Android. When android side doing some work, we should stop timeout.
        */
        void StopEmulatorTimeout ();
        
        /**
        * Start timeout on Android. When android side done work, we should start timeout.
        */
        void StartEmulatorTimeout ();
    private:
        RequestResponseWebSocket* debuggingSocket;
        void saveEmulatorUrl(std::string url);

        /**
         * Notifies native emulators about file list that to be deleted when an update is applied or
         * DeleteFiles method called. 
         */
        virtual void SetToDeleteFileList(const vector<string>& fileList);

        /**
         * Deletes files from emulator which are specified with the SetToDeleteFileList method.
         */
        virtual void DeleteFiles();
};

#endif
