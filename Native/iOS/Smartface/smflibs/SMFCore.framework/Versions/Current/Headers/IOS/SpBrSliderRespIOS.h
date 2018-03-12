/*
 * SpBrSliderRespIOS.h
 *
 *  Created on: 25 May 2012
 *      Author: ugur kilic
 */

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "Core/SpDefs.h"

class SpEventGroup;

@interface SpBrSliderRespIOS : NSObject {
    int stepvalue;
}

@property SpEventGroup *events;

- (id) initWithEventGroup:(SpEventGroup*)eventGroup :(int)stepSize;

@end

