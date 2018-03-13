//
//  ZXingObjcHelper.h
//  ZXingObjC-iOS
//
//  Created by Dogan Ekici on 20.10.2017.
//  Copyright © 2017 zxing. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "ZXingObjC.h"

@interface ZXingObjcHelper : NSObject

+ (void)applyOrientation:(ZXCapture *)capture;
+ (NSDictionary *)encodingString:(NSString *)string format:(ZXBarcodeFormat)format size:(CGSize)size;
+ (NSDictionary *)decodingImage:(UIImage *)image;

@end
