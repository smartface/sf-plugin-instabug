#ifndef __SMF_CLOUD_DEBUGGER_HDR__
#define __SMF_CLOUD_DEBUGGER_HDR__

#include <atomic>
#include <mutex>
#include <condition_variable>

#include "CloudEmulator/Core/AsyncWebSocket.h"
#include "Core/ObserverPattern.h"
#include "Core/SpLog.h"

#include "SpJsEngine/Core/SpJsEngine.h"
using namespace std;

class DebuggerConnectionObserver : public Observer {
    private:
        function<void()> startCallback;
        function<void()> shutdownCallback;
    public:
        DebuggerConnectionObserver(function<void()> startCallback, function<void()> shutdownCallback) :
                startCallback(startCallback), shutdownCallback(shutdownCallback) {
            // intentionally empty
        }

        virtual void notify(Observable& sender, shared_ptr<NotifyArgument> notifyArgument) override {
            NotifyArgument* ptrNotifyArgument = notifyArgument.get();
            splog(SPDEB, "Debugger", "Notified DebuggerConnectionObserver");
            if (StateChange* stateChange = dynamic_cast<StateChange*>(ptrNotifyArgument)) {
                if (stateChange->to == WS_SHUTTING_DOWN) {
                    splog(SPDEB, "Debugger", "Notified with shutting down");
                    shutdownCallback();
                } else if (stateChange->to == WS_RUNNING) {
                    splog(SPDEB, "Debugger", "Notified with running");
                    startCallback();
                }
            }
        }
};

class CloudDebugger {
    private:
        atomic<bool>                debuggerSyncWaiting;
        atomic<bool>                isStartingDebug;
        mutex                       debuggerSyncLock;
        condition_variable          debuggerStarting;
        RequestResponseWebSocket*   debuggerSocket;
        RequestResponseWebSocket*   controlSocket;

        shared_ptr<DebuggerConnectionObserver> connectionObserver;

        void resumeFromSync (string msg);

        bool dismissWaitingDialog();

        enum DebuggerState {
            Unknown,
            WillDebug,
            WillNotDebug,
            IsDebugging,
            IsNotDebugging
        };

        DebuggerState state;
    public:
        /**
         * Blocks until the UI responds or a timeout occurs for debug
         * sessions to work.
         */
        void startSyncDebugger ();

        /**
         * Stops debug session without killing application. If debug session not yet started
         * it will prevent resume.
         */
        void stop();

        CloudDebugger (RequestResponseWebSocket* debuggerSocket, RequestResponseWebSocket* controlSocket);
        virtual ~CloudDebugger();
};

#endif
