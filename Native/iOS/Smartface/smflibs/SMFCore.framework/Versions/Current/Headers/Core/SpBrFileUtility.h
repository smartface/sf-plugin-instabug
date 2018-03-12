/*
 * SpBrFileUtility.h
 *
 *  Created on: Sep 14, 2011
 *      Author: ugurkilic
 */

#ifndef SPBRFILEUTILITY_H_
#define SPBRFILEUTILITY_H_

#include <vector>

#include "SpDefs.h"

class SpBrString;

class SpBrFileUtility {
public:
	SpBrFileUtility();
	virtual ~SpBrFileUtility();
    
public:
    /**
     * If the file is in MainBundle (APK), but not in Documents, copy it to Documents folder for reading
     */
    static void CheckDataSetFolder(SpBrString *dataTableFile);
    /**
     * check file is in document folder. it gets only file name, not full path
     */
    static bool FileExistsInDocumentFolder(const char * filename);
    static bool FileExists(const char *fullPath);
    static int FileLength(const char * filename);
    static bool IsFileImage(SpBrString *name);
    static SpBrString* GetFileNameFromPath(SpBrString *path);
    static char* GetFileExtension(SpBrString *path);
    /**
     * get file full path in docuemnt folder.
     *
     */
    static SpBrString* GetFilePathInDocumentFolder(const char *filename);
    static SpBrString* GetFilePathInBundle(const char *filename);
#ifdef TARGET_PLATFORM_IOS
    // Assets Development
    static SpBrString* GetFilePathInAssetsFolder(const char *filename, bool isBundle);
    
    static SpBrString* GetFullPath(const char *filename);
    /**
     * Returns the approprate image with respect to device type (phone-pad)
     */
    static void* GetImage(SpBrString *imageName);
#endif

    static SpBrString* GetFileSavingPath();
#ifdef TARGET_PLATFORM_IOS
    static void CheckAssetsFolder(bool isBundle);
    static SpBrString* GetAssetsFolderPath(bool isBundle);
    static bool CreateDirectoryAtPath(char *path);
#endif
    static SpBrString* GetBundlePath();
    
    static SpBrString* MoveToImageGallery(SpBrString* filePath,SpBrString* fileName);

    /**
     * remove all files in document folder.
     * because, application is reinstalling
     *
     * @author adem.cayir
     */
    static void ClearDocumentFolder();
    
#ifdef TARGET_PLATFORM_IOS
    /**
     * Remove all files below Documents/assets folder for emulator
     */
    static void ClearAssetsFolder();
#endif
    
    static void ClearFolder(IOApplicationPath folder);
    
    /**
     * Removes all temporary files (images saved from ws, camera etc. if not committed)
     */
    static void ClearTemporaryFiles();
    static void DeleteFileInPath(const char *filename);
    static void DeleteFile(const char *filename);
    static std::vector<SpBrString*> GetTableFiles(SpBrString* dataTableTame);
    static int RenameFile(const char *oldName, const char *newName);
    static int RenameFileInPath(const char *path, const char *oldName, const char *newName);
    static bool CopyFile(const char *oldPath, const char *newName);
#ifdef TARGET_PLATFORM_IOS
    static bool CopyFileToAssets(const char *oldPath, const char *toNewFile);
#endif
};

#endif /* SPBRFILEUTILITY_H_ */
