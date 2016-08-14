//
//  clickergame.h
//  MyCppGame
//
//  Created by Hao ran chen on 2016-08-14.
//
//

#ifndef clickergame_h
#define clickergame_h
#include "ui/CocosGUI.h"//widgets
#include "extensions/cocos-ext.h"//ui features
#include "cocos2d.h"

USING_NS_CC;//ui features

USING_NS_CC_EXT;//ui features
//using namespace ui;
using namespace cocos2d;

class Gameplay : public cocos2d::Layer, public cocos2d::ui::EditBoxDelegate
{
    public:
        static cocos2d::Scene* createGameplayScene();
    
        virtual bool init();
        // implement the "static create()" method manually
        CREATE_FUNC(Gameplay);
    
        void touchEvent(Ref *sender, ui::Widget::TouchEventType type);
}

#endif /* clickergame_h */
