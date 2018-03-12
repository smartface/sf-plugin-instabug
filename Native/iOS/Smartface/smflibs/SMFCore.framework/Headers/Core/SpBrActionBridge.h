//
//  SpBrActionBridge.h
//  SpratIOS
//
//  Created by ugur on 8/10/11.
//  Copyright 2011 Bivium. All rights reserved.
//

#import <Foundation/Foundation.h>

class SpEventGroup;
class SpBrParcelable;

@interface SpBrActionBridge : NSObject <UIGestureRecognizerDelegate> {
    SpBrParcelable *senderObject;
    bool delayControl;
}

@property SpEventGroup *events;

- (id) initWithEventGroup: (SpEventGroup*) eventGroup Object: (SpBrParcelable *) object;
- (void) OnPressUp: (id) sender forEvent:(UIEvent*)event;
- (void) OnPressDown: (id) sender forEvent:(UIEvent*)event;
- (void) OnTouchEnd: (id) sender;
- (void) OnTouchEnd: (id) sender forEvent:(UIEvent*)event;
- (void) OnDragInside: (id) sender;
- (void) OnDragOutside: (id) sender;
- (void) OnDragInside:(id)sender forEvent:(UIEvent*)event;
- (void) OnDragOutside:(id)sender forEvent:(UIEvent*)event;
- (void) OnDragEnter: (id) sender;
- (void) OnDragExit: (id) sender;
- (void) OnDoubleTap: (id) sender;
- (void) OnSwitchChanged: (id) sender;
- (void) OnSliderChanged: (id) sender;
- (void) OnSegmentChanged: (id) sender;
- (void) OnLongTouch: (UILongPressGestureRecognizer *)gestureRecognizer;

@end
