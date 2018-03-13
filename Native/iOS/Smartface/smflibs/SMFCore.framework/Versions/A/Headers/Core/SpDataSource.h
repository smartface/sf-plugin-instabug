/*
 * SpDataSource.h
 *
 *  Created on: Jul 22, 2011
 *      Author: antti
 */

#ifndef SPDATASOURCE_H_
#define SPDATASOURCE_H_

#include <vector>
#include <string>

#include "SpBrString.h"

class SpBrParcelable;

class SpDataSource {
private:
	/**
	 * to show list lenght 4 bytes or 2 bytes.
	 *
	 * default 2 bytes is used
	 *
	 */
	bool listlenght4bytes;
    bool boolsFixed;

public:
    SpDataSource(char* buffer, int length);
    SpDataSource(const char* filename);
    virtual ~SpDataSource();
    void CheckSize(int toAppend);
    int ReadInt(); 				//BE 4 bytes
    int ReadIntLe();            //LE 4 bytes;
    void ReadIntList(std::vector<int>& list);
    float ReadFloat();
    char ReadByte();			//Byte
    void ReadByteList(std::vector<char>& list);
    short ReadShort();            //BE 2 bytes
    short ReadShortLe();
    void ReadShortList(std::vector<short>& list);
    bool ReadBool(bool isFirst = false);
    void ReadBoolList(std::vector<bool>& list);
    char* ReadUTF();
    int ReadBytes(char *buf_ptr, int len);
    SpBrString* ReadString();
    SpBrString* ReadStringWithLeSize();
    void SkipString();
    void ReadStringList(std::vector<SpBrString*>& list);
    void SkipStringList();
    SpBrParcelable* ReadElement(std::vector<SpBrParcelable*> *objects);
    void ReadElementList(std::vector<SpBrParcelable*>& list, std::vector<SpBrParcelable*> *objects);
    void SkipElementList();
    void Seek(int off);
    bool BytesAvailable();
    void MarkStart();
    void MarkEnd();
    int GetPos();
    void MarkPos(int ind);
    void Move(int val);
    bool Eof();
    unsigned char GetByteAt(int index);

    void WriteInt(int value);
    void WriteShort(short value);
    void WriteFloat(float value);
    void WriteUTF(const char *value);
    void WriteBytes(const char *value,int offset=0,int length=-1);
    /**
     * it prints its data as hex string.
     * its purpose is only debugging
     */
    void PrintAsHex(const char *label=NULL);
    unsigned char* ReadUUTF();
    void WriteUUTF(unsigned char *value, int valLen);

    void SetDataBuffer(char **value, int len);
    bool Finalize(const char *newPath = NULL,int start=0,int len=-1, const char *accessMode = "wb");

    /**
     * copy current stream to a file
     *
     * @param fileName target file name
     */
    bool CopyTo(const char *filename);
    void DecryptWith3DES(const char *tripledeskey);
    void EncryptWith3DES(const char *tripledeskey);
public:
    const char *fileName;
    char* dataBuffer;
    int index;
    char byteRead;
    bool trackPos;
    int lastIndex;
    int length;
    int expandCount;
    int byteIndex;
};

#endif /* SPDATASOURCE_H_ */
