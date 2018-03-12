/*
 * SpPlayerParameters.h
 *
 *  Created on: Oct 6, 2011
 *      Author: ugurkilic
 */

#ifndef SPPLAYERPARAMETERS_H_
#define SPPLAYERPARAMETERS_H_

#include "SpDefs.h"
class SpBrString;

class SpPlayerParameters {
public:
	SpPlayerParameters();
    SpPlayerParameters(SpPlayerParameters *playerParameters);
	virtual ~SpPlayerParameters();

public:
    void SetAppName(SpBrString *appname);
    void SetProjectVersion(SpBrString *projectversion);
    void SetUserUUID(SpBrString *uuid);
    void SetAllowedOrientations(unsigned int options);
    void SetAndroidInAppBillingPublicKey(SpBrString* publickey);
    void SetLicenceType(TLicenceType l);
    void SetMaxCacheSize(long long size);

    SpBrString* GetAppName();
    SpBrString* GetProjectVersion();
    SpBrString* GetUserUUID();
    unsigned int GetAllowedOrientations();
    SpBrString* GetAndroidInAppBillingPublicKey();
    TLicenceType GetLicenceType();
    long long GetMaxCacheSize();

private:
    SpBrString *appName;
    SpBrString *projectVersion;
    SpBrString *UserUUID;
    unsigned int allowedOrientations;
    SpBrString *androidInAppBillingPublicKey;
    TLicenceType licenceType;
    long long maxCacheDataSize;
};

#endif /* SPPLAYERPARAMETERS_H_ */
