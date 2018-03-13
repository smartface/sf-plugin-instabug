//
//  SpProjectJson.h
//  SpratIOS
//
//  Created by M.Halit Karakis on 7/14/16.
//  Copyright © 2016 Smartface. All rights reserved.
//

#ifndef SpProjectJson_h
#define SpProjectJson_h

#define PROJECTJSON_FILENAME "project.json"

#include "SpDataSource.h"

#include <exception>
#include <Poco/JSON/Object.h>

using Poco::JSON::Object;

/**
 *  Every project should have a project.json file. This class designed to get and set project.json
 *  informations as JSON object in place of reading/writing from file. Everytime an instance created
 *  and initialized it reads project.json and parses it. So having one instance of this object
 *  in SpApplication is good idea. But multiple instances is also ok.
 */
class ProjectJson {
public:
    /**
     *  Constructor
     *
     *  @param encrypted Indicates if application resources are encrypted or not
     *  @param cipherKey Cipher key to be used to decrypt if resources are encrypted
     */
    ProjectJson(bool encrypted, std::string cipherKey = "");
    /**
     *  Destructor, removes data source if created
     */
    virtual ~ProjectJson();

    /**
     *  Reads project.json file and parse it as JSON object. If there is an error parsing
     *  project.json it will throw exception.
     */
    void init();

    /**
     *  Returns parsed JSON object of project.json. If init is not called it will return an
     *  empty JSON object.
     *
     *  return Object::Ptr Current project json object in instance, if not initialized empty object
     */
    Object::Ptr get();
    /**
     *  Sets project.json object. This function will change project.json in memory. If it is
     *  needed to save changes to project.json file Save() should be called
     *
     *  param newProjectJsonObj New project json object
     */
    void set(Object::Ptr newProjectJsonObj);

    /**
     *  Saves JSON object to file.
     *
     *  notes: it doesn't have any stringify rules, so most probably it will write one line json
     *         but that feature can be added, need to check Poco documentations
     */
    void Save();
private:
    void openProjectJsonFile();

    Object::Ptr projectJsonObj;
    SpDataSource* dataSource;

    bool encrypted;
    std::string masterKey;
};

class ProjectJsonException : public std::exception {
public:
    ProjectJsonException(std::string message = "There is a problem with project.json file") {
        this->message = message;
    }

    virtual const char* what() const throw() {
        return "message";
    }
private:
    std::string message;
};

#endif /* SpProjectJson_h */
