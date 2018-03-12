#ifndef __SPDEFSIOS_H_
#define __SPDEFSIOS_H_

#define KMaxRuntimeVersion  1101
#define KEYBOARD_ANIMATION_DURATION 0.3
#define MINIMUM_SCROLL_FRACTION 0.5
#define MAXIMUM_SCROLL_FRACTION 0.8
#define PORTRAIT_KEYBOARD_HEIGHT_IPHONE 216
#define LANDSCAPE_KEYBOARD_HEIGHT_IPHONE 162
#define PORTRAIT_KEYBOARD_HEIGHT_IPAD 264
#define LANDSCAPE_KEYBOARD_HEIGHT_IPAD 352

#pragma mark - ViewTags

const int       kTagDialogBackgroundView            = 1;
const int       kTagPageView                        = 3;
const int       kTagNavigationBar                   = 4;
const int       kTagPopupMenuCloser                 = 5;
const int       kTagPageBackgroundImage             = 44;
const int       kStatusBarBlackBackgroundTag        = 77;
const int       kTagVersionCheckerAlert             = 78;
const int       kTagSliderDrawer                    = 314;
const int       kTagMainWindow                      = 315;
const int       kTagAlertControllerWindow           = 316;

#pragma mark - RepeatBox Caching

const int       kRepeatboxCachedRowImages           = 3;
const int       kRepeatboxCachedImageMinSize        = 200000;

#pragma mark - Object animation

const float     kColorStep                          = 0.5;
const int       kBounceVal                          = 10;

#endif
