//
//  AppodealInterface.cpp
//  AppodealCocosSample
//
//  Created by ewgenius on 03/09/15.
//
//



#include "AppodealInterface.h"

#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "AppodealIOSHelper.h"
#endif

#include <string>
using namespace std;

void AppodealInterface::initialize(const char* appKey)
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    
    AppodealIOSHelper* appodealIos = new AppodealIOSHelper();
    appodealIos->initialize(appKey);
    
#endif
}

void AppodealInterface::initialize(const char* appKey, AppodealAdType adType)
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    
    AppodealIOSHelper* appodealIos = new AppodealIOSHelper();
    appodealIos->initialize(appKey, adType);
    
#endif
}

bool AppodealInterface::show(int adType)
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    
    AppodealIOSHelper* appodealIos = new AppodealIOSHelper();
    return appodealIos->show(adType);
    
#endif
}

void AppodealInterface::hide()
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    
    AppodealIOSHelper* appodealIos = new AppodealIOSHelper();
    appodealIos->hide();
    
#endif
}

void AppodealInterface::setPrecache(AppodealAdType adType, bool precache)
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    
    AppodealIOSHelper* appodealIos = new AppodealIOSHelper();
    appodealIos->setPrecache(adType, precache);
    
#endif
}

void AppodealInterface::disableNetworkForAdType(AppodealAdType adType, const char* network)
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    
    AppodealIOSHelper* appodealIos = new AppodealIOSHelper();
    appodealIos->disableNetworkForAdType(adType, network);
    
#endif
}

void AppodealInterface::disableLocationPermissionCheck()
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    
    AppodealIOSHelper* appodealIos = new AppodealIOSHelper();
    appodealIos->disableLocationPermissionCheck();
    
#endif
}

bool AppodealInterface::isReadyForShow(AppodealAdType adType)
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    
    AppodealIOSHelper* appodealIos = new AppodealIOSHelper();
    return appodealIos->isReadyForShow(adType);
#else
    return false
#endif
    
}

void AppodealInterface::setBannerDelegate(
                  void (*bannerDidLoadAd)(),
                  void (*bannerDidFailToLoadAd)(),
                  void (*bannerDidClick)()
                  )
{
    AppodealIOSHelper* appodealIos = new AppodealIOSHelper();
    appodealIos->setBannerDelegate(
                                   bannerDidLoadAd,
                                   bannerDidFailToLoadAd,
                                   bannerDidClick);
}

void AppodealInterface::setInterstitialDelegate(
                             void (*interstitialDidLoadAd)(),
                             void (*interstitialDidFailToLoadAd)(),
                             void (*interstitialWillPresent)(),
                             void (*interstitialDidDismiss)(),
                             void (*interstitialDidClick)()
                             )
{
    AppodealIOSHelper* appodealIos = new AppodealIOSHelper();
    appodealIos->setInterstitialDelegate(
                                         interstitialDidLoadAd,
                                         interstitialDidFailToLoadAd,
                                         interstitialWillPresent,
                                         interstitialDidDismiss,
                                         interstitialDidClick);
}

void AppodealInterface::setVideoDelegate(
                      void (*videoDidLoadAd)(),
                      void (*videoDidFailToLoadAd)(),
                      void (*videoDidPresent)(),
                      void (*videoWillDismiss)(),
                      void (*videoDidFinish)()
                      )
{
    AppodealIOSHelper* appodealIos = new AppodealIOSHelper();
    appodealIos->setVideoDelegate(
                                  videoDidLoadAd,
                                  videoDidFailToLoadAd,
                                  videoDidPresent,
                                  videoWillDismiss,
                                  videoDidFinish);
}

AppodealInterface::AppodealInterface()
{
}

AppodealInterface::~AppodealInterface()
{
}