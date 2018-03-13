#ifndef __SMF_IO_SPFILEIMPL_H__
#define __SMF_IO_SPFILEIMPL_H__

#include "Core/IO/SpFile.h"

#include <jni.h>

namespace Smf {

class SpFileImpl : public SpFile {
public:
    /**
     * Constructor taking path as parameter. Path can be a fullpath or
     * a Smartface URI. If path is a URI constructor should resolve fullpath
     * and keep both paths. Given original path doesn't change unless
     * file moved to another place.
     */
    SpFileImpl(const string path);

    SpFileImpl(jobject javaObject, jclass javaClass);

    /**
     * Destructor, free used resources
     */
    virtual ~SpFileImpl();

    /**
     * Getter for creation date of file/directory.
     *
     * @return File creation date as milliseconds
     */
    virtual long long getCreationDate() const;
    /**
     * Getter for modification date of file/directory
     *
     * @return File modification date as milliseconds
     */
    virtual long long getModifiedDate() const;
    /**
     * Returns extension of file
     *
     * @return  File extension
     */
    virtual string getExtension() const;
    /**
     * Getter for file name with extension
     * For path: /usr/test.txt returns test.txt
     *
     * @return  File name with extension
     */
    virtual string getName() const;
    /**
     * Creates new SpFile object points to parent directory of file/directory
     *
     * @return Parent directory
     */
    virtual SpFile* getParent() const;
    /**
     * Getter for path which given to constructor, if file moved
     * gives changed path
     *
     * @return Path of file
     */
    virtual string getPath() const;
    /**
     * Getter for actual path of file on filesystem
     *
     * @return Actual path of file
     */
    virtual string getActualPath() const;
    /**
     * Gets file size as bytes
     *
     * @return File size as Bytes
     */
    virtual int getSize() const;
    /**
     * Gets child files/directories according to given filters. Filters
     * are optional. If file name filter is empty; don't filter by name.
     * If file type is NONE don't filter by type.
     *
     * @param nameFilter    File name filter
     * @param typeFilter    File type filter
     * @return              File list
     */
    virtual vector<SpFile*> getFiles(const string nameFilter = "",
            const TYPE_FILTER typeFilter = TYPE_FILTER::NONE) const;

    /**
     * Checks if file/directory exists or not
     *
     * @return  true if file/directory exists, false otherwise
     */
    virtual bool exists() const;
    /**
     * Checks if path points to a directory
     *
     * @return  true if path is directory, false otherwise
     */
    virtual bool isDirectory() const;
    /**
     * Checks if path points to a file
     *
     * @return  true if path points a file, false otherwise
     */
    virtual bool isFile() const;
    /**
     * Returns file writable status by checking file type. If file is
     * a resource or asset file result is false, otherwise true
     *
     * @return  File writable status
     */
    virtual bool isWritable() const;

    /**
     * Copy file to given destination.
     *
     * @param destinationPath   Destination path
     * @return                  true if copied, false otherwise
     */
    virtual bool copy(const string destinationPath) const;
    /**
     * Remove file/directory in the path
     *
     * @param recursive Remove subdirectories too -if this is a directory
     * @return          true if deleted, false otherwise
     */
    virtual bool remove(bool recursive = false);
    /**
     * Move file/directory to destination path if move operation
     * is successful changes paths
     *
     * @param destinationPath Destination path
     * @return  true if moved, false otherwise
     */
    virtual bool move(const string destinationPath);
    /**
     * Rename file/directory, if rename operation is successful
     * changes paths
     *
     * @param newName   New name
     * @return          true if renamed, false otherwise
     */
    virtual bool rename(const string newName);

    /**
     * Create directory in path or path's parent directories
     * according to parameter
     *
     * @param justParents   Optional, create just parent directories of path,
     *                      default false
     * @return              true if created, false otherwise
     */
    virtual bool createDirectory(bool justParents = false);
    /**
     * Create file in path and parents if createParents given true
     *
     * @param createParents Create parent directories
     * @return              true if created, false otherwise
     */
    virtual bool createFile(bool createParents);

    // OLD FUNCTIONALITIES WRITTEN IN CORE

    /**
     * Checks file path URI
     *
     * @return true if starts with "assets://", false otherwise
     */
    virtual bool isAsset() const;
    /**
     * Checks file path URI
     *
     * @return true if starts with "images://", false otherwise
     */
    virtual bool isResource() const;

private:
    jobject javaObject;
    jclass javaClass;
};

} // namespace Smf

#endif
