//
//  ArabicConverter.h
//  CreationHD_Arabic
//
//  Created by Accorpa LLC on 3/20/12.
//  Copyright (c) 2012 Accorpa. All rights reserved.
//
/*
 * Arabic Converter v1.0
 *
 * Copyright 2012, Accorpa, LLC
 * Licensed under GPL Version 3 License
 * http://www.gnu.org/licenses/gpl-3.0.txt
 *
 * download: https://github.com/Accorpa/Arabic-Converter-From-and-To-Arabic-Presentation-Forms-B
 */

#import <Foundation/Foundation.h>

@interface ArabicConverter : NSObject

-(NSString*)convertArabic:(NSString*)normal;
-(NSString*)convertArabicBack:(NSString*)apfb;

@end
