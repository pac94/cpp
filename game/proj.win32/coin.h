#ifndef __COIN_H__
#define __COIN_H__
#include "cocos2d.h"

USING_NS_CC ;
class Coin 
{
public:
	CCSize size;
	CCSprite* sprite;
	Coin(void);
	~Coin(void);
	void rotateAction();

};
#endif
