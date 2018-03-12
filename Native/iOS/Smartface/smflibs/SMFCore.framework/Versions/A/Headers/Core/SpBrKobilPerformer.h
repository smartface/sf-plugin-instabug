/*
 * SpBrKobilPerformer.h
 *
 *  Created on: 30 Nov 2011
 *      Author: ugur.kilic
 */

#ifndef SPBRKOBILPERFORMER_H_
#define SPBRKOBILPERFORMER_H_

#include "SpDefs.h"

#ifdef TARGET_PLATFORM_ANDROID
#include <jni.h>
#endif
#define KOBIL_MAX_ATTEMPTS  5

class SpBrString;

typedef enum {
    KSActive = 0,
    KSLocked,
    KSNotActive
} TKobilStatus;

class SpBrKobilPerformer {
public:
	SpBrKobilPerformer();
	~SpBrKobilPerformer();

public:
    int CheckPIN(SpBrString *pin, TKobilStatus &status);
    void WriteData(SpBrString *oldPin,SpBrString *pin);
    bool Activate(SpBrString *activationCode, SpBrString *pin);
    SpBrString* GetOTP(SpBrString *pin, TKobilStatus &status);
    bool IsAppActivated();
    void EraseData();
    int GetAttemptCount();
    void SetAttemptCount(int count);
    bool VerifyActivationCode(SpBrString *aActivationCode);

private:
    void *input;
#ifdef TARGET_PLATFORM_ANDROID
    jobject kobilJavaManager;
#endif
};

#endif /* SPBRKOBILPERFORMER_H_ */
