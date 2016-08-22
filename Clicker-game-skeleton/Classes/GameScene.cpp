//
//  Gameplay.cpp
//  MyCppGame
//
//  Created by Hao ran chen on 2016-08-15.
//
//
#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "extensions/cocos-ext.h"//ui
#include "ui/CocosGUI.h"//widgets
#include "HUD.h"
#include <iostream>

USING_NS_CC;
USING_NS_CC_EXT;//ui features
using namespace cocos2d;
using namespace std;

Scene* GameScene::createGameScene()
{
    
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}
// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    CCLOG("In gameplay scene");
    //storing visible screensize
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    //logs visible and original size. Testing purpose
    CCLOG("visibleSize is (%.2f, %.2f)", visibleSize.width, visibleSize.height);
    CCLOG("origin is (%.2f, %.2f)", origin.x, origin.y);
    
    
    // add background image
    auto sprite = Sprite::create("blue background.jpg");
    sprite->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    this->addChild(sprite, 0);
    
    //**************************************
    //local datastorage
    UserDefault *def = UserDefault::getInstance();
    //def->setIntegerForKey("Hello22012", -99);
    //delete the app from iphone/ipad simulator to reset userdefault database
    //searches key, give back default value type integer 300 if nothing is found.
    CCLOG("%d@@@@@@", def->getIntegerForKey("Hello22012", 300));
    //creates a key with the integer value
    def->setIntegerForKey("Coins", 0);
    def->setIntegerForKey("Coins per click", 1);
    def->setIntegerForKey("Passive income", 0);
    CCLOG("%d@@@@@@", def->getIntegerForKey("Coins"));
    CCLOG("%d@@@@@@", def->getIntegerForKey("Coins per click"));
    CCLOG("%d@@@@@@", def->getIntegerForKey("Passive income"));
    def->flush();
    
    //HUD integration
    _hud = HUD::create();
    addChild(_hud, 1);
    
    //adding single touch event listener
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    

    return true;
}
bool GameScene::onTouchBegan(Touch *touch, Event *event)
{
    CCLOG("ontouchbegan x = %f, y = %f", touch->getLocationInView().x, touch->getLocationInView().y);
    
    return true;
}