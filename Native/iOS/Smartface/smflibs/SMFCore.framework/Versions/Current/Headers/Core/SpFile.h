/*
 * SpFile.h
 *
 *  Created on: Apr 26, 2014
 *      Author: adem
 */

#ifndef SPFILE_H_
#define SPFILE_H_

#include "SpBrString.h"
#include "SpBrBase.h"
#include "SpContext.h"
#include "SpDefs.h"
#include "SpDefs.h"
#include <vector>
#include <string>
#include "SpJsEngine/Core/SpJsEngine.h"

class SpFile
{
private:
	SpBrString* fullpath;
    SpBrString *inBundlePathIOS;
	SpBrBase* base;
	void init(SpBrBase *base,const char* fullpath);
	static std::string resourcePath;
    static std::string assetPath;
    
    static bool ExistsInAssets(SpBrBase* base, const char* filename);
    static bool ExistsInResources(SpBrBase* base, const char* filename);
    
    static bool IsFilenameResource(const char* filename);
    static bool IsFilenameAsset(const char* filename);
   	#ifdef TARGET_PLATFORM_ANDROID
    static bool CallAndroidFileExists(int existsIn, const char* filename);
    static char* ReadFileNative(SpBrBase* base,int existsIn, const char* filename, int &len);
    #endif
public:
    static int getScriptStat(SpBrBase* base, const char* innerPath);
    static char* ReadFileInAsset(SpBrBase* base, const char* filename, int &length);
    static char* ReadFileInResource(SpBrBase* base, const char* filename, int &length);
    static std::string ResourcePath();
    static std::string AssetPath();
	SpFile(SpBrBase *base,SpBrString* fullpath);
	SpFile(SpBrBase *base,const char* fullpath);
    /**
     * Destructor
     */
	virtual ~SpFile();
	bool IsFile();
	bool IsDirectory();
	bool IsWritable();
    bool IsResource();
    bool IsAsset();
    bool CanOpenAsFILE();
    bool drawableCheck(std::string name);
	bool Exist();
	static bool Exist(SpBrString* parent,SpBrString* filename);
	static bool Exist(SpBrString* fullpath);
	static bool Exist(const char* fullpath);
	std::vector<SpFile*> GetFiles();
	std::string GetName();
	std::string GetPath();
    SpBrString* GetInsiderPath();
	std::string GetExtension();
	SpFile* GetParent();
	long long GetSize();
	long long GetCreationDate();
	long long GetModifiedDate();
	bool CopyTo(SpFile* file);
    bool CopyTo(const char* file);
	bool MoveTo(SpFile* file);
    bool MoveTo(const char* file);
	bool CreateFile(bool createParents);
	bool CreateDirectory(bool createParents);
	bool Rename(const char* newName);
	bool Delete();
	bool DeleteAllRecursively();
	SpBrBase* GetBase();
};

#endif /* SPFILE_H_ */
