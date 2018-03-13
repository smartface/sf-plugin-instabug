function Instabug() {}

/**
 * You can set the SDK to be shown using one of the following modes:
 *
 *	Shake device
 *	Take a normal screenshot
 *	Tap on a floating button shown above your app's UI
 *	Do a 2-finger swipe from right to left
 *	To customize the invocation event, pass one of the values of the Instabug.InvocationEvent enum when starting the SDK.
 *
 * @event build
 * @param {String} token
 * @param {Instabug.InvocationEvent} invocationEvent
 * @android
 * @ios
 * @since 0.1
 */
Instabug.build = function(token,invocationEvent){}

/**
 * If you want to invoke the SDK manually, use the invoke method.
 *
 * @event invoke
 * @android
 * @ios
 * @since 0.1
 */
Instabug.invoke = function(){}

/**
 * Show Instabug invocation dialog so user can choose to talk to us, report a bug, or submit feedback.
 *
 * @event invokeWithInvocationMode
 * @param {Instabug.InvocationMode} invocationMode
 * @android
 * @ios
 * @since 0.1
 */
Instabug.invokeWithInvocationMode = function(invocationMode){}

/**
 * Dismisses all visible Instabug views.
 *
 * @event dismiss
 * @android
 * @ios
 * @since 0.1
 */
Instabug.dismiss = function(){}

/**
 * If you are using the shaking gesture as your invocation event you can set how sensitive your device is to the shaking.
 *
 * @event setShakingThreshold
 * @param {Object} shakingThreshold
 * @param {Number} shakingThreshold.android [shakingThreshold.android = 350]
 * @param {Number} shakingThreshold.iphone	[shakingThreshold.iphone = 2.5]
 * @param {Number} shakingThreshold.ipad	[shakingThreshold.ipad = 0.6]
 * @android
 * @ios
 * @since 0.1
 */
Instabug.setShakingThreshold = function(shakingThreshold){}

/**
 * The SDK UI has 2 color themes: light and dark.You can set which theme to use by adding the following method to Instabug builder.
 *
 * @event setTheme
 * @param {Instabug.Theme} theme
 * @android
 * @ios
 * @since 0.1
 */
Instabug.setTheme = function(theme){}

/**
 * You can also set the color of UI elements indicating interactivity or call to action to match your app.
 *
 * @event setPrimaryColor
 * @param {UI.Color} color
 * @android
 * @ios
 * @since 0.1
 */
Instabug.setPrimaryColor = function(color){}

/**
 * You can also manually show it later whenever you want using the method below.
 *
 * @event showIntroMessage
 * @android
 * @ios
 * @since 0.1
 */
Instabug.showIntroMessage = function(){}

/**
 * When the user Invokes the SDK with any of the previously discussed gestures, the prompt options popup appears. 
 * By default, it shows all the enabled features. You have control on which options are allowed and which are not by disabling and enabling any of the features. 
 * Each one can be enabled or disabled separately.
 *
 * When only a single option is enabled, it becomes the default invocation mode. If all options are disabled, bug reporting becomes the default invocation mode.
 *
 * @event setPromptOptionsEnabled
 * @param {Boolean} chat
 * @param {Boolean} bug
 * @param {Boolean} feedback
 * @android
 * @ios
 * @since 0.1
 */
Instabug.setPromptOptionsEnabled = function(chat,bug,feedback){}

/**
 * The SDK will automatically use the device's current locale.
 *
 * @event setLocale
 * @param {Instabug.Locale} locale
 * @android
 * @ios
 * @since 0.1
 */
Instabug.setLocale = function(locale){}

/**
 * However, you can set the email as well as the username yourself and the email field will be prefilled with the one you already provided. Ideally, this API should be called as soon as a user logs into your app.
 *
 * @event identifyUser
 * @param {String} name
 * @param {String} email
 * @android
 * @ios
 * @since 0.1
 */
Instabug.identifyUser = function(name,email){}

