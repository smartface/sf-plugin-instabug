function InstaBug() {}

InstaBug.ios = {};
InstaBug.android = {};

InstaBug.InvocationEvent = {}

InstaBug.build = function(token,invocationEvent){}

InstaBug.invoke = function(){}

InstaBug.InvocationMode = {}

InstaBug.invokeWithInvocationMode = function(invocationMode){}

InstaBug.dismiss = function(){}

InstaBug.setShakingThreshold = function(shakingThreshold){}

InstaBug.Theme = {}

InstaBug.setTheme = function(theme){}

InstaBug.setPrimaryColor = function(color){}

InstaBug.showIntroMessage = function(){}

InstaBug.setPromptOptionsEnabled = function(chat,bug,feedback){}

InstaBug.identifyUser = function(name,email){}

InstaBug.setUserAttribute = function(key,value){}

InstaBug.removeUserAttribute = function(key){}

InstaBug.getAllUserAttributes = function(){}

InstaBug.getUserAttribute = function(key){}

InstaBug.logoutUser = function(){}

InstaBug.Locale = {}

InstaBug.setLocale = function(locale){}

module.exports = InstaBug;