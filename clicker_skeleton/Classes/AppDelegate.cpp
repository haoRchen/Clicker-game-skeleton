#include "AppDelegate.h"
#include "HelloWorldScene.h"

USING_NS_CC;

//static cocos2d::Size designResolutionSize = cocos2d::Size(480, 320);
//static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
//static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
//static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate() 
{
}

// if you want a different context, modify the value of glContextAttrs
// it will affect all platforms
void AppDelegate::initGLContextAttrs()
{
    // set OpenGL context attributes: red,green,blue,alpha,depth,stencil
    //rendering purposes 
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};
    
    GLView::setGLContextAttrs(glContextAttrs);
}

// if you want to use the package manager to install more packages,
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::create("MyCppGame");
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0f / 60);
    
    auto fileUtils = FileUtils::getInstance();
    //storing device resolution
    auto screenSize = glview->getFrameSize();
    
    CCLOG("%f, %f", screenSize.width, screenSize.height);
    //resolution order
    std::vector<std::string> resDirOrders;
    //check which asset the device requires
    //2048x1536 for ipad pro 9.7/air 2/mini4 and 2
    if(screenSize.width == 2048 || screenSize.height == 2048)
    {
        CCLOG("screensize 2048 x 1536****");
        resDirOrders.push_back("ipad pro 9.7:air2:mini4and2");
        resDirOrders.push_back("iphone 6");
        resDirOrders.push_back("iphone 5");
        //design resolution for landscape, for portrait set to 1536, 2048
        glview->setDesignResolutionSize(screenSize.width, screenSize.height, ResolutionPolicy::NO_BORDER);
    
    }
    //iphone 6 resolution
    else if(screenSize.width == 1334 || screenSize.height == 1334)
    {
        CCLOG("screensize 1334 x 750***");
        resDirOrders.push_back("iphone 6");
        resDirOrders.push_back("iphone 5");
        glview->setDesignResolutionSize(screenSize.width, screenSize.height, ResolutionPolicy::FIXED_WIDTH);
        
    }
    //iphone 5 resolution
    else
    {
        CCLOG("screensize 1136 x 640****");
        resDirOrders.push_back("iphone 5");
        glview->setDesignResolutionSize(screenSize.width, screenSize.height, ResolutionPolicy::NO_BORDER);
        //1136 x 640
        
    }
    //search vector order of resolution
    fileUtils->setSearchPaths(resDirOrders);
    
    // create a scene. it's an autorelease object
    auto scene = HelloWorld::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be paused
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