/**
 * You can assign custom attributes to your users and they will show up on your Instabug dashboard with each report. Those attributes can later be used to filter the reports on the dashboard.
 *
 * @event setUserAttribute
 * @param {String} key
 * @param {String} value
 * @android
 * @ios
 * @since 0.1
 */
Instabug.setUserAttribute = function(key,value){}

/**
 * You can also retrieve or remove the current value of a certain user attribute.
 *
 * @event removeUserAttribute
 * @param {String} key
 * @android
 * @ios
 * @since 0.1
 */
Instabug.removeUserAttribute = function(key){}

/**
 * You can also get user attribute.
 *
 * @event getUserAttribute
 * @android
 * @ios
 * @since 0.1
 */
Instabug.getUserAttribute = function(){}

/**
 * You can also get all user attributes.
 *
 * @event getAllUserAttributes
 * @android
 * @ios
 * @since 0.1
 */
Instabug.getAllUserAttributes = function(){}

/**
 * When a user logs out, the following API should be called.
 * Calling logoutUser will reset the value of the email and name previously set. It will also remove any currently set user attributes, user events, user chats.
 *
 * @event logoutUser
 * @android
 * @ios
 * @since 0.1
 */
Instabug.logoutUser = function(){}

/**
	
	ENUMS

*/

/**
 * @enum {Number} Instabug.Theme
 * @static
 * @since 0.1
 *
 * Instabug theme type.
 *
 */

Instabug.Theme = {};
/**
 * @property {Number} LIGHT
 * @android
 * @ios
 * @static
 * @readonly
 * @since 0.1
 */
Instabug.Theme.LIGHT;

/**
 * @property {Number} DARK
 * @android
 * @ios
 * @static
 * @readonly
 * @since 0.1
 */
Instabug.Theme.DARK;

/**
 * @enum {Number} Instabug.InvocationMode
 * @static
 * @since 0.1
 *
 * Possible invocation modes.
 *
 */

Instabug.InvocationMode = {};
/**
 * @property {Number} NEW_BUG
 * @android
 * @ios
 * @static
 * @readonly
 * @since 0.1
 */
Instabug.InvocationMode.NEW_BUG;

/**
 * @property {Number} NEW_FEEDBACK
 * @android
 * @ios
 * @static
 * @readonly
 * @since 0.1
 */
Instabug.InvocationMode.NEW_FEEDBACK;

/**
 * @property {Number} NEW_CHAT
 * @android
 * @ios
 * @static
 * @readonly
 * @since 0.1
 */
Instabug.InvocationMode.NEW_CHAT;

/**
 * @property {Number} CHATS_LIST
 * @android
 * @ios
 * @static
 * @readonly
 * @since 0.1
 */
Instabug.InvocationMode.CHATS_LIST;

/**
 * @enum {Number} Instabug.InvocationEvent
 * @static
 * @since 0.1
 *
 * Possible invocation events.
 *
 */

Instabug.InvocationEvent = {};
/**
 * @property {Number} NONE
 * @android
 * @ios
 * @static
 * @readonly
 * @since 0.1
 */
Instabug.InvocationEvent.NONE;

/**
 * @property {Number} SHAKE
 * @android
 * @ios
 * @static
 * @readonly
 * @since 0.1
 */
Instabug.InvocationEvent.SHAKE;

/**
 * @property {Number} FLOATING_BUTTON
 * @android
 * @ios
 * @static
 * @readonly
 * @since 0.1
 */
Instabug.InvocationEvent.FLOATING_BUTTON;

/**
 * @property {Number} SCREENSHOT_GESTURE
 * @android
 * @ios
 * @static
 * @readonly
 * @since 0.1
 */
Instabug.InvocationEvent.SCREENSHOT_GESTURE;

/**
 * @property {Number} TWO_FINGER_SWIPE_LEFT
 * @android
 * @ios
 * @static
 * @readonly
 * @since 0.1
 */
