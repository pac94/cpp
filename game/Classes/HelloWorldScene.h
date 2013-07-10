#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

#include "Box2D/Box2D.h"
#include "MenuScene.h"
#include "SimpleAudioEngine.h"
#include "CParallaxNodeExtras.h"
#include <math.h>

USING_NS_CC ;

class HelloWorld : public CCLayer
{
public:
    
    virtual bool init();  

   
    static cocos2d::CCScene* scene();
    
    
    void menuCloseCallback(CCObject* pSender);
	void ccTouchesEnded(CCSet* touches, CCEvent* event);
	void ccTouchesBegan(CCSet* touches, CCEvent* event);
	void next(CCObject* pSender);
	CCSprite* player;
	void update(float dt);
    CREATE_FUNC(HelloWorld);
	CCPoint pos;
private:
	CCParallaxNodeExtras *_backgroundNode; 
CCSprite *_spacedust1;
CCSprite *_spacedust2;
CCSprite *_planetsunrise;
CCSprite *_galaxy;
CCSprite *_galaxy2;
CCSprite *_spacialanomaly;
CCSprite *_spacialanomaly2;
CCSprite *_spacialanomaly3;
};

#endif  