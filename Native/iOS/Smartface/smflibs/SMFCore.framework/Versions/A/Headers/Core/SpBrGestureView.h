//
//  SpBrGestureView.h
//  SpratIOS
//
//  Created by mehmet akyol on 5/13/13.
//  Copyright (c) 2013 Bivium. All rights reserved.
//

#import <UIKit/UIKit.h>

class SpEventGroup;

@interface SpBrGestureView : UIView

@property SpEventGroup* events;
@property int numberOfTabs;

- (id) initWithEventGroup:(SpEventGroup*)eventGroup;
- (id)initWithFrame:(CGRect)rect eventGroup:(SpEventGroup*)eventGroup;

@end
