#include "Player.h"


Player::Player(void)
{
	vie = 3;
	score = 0;
	inAction = false;
	sprite = CCSprite::create("yes6.png");
	size = CCDirector::sharedDirector()->getWinSize();
	sprite->setPosition(ccp(size.width/7 - 10, size.height/4));
}


Player::~Player(void)
{
}

void Player::jumpAction()
{
	inAction = true;
	CCAnimation* action = CCAnimation::create();
	CCJumpTo*	jumpPlayer = CCJumpTo::create(1,ccp(size.width/2, size.height/4),100,1);
	action->setDelayPerUnit(0.11f);
	action->setRestoreOriginalFrame(true);
	action->addSpriteFrameWithFileName("jump1.png");
	action->addSpriteFrameWithFileName("jump2.png");
	action->addSpriteFrameWithFileName("jump3.png");
	action->addSpriteFrameWithFileName("jump4.png");
	action->addSpriteFrameWithFileName("jump5.png");
	action->addSpriteFrameWithFileName("jump6.png");
	action->addSpriteFrameWithFileName("jump7.png");
	action->addSpriteFrameWithFileName("jump8.png");
	action->addSpriteFrameWithFileName("jump9.png");
	CCAnimate* animate = CCAnimate::create(action);
	sprite->stopAllActions();
	sprite->runAction(animate);
	sprite->runAction(jumpPlayer);
}

void Player::slideAction()
{
	inAction = 1;
	CCAnimation* action = CCAnimation::create();
	action->setDelayPerUnit(0.1f);
	action->setRestoreOriginalFrame(true);
	action->addSpriteFrameWithFileName("slash1.png");
	action->addSpriteFrameWithFileName("slash2.png");
	action->addSpriteFrameWithFileName("slash3.png");
	action->addSpriteFrameWithFileName("slash4.png");
	CCAnimate* animate = CCAnimate::create(action);
	CCRepeatForever* repeat = CCRepeatForever::create(animate);
	sprite->stopAllActions();
	sprite->runAction(animate);
}

void Player::fastAction()
{
	inAction = 0;
	CCAnimation* action = CCAnimation::create();
	action->setDelayPerUnit(0.04f);
	action->setRestoreOriginalFrame(true);
	action->addSpriteFrameWithFileName("speed9.png");
	action->addSpriteFrameWithFileName("speed10.png");
	action->addSpriteFrameWithFileName("speed11.png");
	action->addSpriteFrameWithFileName("speed12.png");
	action->addSpriteFrameWithFileName("speed13.png");
	action->addSpriteFrameWithFileName("speed14.png");
	action->addSpriteFrameWithFileName("speed15.png");
	action->addSpriteFrameWithFileName("speed16.png");
	sprite->stopAllActions();
	CCAnimate* animate = CCAnimate::create(action);
	CCRepeatForever* repeat = CCRepeatForever::create(animate);
	CCMoveTo* goMiddle = CCMoveTo::create(1,ccp(size.width/2, size.height/4 + 10));
	sprite->runAction(goMiddle);
	sprite->runAction(repeat);
}

void Player::runAction()
{
	CCAnimation* action = CCAnimation::create();
	action->setDelayPerUnit(0.04f);
	action->setRestoreOriginalFrame(true);
	action->addSpriteFrameWithFileName("speed0.png");
	action->addSpriteFrameWithFileName("speed1.png");
	action->addSpriteFrameWithFileName("speed2.png");
	action->addSpriteFrameWithFileName("speed3.png");
	action->addSpriteFrameWithFileName("speed4.png");
	action->addSpriteFrameWithFileName("speed5.png");
	action->addSpriteFrameWithFileName("speed6.png");
	action->addSpriteFrameWithFileName("speed7.png");
	action->addSpriteFrameWithFileName("speed8.png");
	sprite->stopAllActions();
	CCAnimate* animate = CCAnimate::create(action);
	CCRepeatForever* repeat = CCRepeatForever::create(animate);
	CCMoveTo* goMiddle = CCMoveTo::create(1,ccp(size.width/2, size.height/4 + 10));
	sprite->runAction(goMiddle);
	sprite->runAction(repeat);
}

