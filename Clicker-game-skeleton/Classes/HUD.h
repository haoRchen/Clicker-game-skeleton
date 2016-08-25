#ifndef  _HUD_H__
#define  _HUD_H__
#include "cocos2d.h"

USING_NS_CC;

class HUD : public Layer
{
private:
    Sprite* sprite;
    Label *Coins;
    Label *CoinsPerClick;
    Label *CoinsPerSecond;
    
    int _coinAmount;
    int _coinGainPerClick;
    int _coinGainPerSec;
    
    Sprite* _coinS;
    Sprite* _coinPerClickS;
    Sprite* _coinPerSecondS;
    //local database pointer
    UserDefault *def;
public:
    void updateCoins(int NewCoin);
    void updateCoinsPClick(int NewClickValue);
    void updateCoinsPSec(int NewPassiveIncome);
    int get_coinAmount();
    int get_coinGainPerClick();
    int get_coinGainPerSec();
    void set_coinAmount(int);
    void set_coinPerClick(int);
    void set_coinGainPerSec(int);
    //Returns a pointer to the HUD background sprite
    Sprite* getBackgroundSprite();
    
    virtual bool init();
    CREATE_FUNC(HUD);
    //difference between frames
    void update(float dt);

};

#endif // _HUD_HPP_
