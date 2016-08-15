#include "HelloWorldScene.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "extensions/cocos-ext.h"//ui
#include "ui/CocosGUI.h"//widgets

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
    
    
    //storing visible screensize
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    //logs visible and original size. Testing purpose
    CCLOG("visibleSize is (%.2f, %.2f)", visibleSize.width, visibleSize.height);
    CCLOG("origin is (%.2f, %.2f)", origin.x, origin.y);
    
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

    //////////////////
    // create and initialize a label/title
    float scaleFactor = Director::getInstance()->getContentScaleFactor();
    auto label = Label::createWithTTF("Sign In", "fonts/Marker Felt.ttf", 45*scaleFactor);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);
    
    // add background image
    auto sprite = Sprite::create("greenbackground.png");
    //auto oWidth = sprite->getContentSize().width;
    //auto oHeight = sprite->getContentSize().height;
    //scaling background according to resolution
    //sprite->setscale(visibleSize.width/oWidth, visibleSize.height/oHeight);
    //sprite->setContentSize(visibleSize);//stretches/shrinks the image to the size of visible screen
    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    CCLOG("********%f, %f", sprite->getContentSize().width, sprite->getContentSize().height);

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    ////////////////////
    //editBox implementation*****************
    
    //username input
    ui::EditBox *userNameInput = ui::EditBox::create( Size(visibleSize.width/3, visibleSize.height/30), ui::Scale9Sprite::create("white.png"));
    //set textbox position with openGL coordinates
    userNameInput->setPosition(Vec2((visibleSize.width/2), visibleSize.height/1.15 + origin.y));
    //checking sprite position-testing purpose
    CCLOG("X and Y is: (%.2f, %.2f)",((visibleSize.width * 1.35)), (visibleSize.height));
    
    userNameInput->setFontSize(20);
    userNameInput->setFontColor(Color3B::BLACK);
    userNameInput->setPlaceHolder("Username");
    userNameInput->setPlaceholderFontSize(20);
    userNameInput->setPlaceholderFontColor(Color3B::GRAY);
    //limits the amount of characters the user may input
    userNameInput->setMaxLength(10);
    //type of return when finished typing
    userNameInput->setReturnType(ui::EditBox::KeyboardReturnType::DONE);
    userNameInput->setDelegate(this);
    this->addChild(userNameInput);
    
    //email address input
    ui::EditBox *emailAddressInput = ui::EditBox::create( Size(visibleSize.width/3, visibleSize.height/30), ui::Scale9Sprite::create("white.png"));
    //set textbox position with openGL coordinates
    emailAddressInput->setPosition(Vec2((visibleSize.width/2), visibleSize.height/1.23 + origin.y));
    emailAddressInput->setFontSize(20);
    emailAddressInput->setFontColor(Color3B::BLACK);
    emailAddressInput->setPlaceHolder("Email address");
    emailAddressInput->setPlaceholderFontSize(20);
    emailAddressInput->setPlaceholderFontColor(Color3B::GRAY);
    emailAddressInput->setInputMode(ui::EditBox::InputMode::EMAIL_ADDRESS);
    //type of return when finished typing
    emailAddressInput->setReturnType(ui::EditBox::KeyboardReturnType::DONE);
    emailAddressInput->setDelegate(this);
    this->addChild(emailAddressInput);
    
    //email password input
    ui::EditBox *emailPasswordInput = ui::EditBox::create( Size(visibleSize.width/3, visibleSize.height/30), ui::Scale9Sprite::create("white.png"));
    //set textbox position with openGL coordinates
    emailPasswordInput->setPosition(Vec2((visibleSize.width/2), visibleSize.height/1.33 + origin.y));
    emailPasswordInput->setFontSize(20);
    emailPasswordInput->setFontColor(Color3B::BLACK);
    emailPasswordInput->setPlaceHolder("Email Password");
    emailPasswordInput->setPlaceholderFontSize(20);
    emailPasswordInput->setPlaceholderFontColor(Color3B::GRAY);
    emailPasswordInput->setInputFlag(ui::EditBox::InputFlag::PASSWORD);
    emailPasswordInput->setInputMode(ui::EditBox::InputMode::SINGLE_LINE);
    //type of return when finished typing
    emailPasswordInput->setReturnType(ui::EditBox::KeyboardReturnType::DONE);
    emailPasswordInput->setDelegate(this);
    this->addChild(emailPasswordInput);
    
    //**********************************
    
    //creating button, 1st parameter is the normal state, and second is the pressed state
    ui::Button *loginButton = ui::Button::create("button_normal.png", "button_pressed.png");
    //270 x 215
    loginButton->setPosition(Vec2((visibleSize.width/2), visibleSize.height/1.50 + origin.y));
    loginButton->setTitleText("Login");
    loginButton->setTitleFontSize(25);
    this->addChild(loginButton);
    loginButton->addTouchEventListener(CC_CALLBACK_2(HelloWorld::touchEvent, this));
    
    //**************************************
    //local datastorage
    UserDefault *def = UserDefault::getInstance();
    //searches key, give back default value type integer 300 if nothing is found.
    CCLOG("%d@@@@@@", def->getIntegerForKey("Hello22012", 300));
    //creates a key with the integer value
    def->setIntegerForKey("Hello22012", 2000);
    def->flush();
    
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
//logging the occurences of touch events
void HelloWorld::touchEvent(Ref *sender, ui::Widget::TouchEventType type)
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

void HelloWorld::toGameScene()
{
    //get the game scene and run it.
    auto scene = GameScene::createGameScene();
    Director::getInstance()->replaceScene(scene);
}
