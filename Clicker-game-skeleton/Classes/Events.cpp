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
    auto size = 1;
    if(visibleSize.width == 2048 || visibleSize.height == 2048)
    {
        size = visibleSize.height / 1136;
        CCLOG("%d is the size of content scale", size);
    }//need fixing
    
    //creating the background sprite for the popup
    popupBackground = Sprite::create("eventpopup.png");
    popupBackground->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    this->addChild(popupBackground, 0);
    
    //event message label
    eventMessage = Label::createWithTTF(eventName()->c_str(), "fonts/arial.ttf", 50*size);
    eventMessage->setScale(0.5f);
    eventMessage->setColor(Color3B(0,0,0));
    eventMessage->setAnchorPoint(Point(0.5f, 0.5f));
    eventMessage->setAlignment(TextHAlignment::CENTER, TextVAlignment::CENTER);
    eventMessage->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2 - 10));
    addChild(eventMessage, 1);
    //need to make text horizontally align with screen, uncomment afterwards.
    
    
    //event message label
    eventMessage2 = Label::createWithTTF(eventMessageGenerator()->c_str(), "fonts/arial.ttf", 50);
    eventMessage2->setScale(0.5f);
    eventMessage2->setColor(Color3B(0,0,0));
    eventMessage2->setAnchorPoint(Point(0.5f, 0.5f));
    eventMessage->setAlignment(TextHAlignment::CENTER, TextVAlignment::CENTER);
    eventMessage2->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2 - 50));
    addChild(eventMessage2, 1);
    
    //creating button, 1st parameter is the normal state, and second is the pressed state
    ui::Button *eventButton = ui::Button::create("button_normal.png", "button_pressed.png");
    eventButton->setPosition(Vec2((visibleSize.width/2), visibleSize.height/2 - visibleSize.height/9));
    this->addChild(eventButton, 1);
    eventButton->addTouchEventListener(CC_CALLBACK_2(Events::eventCloseCallback, this));
    
    return true;
}

string *Events::eventName()
{
    eventNumber = RandomHelper::random_int(1, 3);
    switch (eventNumber) {
        case 1:
            eventType = "Oh look, free coins!";
            break;
        case 2:
            eventType = "Oh no! Your pants had holes in them...";
            break;
        case 3:
            eventType = "You've become wiser and more efficient.";
            break;
        default:
            CCLOG("invalid");
            break;
    }
    return &eventType;
}
string *Events::eventMessageGenerator()
{
    switch (eventNumber) {
        case 1:
            eventMsg = "+50 coins!";
            break;
        case 2:
            eventMsg = "-50 coins!";
            break;
        case 3:
            eventMsg = "+3 coins per second";
            break;
        default:
            CCLOG("invalid msg");
            break;
    }
    return &eventMsg;
}

int Events::getEventNum()
{
    return eventNumber;
}

void Events::eventCloseCallback(cocos2d::Ref* pSender, ui::Widget::TouchEventType type)
{
    
    switch(type)
    {
            //after user touched the button
        case ui::Widget::TouchEventType::ENDED:
        {
            log("touch ended");
            CCLOG("exiting events");
            //destroy events object
            this->removeFromParentAndCleanup(true);
            break;
        }
        default:
        {
            break;
        }
    }
    
}

