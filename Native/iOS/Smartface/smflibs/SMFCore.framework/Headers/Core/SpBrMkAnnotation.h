//
//  SpBrMapAnnotation.h
//  SpratIOS
//
//  Created by Antti Panula on 24.11.2011 -- 4.
//  Copyright (c) 2011 Bivium. All rights reserved.
//
#import <MapKit/MapKit.h>
#import <Foundation/Foundation.h>

@interface SpBrMkAnnotation : NSObject <MKAnnotation>
{
	NSString *title;
	NSString *subtitle;
}

// Re-declare MKAnnotation's readonly property 'coordinate' to readwrite.
@property (nonatomic, readwrite, assign) CLLocationCoordinate2D coordinate;

@property (nonatomic, retain) NSString *title;
@property (nonatomic, retain) NSString *subtitle;
@property (assign) NSInteger dsetIndex;
@property (assign) BOOL isDraggable;
@property (assign) BOOL isAnimate;
@property (assign) BOOL isFirstShow;
@property (assign) BOOL vsb;
@property (nonatomic, retain) NSString* selImageUrl;
@property (nonatomic, retain) NSString* unSelImageUrl;

@end
