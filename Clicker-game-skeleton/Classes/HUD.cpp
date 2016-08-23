#include "HUD.h"
USING_NS_CC;

bool HUD::init()
{
    Size s = Director::getInstance()->getVisibleSize();
    //HUD background
    auto sprite = Sprite::create("greybackground1.jpeg");
    sprite->setPosition(Vec2(s.width/2, s.height - sprite->getContentSize().height/2));
    CCLOG("background X and Y is: (%.2f, %.2f)",((s.width/2)), (sprite->getContentSize().height/2));
    this->addChild(sprite, 0);
    
    //HUD sprites
    //coin sprite
    _coinS = Sprite::create("coin1.jpg");
    _coinS->setPosition(Vec2(s.width/4, s.height - sprite->getContentSize().height/2));
    CCLOG("background X and Y is: (%.2f, %.2f)",((s.width/3)), (s.height/7));
    this->addChild(_coinS);
    
    //coins per click sprite
    _coinPerClickS = Sprite::create("mouse-click1.png");
    _coinPerClickS->setPosition(Vec2(s.width/4 + s.width/4, s.height - sprite->getContentSize().height/2));
    CCLOG("background X and Y is: (%.2f, %.2f)",((s.width/3 + 60)), (s.height/7));
    this->addChild(_coinPerClickS);
    
    //passive income per second sprite
    _coinPerSecondS = Sprite::create("hourglass1.png");
    _coinPerSecondS->setPosition(Vec2(s.width/4 + (s.width/4)*2, s.height - sprite->getContentSize().height/2));
    CCLOG("background X and Y is: (%.2f, %.2f)",((s.width/3 + 120)), (s.height/7));
    this->addChild(_coinPerSecondS);
    
    //local database pointer
    def = UserDefault::getInstance();
    //HUD Labels
    
    //coin label
    Coins = Label::createWithTTF(StringUtils::toString(def->getIntegerForKey("Coins")), "fonts/arial.ttf", 60);
    //grab interger value from database, then convert to string to fit the argument
    Coins->setScale(0.5f);
    Coins->setAnchorPoint(Point(0.0f, 0.5f));
    Coins->setPosition(Point(s.width/4 + _coinS->getContentSize().width, s.height - sprite->getContentSize().height/2));
    CCLOG("background X and Y is: (%.2f, %.2f)", 90.00, (s.height/7));

    addChild(Coins);
    
    //coin per click label
    CoinsPerClick = Label::createWithTTF(StringUtils::toString(def->getIntegerForKey("Coins per click")), "fonts/arial.ttf", 60);
    CoinsPerClick->setScale(0.5f);
    CoinsPerClick->setAnchorPoint(Point(0.0f, 0.5f));
    CoinsPerClick->setPosition(Point((s.width/4)*2 + CoinsPerClick->getContentSize().width, s.height - sprite->getContentSize().height/2));
    CCLOG("background X and Y is: (%.2f, %.2f)",180.00, (s.height/7));
    addChild(CoinsPerClick);
    
    //coin per second label
    CoinsPerSecond = Label::createWithTTF(StringUtils::toString(def->getIntegerForKey("Passive income")), "fonts/arial.ttf", 60);
    CoinsPerSecond->setScale(0.5f);
    CoinsPerSecond->setAnchorPoint(Point(0.0f, 0.5f));
    CoinsPerSecond->setPosition(Point((s.width/4)*3 + CoinsPerSecond->getContentSize().width, s.height - sprite->getContentSize().height/2));
    CCLOG("background X and Y is: (%.2f, %.2f)", 270.00, (s.height/7));
    addChild(CoinsPerSecond);
    
    return true;

}

/*
 //pass in pointer to database and the new value to be set
void HUD::updateCoins(UserDefault *def, int NewCoin)
{
    
    delete Coins;
    __String *tempScore = __String::createWithFormat( "%i", NewCoin);
    //changing label string value for display
    Coins->setString(tempScore->getCString( ));
    //updating the local database
    def->setIntegerForKey("Coins", NewCoin + def->getIntegerForKey("Coins"));
}
void HUD::updateCoinsPClick(int NewClickValue);
void HUD::updateCoinsPSec(int NewPassiveIncome);


*/



