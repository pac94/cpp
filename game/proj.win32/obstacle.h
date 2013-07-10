#ifndef __OBSTABLE_H__
#define __OBSTABLE_H__
#include "cocos2d.h"

USING_NS_CC ;
class Obstacle
{
public:
	CCSprite* sprite;
	CCSize size;
	Obstacle(int i);
	~Obstacle(void);
};
#endif
