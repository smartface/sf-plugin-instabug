/*
 * SpBrUIDateTimePicker.h
 *
 *  Created on: Jul 10, 2012
 *      Author: ugur
 */

#import <UIKit/UIKit.h>

@interface SpBrUIDateTimePicker : UIPickerView <UIPickerViewDelegate, UIPickerViewDataSource> {
    int yearCount;
    BOOL isMonthYear;
    int selectedMonth;
    int selectedYear, minYear, maxYear, minMonth, maxMonth;

    int YEAR, MONTH, DAY;
}

@property (nonatomic, retain, readonly) NSDate *date;
@property (nonatomic, retain) NSDate *minDate;
@property (nonatomic, retain) NSDate *maxDate;
@property (nonatomic, retain) NSDate *currDate;

-(id)initWithFrame:(CGRect)frame:(NSDate *)mnDate :(NSDate *)mxDate :(NSDate *)cDate :(BOOL)mmyy;

@end
