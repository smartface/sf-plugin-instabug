# InstaBug plugin from Smartface
[![Twitter: @Smartface_io](https://img.shields.io/badge/contact-@Smartface_io-blue.svg?style=flat)](https://twitter.com/smartface_io)
[![License](https://img.shields.io/badge/license-MIT-green.svg?style=flat)](https://raw.githubusercontent.com/smartface/sf-extension-extendedlabel/master/LICENSE)

## InstaBug plugin
Instabug is an in-app feedback and bug reporting tool for mobile apps. With just a simple shake, your users or beta testers can report bugs or send in-app feedback and the SDK will capture an environment snapshot of your user's device including all console logs, server-side network requests and bug reproduction steps compiling all these details in one organised dashboard to help you debug and fix bugs faster.

## Installation
Smartface InstaBug plugin can be installed via npm easily from our public npm repository. The installation is pretty easy via Smartface Cloud IDE.

- Run command `(cd ~/workspace/scripts && npm i -S sf-plugin-instabug)`

### iOS
- Add instabug plugin to config/project.json.

```javascript
"instabugios": {
"url": "",
"path": "plugins/iOS/instabugios.zip",
"active": true
}
```
- If your app doesn’t already access the microphone or photo library, you’ll need to add the following 2 keys to your app’s config/iOS/info.plist file

```xml
<key>NSMicrophoneUsageDescription</key>
<string>Need microphone access for uploading videos</string>
<key>NSPhotoLibraryUsageDescription</key>
<string>Need Library access for uploading Images</string>
```

## How to use
- You can initialize the SDK by calling the .build(token,invocationEvent)
```javascript
const InstaBug = require("sf-plugin-instabug");
InstaBug.build("TOKEN",InstaBug.InvocationEvent.SHAKE);
```

#### Invocation Events
You can set the SDK to be shown using one of the following modes:

- Shake device
- Take a screenshot
- Tap on a floating button shown above your app's UI
- Do a 2-finger swipe from right to left
To customize the invocation event, pass one of the values of the InstaBug.InvocationEvent enum when starting the SDK.

```javascript
InstaBug.InvocationEvent.NONE
InstaBug.InvocationEvent.SHAKE
InstaBug.InvocationEvent.FLOATING_BUTTON
InstaBug.InvocationEvent.SCREENSHOT_GESTURE
InstaBug.InvocationEvent.TWO_FINGER_SWIPE_LEFT
```

#### Shaking Threshold
If you are using the shaking gesture as your invocation event you can set how sensitive your device is to the shaking. The values in the following example are the default ones. The higher the value the less sensitive the device will be to shaking.

```javascript
var shakingThreshold = {
	android : 350,
	iphone : 2.5,
	ipad : 0.6
}
InstaBug.setShakingThreshold(shakingThreshold);
```

#### Manual Invocation
If you want to invoke the SDK manually, use the invoke method.

```javascript
InstaBug.invoke();
```

Alternatively, instead of showing the menu that lets the users choose what they want to do as shown in the image below, you could show the SDK with a specific feature. In this case, the "How can we help you?" popup shown below will not appear.

```javascript
InstaBug.invokeWithInvocationMode(InstaBug.InvocationMode.NEW_BUG);
```

Here are the possible invocation modes.

```javascript
InstaBug.InvocationMode.NEW_BUG
InstaBug.InvocationMode.NEW_FEEDBACK
InstaBug.InvocationMode.NEW_CHAT
InstaBug.InvocationMode.CHATS_LIST
```

Dismisses all visible Instabug views.

```javascript
InstaBug.dismiss();
```

#### Color Theme

The SDK UI has 2 color themes: light and dark.You can set which theme to use with the following method.

```javascript
InstaBug.setTheme(InstaBug.Theme.DARK);
```

Here are the possible theme.

```javascript
InstaBug.Theme.LIGHT
InstaBug.Theme.DARK
```

#### Primary Color

You can also set the color of UI elements indicating interactivity or call to action to match your app.

```javascript
InstaBug.setPrimaryColor(Color.WHITE);
```

#### Introductory

An intro message is shown to guide users on how to use Instabug.

```javascript
InstaBug.showIntroMessage();
```

#### Prompt Options

When the user Invokes the SDK with any of the previously discussed gestures, the prompt options popup appears. By default, it shows all the enabled features. You have control on which options are allowed and which are not by disabling and enabling any of the features. Each one can be enabled or disabled separately.

```javascript
InstaBug.setPromptOptionsEnabled(true,true,true);
```

When only a single option is enabled, it becomes the default invocation mode. If all options are disabled, bug reporting becomes the default invocation mode.

#### Language

The SDK will automatically use the device's current locale, however, you can override it with the following method

```javascript
InstaBug.setLocale(InstaBug.Locale.English);
```

Here are the possible locale values.

```javascript
InstaBug.Locale.Arabic;
InstaBug.Locale.ChineseSimplified;
InstaBug.Locale.ChineseTaiwan;
InstaBug.Locale.ChineseTraditional;
InstaBug.Locale.Czech;
InstaBug.Locale.Danish;
InstaBug.Locale.Dutch;
InstaBug.Locale.English;
InstaBug.Locale.French;
InstaBug.Locale.German;
InstaBug.Locale.Italian;
InstaBug.Locale.Japanese;
InstaBug.Locale.Korean;
InstaBug.Locale.Norwegian;
InstaBug.Locale.Polish;
InstaBug.Locale.Portugese;
InstaBug.Locale.PortugueseBrazil;
InstaBug.Locale.Russian;
InstaBug.Locale.Slovak;
InstaBug.Locale.Spanish;
InstaBug.Locale.Swedish;
InstaBug.Locale.Turkish;
```

## License
This project is licensed under the terms of the MIT license. See the [LICENSE](https://raw.githubusercontent.com/smartface/sf-extension-extendedlabel/master/LICENSE) file. Within the scope of this license, all modifications to the source code, regardless of the fact that it is used commercially or not, shall be committed as a contribution back to this repository.

