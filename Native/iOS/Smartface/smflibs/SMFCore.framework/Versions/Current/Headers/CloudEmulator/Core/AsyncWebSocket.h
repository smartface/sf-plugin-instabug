#ifndef __SMF_ASYNCWEBSOCKET_HDR__
#define __SMF_ASYNCWEBSOCKET_HDR__

#include "Core/ObserverPattern.h"

#include <thread>
#include <string>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <atomic>
#include <Poco/Net/SocketAddress.h>
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/WebSocket.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/JSON/Object.h>

using namespace std;
using Poco::Timespan;
using namespace Poco::Net;
using namespace Poco::JSON;

template <typename T>
class ThreadSafeQueue {
  private:
    queue<T>  q;
    mutex     lock;
    condition_variable isNotEmpty;

  public:
    void push (T item) {
      lock_guard <mutex> l (lock);
      q.push (item);
      isNotEmpty.notify_one();
    }

    T pop (long timeout=-1) {
      unique_lock <mutex> l(lock);
      if (isNotEmpty.wait_for (l, chrono::milliseconds (timeout), [this] () { return !this->q.empty(); })) {
          T i = q.front();
          q.pop();
          return i;
      } else if (timeout != -1) {
          throw "Timeout!";
      }
    }

    bool empty () {
      lock_guard <mutex> l (lock);
      return q.empty ();
    }

    int size () {
        lock_guard <mutex> l (lock);
        return q.size();
    }
};

typedef int AsyncWebSocketState;
#define WS_IDLE            1
#define WS_STARTING        2
#define WS_RUNNING         4
#define WS_SHUTTING_DOWN   8

// This is an asynchronous web socket that provides the following features:
//  - Automatic reconnect
//  - Queing of unsent messages
//  - Asynchronous response handling.
//
// Example:
//  AsyncWebSocket s ("foo", 8000, "/bar");
//  s.Send ("Hello world!");
class AsyncWebSocket : public Observable {
    private:
        const int minRetryDuration = 2000;
        const int maxRetryDuration = 2000;
        const Timespan receiveTimeout = Timespan (10, 0);
        atomic_int state;
        string host;
        int port;
        string caFilePath;
        bool waitForConnection;
        WebSocket* socket = NULL;
        thread* sending = NULL;
        thread* receiving = NULL;
        mutex   ioLock;
        mutex   stateLock;
        ThreadSafeQueue<string> msgsToSend;
        atomic_bool running;
        void Start ();
        void Restart ();
        void switchState (AsyncWebSocketState a, AsyncWebSocketState b, function<void(void)> onSwitch);
        unsigned int retries = 0;

    protected:
        void ReceivingThread ();
        void SendingThread ();

    public:
        int retryCount = 30;
        string uri;
        AsyncWebSocket (string host, int port, string uri="/", string caFilePath="", bool waitForConnection=true);
        void Send (string msg);
        void Shutdown ();
        bool isIdle() const;
        function<void(string)> onErrorHandler = [] (string s) {};
        function<void()> onTimeout = [] () {};
        function<void(uint8_t*,size_t)> onBinaryReceived = [] (uint8_t* bytes, size_t length) {};
        function<void(uint8_t*,size_t,bool,bool,int)> onChunkReceived = [] (uint8_t* bytes, size_t length, bool isFirst, bool isFinal, int offset) {};
        virtual void onMessageReceived (string msg);
        virtual void onError (string errorMsg);
        virtual ~AsyncWebSocket ();
};

class RequestResponseWebSocket : public AsyncWebSocket {
    private:
        int currentId = 1;
        int getNextId ();
        map<int, function<void(string)>> handlers;
    protected:
        typedef AsyncWebSocket super;
    public:
        RequestResponseWebSocket (string host, int port, string uri="/", string caFilePath = "", bool waitForConnection=true);
        virtual void onUnhandledMessage (string msg);
        void onMessageReceived (string msg);
        void Request (string request, string data="{}", function<void(string)> responseHandler=[](string msg){});
        void Request (string request, Object::Ptr json, function<void(string)> responseHandler=[](string msg){});
        void Respond (string id, string data="{}");
        void Fail (string id, string error="");
};

class StateChange : public NotifyArgument {
    public:
        AsyncWebSocketState from;
        AsyncWebSocketState to;

        StateChange(AsyncWebSocketState from, AsyncWebSocketState to) : from(from), to(to) {}
};

#endif
