/*
 * SpApplication.h
 *
 *  Created on: 27 Tem 2011
 *      Author: ugur
 */

#ifndef SPAPPLICATION_H_
#define SPAPPLICATION_H_

#include <vector>
#include <map>
#include <string>

#include "SpBrParcelable.h"
#include "SpDefs.h"
#include "SpPlayerParameters.h"
#include "SpProjectJson.h"
#include "Core/fast_array.h"

class SpContext;
class SpBrBase;
// Main application object, has baseData which holds object lists
// And it's also an action performer, used by Actions and Events
//
extern FastArray* application_properties;

class SpApplication: public SpBrParcelable {
public:
	SpApplication(SpContext* context);
    SpApplication(SpApplication* objectToCopy);
	virtual ~SpApplication();

public:
    /**
     * Several checks on startup.
     * Also Smartface Data Source is created here.
     */
    bool CheckConfig();
    void CreateSplashDummies(SpPlayerParameters *playerParameters);
    void DoLoadSplash();
    
	/**
	 * - create resourcemanager
	 * - parse all component
	 *
	 */
	void Initialize();

	/**
	 * Called by initialize after splash has been displayed to finish initialization.
	 */
	void InitializeAfterSplash();

    void LoadPreLibs();
	void LoadGlobalJS();

	/**
	 * make free using applicaiton resources after update
	 */
	void FreeResources();
    
    void Parse(Object::Ptr);
    virtual void firedEventOnThis(int eventID, int eventCode);
    void CheckForApplicationStartEvents();
    
    shared_ptr<ProjectJson> getProjectJson();
    
    bool AllowInterfaceOrientation(TApplicationAllowedOrientation orientation);
    
    std::vector<int> GetEventCodes();
    bool HasOnGlobalError();

public:
	SpContext* context;
    SpPlayerParameters *playerParameters;

    /**
     * 3DES master key for encrption for resource files
     */
    SpBrString *config3DESMasterKey;
    SpBrString *config3DESInitVector;
            
    static SpBrBase* GetBase();
    
private:
    /**
     * Application's verified name
     */
    SpBrString *applicationNameConfig;

    
    int configFileVersion;
    /**
     *  Project json object of application
     */
    shared_ptr<ProjectJson> projectJson;

public:
    bool hasOnGlobalError;
	SpBrBase* splashDummyBase;
	SpApplication* splashDummyApp;
    int debugAlertTag;
};

#endif /* SPAPPLICATION_H_ */
