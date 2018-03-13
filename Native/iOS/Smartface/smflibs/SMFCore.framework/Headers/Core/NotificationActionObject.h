//
//  NotificationActionObject.h
//  Smartface
//
//  Created by nosaiba on 12/11/2014.
//


#ifndef NOTIFICATIONACTIONOBJECT_H_
#define NOTIFICATIONACTIONOBJECT_H_
#include "SpBrString.h"

class NotificationActionObject {
public:
	NotificationActionObject();
    ~NotificationActionObject();

public:
    SpBrString* title;
    SpBrString* icon;
    SpBrString* action;

};
#endif

