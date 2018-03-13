//
//  FileChangeMonitor.h
//  SpratIOS
//
//  Created by Antti Panula on 1/29/14.
//  Copyright (c) 2014 Bivium. All rights reserved.
//

#ifndef __SpratIOS__FileChangeMonitor__
#define __SpratIOS__FileChangeMonitor__

#include "Core/SpDefs.h"

#ifdef TARGET_PLATFORM_IOS
#include "Core/SpBrString.h"
class FileChangeMonitor
{
public:
    FileChangeMonitor();
    ~FileChangeMonitor();
    bool StartMonitoring(SpBrString* file);

private:
    int fileFD;
    int kq;
    CFFileDescriptorRef fileKQRef;
};

#endif

#endif /* defined(__SpratIOS__FileChangeMonitor__) */
