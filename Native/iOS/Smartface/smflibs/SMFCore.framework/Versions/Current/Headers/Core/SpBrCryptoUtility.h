/*
 * SpBrCryptoUtility.h
 *
 *  Created on: Sep 5, 2011
 *      Author: ugurkilic
 */

#ifndef SPBRCRYPTOUTILITY_H_
#define SPBRCRYPTOUTILITY_H_

#include "SpDefs.h"

#define MD5HexOutputLength  32
#define SHA1HexOutputLength 40

class SpBrString;

class SpBrCryptoUtility {
public:
	SpBrCryptoUtility();
	virtual ~SpBrCryptoUtility();

public:
    static SpBrString* GetSha(TShaType type, const char *data, int len);
    static SpBrString* GetMD5(const char *data, int len);
    static SpBrString* PerformTripleDes(CryptoMode mode, TBlockCipherMode blockCipherMode, TCryptoPaddingType paddingType, char *initializationVector, char *keyID, char *inputString, int inputLength, int &outputLength, bool inside = false);
    static SpBrString* GetRSAEncryptedString(const char *data, int len, int outputLen, int version);
    static SpBrString* PerformAES(CryptoMode mode, TBlockCipherMode blockCipherMode, TCryptoPaddingType paddingType, char *key, int keyLen, char *initializationVector, int ivLen, char *inputString, int inputLength, int &outputLength);
    static SpBrString* PerformRSA(CryptoMode mode, char* &E, char* &D, char* &N, bool reverse, SpBrString *&input, int inputLength, int &outputLength);

    static bool DESEncryptFile(const char* sourceFileName, const char* destFileName, const char* key);
    static bool DESDecryptFile(const char* sourceFileName, const char* destFileName, const char* key);

private:
    static SpBrString* GetDigest(const char *algorithm, const char *data, int len);
};

#endif /* SPBRCRYPTOUTILITY_H_ */
