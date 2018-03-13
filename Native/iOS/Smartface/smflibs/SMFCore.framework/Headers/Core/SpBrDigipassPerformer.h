/*
 * SpBrDigipassPerformer.h
 *
 *  Created on: 30 Nov 2011
 *      Author: ugur.kilic
 */

#ifndef SPBRDIGIPASSPERFORMER_H_
#define SPBRDIGIPASSPERFORMER_H_

#include "SpBrDigipassPerformer.h"
#include "SpDefs.h"
#include "SPDigipass/DP4Capi.h"

#ifdef TARGET_PLATFORM_ANDROID
#include <jni.h>
#endif

#define DPFile                          "dppr.bin"

#define DPEVENT_SUCCESS					0
#define DPEVENT_WEAK_PIN_ERROR			1
#define DPEVENT_GENERIC_ERROR			2
#define DPEVENT_INVALID_PIN_ERROR		3
#define DPEVENT_ACTIVATION_REQUIRED		4
#define DPEVENT_REACTIVATION_REQUIRED	5

class SpBrString;

class SpBrDigipassPerformer {
public:
	SpBrDigipassPerformer();
	~SpBrDigipassPerformer();

public:
    int Activate(vds_ascii *i_szXFAD, vds_ascii *i_szCHS, vds_ascii *szPWD, vds_byte *o_bSV, vds_byte *io_bDV);
    int CheckPin(vds_byte *i_bXStaticVector, vds_byte *io_bXDynamicVector, vds_ascii *i_szPWDEntered);
    int ChangePIN(vds_byte *io_bXStaticVector, vds_byte *io_bXDynamicVector, vds_ascii *i_szOldPWD, vds_ascii *i_szNewPWD);
    int GenerateOTP(vds_byte *i_bXStaticVector, vds_byte *io_bXDynamicVector, vds_ascii *o_szResponse, vds_ascii *o_szRHC, vds_ascii* aPin, vds_int32 timeShift);
    int GenerateSignature(vds_byte *i_bXStaticVector, vds_byte *io_bXDynamicVector, vds_ascii iChallengeList[8][LNG_DTF_MAX], vds_ascii *o_aSignature, vds_ascii *o_aSigConfCode, vds_int32 timeShift);
    int GetInfo(vds_byte *i_bXStaticVector, vds_byte *io_bXDynamicVector, vds_ascii *seriNo, vds_ascii *counter1, vds_ascii *counter2, vds_ascii *gmtTime);
    int FormUrl(vds_byte *i_bXStaticVector, vds_byte *io_bXDynamicVector, vds_byte * i_bDataIn, vds_ascii* aUrl, vds_int32 timeShift, vds_ascii* aEncryptedUrlResult);
#ifdef TARGET_PLATFORM_ANDROID
    void SetJavaArrays(vds_byte *staticVector, vds_byte *dynamicVector);
    void ReadJavaArrays(vds_byte *staticVector, vds_byte *dynamicVector);
    int ReadJavaResultCode();
#endif

    int GetNewShift(SpBrString *serverTime);
    SpBrString* CalculateUpdateDate(SpBrString *dateIn);
private:
    int DigitsToBytes(vds_ascii *Digits, vds_byte *Bytes, vds_int32 Number);
#ifdef TARGET_PLATFORM_ANDROID
    jobject androidDigipassManager;
    jclass clazzDigipassManager;

    void UpdateDigipassManager();
#endif

private:
    vds_ascii szDVKey[32 + 1];
    int iret;
};

#endif /* SPBRDIGIPASSPERFORMER_H_ */
