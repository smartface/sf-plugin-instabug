//
//  UIButton+Label.h
//  ugurTest
//
//  Created by ugur on 21.06.2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "SPBrUILabelIOS.h"

@class SPBrUILabeIOS;

@interface UIButton (Label)

@property (nonatomic, retain) SPBrUILabeIOS *imgButtonLabel;
@property (nonatomic, retain) UIColor *labelNormalColor;
@property (nonatomic, retain) UIColor *labelPressedColor;
@property (nonatomic, retain) UIColor *labelDisabledColor;

-(void)setLabel:(SPBrUILabeIOS *)label;
-(SPBrUILabeIOS *)imgButtonLabel;
-(void)setNormalTextColor:(UIColor *)color;
-(UIColor *)normalTextColor;
-(void)setPressedTextColor:(UIColor *)color;
-(UIColor *)pressedTextColor;
-(void)setDisabledTextColor:(UIColor *)color;
-(UIColor *)disabledTextColor;

@end

