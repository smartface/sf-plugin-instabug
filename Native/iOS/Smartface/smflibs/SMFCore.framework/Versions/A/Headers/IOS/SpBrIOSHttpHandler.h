//
//  SpBrIOSHttpHandler.h
//  SpratLib_B
//
//  Created by Antti Panula on 10.8.2011 -- 2.
//  Copyright 2011 Bivium. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Core/SpEventGroup.h"

@interface SpBrIOSHttpHandler : NSObject {
    NSData *dataContents;
    SpEventGroup* eventGroup;
    SpBrParcelable* dstObj;
    SpBrString* dstParam;
    int timeout;
}

@property (assign) int timeout;

- (void)free;
- (NSData*)getURLData:(NSURL*)URL: (SpBrString*)requestBody :(std::vector<char *> *)requestHeaders setReturnHeader:(std::vector<char *> *) returnHeader methodType:(THttpMethod) type;
- (void)doRequest:(NSURL *)URL async:(bool)async method:(SpBrString*)method eventGroup:(SpEventGroup *)eventGroup destObj:(SpBrParcelable*)destinationObject destParam:(SpBrString*)destinationParameter;
- (void)cancelRequests;
- (void)setDataContents:(NSData **)data;
- (NSData *)dataContents;

@end
