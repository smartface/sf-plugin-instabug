#import <UIKit/UIKit.h>

#import <JavaScriptCore/JavaScriptCore.h>

@protocol CloudEmulatorDelegate <NSObject>

- (void) clearDone;
- (void) invalidProtocolVersionWithEmulatorVersion:(NSString*)emulatorVersion andDispatcherVersion:(NSString*)dispatcherVersion;
- (void) filesRecieved:(uint8_t*) bytes : (int) byteLength;
- (void) chunkReceived:(uint8_t*)chunk withSize:(int)size withStatus:(BOOL)isFinal withOffset:(int)offset;
- (void) fileInfoReceived:(int)message;
- (void) handleError:(NSString*) errorMessage;
- (void) timeOutException;
- (void) setEmulatorProjectName:(NSString*) projectName;
- (void) saveEmulatorUrlToUserDefaults:(NSString*) url;
- (void) resetTimeout;
- (void) setToDeleteFileList:(NSArray*)fileList;
- (void) deleteFiles;

@end


__attribute__ ((visibility ("default"))) @protocol SMFiOSPlayerInterface <NSObject>
-(void) SMFRun;
-(void) SMFClean;
-(void) SMFAppWillTerminate;
-(void) SMFAppEnteredBackground;
-(void) SMFAppCameFromBackground;
-(void) SMFReceiveNotification :(UILocalNotification*)notification;
-(void) SMFRegisteredNotification:(NSData *)token andError:(NSError *)error;
-(void) SMFRegisterUserNotificationSettings:(UIUserNotificationSettings *)settings;
-(void) SMFSetRemoteTempDict:(NSDictionary *)dictionary;
-(void) SMFHandleRemoteNotification:(UIApplication *)application andDict:(NSDictionary *)dict;
-(void) SMFHandleUrlAppCall:(NSURL *)url;
-(void) SMFSetAppCallUrl:(NSURL *)url;
-(BOOL) SMFIsCameFromBack;
-(void) SMFLoadCustomPluginIdentifier:(const char *)definitonString andDefinition:(const JSClassDefinition *)classDefinition withObject:(void **)privateObject;
-(void) SMFRunJavaScriptSmartface:(JSObjectRef)object :(JSObjectRef)thisObject :(size_t)argumentCount :(const JSValueRef[])args;
-(JSGlobalContextRef) SMFGetGlobalContextRef;
-(void) SMFSetCloudEmulatorDelegate:(id)delegate;
-(void) SMFAppContextWillResetWith:(int)state;
@end

__attribute__ ((visibility ("default"))) @interface SMFiOSPlayer : NSObject{
}

+(id<SMFiOSPlayerInterface>) SMFGetPlayer;

@end
