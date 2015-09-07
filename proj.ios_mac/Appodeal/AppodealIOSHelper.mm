#import <Appodeal/Appodeal.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#include "AppodealIOSHelper.h"

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////

#define APPODEAL_DELEGATE_PROPERTY(NAME) \
@property (assign, nonatomic) AppodealNativeDelegate NAME ## Delegate;

#define APPODEAL_DELEGATE_METHOD(NAME) \
- (void)NAME { \
if ([self NAME ## Delegate]) { \
[self NAME ## Delegate](); \
} \
}

@interface AppodealBannerDelegate : NSObject <AppodealBannerDelegate>
APPODEAL_DELEGATE_PROPERTY(bannerDidLoadAd)
APPODEAL_DELEGATE_PROPERTY(bannerDidFailToLoadAd)
APPODEAL_DELEGATE_PROPERTY(bannerDidClick)
@end

@implementation AppodealBannerDelegate
APPODEAL_DELEGATE_METHOD(bannerDidLoadAd)
APPODEAL_DELEGATE_METHOD(bannerDidFailToLoadAd)
APPODEAL_DELEGATE_METHOD(bannerDidClick)
@end



@interface AppodealInterstitialDelegate : NSObject <AppodealInterstitialDelegate>
APPODEAL_DELEGATE_PROPERTY(interstitialDidLoadAd)
APPODEAL_DELEGATE_PROPERTY(interstitialDidFailToLoadAd)
APPODEAL_DELEGATE_PROPERTY(interstitialWillPresent)
APPODEAL_DELEGATE_PROPERTY(interstitialDidDismiss)
APPODEAL_DELEGATE_PROPERTY(interstitialDidClick)
@end

@implementation AppodealInterstitialDelegate
APPODEAL_DELEGATE_METHOD(interstitialDidLoadAd)
APPODEAL_DELEGATE_METHOD(interstitialDidFailToLoadAd)
APPODEAL_DELEGATE_METHOD(interstitialWillPresent)
APPODEAL_DELEGATE_METHOD(interstitialDidDismiss)
APPODEAL_DELEGATE_METHOD(interstitialDidClick)
@end



@interface AppodealVideoDelegate : NSObject <AppodealVideoDelegate>
APPODEAL_DELEGATE_PROPERTY(videoDidLoadAd)
APPODEAL_DELEGATE_PROPERTY(videoDidFailToLoadAd)
APPODEAL_DELEGATE_PROPERTY(videoWillDismiss)
APPODEAL_DELEGATE_PROPERTY(videoDidFinish)
APPODEAL_DELEGATE_PROPERTY(videoDidPresent)
@end

@implementation AppodealVideoDelegate
APPODEAL_DELEGATE_METHOD(videoDidLoadAd)
APPODEAL_DELEGATE_METHOD(videoDidFailToLoadAd)
APPODEAL_DELEGATE_METHOD(videoWillDismiss)
APPODEAL_DELEGATE_METHOD(videoDidFinish)
APPODEAL_DELEGATE_METHOD(videoDidPresent)
@end

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////

const int INTERSTITIAL  = 1;
const int VIDEO         = 2;
const int BANNER        = 4;
const int BANNER_BOTTOM = 8;
const int BANNER_TOP    = 16;
const int BANNER_CENTER = 32;
const int ALL           = 127;
const int ANY           = 127;

int nativeAdTypesForType(int adTypes) {
    int nativeAdTypes = 0;
    
    if ((adTypes & INTERSTITIAL) > 0) {
        nativeAdTypes |= AppodealAdTypeInterstitial;
    }
    
    if ((adTypes & VIDEO) > 0) {
        nativeAdTypes |= AppodealAdTypeVideo;
    }
    
    if ((adTypes & BANNER) > 0 ||
        (adTypes & BANNER_TOP) > 0 ||
        (adTypes & BANNER_CENTER) > 0 ||
        (adTypes & BANNER_BOTTOM) > 0) {
        
        nativeAdTypes |= AppodealAdTypeBanner;
    }
    
    return nativeAdTypes;
}

AppodealShowStyle nativeShowStyleForType(int adTypes) {
    bool isInterstitial = (adTypes & INTERSTITIAL) > 0;
    bool isVideo = (adTypes & VIDEO) > 0;
    
    if (isInterstitial && isVideo) {
        return AppodealShowStyleVideoOrInterstitial;
    } else if (isVideo) {
        return AppodealShowStyleVideo;
    } else if (isInterstitial) {
        return AppodealShowStyleInterstitial;
    }
    
    if ((adTypes & BANNER_TOP) > 0) {
        return AppodealShowStyleBannerTop;
    }
    
    if ((adTypes & BANNER_CENTER) > 0) {
        return AppodealShowStyleBannerCenter;
    }
    
    if ((adTypes & BANNER_BOTTOM) > 0) {
        return AppodealShowStyleBannerBottom;
    }
    
    return AppodealShowStyle::AppodealShowStyleBannerBottom;
}


////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////

void AppodealIOSHelper::initialize(const char* appKey)
{
    [Appodeal initializeWithApiKey:[NSString stringWithUTF8String:appKey]];
}

void AppodealIOSHelper::initialize(const char* appKey, int adType)
{
    [Appodeal initializeWithApiKey:[NSString stringWithUTF8String:appKey] types:nativeAdTypesForType(adType)];
}

bool AppodealIOSHelper::show(int adType)
{
    return [Appodeal showAd:nativeShowStyleForType(adType) rootViewController:[UIApplication sharedApplication].keyWindow.rootViewController];
}

void AppodealIOSHelper::hide()
{
    [Appodeal hideBanner];
}

void AppodealIOSHelper::setPrecache(int adType, bool precache)
{
    [Appodeal setAutocache:precache types:nativeAdTypesForType(adType)];
}

void AppodealIOSHelper::disableNetworkForAdType(int adType, const char* network)
{
    [Appodeal disableNetworkForAdType:nativeAdTypesForType(adType) name:[NSString stringWithUTF8String:network]];
}

void AppodealIOSHelper::disableLocationPermissionCheck()
{
    [Appodeal disableLocationPermissionCheck];
}

bool AppodealIOSHelper::isReadyForShow(int adType)
{
    return [Appodeal isReadyForShowWithStyle:nativeShowStyleForType(adType)];
}

static AppodealBannerDelegate* bannerDelegate;
void AppodealIOSHelper::setBannerDelegate(
                                          AppodealNativeDelegate bannerDidLoadAd,
                                          AppodealNativeDelegate bannerDidFailToLoadAd,
                                          AppodealNativeDelegate bannerDidClick)
{
    bannerDelegate = [AppodealBannerDelegate new];
    bannerDelegate.bannerDidClickDelegate = bannerDidClick;
    bannerDelegate.bannerDidFailToLoadAdDelegate = bannerDidFailToLoadAd;
    bannerDelegate.bannerDidLoadAdDelegate = bannerDidLoadAd;
    
    [Appodeal setBannerDelegate:bannerDelegate];
}

static AppodealInterstitialDelegate* interstitialDelegate;
void AppodealIOSHelper::setInterstitialDelegate(
                             AppodealNativeDelegate interstitialDidLoadAd,
                             AppodealNativeDelegate interstitialDidFailToLoadAd,
                             AppodealNativeDelegate interstitialWillPresent,
                             AppodealNativeDelegate interstitialDidDismiss,
                             AppodealNativeDelegate interstitialDidClick)
{
    interstitialDelegate = [AppodealInterstitialDelegate new];
    interstitialDelegate.interstitialDidLoadAdDelegate = interstitialDidLoadAd;
    interstitialDelegate.interstitialDidFailToLoadAdDelegate = interstitialDidFailToLoadAd;
    interstitialDelegate.interstitialWillPresentDelegate = interstitialWillPresent;
    interstitialDelegate.interstitialDidDismissDelegate = interstitialDidDismiss;
    interstitialDelegate.interstitialDidClickDelegate = interstitialDidClick;
    
    [Appodeal setInterstitialDelegate:interstitialDelegate];
}

static AppodealVideoDelegate* videoDelegate;
void AppodealIOSHelper::setVideoDelegate(
                      AppodealNativeDelegate videoDidLoadAd,
                      AppodealNativeDelegate videoDidFailToLoadAd,
                      AppodealNativeDelegate videoDidPresent,
                      AppodealNativeDelegate videoWillDismiss,
                      AppodealNativeDelegate videoDidFinish)
{
    videoDelegate = [AppodealVideoDelegate new];
    videoDelegate.videoDidLoadAdDelegate = videoDidLoadAd;
    videoDelegate.videoDidFailToLoadAdDelegate = videoDidFailToLoadAd;
    videoDelegate.videoDidPresentDelegate = videoDidPresent;
    videoDelegate.videoWillDismissDelegate = videoWillDismiss;
    videoDelegate.videoDidFinishDelegate = videoDidFinish;
    
    [Appodeal setVideoDelegate:videoDelegate];
}

/////////////////////////////////////////////////////////

AppodealIOSHelper::AppodealIOSHelper()
{
}

AppodealIOSHelper::~AppodealIOSHelper()
{
}