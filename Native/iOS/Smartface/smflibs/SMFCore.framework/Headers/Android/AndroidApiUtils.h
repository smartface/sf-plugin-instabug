/*
 * AndroidApiUtils.h
 *
 *  Created: 2012-04-16
 *   Author: Timo
 */
#ifndef ANDROIDAPIUTILS_H_
#define ANDROIDAPIUTILS_H_

#include "Core/SpDefs.h"
#ifdef TARGET_PLATFORM_ANDROID
#include <jni.h>
#include "FastDelegate/FastDelegate.h"

typedef fastdelegate::FastDelegate0<> Selector0;
typedef fastdelegate::FastDelegate1<void*> Selector1;
typedef fastdelegate::DelegateMemento Memento;

void performOnMainThread(Selector0 selector, bool waitUntilDone, int line);
void performOnMainThread(Selector1 selector, void* withObject, bool waitUntilDone, int line);
void mementoToBePerformedOnMainThread(Memento selector, void* withObject, bool waitUntilDone);
void executeFromMainThread(Memento memento, void* withObject);
bool isMainThread();
void performOnNewThread(Selector0 selector);
void* executeFromNewThread(void *ptr);
void callMethod(const char *methodName, const char *methodSignature, ...);
void callMethod(jobject instance, const char* methodName, const char* methodSignature, ...);
void callMethod(const char* className, const char* methodName, const char* methodSignature, ...);
#endif

#endif // ANDROIDAPIUTILS_H_
