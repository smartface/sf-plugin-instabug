/*
 * SpBrUIButtonIOS.h
 *
 *  Created on: 21 Jan 2012
 *      Author: ugur
 */

#import <UIKit/UIKit.h>

class SpBrNuiButtonView;

@interface SpBrUIButtonIOS : UIButton {
    float _hue;
    float _saturation;
    float _brightness;
}

@property SpBrNuiButtonView *smfObject;
@property float hue;
@property float saturation;
@property float brightness;
@property UIFont* textButtonFont;

-(void) calculateColors;

@end
