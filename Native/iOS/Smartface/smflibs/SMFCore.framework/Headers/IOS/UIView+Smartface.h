//
//  UIView+Smartface.h
//  UIView+Smartface
//
//  Created by Ugur Kilic on 16/01/2014.
//  Copyright 2014 Smartface. All rights reserved.

#import <UIKit/UIKit.h>

@interface UIView (Smartface)

-(void) touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event andSpEvent:(SpEventGroup *)spEvents endEditing:(BOOL)endEditing;
-(void) touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event andSpEvent:(SpEventGroup *)spEvents endEditing:(BOOL)endEditing;
-(void) touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event andSpEvent:(SpEventGroup *)spEvents;
-(void) touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event andSpEvent:(SpEventGroup *)spEvents;
-(void) touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event andSpEvent:(SpEventGroup *)spEvents;
-(void) setUserInteractionEnabledWithNumber:(NSNumber *)number;
-(void) addNativeSwipeGesture : (int) direction withTarget:(id)handleTarget;
-(void) addNativeTapGesture:(int)taps withTarget:(id)handleTarget;
-(void) addNativePinchGesture:(id)handleTarget;
-(void) removeSwipeGesture:(int)type;
-(void) removeTapGesture:(int)tapNumbers;
-(void) removePinchGesture;

-(void) handleGenericSwipe:(UISwipeGestureRecognizer *)recognizer withEvents:(SpEventGroup *)events;
-(void) handleGenericTap:(UISwipeGestureRecognizer *)recognizer withEvents:(SpEventGroup *)events;

@end