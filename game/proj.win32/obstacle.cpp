#include "obstacle.h"


Obstacle::Obstacle(int i)
{
	if(i == 1)
		sprite = CCSprite::create("obs1.png");
	else
		sprite = CCSprite::create("obs2.png");
	size = CCDirector::sharedDirector()->getWinSize();
	sprite->setPosition(ccp(size.width/4 - 10, size.height/4 + 10));

}


Obstacle::~Obstacle(void)
{
}
