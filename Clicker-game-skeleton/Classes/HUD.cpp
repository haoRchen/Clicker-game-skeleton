#include "HUD.h"

USING_NS_CC;

bool HUD::init()
{
    size = 1;
    Size s = Director::getInstance()->getVisibleSize();
    //HUD background
    hudBackground = Sprite::create("greybackground1.jpeg");
    hudBackground->setPosition(Vec2(s.width/2, s.height - hudBackground->getContentSize().height/2));
    this->addChild(hudBackground, 0);
    
    if(s.width == 2048 || s.height == 2048)
    {
        size = s.height / 1136;
        CCLOG("%f is the size of content scale", size);
    }
    //HUD sprites
    //coin sprite
    _coinS = Sprite::create("coin1.jpg");
    _coinS->setPosition(Vec2(s.width/4, s.height - hudBackground->getContentSize().height/2));
    this->addChild(_coinS);
    
    //coins per click sprite
    _coinPerClickS = Sprite::create("mouse-click1.png");
    _coinPerClickS->setPosition(Vec2((s.width/4)*2, s.height - hudBackground->getContentSize().height/2));
    this->addChild(_coinPerClickS);
    
    //passive income per second sprite
    _coinPerSecondS = Sprite::create("hourglass1.png");
    _coinPerSecondS->setPosition(Vec2(s.width/4 + (s.width/4)*2, s.height - hudBackground->getContentSize().height/2));
    this->addChild(_coinPerSecondS);
    
    //local database pointer
    def = UserDefault::getInstance();
    //delete the app from iphone/ipad simulator to reset userdefault database
    //searches key in database to see if the key exist
    if (def->getIntegerForKey("Coins", 111) == 111 && def->getIntegerForKey("Coins per click", 222) == 222 && def->getIntegerForKey("Passive income", 333) == 333){
        //creates a key with the integer value
        def->setIntegerForKey("Coins", 0);
        def->setIntegerForKey("Coins per click", 1);
        def->setIntegerForKey("Passive income", 0);
        def->flush();
        CCLOG("database values initialized");
    }
    _coinAmount = def->getIntegerForKey("Coins");
    _coinGainPerClick = def->getIntegerForKey("Coins per click");
    _coinGainPerSec = def->getIntegerForKey("Passive income");
    CCLOG("%d", def->getIntegerForKey("Coins per click"));
    CCLOG("%d", _coinGainPerClick);
    
    
    //HUD Labels
    
    //coin label
    Coins = Label::createWithTTF(StringUtils::toString(_coinAmount), "fonts/arial.ttf", 60*size);
    //grab interger value from database, then convert to string to fit the argument
    Coins->setScale(0.5f);
    Coins->setAnchorPoint(Point(0.5f, 0.5f));
    Coins->setPosition(Point(s.width/4 + _coinS->getContentSize().width, s.height - hudBackground->getContentSize().height/2));

    addChild(Coins);
    
    //coin per click label
    CoinsPerClick = Label::createWithTTF(StringUtils::toString(_coinGainPerClick), "fonts/arial.ttf", 60*size);
    CoinsPerClick->setScale(0.5f);
    CoinsPerClick->setAnchorPoint(Point(0.5f, 0.5f));
    CoinsPerClick->setPosition(Point((s.width/4)*2 + CoinsPerClick->getContentSize().width, s.height - hudBackground->getContentSize().height/2));
    addChild(CoinsPerClick);
    
    //coin per second label
    CoinsPerSecond = Label::createWithTTF(StringUtils::toString(_coinGainPerSec), "fonts/arial.ttf", 60*size);
    CoinsPerSecond->setScale(0.5f);
    CoinsPerSecond->setAnchorPoint(Point(0.5f, 0.5f));
    CoinsPerSecond->setPosition(Point((s.width/4)*3 + CoinsPerSecond->getContentSize().width, s.height - hudBackground->getContentSize().height/2));
    addChild(CoinsPerSecond);
    
    //manually resetting the database
    //updateCoins(-17000);
    //updateCoinsPClick(-5);
    //updateCoinsPSec(-100);
    
    
    //calls scheduler every 1 second for passive income
    this->schedule(schedule_selector(HUD::update), 1.0);
    return true;

}


 //pass in pointer to database and the new value to be set
void HUD::updateCoins(int NewCoin)
{
    
    set_coinAmount(get_coinAmount() + NewCoin);
    __String *tempScore = __String::createWithFormat( "%i", get_coinAmount());
    //changing label string value for display
    Coins->setString(tempScore->getCString( ));
    //updating the local database
    def->setIntegerForKey("Coins", get_coinAmount());
    def->flush();
}
void HUD::updateCoinsPClick(int NewClickValue)
{
    
    set_coinPerClick(get_coinGainPerClick() + NewClickValue);
    __String *tempScore = __String::createWithFormat( "%i", get_coinGainPerClick());
    //changing label string value for display
    CoinsPerClick->setString(tempScore->getCString( ));
    //updating the local database
    def->setIntegerForKey("Coins per click", get_coinGainPerClick());
    def->flush();
}
void HUD::updateCoinsPSec(int NewPassiveIncome)
{
    
    set_coinGainPerSec(get_coinGainPerSec() + NewPassiveIncome);
    __String *tempScore = __String::createWithFormat( "%i", get_coinGainPerSec());
    //changing label string value for display
    CoinsPerSecond->setString(tempScore->getCString( ));
    //updating the local database
    def->setIntegerForKey("Passive income", get_coinGainPerSec());
    def->flush();
}

//getter and setter definition
int HUD::get_coinAmount()
{
    return _coinAmount;
}
int HUD::get_coinGainPerClick()
{
    return _coinGainPerClick;
}
int HUD::get_coinGainPerSec()
{
    return _coinGainPerSec;
}
void HUD::set_coinAmount(int newCoin)
{
    _coinAmount = newCoin;
}
void HUD::set_coinPerClick(int newValuePerClick)
{
    _coinGainPerClick = newValuePerClick;
}
void HUD::set_coinGainPerSec(int newPassiveIncome)
{
    _coinGainPerSec = newPassiveIncome;
}

Sprite* HUD::getBackgroundSprite()
{
    return hudBackground;
}

//scheduler calls this function to update using delta time
void HUD::update(float dt)
{
    CCLOG("UPDATED coins ");
    //check if user will gain coin passively
    if(get_coinGainPerSec() > 0)
    {
        updateCoins(_coinGainPerSec);
    }
    
}




