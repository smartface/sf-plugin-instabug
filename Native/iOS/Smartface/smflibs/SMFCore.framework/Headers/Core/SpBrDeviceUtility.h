/*
 * SpBrDeviceUtility.h
 *
 *  Created on: Oct 6, 2011
 *      Author: ugurkilic
 */

#ifndef SPBRDEVICEUTILITY_H_
#define SPBRDEVICEUTILITY_H_

#include <vector>

class SpBrString;

class SpBrDeviceUtility {
public:
	SpBrDeviceUtility();
	virtual ~SpBrDeviceUtility();

public:
    static SpBrString* GetDeviceIdentifier();
    static SpBrString* GetDeviceIP();
    static int GetDeviceTotalWidth();
    static std::vector<SpBrString *> GetCarrierInfo();
    static SpBrString* GetCurrentDate();
    static SpBrString* GetApplicationName();
    static SpBrString* GetApplicationState();
    static SpBrString* GetDeviceOS();
    static SpBrString* GetDeviceOSVersion();
    static SpBrString* GetDeviceBrand();
    static SpBrString* GetDeviceModel();
    static int GetStatusBarHeight();
    static int GetNavigationBarHeight();
    static bool IsModified();
    static int GetPointScale();
};

#endif /* SPBRDEVICEUTILITY_H_ */
