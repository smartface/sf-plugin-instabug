#include "CloudEmulator/Core/CloudEmulator.h"

class CloudEmulatorIOS : public CloudEmulator {
    public:
        CloudEmulatorIOS (string info, string host, int port);
        void ClearAllEmulatorRes();
        void invalidProtocolVersion (std::string emulatorVersion, std::string dispatcherVersion);
        void onChunkReceived (unsigned char* chunk, int size, bool isFirst, bool isFinal, int offset);
        void onFilesReceived (unsigned char* fileBinaries, int size);
        void onFileInfoReceived (int message);
        void onError (std::string s);
        void onTimeout ();
        void SetEmulatorProjectName(string name);
        void ResetTimeout ();
    private:
        virtual void saveEmulatorUrl(string url);
};
