/*
 * SpTimeoutManager.h
 *
 *  Created on: Mar 5, 2014
 *      Author: adem
 */

#ifndef SPTIMEOUTMANAGER_H_
#define SPTIMEOUTMANAGER_H_

#include <map>
#include <pthread.h>
#include "SpBrString.h"
#include "SpDefs.h"
#include "SpJsEngine/Core/SpJsEngine.h"

class SpTimeoutManager;

struct SpTimeoutItem
{
	SpBrString* code;
	SpJsObject callback;
	int timeout;
	int id;
	pthread_t threadId;
	SpTimeoutManager* manager;
	bool canceled;
	bool repeat;
};
class SpTimeoutManager {
private:
    SMARTFACE_MUTEX lock;
	int counter;
	std::map<int,SpTimeoutItem*> items;
	static SpTimeoutManager* instance;
	SpTimeoutManager();
public:
	static SpTimeoutManager* GetInstance();
	virtual ~SpTimeoutManager();
	int AddTimeoutAsCode(const char* code, int timeout,bool repeat);
	int AddTimeoutAsCallback(SpJsObject callback, int timeout,bool repeat);
	bool ClearTimeout(int timerId);
	void RemoveTimeoutItem(int timerId);
    void ClearAll();
};

#endif
