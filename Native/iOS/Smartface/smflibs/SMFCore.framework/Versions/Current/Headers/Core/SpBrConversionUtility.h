/*
 * SpBrConversionUtility.h
 *
 *  Created on: Aug 12, 2011
 *      Author: ugurkilic
 */

#ifndef SPBRCONVERSIONUTILITY_H_
#define SPBRCONVERSIONUTILITY_H_

#include <math.h>
#include <map>
#include <string>

#include "SpDefs.h"
#include "SpBrString.h"
#include "SpDefs.h"
#include "SpJsEngine/Core/SpJsEngine.h"

static const char  table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

class SpBrConversionUtility {
public:
	SpBrConversionUtility();
	virtual ~SpBrConversionUtility();

public:
    static SpBrString* ConvertToUTF8String(char *input, const char *sourceEncoding);
    static void* ConvertIntToRgb(int colorValue);
    static void* GetImageFromColor(int colorValue);
    static void* GetGradientImageFromColor(int colorValue, int width, int height);
    static void* ReturnValidPhoneNumber(SpBrString *numberText);
    static SpBrString* StringToSpBrString(void *nativeString);
    static int HexToInt(const char *str);
    static int HexToInt(SpBrString* str);
    static char* IntToHex(int value);
    static void RGB2HSL(float r, float g, float b, float *outH, float *outS, float *outL);
    static SpBrString* GetNumericFiltered(SpBrString *value);
    static int GetNormalizedDrawMode(int value);
    static int GetNormalizedDrawPosition(int value);
public:
    // These 4 methods allocate char pointer in return
    // Don't forget to free them!
    // [ugur *]
    static char* CharToHex(const unsigned char *value, int length);
    static unsigned char* HexToChar(const char *value, int length, int &resultLength);
    static char* CharToBase64(const unsigned char *value, int length, int &resultLength);
    static unsigned char* Base64ToString(const char *value, int length, int &resultLength);
    static unsigned char* Base64ToByte(const char *value, int length, int &resultLength);
    static char* HexToBase64(const char *value, int length);
    static char* Base64ToHex(const char *value, int length);
    static unsigned char* ReverseBytes(const unsigned char *value, int length);

public:
    static int GetEventIdFromName(const char* eventName, int objectType = -1);

public:
    static int GetPercentageValue(int value, int valuePercentage);
    static int ConvertPuntoToPoint(int puntoValue);

public:
    static SpJsValue GetArgumentObject(const char *argumentString, int argumentStringLength);

    static std::map<std::string, std::string> ConvertJSObjectToMap(SpJsObject objectRef);
};

#endif /* SPBRCONVERSIONUTILITY_H_ */
