/*
 * SpBrString.h
 *
 *  Created on: Jul 4, 2011
 *      Author: umit
 */

#ifndef SPBRSTRING_H_
#define SPBRSTRING_H_

#include "SpDefs.h"
#include "SpContext.h"
#include <vector>

#ifdef TARGET_PLATFORM_IOS
#endif
#ifdef TARGET_PLATFORM_ANDROID
#include <jni.h>
#endif

class SpBrString {
public:
    // If you've allocated a memory for your SpBrString char*,
    // please construct your SbBrString with bytesAllocated parameter = true.
    SpBrString(const char *utf8Bytes);
    SpBrString(char *utf8Bytes, bool bytesAllocated = false);
    SpBrString(const SpBrString *refString, bool bytesAllocated = true);    
#ifdef TARGET_PLATFORM_ANDROID
    SpBrString(jstring string);
#endif
    SpBrString(int intValue);
    SpBrString(float floatValue);
    SpBrString(double doubleValue);
    virtual ~SpBrString();
    
    char* GetCString();
    void SetBytes(const char *utf8Bytes);
    
#ifdef TARGET_PLATFORM_IOS
    // TODO: To be implemented.
    void* GetInnerString(SpContext* context);
#endif
#ifdef TARGET_PLATFORM_ANDROID
    // It should not modified with jstring methods!
    jstring GetJavaString();
    jstring GetJavaString(SpContext* context);
    void ReleaseInnerStringggg();
#endif
    
    /**
     * startoffset is original chars startoffset to compare
     */
    bool Equals(SpBrString*,int startOffset=0);
    bool operator== (const SpBrString*);

    /**
     * startoffset is original chars startoffset to compare
     */
    bool Equals(const char* c,int startOffset=0);
    bool operator== (const char*);

    int intValue();
    int ColorValue();
    bool intValue(int &result);
    float floatValue();
    bool floatValue(float &result);
    double doubleValue();
    bool doubleValue(double &result);
    bool boolValue();
    int Bytes();
    int Length();
    



    std::vector <SpBrString *> SeperateByCharacter(char sepChar);
    void Trim();
    void TrimNotNumber(char **outBuffer);
    void Trim(char **outBuffer, const char trimChar);
    void TrimLeft(char **outBuffer, const char trimChar);
    void TrimRight(char **outBuffer, const char trimChar);
    int Find(const char *value,int startloc=0);
    char* Replace(const char *value, const char *newValue);
    void ReplaceInside(const char *value, const char *newValue);
    char* Substring(int index, int length);
    SpBrString *SubSpBrString(int index,int length);
    char* GetNumericOnly();
    int CountChar(char chr);
    SpBrString* ToUpperCase();
    SpBrString* ToLowerCase();
    char CharAt(int index);
    char GetCapitalChar(char c);
    int GetTurkishCapitalChar(int ch);    
    char GetSmallChar(char c);
    int GetTurkishSmallLetter(int ch);
    bool HasChars();
    static bool StartsWith(const char *src,const char *needle);
    static bool EndsWith(const char *src,const char *needle);
    static int StrPos(const char *src,const char *needle);
    static char* NumToStr(int num);
    void Insert(char p, int position);
    void Insert(const char str[], int position=-1);
    void InsertInt(int value, int position=-1);
private:
    std::string data;

};

#endif /* SPBRSTRING_H_ */