Instabug.InvocationEvent.TWO_FINGER_SWIPE_LEFT;

/**
 * @enum {Number} Instabug.Locale
 * @static
 * @since 0.1
 *
 * Possible invocation events.
 *
 */

Instabug.Locale = {};

/**
 * @property {Number} Arabic
 * @android
 * @ios
 * @static
 * @readonly
 * @since 0.1
 */
Instabug.Locale.Arabic;

/**
 * @property {Number} ChineseSimplified
 * @android
 * @ios
 * @static
 * @readonly
 * @since 0.1
 */
Instabug.Locale.ChineseSimplified;

/**
 * @property {Number} ChineseTaiwan
 * @android
 * @ios
 * @static
 * @readonly
 * @since 0.1
 */
Instabug.Locale.ChineseTaiwan;

/**
 * @property {Number} ChineseTraditional
 * @android
 * @ios
 * @static
 * @readonly
 * @since 0.1
 */
Instabug.Locale.ChineseTraditional;

/**
 * @property {Number} Czech
 * @android
 * @ios
 * @static
 * @readonly
 * @since 0.1
 */
Instabug.Locale.Czech;

/**
 * @property {Number} Danish
 * @android
 * @ios
 * @static
 * @readonly
 * @since 0.1
 */
Instabug.Locale.Danish;

/**
 * @property {Number} Dutch
 * @android
 * @ios
 * @static
 * @readonly
 * @since 0.1
 */
Instabug.Locale.Dutch;

/**
 * @property {Number} English
 * @android
 * @ios
 * @static
 * @readonly
 * @since 0.1
 */
Instabug.Locale.English;

/**
 * @property {Number} French
 * @android
 * @ios
 * @static
 * @readonly
 * @since 0.1
 */
Instabug.Locale.French;

/**
 * @property {Number} German
 * @android
 * @ios
 * @static
 * @readonly
 * @since 0.1
 */
Instabug.Locale.German;

/**
 * @property {Number} Italian
 * @android
 * @ios
 * @static
 * @readonly
 * @since 0.1
 */
Instabug.Locale.Italian;

/**
 * @property {Number} Japanese
 * @android
 * @ios
 * @static
 * @readonly
 * @since 0.1
 */
Instabug.Locale.Japanese;

/**
 * @property {Number} Korean
 * @android
 * @ios
 * @static
 * @readonly
 * @since 0.1
 */
Instabug.Locale.Korean;

/**
 * @property {Number} Norwegian
 * @android
 * @ios
 * @static
 * @readonly
 * @since 0.1
 */
Instabug.Locale.Norwegian;

/**
 * @property {Number} Polish
 * @android
 * @ios
 * @static
 * @readonly
 * @since 0.1
 */
Instabug.Locale.Polish;

/**
 * @property {Number} Portugese
 * @android
 * @ios
 * @static
 * @readonly
 * @since 0.1
 */
Instabug.Locale.Portugese;

/**
 * @property {Number} PortugueseBrazil
 * @android
 * @ios
 * @static
 * @readonly
 * @since 0.1
 */
Instabug.Locale.PortugueseBrazil;

/**
 * @property {Number} Russian
 * @android
 * @ios
 * @static
 * @readonly
 * @since 0.1
 */
Instabug.Locale.Russian;

/**
 * @property {Number} Slovak
 * @android
 * @ios
 * @static
 * @readonly
 * @since 0.1
 */
Instabug.Locale.Slovak;

/**
 * @property {Number} Spanish
 * @android
 * @ios
 * @static
 * @readonly
 * @since 0.1
 */
Instabug.Locale.Spanish;

/**
 * @property {Number} Swedish
 * @android
 * @ios
 * @static
 * @readonly
 * @since 0.1
 */
Instabug.Locale.Swedish;

/**
 * @property {Number} Turkish
 * @android
 * @ios
 * @static
 * @readonly
 * @since 0.1
 */
Instabug.Locale.Turkish;

module.exports = Instabug;