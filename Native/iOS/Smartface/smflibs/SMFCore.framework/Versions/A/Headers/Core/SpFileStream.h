/*
 * SpFileStream.h
 *
 *  Created on: Apr 26, 2014
 *      Author: adem
 */

#ifndef SPFILESTREAM_H_
#define SPFILESTREAM_H_

#include "IO/SpFile.h"
#include "SpBrString.h"
#include "SpBrBase.h"
#include "SpContext.h"
#include "SpDefs.h"
#include <vector>
#include <string>
#include "SpJsEngine/Core/SpJsEngine.h"

using Smf::SpFile;

class SpFileStream
{
private:
	SpFile* file;
	IOStreamType mode;
	bool isClosed;
	FILE* writeTo;
	FILE* readFrom;
    void init(SpBrBase *base,const char* fullpath,IOStreamType mode);
public:
    SpFileStream(SpBrBase *base,const char* fullpath,IOStreamType mode);
    SpFileStream(SpBrBase *base,SpBrString* fullpath,IOStreamType mode);
    SpFileStream(SpBrBase *base,SpFile* file,IOStreamType mode);
    /**
     * Destructor
     */
	virtual ~SpFileStream();
	bool Open();
	bool Close();
	bool IsClosed();
	bool IsWritable();
	SpBrString* ReadToEnd();
	bool WriteBytes(const char* value,int size);
	bool Write(const char* value);
	bool IsAppendMode();
	std::string GetName();
	std::string GetPath();
};

#endif /* SPFILESTREAM_H_ */
