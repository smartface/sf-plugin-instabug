/*
 * SpContext.h
 *
 *  Created on: Jun 30, 2011
 *      Author: umit
 */

#ifndef SPCONTEXT_H_
#define SPCONTEXT_H_

#include "SpDefs.h"
#include <string>
#include <map>

class SpApplication;
class SpBrString;

#ifdef TARGET_PLATFORM_IOS
// TODO: To be implemented.
#endif

#if defined(TARGET_PLATFORM_WINDOWS)
#include "pthread.h"
#include <windows.h>
#include <map>
#include <jni.h>
#elif defined(TARGET_PLATFORM_ANDROID)
#include <jni.h>
#include <map>
#include <pthread.h>

#endif

class SpBrBase;

class SpContext {
	private:
		static SpContext* instance;
#ifdef TARGET_PLATFORM_IOS
		// TODO: To be implemented.
#endif
#ifdef TARGET_PLATFORM_ANDROID
		JNIEnv* jniEnvironment;
		jobject callerJavaObject;
		char*   apkFilename;
		char* androidFileSavingPath;
		char* androidUnsecureFileSavingPath;
		JavaVM* jvm;
#ifdef TARGET_PLATFORM_WINDOWS
		// dont change this definition. it is begin used by plugins
		std::map<long,JNIEnv*> envs;
#else
		std::map<pthread_t,JNIEnv*> envs;
		pthread_mutex_t envsLock;
#endif

		std::map<std::string,jobject> classes;
#endif
	public:

    bool EmulatorZipFound;
#ifdef TARGET_PLATFORM_IOS
        SpContext();
        virtual ~SpContext();
#endif
#ifdef TARGET_PLATFORM_ANDROID
		SpContext(JNIEnv* env, jobject thiz, char* apkFn, JavaVM* jvm);
		virtual ~SpContext();
		std::map<pthread_t,JNIEnv*>* GetJNIEnvMap();
__attribute__ ((visibility ("default")))		JNIEnv* GetJniEnvironment();
		jobject GetCallerJavaObject() const;
		char* 	GetApkFilename() const;
		char* GetAndroidFileSavingPath() const;
		char* GetAndroidUnsecureFileSavingPath() const;
		JavaVM* GetJVM() const;
		/**
		 * it loads most used functions
		 */
__attribute__ ((visibility ("default")))		void SetJniEnvironment(JNIEnv* env);
		void SetClass(const char* name, jclass cls);
		jclass getClass(const char* name);
		static void CallAndroidAPI(const char *methodName, const char *methodSignature, ...);
		static jstring AsAndroidString(const char *s);
		static jstring AsAndroidString(SpBrString *s);
		static jint AsAndroidColor(int color);
#endif
__attribute__ ((visibility ("default"))) static SpContext* GetInstance();
__attribute__ ((visibility ("default"))) static void ClearInstance();
__attribute__ ((visibility ("default"))) static SpApplication* GetApplication();
public:
#ifdef TARGET_PLATFORM_ANDROID
		jmethodID JF_setPosition;
		jmethodID JF_setVisible;
		jmethodID JF_enableEvent;
		jmethodID JF_enableTouch;
		jmethodID JF_getTextValue;
		jmethodID JF_setBackground;
		jmethodID JF_setImages;
		jmethodID JF_setEffect;
		jmethodID JF_setForeground;
		jmethodID JF_setRefreshRate;
		jmethodID JF_setTextValue;
		jmethodID JF_animate;
		jmethodID JF_revealAnimate;
		jmethodID JS_setRepeatBoxItemProperties;
		jmethodID JS_notifyDataSetChanged;
		jmethodID JS_getWeaksObjectFromTag;
		jmethodID JF_setHtmlTextValue;
		jmethodID JF_setElevation;
		jmethodID JF_resetZ;
		jmethodID JF_setRippleEffectColor;
		jmethodID JF_setRippleEffectEnabled;
		jmethodID JF_setRippleEffectMask;
		jmethodID JF_setOverScrollGlowColor;
#endif
		int screenHeight;
		SpBrBase* BaseData();
		SpApplication* Application();
				void ClearDynamicJsClasses();
				
private:
		SpApplication* spApplication;

};

#endif /* SPCONTEXT_H_ */
