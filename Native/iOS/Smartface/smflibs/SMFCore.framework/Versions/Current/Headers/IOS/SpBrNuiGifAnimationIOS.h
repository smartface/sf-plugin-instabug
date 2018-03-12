/*
 * SpBrNuiGifAnimationIOS.h
 *
 *  Created on: Sep 6, 2011
 *      Author: antti
 */

#ifndef SPBRNUIGIFANIMATIONIOS_H_
#define SPBRNUIGIFANIMATIONIOS_H_

#include "SpBrNuiGifAnimation.h"

class SpBrNuiGifAnimationIOS: public SpBrNuiGifAnimation {
public:
	SpBrNuiGifAnimationIOS(SpBrBase* base, SpContext* context);
    SpBrNuiGifAnimationIOS(SpBrNuiGifAnimationIOS* objectToCopy);
	virtual ~SpBrNuiGifAnimationIOS();
    void Load();

public:
    void Invalidate(bool skipMainProperty = false);
    void StopGifAnimation();

private:
};

#endif /* SPBRNUIGIFANIMATIONIOS_H_ */
