#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__
#include "cocos2d.h"
#include "Player.h"
#include "Box2D/Box2D.h"
#include "coin.h"
#include "CParallaxNodeExtras.h"
#include "obstacle.h"

class Game : public CCLayer
{
public:
	Game(void);
	~Game(void);
    virtual bool init();  
	Player* sonic;
	Coin* ring;
	float time;
	float obsDelay;
	float ringDelay;
	int truc;
	float randobs;
	int i,y,inAction;
	float Mytest;
	CCArray *rings;
	CCArray* obstacles; 
	CCArray * _blocks;
	CCPoint pos;
	CCSize visibleSize;
	CCLabelTTF* label;
    static cocos2d::CCScene* scene();
    void test(float dt);
	void addCoins();
	void addObstacle();
	void spriteMoveFinished(CCNode* sender);
    void menuCloseCallback(CCObject* pSender);
    void update(float dt);
	void showScore(int score);
	void ccTouchesEnded(CCSet* touches, CCEvent* event);
	void ccTouchesBegan(CCSet* touches, CCEvent* event);
		CCParallaxNodeExtras *_backgroundNode; 
CCSprite *_spacedust1;
CCSprite *_spacedust2;
CCSprite *_planetsunrise;
CCSprite *_galaxy;
CCSprite *_galaxy2;
CCSprite *_spacialanomaly;
CCSprite *_spacialanomaly2;
CCSprite *_spacialanomaly3;
    CREATE_FUNC(Game);
};
#endif
