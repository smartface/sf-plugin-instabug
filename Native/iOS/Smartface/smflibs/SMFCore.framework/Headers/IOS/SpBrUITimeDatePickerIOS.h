/*
 * SpBrUIButtonIOS.h
 *
 *  Created on: 21 Jan 2012
 *      Author: ugur
 */

#import <UIKit/UIKit.h>
#import "Core/SpDefs.h"

class SpEventGroup;

@interface SpBrUITimeDatePickerIOS : UIButton {
    CGFloat _hue;
    CGFloat _saturation;
    CGFloat _brightness;
}

@property SpEventGroup *events;
@property CGFloat hue;
@property CGFloat saturation;
@property CGFloat brightness;
@property BOOL onSelected;

@end