void Player::introAction()
{
	CCAnimation* action = CCAnimation::create();
	action->setDelayPerUnit(0.09f);
	action->setRestoreOriginalFrame(true);
	action->addSpriteFrameWithFileName("yes1.png");
	action->addSpriteFrameWithFileName("yes2.png");
	action->addSpriteFrameWithFileName("yes3.png");
	action->addSpriteFrameWithFileName("yes4.png");
	action->addSpriteFrameWithFileName("yes5.png");
	action->addSpriteFrameWithFileName("yes6.png");
	action->addSpriteFrameWithFileName("yes6.png");
	action->addSpriteFrameWithFileName("yes6.png");
	action->addSpriteFrameWithFileName("yes6.png");
	action->addSpriteFrameWithFileName("yes6.png");
	action->addSpriteFrameWithFileName("yes6.png");
	action->addSpriteFrameWithFileName("yes6.png");
	action->addSpriteFrameWithFileName("yes6.png");
	action->addSpriteFrameWithFileName("yes6.png");
	action->addSpriteFrameWithFileName("yes6.png");
	action->addSpriteFrameWithFileName("yes6.png");
	action->addSpriteFrameWithFileName("yes6.png");
	action->addSpriteFrameWithFileName("yes6.png");
	action->addSpriteFrameWithFileName("yes6.png");
	action->addSpriteFrameWithFileName("yes6.png");
	action->addSpriteFrameWithFileName("yes6.png");
	action->addSpriteFrameWithFileName("wait7.png");
	action->addSpriteFrameWithFileName("wait8.png");
	action->addSpriteFrameWithFileName("wait9.png");
	action->addSpriteFrameWithFileName("wait10.png");
	action->addSpriteFrameWithFileName("wait11.png");
	action->addSpriteFrameWithFileName("wait12.png");
	action->addSpriteFrameWithFileName("wait11.png");
	action->addSpriteFrameWithFileName("wait10.png");
	action->addSpriteFrameWithFileName("wait9.png");
	action->addSpriteFrameWithFileName("wait8.png");
	action->addSpriteFrameWithFileName("wait9.png");
	action->addSpriteFrameWithFileName("wait10.png");
	action->addSpriteFrameWithFileName("wait11.png");
	action->addSpriteFrameWithFileName("wait12.png");
	action->addSpriteFrameWithFileName("wait11.png");
	action->addSpriteFrameWithFileName("wait10.png");
	action->addSpriteFrameWithFileName("wait9.png");
	action->addSpriteFrameWithFileName("wait8.png");
	action->addSpriteFrameWithFileName("wait7.png");
	action->addSpriteFrameWithFileName("wait6.png");
	action->addSpriteFrameWithFileName("wait5.png");
	action->addSpriteFrameWithFileName("wait4.png");
	action->addSpriteFrameWithFileName("wait3.png");
	action->addSpriteFrameWithFileName("wait2.png");
	action->addSpriteFrameWithFileName("wait1.png");
	action->addSpriteFrameWithFileName("wait2.png");
	action->addSpriteFrameWithFileName("wait3.png");
	action->addSpriteFrameWithFileName("wait4.png");
	action->addSpriteFrameWithFileName("wait5.png");
	action->addSpriteFrameWithFileName("wait4.png");
	action->addSpriteFrameWithFileName("wait3.png");
	action->addSpriteFrameWithFileName("wait2.png");
	action->addSpriteFrameWithFileName("wait1.png");
	action->addSpriteFrameWithFileName("wait2.png");
	action->addSpriteFrameWithFileName("wait3.png");
	action->addSpriteFrameWithFileName("wait4.png");
	action->addSpriteFrameWithFileName("wait5.png");
	action->addSpriteFrameWithFileName("wait6.png");
	action->addSpriteFrameWithFileName("wait7.png");
	action->addSpriteFrameWithFileName("wait8.png");
	action->addSpriteFrameWithFileName("wait9.png");
	action->addSpriteFrameWithFileName("wait10.png");
	action->addSpriteFrameWithFileName("wait11.png");
	action->addSpriteFrameWithFileName("wait12.png");
	action->addSpriteFrameWithFileName("wait11.png");
	action->addSpriteFrameWithFileName("wait10.png");
	action->addSpriteFrameWithFileName("wait9.png");
	action->addSpriteFrameWithFileName("wait8.png");
	action->addSpriteFrameWithFileName("wait9.png");
	action->addSpriteFrameWithFileName("wait10.png");
	action->addSpriteFrameWithFileName("wait11.png");
	action->addSpriteFrameWithFileName("wait12.png");
	action->addSpriteFrameWithFileName("wait11.png");
	action->addSpriteFrameWithFileName("wait10.png");
	action->addSpriteFrameWithFileName("wait9.png");
	action->addSpriteFrameWithFileName("wait8.png");
	action->addSpriteFrameWithFileName("wait7.png");
	action->addSpriteFrameWithFileName("wait6.png");
	action->addSpriteFrameWithFileName("wait5.png");
	action->addSpriteFrameWithFileName("wait4.png");
	action->addSpriteFrameWithFileName("wait3.png");
	action->addSpriteFrameWithFileName("wait2.png");
	action->addSpriteFrameWithFileName("wait1.png");
	action->addSpriteFrameWithFileName("wait2.png");
	action->addSpriteFrameWithFileName("wait3.png");
	action->addSpriteFrameWithFileName("wait4.png");
	action->addSpriteFrameWithFileName("wait5.png");
	action->addSpriteFrameWithFileName("wait4.png");
	action->addSpriteFrameWithFileName("wait3.png");
	action->addSpriteFrameWithFileName("wait2.png");
		
	CCAnimate* animate = CCAnimate::create(action);
	animate->setTag(333);
	sprite->runAction(animate);
}