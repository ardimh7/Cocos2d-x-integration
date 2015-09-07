# Appodeal-Cocos2d-x-integration

This is sample of appodeal integration in cocos2d-x ios app.

### iOS integration

1. Download the [latest iOS SDK version](https://s3-us-west-1.amazonaws.com/appodeal-ios/0.4.6/Appodeal.zip) and extract Appodeal iOS SDK.
2. Open ```proj.ios_mac/AppodealCocosSample.xcodeproj``` in Xcode, then drag and drop Appodeal.framework and Resources folder onto your project in ```Appodeal/ios``` folder (use the "Product Navigator view") and choose "Copy items into destination group's folder and click Finish".  

![](http://dl.dropbox.com/s/8z80aridd4gqxub/Screen%20Shot%202015-04-23%20at%204.30.58%20PM.png)

### Framework dependencies

Appodeal iOS SDK works on >= iOS 7.0 version and is compatible with both ARC and non-ARC projects. It depends (Project Settings -> Build Phases -> Link Binary With Libraries) on the following Apple frameworks:

* AdSupport
* AudioToolbox
* AVFoundation
* CFNetwork
* CoreFoundation
* CoreGraphics
* CoreImage
* CoreLocation
* CoreMedia
* CoreTelefony
* EventKit
* EventKitUI
* libc++
* libsqlite3.dylib
* libxml2.2.dylib
* libz.dylib
* MediaPlayer
* MessageUI
* MobileCoreServices
* QuartzCore
* Security
* Social
* StoreKit
* SystemConfiguration
* UIKit
* WebKit

You will need the latest developer tools in order to build Appodeal iOS SDK. Old Xcode versions might work, but compatibility will not be explicitly maintained.
