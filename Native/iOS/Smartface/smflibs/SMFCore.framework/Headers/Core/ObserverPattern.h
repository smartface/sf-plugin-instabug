#ifndef SMARTFACE_OBSERVERPATTERN_H
#define SMARTFACE_OBSERVERPATTERN_H

#include <vector>
#include <memory>
using std::vector;
using std::weak_ptr;
using std::shared_ptr;

class Observable;

class NotifyArgument {
    public:
        // Make NotifyArgument polymorphic to use dynamic_cast
        virtual ~NotifyArgument() {}
};

class Observer {
    public:
        virtual void notify(Observable& sender, shared_ptr<NotifyArgument> arg) = 0;
};

/**
 * class Observable
 * -----
 *  Implementation of Observable class in Observer Pattern. This implementation
 *  doesn't take care of thread issues. If you need use in thread you need to consider
 *  thread issues.
 */
class Observable {
    private:
        vector<weak_ptr<Observer>> observers;

    public:
        void registerObserver(weak_ptr<Observer> observer) {
            observers.push_back(observer);
        }
        
        void unregisterObserver(weak_ptr<Observer> observer) {
            for (auto iter = observers.begin(); iter != observers.end(); ++iter) {
                if (!iter->expired() && !observer.expired()) {
                    if (iter->lock().get() == observer.lock().get()) {
                        observers.erase(iter);
                        break;
                    }
                }
            }
        }

        void notifyObservers(shared_ptr<NotifyArgument> arg) {
            for (auto observer : observers) {
                if (!observer.expired())
                    observer.lock()->notify(*this, arg);
            }
        }
};

#endif // SMARTFACE_OBSERVABLE_H
