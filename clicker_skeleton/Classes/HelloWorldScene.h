#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__
#include "ui/CocosGUI.h"//widgets
#include "extensions/cocos-ext.h"//ui features
#include "cocos2d.h"
#include "network/HttpClient.h"

USING_NS_CC;//ui features

USING_NS_CC_EXT;//ui features
//using namespace ui;
using namespace cocos2d;

class HelloWorld : public Layer, public ui::EditBoxDelegate
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

    /**
     * This method is called when an edit box gains focus after keyboard is shown.
     * @param editBox The edit box object that generated the event.
     */
    virtual void editBoxEditingDidBegin(ui::EditBox* editBox);
    
    
    /**
     * This method is called when an edit box loses focus after keyboard is hidden.
     * @param editBox The edit box object that generated the event.
     */
    virtual void editBoxEditingDidEnd(ui::EditBox* editBox);
    
    /**
     * This method is called when the edit box text was changed.
     * @param editBox The edit box object that generated the event.
     * @param text The new text.
     */
    virtual void editBoxTextChanged(ui::EditBox* editBox, const std::string& text);
    
    /**
     * This method is called when the return button was pressed or the outside area of keyboard was touched.
     * @param editBox The edit box object that generated the event.
     */
    virtual void editBoxReturn(ui::EditBox* editBox);
    
    //transition to game scene
    void toGameScene();
    
    //tracking touch events
    void touchEvent(Ref *sender, ui::Widget::TouchEventType type);
    // Method grabs data from JSON array and stores them in local variables
    void onHttpRequestCompleted(cocos2d::network::HttpClient *sender, cocos2d::network::HttpResponse *response);

};

#endif // __HELLOWORLD_SCENE_H__
