/*
 * SpKobilManager.h
 *
 *  Created on: 30 Nov 2011
 *      Author: ugur.kilic
 */

#ifndef SPKOBILMANAGER_H_
#define SPKOBILMANAGER_H_

#include "SpDefs.h"
#include "SpBrKobilPerformer.h"

class SpContext;

class SpKobilManager {
public:
	SpKobilManager(SpContext *aContext);
	~SpKobilManager();

    bool DoActivation(SpBrString *aActivationCode, SpBrString *aPin, bool &aPinIsWeak);
    bool VerifyPIN(SpBrString *aPin, TKobilStatus &aStatus);
    SpBrString* GetNextOTP(SpBrString *aPin, TKobilStatus &aStatus);
    bool ChangePIN(SpBrString *oldPin, SpBrString *newPin, TKobilStatus &aStatus, bool &aPinIsWeak);
    bool IsWeakPin(SpBrString *aPin);
    bool VerifyActivationCode(SpBrString *aActivationCode);
    bool IsActivated();
private:
	void DeleteData();
    int GetRemainingAttempts();
    void SetRemainingAttempts(int count);

private:
    SpBrKobilPerformer *performer;
    SpContext *context;

    bool result;
    bool lockNext;

};

#endif /* SPKOBILMANAGER_H_ */
