//
//  NFScriptingSupport.h
//  Smartface
//
//
//

#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>

@protocol NFScriptingSupport <JSExport>

@required
JSExportAs(defineClass,
           + (id)defineClass:(NSString *)declaration instanceMembers:(JSValue *)instanceMembers staticMembers:(JSValue *)staticMembers);

JSExportAs(require,
           + (id)require:(NSString *)name);

JSExportAs(requireClass,
           + (id)requireClass:(NSString *)className);

JSExportAs(dispatch_async,
           + (void)dispatch_async:(id)queue block:(JSValue *)block);

JSExportAs(dispatch_get_global_queue,
           + (id)dispatch_get_global_queue:(dispatch_queue_priority_t)priority flags:(unsigned long)flags);
+ (id)dispatch_get_main_queue;

@optional
JSExportAs(log,
           + (void)log:(NSString *)format arguments:(NSArray *)arguments);
JSExportAs(dump,
           + (void)dump:(id)object);

@end

@interface NFScriptingSupport : NSObject <NFScriptingSupport>

+ (JSContext *)createContextToVirtualMachine:(JSVirtualMachine *)virtualMachine
                       withContextForSupport:(JSContext *)contextToSupport;

@end
