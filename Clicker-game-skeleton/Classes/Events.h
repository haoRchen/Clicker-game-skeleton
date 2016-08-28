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

USING_NS_CC;
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
    
    //a number to reference event
    //popup background sprite
    Sprite *popupBackground;
    //database pointer
public:
    //getters and setters for private variables
    //switch function to push the proper message to the label
    // a selector callback to exit the popup
    //void eventCloseCallback(cocos2d::Ref* pSender);
    string* eventMessageGenerator();
    string* eventName();
    virtual bool init();
    CREATE_FUNC(Events);
};


#endif /* Events_h__ */
