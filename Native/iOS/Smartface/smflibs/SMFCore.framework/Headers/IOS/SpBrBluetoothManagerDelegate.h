//
//  SpBrBluetoothManagerDelegate.h
//  Smartface.io
//
//  Created by ugur on 05.06.2014
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CLLocationManager.h>
#import <CoreBluetooth/CoreBluetooth.h>

#import "Core/SpJSCallbackGroup.h"

@interface SpBrBluetoothManagerDelegate : NSObject <CLLocationManagerDelegate, CBPeripheralManagerDelegate> {
    SpJSCallbackGroup *peripheralManagerUpdateCallback;
    CBPeripheralManager *peripheralManager;
}
@property SpJSCallbackGroup *peripheralManagerUpdateCallback;
@property (nonatomic, retain) CBPeripheralManager *peripheralManager;
@property bool isAdvertised;
@end
