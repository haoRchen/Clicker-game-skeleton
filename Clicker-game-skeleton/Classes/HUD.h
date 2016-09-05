#ifndef  _HUD_H__
#define  _HUD_H__
#include "cocos2d.h"

USING_NS_CC;

class HUD : public Layer
{
private:
    //hud background layer
    Sprite* hudBackground;
    //labels for each sprite inside the hud
    Label *Coins;
    Label *CoinsPerClick;
    Label *CoinsPerSecond;
    //value trackers
    int _coinAmount;
    int _coinGainPerClick;
    int _coinGainPerSec;
    //sprites for income types, displayed inside the hud
    Sprite* _coinS;
    Sprite* _coinPerClickS;
    Sprite* _coinPerSecondS;
    //local database pointer
    UserDefault *def;
    float size;
public:
    //updating values. Will add parameter to original amount in the database
    void updateCoins(int NewCoin);
    void updateCoinsPClick(int NewClickValue);
    void updateCoinsPSec(int NewPassiveIncome);
    //getters for private variables
    int get_coinAmount();
    int get_coinGainPerClick();
    int get_coinGainPerSec();
    //setters for private variables
    void set_coinAmount(int);
    void set_coinPerClick(int);
    void set_coinGainPerSec(int);
    //Returns a pointer to the HUD background sprite
    Sprite* getBackgroundSprite();
    
    virtual bool init();
    CREATE_FUNC(HUD);
    //difference between frames. Used for scheduled calls
    void update(float dt);

};

#endif // _HUD_HPP_
