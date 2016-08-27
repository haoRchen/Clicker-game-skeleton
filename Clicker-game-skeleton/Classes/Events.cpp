//
//  Events.cpp
//  MyGame
//
//  Created by Hao ran chen on 2016-08-25.
//
//

#include "Events.h"
#include "ui/CocosGUI.h"//widgets
#include "extensions/cocos-ext.h"//ui features

USING_NS_CC;
USING_NS_CC_EXT;//ui features
using namespace ui;
using namespace cocos2d;

bool Events::init()
{
    //storing visible screensize
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    popupBackground = Sprite::create("eventPopup.png");
    popupBackground->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    this->addChild(popupBackground);
    
    //event message label
    eventMessage = Label::createWithTTF("message", "fonts/arial.ttf", 60);
    eventMessage->setScale(0.5f);
    eventMessage->setAnchorPoint(Point(0.0f, 0.5f));
    eventMessage->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    addChild(eventMessage);
    
    //creating button, 1st parameter is the normal state, and second is the pressed state
    Button *eventButton = Button::create("button_normal.png", "button_pressed.png");
    eventButton->setPosition(Vec2((visibleSize.width/2), visibleSize.height/1.50 + origin.y));
    eventButton->setTitleText("Ok");
    eventButton->setTitleFontSize(25);
    this->addChild(eventButton);
    
    return true;
}