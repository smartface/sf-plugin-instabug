#ifdef TARGET_PLATFORM_IOS
#import <Foundation/Foundation.h>
@interface NSInvocation (Sprat)
-(void)invokeOnMainThreadWaitUntilDone:(BOOL)wait;
+(NSInvocation *)invocationWithTarget:(id)target selector:(SEL)aSelector withArg:(void *)argument;
@end
#endif