//
//  SMFApplication.m
//  Smartface
//
//  Created by Tolga Haliloğlu on 02/03/2017.
//
//


#include <arpa/inet.h>
#include <net/if.h>
#include <ifaddrs.h>
#include <net/if_dl.h>

// SMFCORE NEEDED
#ifdef SMARTFACE_PRODUCTION
    #import <iOSPlayer/inc/SMFiOSPlayer.h>
#else
    #import "SMFiOSPlayer.h"
#endif
// SMFCORE NEEDED

#import "SMFApplication.h"

static NSString *const DataCounterKeyWWANSent = @"WWANSent";
static NSString *const DataCounterKeyWWANReceived = @"WWANReceived";
static NSString *const DataCounterKeyWiFiSent = @"WiFiSent";
static NSString *const DataCounterKeyWiFiReceived = @"WiFiReceived";

@implementation SMFApplication

+(NSDictionary *)dataCounters
{
    
    struct ifaddrs *addrs;
    const struct ifaddrs *cursor;
    
    u_int32_t WiFiSent = 0;
    u_int32_t WiFiReceived = 0;
    u_int32_t WWANSent = 0;
    u_int32_t WWANReceived = 0;
    
    if (getifaddrs(&addrs) == 0)
    {
        cursor = addrs;
        while (cursor != NULL)
        {
            if (cursor->ifa_addr->sa_family == AF_LINK)
            {
#ifdef DEBUG
                const struct if_data *ifa_data = (struct if_data *)cursor->ifa_data;
                if(ifa_data != NULL)
                {
                    NSLog(@"Interface name %s: sent %tu received %tu",cursor->ifa_name,ifa_data->ifi_obytes,ifa_data->ifi_ibytes);
                }
#endif
                
                // name of interfaces:
                // en0 is WiFi
                // pdp_ip0 is WWAN
                NSString *name = [NSString stringWithFormat:@"%s",cursor->ifa_name];
                if ([name hasPrefix:@"en"])
                {
                    const struct if_data *ifa_data = (struct if_data *)cursor->ifa_data;
                    if(ifa_data != NULL)
                    {
                        WiFiSent += ifa_data->ifi_obytes;
                        WiFiReceived += ifa_data->ifi_ibytes;
                    }
                }
                
                if ([name hasPrefix:@"pdp_ip"])
                {
                    const struct if_data *ifa_data = (struct if_data *)cursor->ifa_data;
                    if(ifa_data != NULL)
                    {
                        WWANSent += ifa_data->ifi_obytes;
                        WWANReceived += ifa_data->ifi_ibytes;
                    }
                }
            }
            
            cursor = cursor->ifa_next;
        }
        
        freeifaddrs(addrs);
    }
    
    return @{DataCounterKeyWiFiSent:[NSNumber numberWithUnsignedInt:WiFiSent],
             DataCounterKeyWiFiReceived:[NSNumber numberWithUnsignedInt:WiFiReceived],
             DataCounterKeyWWANSent:[NSNumber numberWithUnsignedInt:WWANSent],
             DataCounterKeyWWANReceived:[NSNumber numberWithUnsignedInt:WWANReceived]};
}

+(void)call:(NSString *)uri
   withData:(NSDictionary *)data
withSuccessCallback:(JSValue *)onSuccess
withFailureCallback:(JSValue *)onFailure
{
    NSMutableString *url = [uri mutableCopy];
    [url appendString:@"?"];
    for (NSString *key in data) {
        [url appendString:key];
        [url appendString:@"="];
        [url appendString:[data objectForKey:key]];
        [url appendString:@"&"];
    }
    NSRange range = NSMakeRange([url length]-1,1);
    [url replaceCharactersInRange:range withString:@""];
    
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:url] options:@{} completionHandler:^(BOOL success) {
        if (success) {
            if (!([onSuccess isUndefined] || [onSuccess isNull])) {
                [onSuccess callWithArguments:nil];
            }
        } else {
            if (!([onFailure isUndefined] || [onFailure isNull])) {
                [onFailure callWithArguments:nil];
            }
        }
    }];
}

+(void)exit{
    exit(0);
}

+(void)restart{
    dispatch_async(dispatch_get_main_queue(), ^{
        [[SMFiOSPlayer SMFGetPlayer] SMFClean];
        [[SMFiOSPlayer SMFGetPlayer] SMFRun];
    });
}

@end
