#ifndef  _MESSAGEHUD_H__
#define  _MESSAGEHUD_H__

#include "cocos2d.h"

class MessageHUD : public cocos2d::LayerColor
{
    public:
        MessageHUD();
        ~MessageHUD();

        MessageHUD* createLayer(const std::string& _message);
        void initOptions(const std::string& _message);

        virtual void draw (cocos2d::Renderer * renderer, const cocos2d::Mat4 & transform,
                         bool transformUpdated);

    inline virtual cocos2d::LabelBMFont* getMessageLabel() { return _messageLabel; };

    private:
    cocos2d::LabelBMFont* _messageLabel;
};

#endif // _MESSAGEHUD_HPP_
