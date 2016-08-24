//
//  GameScene.h
//  MyCppGame
//
//  Created by Hao ran chen on 2016-08-14.
//
//

#ifndef GameScene_h
#define GameScene_h
#include "ui/CocosGUI.h"//widgets
#include "extensions/cocos-ext.h"//ui features
#include "cocos2d.h"
#include "HUD.h"

USING_NS_CC;//ui features

USING_NS_CC_EXT;//ui features
using namespace ui;
using namespace cocos2d;

class GameScene : public Layer
{
    private:
        HUD* _hud;
    public:
        GameScene(void){;}
        ~GameScene(void){;}
        static cocos2d::Scene* createGameScene();
    
        virtual bool init() override;//overriding helloworld init
        // implement the "static create()" method manually
        CREATE_FUNC(GameScene);
        //single touch events, logging coordinates
        bool onTouchBegan(Touch *touch, Event * event) override;
        void touchEvent(Ref *sender, ui::Widget::TouchEventType type);
};

#endif /* GameScene_h */
