#ifndef  _HUD_H__
#define  _HUD_H__
#include "cocos2d.h"

USING_NS_CC;

class HUD : public Layer
{
private:
    Label *Coins;
    Label *CoinsPerClick;
    Label *CoinsPerSecond;
    
    Sprite* _coinS;
    Sprite* _coinPerClickS;
    Sprite* _coinPerSecondS;
public:
    //void setCoins(int);
    //void setCoinsPClick(int);
    //void setCoinsPSec(int);
    
    virtual bool init();
    CREATE_FUNC(HUD);

};

#endif // _HUD_HPP_
