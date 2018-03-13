/*
 * SpBrBasicUtility.h
 *
 *  Created on: 21 Sep 2011
 *      Author: ugur
 */

#ifndef SPBRBASICUTILITY_H
#define SPBRBASICUTILITY_H

#include "SpDefs.h"
#include <string>
#include <string>

class SpBrString;
class SpDataSource;
class SpBrBase;

class SpBrBasicUtility {
public:
	SpBrBasicUtility();
	virtual ~SpBrBasicUtility();

public:
#ifdef TARGET_PLATFORM_IOS
    static void LoadAllLocalFonts();
    static int GetContentMode(int drawMode, int drawPosition);
    static void* CreateBackgroundImage(int width, int height, SpBrString *imageName, int drawMode, int drawPosition);

#endif
    static SpDataSource* GetJavaScriptFile(SpBrBase* baseData, const char* filename);

	static double CharsToDouble(char* chars);
};

#endif /* SPBRBASICUTILITY_H */
