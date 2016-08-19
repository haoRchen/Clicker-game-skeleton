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
    return true;
}