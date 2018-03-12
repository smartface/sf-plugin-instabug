//
//  SpRefCounted.cpp
//  Sprat
//
//  Created by Antti Panula on 2015-02-13.
//  Copyright (c) 2014 Bivium Oy. All rights reserved.
//
// Just simple and manual reference counting, until we can replace this with something better.

#ifndef SPREFCOUNTED_H_
#define SPREFCOUNTED_H_
#include <pthread.h>
static pthread_mutex_t refMutex = PTHREAD_RECURSIVE_MUTEX_INITIALIZER; //slowish to use mutex, but ok for now...

class SpRefCounted {
public:
    SpRefCounted();
    virtual ~SpRefCounted(){};
    void grab();
    void release();
private:
    int mRefCount;
};
#endif