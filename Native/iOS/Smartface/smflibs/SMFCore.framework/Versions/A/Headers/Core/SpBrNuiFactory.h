/*
 * SpBrNuiFactory.h
 *
 *  Created on: Jun 22, 2011
 *      Author: umit
 */

#ifndef SPBRNUIFACTORY_H_
#define SPBRNUIFACTORY_H_

#include "SpBrParcelable.h"
#include "SpContext.h"
#include "SpDataSource.h"
#include "SpBrBase.h"
#include "SpApplication.h"

#include "TinyXML/tinyxml.h"
#include "TinyXML/tinystr.h"

 // ELEMENT_ID_IMAGEBUTTON Used client-side for Android
#define ELEMENT_ID_IMAGEBUTTON			-2
#define ELEMENT_ID_ACTION				0
#define ELEMENT_ID_APPLICATION			2
#define ELEMENT_ID_COMBOBOX				4
#define ELEMENT_ID_DATASET				5
#define ELEMENT_ID_DATASOURCE			6
#define ELEMENT_ID_EVENT				8
#define ELEMENT_ID_LABEL				10
#define ELEMENT_ID_PAGE					11
#define ELEMENT_ID_IMAGE				12
#define ELEMENT_ID_REPEATBOX			13
#define ELEMENT_ID_TABLE				15

//#define ELEMENT_ID_UPDATESTATUS			18
// update status is not exist anymore
#define ELEMENT_ID_VIDEO				19
#define ELEMENT_ID_MENU					21
#define ELEMENT_ID_MENUITEM				22
#define ELEMENT_ID_DEVICETABLEVIDEO		23
#define ELEMENT_ID_DEVICETABLEIMAGE		24
#define ELEMENT_ID_DEVICETABLESOUND		25
#define ELEMENT_ID_DEVICETABLECONTACT	26
#define ELEMENT_ID_RECTANGLE			27
#define ELEMENT_ID_DEVICETABLECBM		29
#define ELEMENT_ID_DEVICETABLEAPP		30
#define ELEMENT_ID_CAMERA				31 // Deprecated in SMF 3.0.
#define ELEMENT_ID_GPRSSTATUS			32
#define ELEMENT_ID_COVERAGESTATUS		33
#define ELEMENT_ID_BATTERYSTATUS		34
#define ELEMENT_ID_DEVICETABLEINFO		35
#define ELEMENT_ID_WEBVIEW 				36

#define ELEMENT_ID_CONTAINER			38
#define ELEMENT_ID_SCROLLVIEW           39
#define ELEMENT_ID_SWITCHBUTTON         40
#define ELEMENT_ID_TABBAR               41



#define ELEMENT_ID_MAPVIEW 				45
#define ELEMENT_ID_ACTIVITY_INDICATOR   47
#define ELEMENT_ID_FUNCTION             49
#define ELEMENT_ID_SLIDER               50
#define ELEMENT_ID_DEVICETABLECONTACT2  51

#define ELEMENT_ID_INAPP_TABLE          53
#define ELEMENT_ID_LINE_CHART	        54
#define ELEMENT_ID_GESTURE				55
#define ELEMENT_ID_CANVAS               56
#define ELEMENT_ID_SEARCHBAR            57
#define ELEMENT_ID_SLIDERDRAWER         58

#define ELEMENT_ID_SMFIMAGE             200
#define ELEMENT_ID_MAPPIN               201
#define ELEMENT_ID_REPEATBOXSWIPEITEM   202
#define ELEMENT_ID_DATAPARAMETER        203
#define ELEMENT_ID_QUICKLOOK            206

#define ELEMENT_ID_EVENTARGUMENTDUMMY   567
#define ELEMENT_ID_FILE				   	568
#define ELEMENT_ID_FILESTREAM			569
#define ELEMENT_ID_BEACONREGION			570
#define ELEMENT_ID_PERIPHERALMANAGER	571
#define ELEMENT_ID_LOCALNOTIFICATION	572
#define ELEMENT_ID_BLOB                 573
#define ELEMENT_ID_FORMDATA             574

#define ELEMENT_ID_DATABASE             600

#define ELEMENT_ID_PLUGIN_VIEW          10001

class SpBrNuiFactory {
	private:
		SpBrNuiFactory() { };
	public:
		enum TNuiClassIDs { NCIDTextView, NCIDMapView, NCIDButtonView, NCIDImageView, NCIDWebView };
	public:
        static SpBrParcelable* NewObject(int classID, SpContext* context, SpBrBase* base, SpApplication* app);
};

#endif /* SPBRNUIFACTORY_H_ */
