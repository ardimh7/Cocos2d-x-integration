//
//  AppodealIOSHelper.h
//  AppodealCocosSample
//
//  Created by ewgenius on 03/09/15.
//
//

//#import <Foundation/Foundation.h>
//

#ifndef AppodealCocosSample_AppodealIOSHelper_h
#define AppodealCocosSample_AppodealIOSHelper_h

using namespace std;

////////

typedef void (*AppodealNativeDelegate) ();
typedef void (*AppodealNativeRewardDelegate) (int rewardAmount,  const char *rewardName);

class AppodealIOSHelper
{
public:
    void initialize(const char* appKey);
    
    void initialize(const char* appKey, int adType);
    
    bool show(int adType);
    
    void hide();
    
    void setPrecache(int adType, bool precache);
    
    void disableNetworkForAdType(int adType, const char* network);
    
    void disableLocationPermissionCheck();
    
    bool isReadyForShow(int adType);
    
    void setBannerDelegate(
                           AppodealNativeDelegate bannerDidLoadAd,
                           AppodealNativeDelegate bannerDidFailToLoadAd,
                           AppodealNativeDelegate bannerDidClick);
    
    void setInterstitialDelegate(
                                 AppodealNativeDelegate interstitialDidLoadAd,
                                 AppodealNativeDelegate interstitialDidFailToLoadAd,
                                 AppodealNativeDelegate interstitialWillPresent,
                                 AppodealNativeDelegate interstitialDidDismiss,
                                 AppodealNativeDelegate interstitialDidClick);
    
    void setVideoDelegate(
                          AppodealNativeDelegate videoDidLoadAd,
                          AppodealNativeDelegate videoDidFailToLoadAd,
                          AppodealNativeDelegate videoDidPresent,
                          AppodealNativeDelegate videoWillDismiss,
                          AppodealNativeDelegate videoDidFinish);
    
    void setRewardedVideoDelegate(
                                  AppodealNativeDelegate rewardedVideoDidLoadAd,
                                  AppodealNativeDelegate rewardedVideoDidFailToLoadAd,
                                  AppodealNativeDelegate rewardedVideoDidPresent,
                                  AppodealNativeDelegate rewardedVideoWillDismiss,
                                  AppodealNativeRewardDelegate rewardedVideoDidFinish);

    AppodealIOSHelper();
    virtual ~AppodealIOSHelper();
};

#endif
