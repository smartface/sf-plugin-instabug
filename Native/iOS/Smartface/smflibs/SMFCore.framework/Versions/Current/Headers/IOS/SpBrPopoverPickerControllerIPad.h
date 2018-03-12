//
//  SpBrPopoverPickerControllerIPad.h
//  SpratIOS
//
//  Created by ugur on 30 Jan 2012.
//  Copyright 2011 Smartface. All rights reserved.
//

#import <UIKit/UIKit.h>

class SpBrString;

@protocol PopoverPickerDelegate

-(void)itemSelected:(NSInteger)index;

@end

@interface SpBrPopoverPickerControllerIPad : UITableViewController {
    SpBrString *column;
    NSMutableArray* comboList;
}

@property (nonatomic, assign) id<PopoverPickerDelegate> delegate;

- (id) initWithStyle:(UITableViewStyle)style : (NSMutableArray*) list;

@end
