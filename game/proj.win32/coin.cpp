#include "coin.h"


Coin::Coin(void)
{
	sprite = CCSprite::create("ring1.png");
	size = CCDirector::sharedDirector()->getWinSize();
	sprite->setPosition(ccp(size.width/4 - 10, size.height/4 + 10));
}

Coin::~Coin(void)
{
}

void Coin::rotateAction()
{
	CCAnimation* action = CCAnimation::create();
	action->setDelayPerUnit(0.1f);
	action->setRestoreOriginalFrame(true);
	action->addSpriteFrameWithFileName("ring1.png");
	action->addSpriteFrameWithFileName("ring2.png");
	action->addSpriteFrameWithFileName("ring3.png");
	action->addSpriteFrameWithFileName("ring4.png");
	CCAnimate* animate = CCAnimate::create(action);
	CCRepeatForever* repeat = CCRepeatForever::create(animate);
	sprite->runAction(repeat);

}