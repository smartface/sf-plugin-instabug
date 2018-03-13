/*
 * SpBrNuiBase.h
 *  Created on: Jun 22, 2011
 *      Author: sprat
 */

#ifndef SPBRNUIBASE_H_
#define SPBRNUIBASE_H_

#include "SpDefs.h"
#include "SpContext.h"
#include "SpBrBase.h"
#include "SpBrParcelable.h"
#include "SpDataSource.h"
#include "SpEventGroup.h"
#include "SpParserConstants.h"
#include "SpJsEngine/Core/SpJsEngine.h"
#ifdef TARGET_PLATFORM_ANDROID
#include <jni.h>
#endif


/**
 * letter of i means initial value. its means is not "integer"
 * this properties is used by reset function to reset all object properties
 *
 *
 */
class SpBrNuiBase: public SpBrParcelable {
public:
    SpContext *context;

    SpBrString *columnName;
    SpBrString* fontName;
    SpBrString* iFontName;
    SpBrString* finalFontName;
    SpBrString* accessibilityIdentifier;
    SpEventGroup *animationEvents;

public:
    void SetLeft(int l);
    void SetTop(int l);
    void SetWidth(int l);
    void SetHeight(int l);
    void SetAnchorTop(int l);
    void SetAnchorLeft(int l);
    void SetAnchorWidth(int l);
    void SetAnchorHeight(int l);
    int GetLeft();
    int GetTop();
    int GetWidth();
    int GetHeight();
    int GetLeftLast();
    int GetTopLast();
    int GetWidthLast();
    int GetHeightLast();
    SpBrString * GetImageFilePath(SpBrString * image);
    void SetElevation(float elevation);
    float GetElevation();
public:
    bool iIsLeftPerc, iIsTopPerc, iIsWidthPerc, iIsHeightPerc;
    int iLeftPerc, iTopPerc, iWidthPerc, iHeightPerc;
    int iLeft, iTop, iWidth, iHeight;
    bool isLeftPerc,isTopPerc,isWidthPerc,isHeightPerc;
    int leftPerc,topPerc,widthPerc,heightPerc;
    bool leftInitIsDp,topInitIsDp,iLeftInitIsDp,iTopInitIsDp;
    bool widthInitIsDp,heightInitIsDp,iHeightInitIsDp,iWidthInitIsDp;
    float iElevation, elevation;
private:
    int left,top,width,height;
    int leftAnchor,topAnchor,widthAnchor,heightAnchor;
public:
    // These are always calculated from screen and component sizes.
    int right,bottom;
public:
    int iVisible, visible;
    int iEnabled, enabled;
    int iBackgroundColor, backgroundColor;
    int iPixelEdge, pixelEdge;
    float iAlpha, alpha;
    TVerticalAlign iVerticalAlign, verticalAlign;
    THorizontalAlign iHorizontalAlign, horizontalAlign;
    int iHorizontalPadding, horizontalPadding;
    int iAnchor, anchor;

    int iBorderWidth, borderWidth;
    int iBordercolor, borderColor;    
    bool iAlwaysFront, alwaysFront;
    bool iBgTransparent, bgTransparent;
    bool iUnderline, underline;
    int iFontColor, fontColor;
    int iFontSize, fontSize,autosizedFontSize;
    GeometryValueTypes fontSizeType, iFontSizeType;
    int drawMode, drawPosition;
    int iDrawMode, iDrawPosition;
    TFontStyle iFontStyle, fontStyle;
    int repeatBoxRowIndex;
    bool iTouchEnabled, touchEnabled;
    bool lockAutoSize, lockAutoPosition;
    bool navBarHeightAdded;
    bool widthLockedForAutosizing, heightLockedForAutosizing;
    bool leftLockedForAutosizing, topLockedForAutosizing;
    bool parentTouchEnabled;
    bool doInvalidate;
    bool mainChildOfRepeatbox;
    bool isAttributedText;
    bool strikeThrough, iStrikeThrough;
    int containedRowIndex, containedGroupIndex, containedRowInGroupIndex;
    bool isOnScreen;
    
    // If an object is not visible while page is laoding, so (text) is not set.
    // And user changed the visibility of object to true, but Invalidate called with true parameter, so (text) not set again.
    // We will set this property to true if (text) ever set, if this is false (true) parameter of Invalidate will be ignored.
    bool isMainPropertyEverSet;
public:
#ifdef TARGET_PLATFORM_ANDROID
    jobject JniObjectRef;
    jweak weakHolder;
    /**
     * set actual view background color for android.
     *
     * it uses background color from SpBrNuiBase. so
     * it should be called from Invalide
     *
     * @author adem.cayir
     */
    void setBackgroundColor();
    /**
     * settext to android view.
     * it s different from SetText. SetText does both set base text and view text.
     * and, called from ChangeProperty action and DataSet.notify. so setTextToAndroidView
     * should be called from only text changing on actual android view.
     * for example, end of Invalidate.
     *
     * Invalide called from change property, so if changeproperty is run for setting text,
     * firstly SetText called, then Invalidate called.
     *
     * @author adem.cayir
     */
    void setTextToAndroidView(SpBrString *string);

