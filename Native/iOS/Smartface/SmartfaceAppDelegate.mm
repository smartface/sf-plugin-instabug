//
//  SmartfaceAppDelegate.h
//  Smartface
//
//  Copyright 2011 Smartface. All rights reserved.
//

#import <objc/runtime.h>

#import "SmartfaceAppDelegate.h"
#import <JavaScriptCore/JavaScriptCore.h>
#import <iOSPlayer/inc/SMFiOSPlayer.h>

// Nativeface
#import <Nativeface/Nativeface.h>

// SMFNative
#import <SMFNative/SMFNative.h>

// Smartface-Objects
#import "SMFApplication.h"

@implementation SmartfaceAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    [[SMFiOSPlayer SMFGetPlayer] SMFRun];
    
    //Accept push notification when app is not open
    NSDictionary *remoteNotif = [launchOptions objectForKey: UIApplicationLaunchOptionsRemoteNotificationKey];
    if (remoteNotif) {
        [[SMFiOSPlayer SMFGetPlayer] SMFHandleRemoteNotification:application andDict:remoteNotif];
    }
    // Handle launching from a notification
    UILocalNotification *locationNotification = [launchOptions objectForKey:UIApplicationLaunchOptionsLocalNotificationKey];
    if (locationNotification) {
        [[SMFiOSPlayer SMFGetPlayer] SMFReceiveNotification:locationNotification];
    }
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    /*
     Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call r SMS message) or when the user quits the application and it begins the transition to the background state.
     Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
     */
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    [[SMFiOSPlayer SMFGetPlayer] SMFAppEnteredBackground];
    /*
     Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
     If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
     */
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    [[SMFiOSPlayer SMFGetPlayer] SMFAppCameFromBackground];
    /*
     Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
     */
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    /*
     Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
     */
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    [[SMFiOSPlayer SMFGetPlayer] SMFAppWillTerminate];
    /*
     Called when the application is about to terminate.
     Save data if appropriate.
     See also applicationDidEnterBackground:.
     */
}

- (BOOL)application:(UIApplication *)application handleOpenURL:(NSURL *)url
{
    if (!url) {
        return NO;
    } else {
        NSString *urlStr = [url description];
        if([urlStr rangeOfString:@"://"].location == NSNotFound){
            NSData *data = [urlStr dataUsingEncoding:NSUTF8StringEncoding];
            id json = [NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
            [[SMFiOSPlayer SMFGetPlayer] SMFHandleRemoteNotification:application andDict:json];
        }
        
        if (![[SMFiOSPlayer SMFGetPlayer] SMFIsCameFromBack]) {
            [[SMFiOSPlayer SMFGetPlayer] SMFRun];
        }
        [[SMFiOSPlayer SMFGetPlayer] SMFHandleUrlAppCall:url];
        return YES;
    }
}

- (void)application:(UIApplication *)application didRegisterUserNotificationSettings:(UIUserNotificationSettings *)notificationSettings
{
    [[SMFiOSPlayer SMFGetPlayer] SMFRegisterUserNotificationSettings:notificationSettings];
}

- (void)application:(UIApplication*)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData*)deviceToken
{
    [[SMFiOSPlayer SMFGetPlayer] SMFRegisteredNotification:deviceToken andError:nil];
}

- (void)application:(UIApplication*)application didFailToRegisterForRemoteNotificationsWithError:(NSError*)error
{
    [[SMFiOSPlayer SMFGetPlayer] SMFRegisteredNotification:nil andError:error];
}

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo
{
    [[SMFiOSPlayer SMFGetPlayer] SMFHandleRemoteNotification:application andDict:userInfo];
}

- (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification
{
    [[SMFiOSPlayer SMFGetPlayer] SMFReceiveNotification:notification];
}

- (void)willSetCustomPluginsOnContext:(JSContext*)context
{
    
    
    /*
     
     1. Register plugin's class, write the following line here:
     context[@"MyPlugin"] = [MyPlugin class]; //now JavaScript understands MyPlugin class
     
     2. Create plugin's objects for JavaScript to call any Objective-C function from JavaScript:
     Option 1: Create plugin's objects for JavaScript in Objective-C, write the following 2 lines here:
     context[@"myPluginObject1"] = [MyPlugin new];
     context[@"myPluginObject2"] = [MyPlugin new]; //Now you can use myPluginObject1 and myPluginObject2 in JavaScript
     
     Option 2: OR Create plugin's objects in JavaScript itself:
     First you need to implement init function inside MyPlugin class, write it in the JSExport protocol, then you can write the following 2 lines in JavaScript:
     MyPlugin myPluginObject1 = new MyPlugin(); //this will call the init function of your Objective-C Plugin
     MyPlugin myPluginObject2 = new MyPlugin(); //Now you can use myPluginObject1 and myPluginObject2 in JavaScript
     
     3. Call-back JavaScript from Objective-C:
     In JavaScript, write the following line:
     myPluginObject1.doSomethingWithCallBack(function(parameter){
     //do whatever you want in JavaScript
     });
     In Objective-C:
     - (void) doSomethingWithCallBack:(JSValue*)callBackJSValue {
     //do something
     [callBackJSValue callWithArguments:@[@"Parameter"]];
     }
     
     */
    
    // Nativeface
    [NFScriptingSupport createContextToVirtualMachine:[context virtualMachine] withContextForSupport:context];
    
    // Smartface-Objects
    context[@"SMFApplication"] = [SMFApplication class];
    
    // SMFNative
    [Protocols setContext:context];
}

- (void)dealloc
{
    [super dealloc];
}

@end
