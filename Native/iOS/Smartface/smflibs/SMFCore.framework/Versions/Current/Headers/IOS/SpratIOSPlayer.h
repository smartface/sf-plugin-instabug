//
//  SpratIOSPlayer.h
//  SpratIOS
//
//  Created by ugur on 10/10/11.
//  Copyright 2011 Bivium. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MediaPlayer/MediaPlayer.h>
#import <MessageUI/MessageUI.h>
#import <AVFoundation/AVFoundation.h>
#import <QuartzCore/QuartzCore.h>
#import <AudioToolbox/AudioToolbox.h>
#import <QuartzCore/CAAnimation.h>
#import <AddressBookUI/ABPeoplePickerNavigationController.h>
#import <AddressBookUI/ABNewPersonViewController.h>
#import <StoreKit/StoreKit.h>
#import <CoreTelephony/CTCarrier.h>
#import <CoreTelephony/CTTelephonyNetworkInfo.h>
#import <AssetsLibrary/AssetsLibrary.h>

#import "Core/SpApplication.h"
#import "SMFiOSPlayer.h"

#define KEventGroupSaveImage        1
#define KEventGroupPickGromGallery  2
#define KEventGroupCropImage        3
#define KEventGroupShare            4
#define KEventGroupTwitter          5

@class SpBrUIPopupMenuIOS;
class SpEventGroup;


@interface SpratIOSPlayer : NSObject <MFMessageComposeViewControllerDelegate, UINavigationControllerDelegate, AVAudioPlayerDelegate, UINavigationControllerDelegate, AVAudioPlayerDelegate, UIActionSheetDelegate, ABPeoplePickerNavigationControllerDelegate, ABNewPersonViewControllerDelegate, SKPaymentTransactionObserver,SMFiOSPlayerInterface
> {
    SpApplication *smartfaceApplication;
    UINavigationController *mainNavigationController;

    MPMoviePlayerController *moviePlayer;
    AVAudioPlayer *audioPlayer;
    NSTimer *progressUpdateTimer;
    MFMailComposeViewController *composer;
    NSString *twitterMessage;
    MFMessageComposeViewController *messageSender;
    SpEventGroup *notifierEvents;
    SpEventGroup *emulatorNotifierEvent;
    int otherMusicIsPlaying, soundInterrupted;
    BOOL firstPageOpened;
    std::vector<SpBrParcelable *> currentMenuItems;
    SpBrUIPopupMenuIOS *customPopover;
    UIPopoverController *popoverController;
    bool protectingBackgroundAdded;
    NSArray *_products;
    NSMutableArray *retrievingProducts;
    NSURL *appCallUrl;
    BOOL cameFromBack;
    BOOL contactPickerDetails;
    NSDictionary* remoteTempDic;
    std::map<int, SpEventGroup *> generalEventGroupMap;
}

@property (nonatomic, retain) UIWindow *window;
@property (nonatomic, retain) UINavigationController *mainNavigationController;
@property (readwrite) SpEventGroup *notifierEvents;
@property (readwrite) SpEventGroup *sesCheckUpdateEvent;
@property UIDeviceOrientation previousOrient;
@property UIDeviceOrientation currentOrientation;
@property BOOL curledDialogIsOpen;
@property BOOL searchBarIsOpen;
@property SpBrString *navbarBackground;
@property int navbarColor;
@property (nonatomic, retain) NSMutableArray *closingDialogArray;
@property BOOL queuedDialogFades;
@property (retain) NSArray *products;
@property (retain) UIView* splashView;
@property (nonatomic) BOOL isSplashOpened;
@property (nonatomic, getter = isMinimized) BOOL minimized;
@property (nonatomic, assign) NSInteger animatedDistanceForEditbox;
@property (nonatomic, retain) NSURL *appCallUrl;
@property BOOL cameFromBack;
@property (nonatomic, retain) NSMutableArray *assetArray;
@property (retain) NSDictionary* remoteTempDic;
@property (nonatomic, retain) UIPopoverController *popoverController;
@property (nonatomic, retain) id<CloudEmulatorDelegate> cloudDelegate;

+ (SpratIOSPlayer*) GetPlayer;
- (void) run;
- (void) clean;
- (void) appEnteredBackground;
- (void) appCameFromBackground;
- (void) appWillTerminate;
- (void) receiveNotification :(UILocalNotification*) notification;
- (void) receivePushNotification: (NSDictionary*) userInfo;
- (void) registeredNotification: (NSData*) deviceToken setNSError:(NSError*) error;
- (void) registerUserNotificationSettings:(UIUserNotificationSettings *)notificationSettings;
+ (CTTelephonyNetworkInfo *) networkInfo;
- (SpApplication *) GetApplication;
- (void) HandleUrlAppCall :(NSURL*) url;
- (void) HandleRemoteNotification: (UIApplication*) app dict:(NSDictionary*) userInfo;

- (void) SMFRun;
- (void) SMFAppWillTerminate;
- (void) SMFAppEnteredBackground;
- (void) SMFAppCameFromBackground;
- (void) SMFReceiveNotification :(UILocalNotification*)notification;
- (void) SMFRegisteredNotification:(NSData *)token andError:(NSError *)error;
- (void) SMFRegisterUserNotificationSettings:(UIUserNotificationSettings *)settings;
- (void) SMFSetRemoteTempDict:(NSDictionary *)dictionary;
- (void) SMFHandleRemoteNotification:(UIApplication *)application andDict:(NSDictionary *)dict;
- (void) SMFHandleUrlAppCall:(NSURL *)url;
- (void) SMFSetAppCallUrl:(NSURL *)url;
- (BOOL) SMFIsCameFromBack;
- (void) SMFLoadCustomPluginIdentifier:(const char *)definitonString andDefinition:(const SpJsClassDefinition *)classDefinition withObject:(void **)privateObject;
- (void) SMFRunJavaScriptSmartface:(SpJsObject)object :(SpJsObject)thisObject :(size_t)argumentCount :(const SpJsValue[])args;
-(JSGlobalContextRef) SMFGetGlobalContextRef;
-(void) SMFSetCloudEmulatorDelegate:(id)delegate;

@end

__attribute__ ((visibility ("default"))) void InstallUncaughtExceptionHandler();
