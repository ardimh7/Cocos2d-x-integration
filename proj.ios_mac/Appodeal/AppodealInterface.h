//
//  Appodeal.h
//  AppodealCocosSample
//
//  Created by ewgenius on 02/09/15.
//
//

#ifndef AppodealCocosSample_Appodeal_h
#define AppodealCocosSample_Appodeal_h

#include "cocos2d.h"
using namespace cocos2d;

enum AppodealAdType
{
    INTERSTITIAL      = 1,
    VIDEO             = 2,
    BANNER            = 4,
    BANNER_BOTTOM     = 8,
    BANNER_TOP        = 16,
    BANNER_CENTER     = 32,
    REWARDED_VIDEO    = 128,
    ALL               = 255,
    ANY               = 255,
};

class AppodealInterface
{
public:
    void initialize(const char* appKey);
    
    void initialize(const char* appKey, AppodealAdType adType);
    
    bool show(int adType);
    
    void hide();
    
    void setPrecache(AppodealAdType adType, bool precache);
    
    void disableNetworkForAdType(AppodealAdType adType, const char* network);
    
    void disableLocationPermissionCheck();
    
    bool isReadyForShow(AppodealAdType adType);
    
    void setBannerDelegate(
                            void (*bannerDidLoadAd)(),
                            void (*bannerDidFailToLoadAd)(),
                            void (*bannerDidClick)()
                           );
    
    void setInterstitialDelegate(
                                 void (*interstitialDidLoadAd)(),
                                 void (*interstitialDidFailToLoadAd)(),
                                 void (*interstitialWillPresent)(),
                                 void (*interstitialDidDismiss)(),
                                 void (*interstitialDidClick)()
                                 );
    
    void setVideoDelegate(
                          void (*videoDidLoadAd)(),
                          void (*videoDidFailToLoadAd)(),
                          void (*videoDidPresent)(),
                          void (*videoWillDismiss)(),
                          void (*videoDidFinish)()
                          );
    
    void setRewardedVideoDelegate(
                                  void (*rewardedVideoDidLoadAd)(),
                                  void (*rewardedVideoDidFailToLoadAd)(),
                                  void (*rewardedVideoDidPresent)(),
                                  void (*rewardedVideoWillDismiss)(),
                                  void (*rewardedVideoDidFinish)(int amount, char const* name)
                                  );
    
    AppodealInterface();
    virtual ~AppodealInterface();
};

#endif
