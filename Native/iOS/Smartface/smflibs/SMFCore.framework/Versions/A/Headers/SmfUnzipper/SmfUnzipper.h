//
//  SmfUnzipper.h
//  SpratIOS
//
//  Created by Tolga Haliloğlu on 20/07/16.
//  Copyright © 2016 Smartface. All rights reserved.
//

#ifndef SmfUnzipper_h
#define SmfUnzipper_h

#include <string>

#include "zip.h"
#include "unzip.h"

using std::string;

class SmfUnzipper {
public:
    SmfUnzipper();
    virtual ~SmfUnzipper();
    
public:
    zipFile zipFile;
    unzFile unzFile;
    string password;
    
public:
    bool unzipOpenFile(string path);
//    bool unzipFileTo(string path, bool isOverWrite);
};

#endif /* SmfUnzipper_h */
