#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "AppodealInterface.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

/// appodeal callbacks

void bannerDidLoadAd()
{
    CCLOG("Appodeal: banner did load");
}
void bannerDidFailToLoadAd()
{
    CCLOG("Appodeal: banner failed to load");
}
void bannerDidClick()
{
    CCLOG("Appodeal: banner did click");
}

void interstitialDidLoadAd(){CCLOG("Appodeal: interstitialDidLoadAd");}
void interstitialDidFailToLoadAd(){CCLOG("Appodeal: interstitialDidFailToLoadAd");}
void interstitialWillPresent(){CCLOG("Appodeal: interstitialWillPresent");}
void interstitialDidDismiss(){CCLOG("Appodeal: interstitialDidDismiss");}
void interstitialDidClick(){CCLOG("Appodeal: interstitialDidClick");}

void videoDidLoadAd(){CCLOG("Appodeal: videoDidLoadAd");}
void videoDidFailToLoadAd(){CCLOG("Appodeal: videoDidFailToLoadAd");}
void videoDidPresent(){CCLOG("Appodeal: videoDidPresent");}
void videoWillDismiss(){CCLOG("Appodeal: videoWillDismiss");}
void videoDidFinish(){CCLOG("Appodeal: videoDidFinish");}

void rewardedVideoDidLoadAd(){CCLOG("Appodeal: rewardedVideoDidLoadAd");}
void rewardedVideoDidFailToLoadAd(){CCLOG("Appodeal: rewardedVideoDidFailToLoadAd");}
void rewardedVideoDidPresent(){CCLOG("Appodeal: rewardedVideoDidPresent");}
void rewardedVideoWillDismiss(){CCLOG("Appodeal: rewardedVideoWillDismiss");}
void rewardedVideoDidFinish(int amount, const char* name){CCLOG("Appodeal: rewardedVideoDidFinish: %s = %d", name, amount);}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("MainScene.csb");
    
    addChild(rootNode);
    
    AppodealInterface* appodeal = new AppodealInterface();
    
    auto buttonInitialize = static_cast< cocos2d::ui::Button*>(rootNode->getChildByName("button_Initialize"));
    if(buttonInitialize)
    {
        buttonInitialize->addClickEventListener([=](Ref *){
            CCLOG("Pressed init");
            appodeal->initialize("dee74c5129f53fc629a44a690a02296694e3eef99f2d3a5f", AppodealAdType::ALL);
            appodeal->setBannerDelegate(
                                        bannerDidLoadAd,
                                        bannerDidFailToLoadAd,
                                        bannerDidClick);
            
            appodeal->setInterstitialDelegate(
                                              interstitialDidLoadAd,
                                              interstitialDidFailToLoadAd,
                                              interstitialWillPresent,
                                              interstitialDidDismiss,
                                              interstitialDidClick);
            appodeal->setVideoDelegate(
                                       videoDidLoadAd,
                                       videoDidFailToLoadAd,
                                       videoDidPresent,
                                       videoWillDismiss,
                                       videoDidFinish);
            
            appodeal->setRewardedVideoDelegate(
                                               rewardedVideoDidLoadAd,
                                               rewardedVideoDidFailToLoadAd,
                                               rewardedVideoDidPresent,
                                               rewardedVideoWillDismiss,
                                               rewardedVideoDidFinish);
        });
    }
    
    auto buttonBanner = static_cast< cocos2d::ui::Button*>(rootNode->getChildByName("button_Banner"));
    if(buttonBanner)
    {
        buttonBanner->addClickEventListener([=](Ref *){
            CCLOG("Pressed banner");
            appodeal->show(AppodealAdType::BANNER_BOTTOM);
        });
    }
    
    auto buttonInterstitial = static_cast< cocos2d::ui::Button*>(rootNode->getChildByName("button_Interstitial"));
    if(buttonInterstitial)
    {
        buttonInterstitial->addClickEventListener([=](Ref *){
            CCLOG("Pressed interstitial");
            appodeal->show(AppodealAdType::INTERSTITIAL);
        });
    }

    auto buttonVideo = static_cast< cocos2d::ui::Button*>(rootNode->getChildByName("button_Video"));
    if(buttonVideo)
    {
        buttonVideo->addClickEventListener([=](Ref *){
            CCLOG("Pressed video");
            appodeal->show(AppodealAdType::VIDEO);
        });
    }
    
    auto buttonRewarded = static_cast< cocos2d::ui::Button*>(rootNode->getChildByName("button_Rewarded"));
    if(buttonRewarded)
    {
        buttonRewarded->addClickEventListener([=](Ref *){
            CCLOG("Pressed rewarded");
            appodeal->show(AppodealAdType::REWARDED_VIDEO);
        });
    }
    
    auto buttonInterstitialVideo = static_cast< cocos2d::ui::Button*>(rootNode->getChildByName("button_IntertitialVideo"));
    if(buttonInterstitialVideo)
    {
        buttonInterstitialVideo->addClickEventListener([=](Ref *){
            CCLOG("Pressed interstitial or video");
            appodeal->show(AppodealAdType::INTERSTITIAL | AppodealAdType::VIDEO);
        });
    }
    
    auto buttonHide = static_cast< cocos2d::ui::Button*>(rootNode->getChildByName("button_Hide"));
    if(buttonHide)
    {
        buttonHide->addClickEventListener([=](Ref *){
            CCLOG("Pressed hide");
            appodeal->hide();
        });
    }

    return true;
}
