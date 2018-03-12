//
//  ESpratViewController.h
//  Smartface
//
//  Created by Ugur Kilic on 31/05/15.
//  Copyright (c) 2014 Smartface. All rights reserved.
//

#import <UIKit/UIKit.h>

__attribute__ ((visibility ("default"))) @protocol ESpratViewControllerInterface <NSObject>

- (void)setStatusBarSetted:(BOOL)value;

@end

__attribute__ ((visibility ("default"))) @interface ESpratViewController : NSObject {

}

+(UIViewController<ESpratViewControllerInterface> *) SMFGetTopViewController;

@end
