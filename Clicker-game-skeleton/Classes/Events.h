//
//  Events.hpp
//  MyGame
//
//  Created by Hao ran chen on 2016-08-25.
//
//

#ifndef Events_h__
#define Events_h__

#include <stdio.h>
#include <string.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"//widgets
#include "extensions/cocos-ext.h"//ui features
USING_NS_CC;//ui features

USING_NS_CC_EXT;//ui features
using namespace ui;
using namespace std;

class Events : public Layer
{
private:
    int eventNumber;
    string eventType;
    string eventMsg;
    //label to display title
    Label *eventMessage;
    Label *eventMessage2;
    //popup background sprite
    Sprite *popupBackground;
    
public:
    Events(void){;}
    ~Events(void){;}
    //returns the eventNumber
    int getEventNum();
    //returns the event message
    string* eventMessageGenerator();
    string* eventName();
    //callback to destroy the event class 
    void eventCloseCallback(cocos2d::Ref* pSender, ui::Widget::TouchEventType type);
    
    virtual bool init();
    CREATE_FUNC(Events);
};


#endif /* Events_h__ */
