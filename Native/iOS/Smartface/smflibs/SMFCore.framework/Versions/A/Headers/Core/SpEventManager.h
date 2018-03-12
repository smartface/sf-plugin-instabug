//
// @author eray.tuncer@smartface.io
//

#ifndef SMARTFACE_SPEVENTMANAGER_H
#define SMARTFACE_SPEVENTMANAGER_H

#include <memory>
#include "ObserverPattern.h"
#include "SpEventGroup.h"

class SpEventNotify : public NotifyArgument {
public:
    TEventID eventID;
};

class EventObserver : public Observer {
public:
    std::function<void(std::shared_ptr<SpEventNotify>)> onEventReceived;

    void notify(Observable& sender, std::shared_ptr<NotifyArgument> arg) {
        std::shared_ptr<SpEventNotify> eventNotify = std::dynamic_pointer_cast<SpEventNotify>(arg);
        onEventReceived(eventNotify);
    };

};

class SpEventManager : public Observable {
private:
    static std::shared_ptr<SpEventManager> instance;

public:
    static std::shared_ptr<SpEventManager> getInstance();

    void broadcast(std::shared_ptr<SpEventNotify> event);

};

#endif //SMARTFACE_SPEVENTMANAGER_H