    void SetOverScrollGlowColor(int color);
    int overScrollGlowColor;
    /**
     * Get text value from Android view.
     * Returns the text as it was given by the underlying native UI component.
     * This method is intended to retrieve free-form user input from components like text editors.
     *
     * TODO if core tries to get text of a object, it shouldnt be given view text. because, component cannot be visible or located
     * in active page. so, we should get minimum info from ui component. we always should use core values. I remove this function from
     * component.
     *
     * @author timo.kinnunen
     */
    SpBrString* GetTextFromAndroidView();
    /*
     * Only call on Java objects that implement AndroidUI.WithBackground.
     */
    void SetBackgroundToAndroid();
    void SetBackgroundToAndroid(int activeFillColorInt, int activeStrokeColorInt);
    /*
     * Only call on Java objects that implement AndroidUI.WithForeground.
     */
    void SetForegroundToAndroid(int pressedColorInt, jboolean multiLine = true,
			jboolean showScrollBar = false, jboolean autoLink = false,
			jboolean autoAdjustFontSize = false, int minFontSize = 10);
    /*
     * Only call on Java objects that implement AndroidUI.WithRefreshRate.
     */
    void SetRefreshToAndroid(int refreshRate);



    /*
     * Only call on Java objects that implement AndroidUI.WithEffect.
     */
    void SetEffectToAndroid(int effectType, int effectEase);

#elif defined TARGET_PLATFORM_IOS
    /*
     * 
     */
    bool SetFrameProperties(void *objToCopy = NULL);
    void RecreateIfNeeded(bool forceRecreation = false);
#endif
    bool hasTopAnchor();
    bool hasBottomAnchor();
    bool hasLeftAnchor();
    bool hasRightAnchor();
    
#ifdef TARGET_PLATFORM_IOS
    void *bridge;
    void *animator;    
    bool drawOverridden;
    SpBrNuiBase *activeChildInRepeatbox;
    bool requiresRecreation;
    bool gesturesAfterLoad;
#endif
    SpBrNuiBase *childInRepeatbox;
    SpBrNuiBase *originalObject;
public:
    SpBrNuiBase();
    SpBrNuiBase(SpBrBase* base, SpContext* context);
    SpBrNuiBase(SpBrNuiBase* objectToCopy);
    virtual ~SpBrNuiBase();
    
public:
#ifdef TARGET_PLATFORM_ANDROID
    void setGeometry();
    void CreateJavaView();
    void EnableEventInAndroid(int eventId);

    /*
    JNIEnv* SetAndroidUiElement(jint elementType, SpEventGroup* jniCallBack, SpBrString* key);
    JNIEnv* SetAndroidUiElement(jint elementType, SpEventGroup* jniCallBack);
    JNIEnv* SetAndroidUiElement(jint elementType);
    JNIEnv* SetAndroidUiElementWithKey(jint elementType, SpBrString* key);
    jobject CreateAndroidUiElement(JNIEnv* env, jint elementType, SpBrString* key);
    Only call on Java objects that implement AndroidUI.WithEvents.
    void EnableAllEventsInAndroid(SpEventGroup* jniCallBack);
    */

    jmethodID GetMethodID(JNIEnv* env, jclass clazz, const char* name, const char* sig);
    void CallVoidMethod(JNIEnv* env, jobject instance, jmethodID method, ...);
    jint CallIntMethod(JNIEnv* env, jobject instance, jmethodID method, ...);
    jobject CallObjectMethod(JNIEnv* env, jobject instance, jmethodID method, ...);
    jint ConvertColor(int color);
    jfloat ScalePixelSize(int size, float multiplier = 1.0);
#endif
    void Reset(bool invalidate = true);
    void ChangeObjectValue(SpBrString* targetAttribute, SpBrString* value);
    bool ChangeObjectValuev2(const char *attribute, SpJsValue valueRef);
    SpBrString* getObjectValue(SpBrString* targetAttribute);
    void UpdateNativeValue(const char *attribute);
    /*
     * this function must be called after this elements ui actions
     *
     * for example, changeobject("x", 190)
     *
     */
    virtual void Invalidate(bool skipMainProperty = false) {};
    void DynamicObjectCreated();
    virtual void SetFocus() {};
    void SetX(SpBrString *x);
    void SetY(SpBrString *y);
    void SetWidth(SpBrString *w, bool objects = true);
    void SetHeight(SpBrString *h, bool objects = true);    
    void SetContext(SpContext* context);
    SpContext* GetContext() const;
    virtual void DisplayFinishedTempFiles() {}
    int GetInitialWidthConstant();
    int GetInitialHeightConstant();
    bool HasAutoSizedParent();
    virtual void EnableNativeObject(bool value);
    virtual void EnableTouchNativeObject(bool value);
    virtual void ShowNativeObject(bool value);
    void EnableParentTouchNativeObject(bool value);
    void ShowTopNativeObject(bool value);
    void SetElementsRepeatboxRowIndex(int index);
    void ArrangeFontSize();
    virtual void SetStrikeThrough(bool strikeThru){};
    bool ViewExists();
    bool InLayout();
    bool ParentAutosized();
    virtual void AdjustView() {};
#ifdef TARGET_PLATFORM_IOS
    bool AddPluginView(SpJsObject childPluginView);
    int zIndexInSuper;
#endif
    
    /**
     * Performs the desired animation on object.
     * @param property The object's attribute to change animated
     * @param endValue Final value of the attribute
     * @param ease Animation ease
     * @param duration Animation duration
     * @param events Action events to run
     */
    virtual void Animate(SpBrString *property, SpBrString *endValue, TPageEffectEase ease, int duration, SpEventGroup *events);
    virtual void Animate(SpBrString *property, int revealCenterX, int revealCenterY, int from, int to, SpEventGroup *events);
public:
    /*
     * Creates native UI elements. Called when a page is opening.
     *
     * The implementation should not change any base class state by calling base class methods.
     *
     */
    virtual void Load() {};		// Is called when page is opening. Creates Native UI elements.
    virtual void Unload();  	// Is called when page is closing. Frees Native UI elements.
    void ReadGeometry(SpDataSource* datasource);
};

#endif /* SPBRNUIBASE_H_ */
