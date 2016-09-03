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
#include "Events.h"
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
    
    //HUD integration
    _hud = HUD::create();
    addChild(_hud, 1);
    
    //adding single touch event listener
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    this->schedule(schedule_selector(GameScene::update), 5.0);
    
    
    return true;
}
bool GameScene::onTouchBegan(Touch *touch, Event *event)
{
    int _x = touch->getLocationInView().x;
    int _y = touch->getLocationInView().y;
    Size s = Director::getInstance()->getVisibleSize();
    Sprite* backgroundsprite = _hud->getBackgroundSprite();
    Size backgroundSize = backgroundsprite->getContentSize();
    
    //logging the coordinates
    CCLOG("ontouchbegan x = %d, y = %d", _x, _y);
    CCLOG("%f, %f", backgroundSize.width, backgroundSize.height);
    //checks if the click is within the coordinates allowed(gameplay area)
    if(_x <= s.width && _y > backgroundSize.height && _y <  1000)
    {
        CCLOG("you are clicking in the right place! ");
        _hud->updateCoins(_hud->get_coinGainPerClick());//value changes depending on coins per click
    }
    
    return true;
}

//scheduler calls this function to update using delta time
void GameScene::update(float dt)
{
    CCLOG("event called ");
    
    _eventDispatcher->pauseEventListenersForTarget(this, true);
    auto dl = Events::create();
    addChild(dl);
    auto eventNum = dl->getEventNum();
    switch (eventNum) {
        case 1:
            _hud->updateCoins(50);
            CCLOG("Added 50 coin");
            break;
        case 2:
            _hud->updateCoins(-50);
            CCLOG("Subtracted 50 coin");
            break;
        case 3:
            _hud->updateCoinsPSec(3);
            CCLOG("+3 more coins per second");
            break;
        default:
            CCLOG("Invalid event num");
            break;
    }
     _eventDispatcher->resumeEventListenersForTarget(this, true);
    
}













