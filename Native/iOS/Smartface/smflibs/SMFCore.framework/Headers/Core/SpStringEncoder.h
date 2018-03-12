//
//  SpStringEncoder.h
//  SpratIOS
//
//  Created by Macbook Pro on 2/15/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef SPSTRING_ENCODER_H
#define SPSTRING_ENCODER_H

#include <iostream>
#include <map>

#define windows_1254    "windows-1254"      // Microsoft Windows Turkish compatible with ISO 8859-9
#define windows_1255    "windows-1255"      // Microsoft Windows to write Hebrew compatible with ISO 8859-8
#define windows_1256    "windows-1256"      // Microsoft Windows to write Arabic compatible with ISO 8859-6 and MacArabic
#define macArabic       "macArabic"         // Mac to write Arabic compatible with ISO 8859-6 and windows-1256
#define iso_8859_6      "iso-8859-6"        // ISOLatinArabic — Arabic (ISO 8859-6) compatible with windows_1255
#define iso_8859_8      "iso-8859-8"        // ISOLatinHebrew — Hebrew (ISO 8859-8) compatible with windows_1256
#define iso_8859_9      "iso-8859-9"        // ISOLatinTurkish — Turkish (ISO 8859-9) compatible with windows_1254

class SpStringEncoder {
public:
    static char* ConvertToUtf8(char *input, const char *input_encoding);
    static void FreeClear(std::map<int, char *> map);

private:
     static std::map<int, char *> GetMap(const char *input_encoding);
     static std::map<int, char *> Get_Windows_1254_Map();
     static std::map<int, char *> Get_Iso_8859_6_Map();
     static std::map<int, char *> Get_Iso_8859_8_Map();
};

#endif /* SPSTRING_ENCODER_H */
