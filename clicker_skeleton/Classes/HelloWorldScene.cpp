#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "extensions/cocos-ext.h"//ui
#include "ui/CocosGUI.h"//widgets
#include <iostream>

USING_NS_CC;
USING_NS_CC_EXT;//ui features
using namespace cocos2d;
using namespace std;



Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Sign In", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);
    
    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("greenBackground.jpeg");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
 
    
    /*
    auto textField = ui::TextField::create("TEXTFIELD","Arial",30);
    
    // set the maximum number of characters the user can enter for this TextField
    textField->setMaxLength(10);
    //change place holder's color
    textField->setPlaceHolderColor(Color3B::BLUE);
    //change text color
    textField->setTextColor(Color4B::RED);
    //set location of text field
    textField->setPosition(Vec2(150, 150));
    textField->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
        std::cout << "editing a TextField" << std::endl;
    });
    
    this->addChild(textField);
     */
    
    //editBox implementation
    ui::EditBox *userNameInput = ui::EditBox::create( Size(200, 30), ui::Scale9Sprite::create("white.png"));
    //set textbox position with openGL percentage coordinate
    //userNameInput->setPositionPercent(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height /2 + origin.y));
    //set textbox position with openGL coordinates
    userNameInput->setPosition(Vec2(250, 150));
    userNameInput->setFontSize(25);
    userNameInput->setFontColor(Color3B::BLACK);
    userNameInput->setPlaceHolder("Input Username Here");
    userNameInput->setPlaceholderFontColor(Color3B::GRAY);
    //limits the amount of characters the user may input
    userNameInput->setMaxLength(10);
    //type of return when finished typing
    userNameInput->setReturnType(ui::EditBox::KeyboardReturnType::DONE);
    userNameInput->setDelegate(this);
    this->addChild(userNameInput);
    
    //creating button, 1st parameter is the normal state, and second is the pressed state
    ui::Button *loginButton = ui::Button::create("button_normal.jpeg", "button_pressed.png");
    loginButton->setPosition(Vec2(300, 200));
    loginButton->setTitleText("Login");
    this->addChild(loginButton);
    loginButton->addTouchEventListener(CC_CALLBACK_2(HelloWorld::loginTouchEvent, this));
    
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}
void HelloWorld::loginTouchEvent(Ref *sender, ui::Widget::TouchEventType type)
{
    switch(type)
    {
        //when the user first touch the button
        case ui::Widget::TouchEventType::BEGAN:
        {
            log("touch began");
            break;
        }
        case ui::Widget::TouchEventType::MOVED:
        {
            log("touch moved");
            break;
        }
        //if user gets interrupted, eg a phone call
        case ui::Widget::TouchEventType::ENDED:
        {
            log("touch ended");
            break;
        }
        case ui::Widget::TouchEventType::CANCELED:
        {
            log("touch cancelled");
            break;
        }
        default:
        {
            break;
        }
    }
}

void HelloWorld::editBoxEditingDidBegin(ui::EditBox* editBox)
{
    log("Begun");
}

void HelloWorld::editBoxEditingDidEnd(ui::EditBox* editBox)
{
    log("End");
}

void HelloWorld::editBoxTextChanged(ui::EditBox* editBox, const std::string& text)
{
    log("Text change, text : %s", text.c_str());
}

void HelloWorld::editBoxReturn(ui::EditBox* editBox)
{
    log("Returned");
}
