
#include "HelloWorldScene.h"

using namespace cocos2d;

CCScene* HelloWorld::scene()
{
    CCScene * scene = NULL;
	HelloWorld *layer = NULL;
    do 
    {
        
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        
		layer = HelloWorld::create();
        CC_BREAK_IF(! layer);

        
        scene->addChild(layer);
    } while (0);
	layer->setTouchEnabled(true);
    
    return scene;
}

bool HelloWorld::init()
{
    bool bRet = false;
	
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    do 
    {


        CC_BREAK_IF(! CCLayer::init());

		CCSize size = CCDirector::sharedDirector()->getWinSize();
        CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            this,
            menu_selector(HelloWorld::menuCloseCallback));
        CC_BREAK_IF(! pCloseItem);

        pCloseItem->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20));


		CCMenuItemImage *pStartItem = CCMenuItemImage::create(
            "start.png",
			NULL,
            this,
            menu_selector(HelloWorld::next));
        CC_BREAK_IF(! pStartItem);

        pStartItem->setPosition(ccp(size.width / 2, size.height / 3));

        CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
        pMenu->setPosition(CCPointZero);
		pMenu->addChild(pStartItem);
        CC_BREAK_IF(! pMenu);

        this->addChild(pMenu, 1);

        CCSprite* pLabel = CCSprite::create("title.png");
        CC_BREAK_IF(! pLabel);

       pLabel->setPosition(ccp(0, size.height - 100));
	   CCMoveTo* titleMove = CCMoveTo::create(1,ccp(size.width / 2, size.height - 100));
        this->addChild(pLabel, 1);
		pLabel->runAction(titleMove);
		_backgroundNode = CCParallaxNodeExtras::node(); //1 
		this->addChild(_backgroundNode,-1) ;
 

_spacedust1 = CCSprite::create("clouds.png");
_spacedust2 = CCSprite::create("clouds.png");
_planetsunrise = CCSprite::create("land_green.png");
_galaxy = CCSprite::create("land_green.png");
_galaxy2 = CCSprite::create("land_green.png");
_spacialanomaly = CCSprite::create("sky_evening.png");
_spacialanomaly2 = CCSprite::create("sky_evening.png"); 
 _spacialanomaly3 = CCSprite::create("sky_evening.png"); 


CCPoint dustSpeed = ccp(0.005, 0.005);
CCPoint bgSpeed = ccp(0.2, 0.2);
 

_backgroundNode->addChild(_spacedust1, 0 , dustSpeed , ccp(0,winSize.height * 0.70) ); // 2
_backgroundNode->addChild(_spacedust2, 0 , dustSpeed , ccp( _spacedust1->getContentSize().width,winSize.height * 0.70)); 
_backgroundNode->addChild(_galaxy,-1, bgSpeed , ccp(0,winSize.height * 0.2));
_backgroundNode->addChild(_planetsunrise,-1 , bgSpeed,ccp(_galaxy->getContentSize().width,winSize.height * 0.2));  
_backgroundNode->addChild(_galaxy2,-1 , bgSpeed,ccp(_galaxy->getContentSize().width * 2,winSize.height * 0.2));   
_backgroundNode->addChild(_spacialanomaly,-2, bgSpeed,ccp(0,winSize.height * 0.5));      
_backgroundNode->addChild(_spacialanomaly2,-2, bgSpeed,ccp(_spacialanomaly->getContentSize().width,winSize.height /2));
_backgroundNode->addChild(_spacialanomaly3,-2, bgSpeed,ccp(_spacialanomaly->getContentSize().width * 2,winSize.height /2));



		player = CCSprite::create("ok4.png");
		CC_BREAK_IF(! player);
		player->setPosition(ccp(size.width/2, size.height/4 - 25));
		this->addChild(player, 0);
		CCAnimation* animation = CCAnimation::create();
		animation->setDelayPerUnit(0.05f);
		animation->setRestoreOriginalFrame(true);
		animation->addSpriteFrameWithFileName("ok4.png");
		animation->addSpriteFrameWithFileName("ok5.png");
		animation->addSpriteFrameWithFileName("ok6.png");
		animation->addSpriteFrameWithFileName("ok7.png");
		animation->addSpriteFrameWithFileName("ok8.png");
		animation->addSpriteFrameWithFileName("ok9.png");
		animation->addSpriteFrameWithFileName("ok10.png");
		animation->addSpriteFrameWithFileName("ok11.png");
		CCAnimate* animate = CCAnimate::create(animation);
		CCRepeatForever* repeat = CCRepeatForever::create(animate);
		repeat->setTag(333);
		CCMoveTo* moveto = CCMoveTo::create(3,ccp(size.width/7, size.height/4 - 25));
		player->runAction(repeat);
		player->runAction(moveto);
        bRet = true;
    } while (0);
	this->scheduleUpdate();
    return bRet;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    // "close" menu item clicked
    CCDirector::sharedDirector()->end();
}

void HelloWorld::update(float dt) {

	if(player->getActionByTag(111))
	{
		if(player->getPositionX() > 470)
		{
			CCScene *s = Menu::scene();
			CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5,s));
		}
	}
  CCPoint backgroundScrollVert = ccp(-1000,0) ;
  _backgroundNode->setPosition(ccpAdd(_backgroundNode->getPosition(),ccpMult(backgroundScrollVert,dt))) ; 

  CCArray *spaceDusts = CCArray::createWithCapacity(2) ;
spaceDusts->addObject(_spacedust1) ;
spaceDusts->addObject(_spacedust2) ;
for ( int ii = 0  ; ii <spaceDusts->count() ; ii++ ) {
    CCSprite * spaceDust = (CCSprite *)(spaceDusts->objectAtIndex(ii)) ;
    float xPosition = _backgroundNode->convertToWorldSpace(spaceDust->getPosition()).x  ;
    float size = spaceDust->getContentSize().width ;
    if ( xPosition < -size ) {
        _backgroundNode->incrementOffset(ccp(spaceDust->getContentSize().width*2,0),spaceDust) ; 
    }                                   
}

  CCArray *sky = CCArray::createWithCapacity(2) ;
sky->addObject(_spacialanomaly) ;
sky->addObject(_spacialanomaly2) ;
sky->addObject(_spacialanomaly3) ;
for ( int ii = 0  ; ii <sky->count() ; ii++ ) {
    CCSprite * bg = (CCSprite *)(sky->objectAtIndex(ii)) ;
    float xPosition = _backgroundNode->convertToWorldSpace(bg->getPosition()).x  ;
    float size = bg->getContentSize().width ;
    if ( xPosition < -size ) {
        _backgroundNode->incrementOffset(ccp(bg->getContentSize().width*3,0),bg) ; 
    }                                   
}


 
CCArray *backGrounds = CCArray::createWithCapacity(2) ;
backGrounds->addObject(_galaxy) ;
backGrounds->addObject(_galaxy2) ;
backGrounds->addObject(_planetsunrise) ;
for ( int ii = 0 ; ii <backGrounds->count() ; ii++ ) {
    CCSprite * background = (CCSprite *)(backGrounds->objectAtIndex(ii)) ;
    float xPosition = _backgroundNode->convertToWorldSpace(background->getPosition()).x ;
    float size = background->getContentSize().width ;
    if ( xPosition < -size ) {
        _backgroundNode->incrementOffset(ccp(_spacialanomaly->getContentSize().width*3,0),background) ; 
    }
}
}

void HelloWorld::ccTouchesBegan(CCSet* touches, CCEvent* event)
{
	CCTouch* touch = (CCTouch*)( touches->anyObject() );
    CCPoint location = touch->getLocationInView();
	pos.x = location.x;
	pos.y = location.y;
}


void HelloWorld::ccTouchesEnded(CCSet *touches, CCEvent *pEvent)
{/*
	CCTouch* touch = (CCTouch*)( touches->anyObject() );
    CCPoint location = touch->getLocationInView();
	CCAnimation* animation = CCAnimation::create();

	if(fabs(pos.x - location.x) < 20 && fabs(pos.y - location.y) < 20)
	{	
		animation->setDelayPerUnit(0.05f);
		animation->setRestoreOriginalFrame(true);
		animation->addSpriteFrameWithFileName("ok4.png");
		animation->addSpriteFrameWithFileName("ok5.png");
		animation->addSpriteFrameWithFileName("ok6.png");
		animation->addSpriteFrameWithFileName("ok7.png");
		animation->addSpriteFrameWithFileName("ok8.png");
		animation->addSpriteFrameWithFileName("ok9.png");
		animation->addSpriteFrameWithFileName("ok10.png");
		animation->addSpriteFrameWithFileName("ok11.png");
		CCAnimate* animate = CCAnimate::create(animation);
		CCRepeatForever* repeat = CCRepeatForever::create(animate);
		player->stopAllActions();
		player->runAction(repeat);
	}
	else if((pos.x - location.x > 0) && (fabs(pos.x - location.x) > fabs(pos.y - location.y)))
	{
		animation->setDelayPerUnit(0.05f);
		animation->setRestoreOriginalFrame(true);
		animation->addSpriteFrameWithFileName("speed0.png");
		animation->addSpriteFrameWithFileName("speed1.png");
		animation->addSpriteFrameWithFileName("speed2.png");
		animation->addSpriteFrameWithFileName("speed3.png");
		animation->addSpriteFrameWithFileName("speed4.png");
		animation->addSpriteFrameWithFileName("speed5.png");
		animation->addSpriteFrameWithFileName("speed6.png");
		animation->addSpriteFrameWithFileName("speed7.png");
		animation->addSpriteFrameWithFileName("speed8.png");
		CCAnimate* animate = CCAnimate::create(animation);
		CCRepeatForever* repeat = CCRepeatForever::create(animate);
		player->stopAllActions();
		player->runAction(repeat);
	}
	else if((pos.x - location.x < 0) && (fabs(pos.x - location.x) > fabs(pos.y - location.y)))
	{
		animation->setDelayPerUnit(0.03f);
		animation->setRestoreOriginalFrame(true);
		animation->addSpriteFrameWithFileName("speed9.png");
		animation->addSpriteFrameWithFileName("speed10.png");
		animation->addSpriteFrameWithFileName("speed11.png");
		animation->addSpriteFrameWithFileName("speed12.png");
		animation->addSpriteFrameWithFileName("speed13.png");
		animation->addSpriteFrameWithFileName("speed14.png");
		animation->addSpriteFrameWithFileName("speed15.png");
		animation->addSpriteFrameWithFileName("speed16.png");
		CCAnimate* animate = CCAnimate::create(animation);
		CCRepeatForever* repeat = CCRepeatForever::create(animate);
		player->stopAllActions();
		player->runAction(repeat);
	}
	else if((pos.y - location.y > 0) && (fabs(pos.x - location.x) < fabs(pos.y - location.y)))
	{
		
	}
	else if((pos.y - location.y < 0) && (fabs(pos.x - location.x) < fabs(pos.y - location.y)))
	{
		animation->setDelayPerUnit(0.05f);
		animation->setRestoreOriginalFrame(true);
		animation->addSpriteFrameWithFileName("slash1.png");
		animation->addSpriteFrameWithFileName("slash2.png");
		animation->addSpriteFrameWithFileName("slash3.png");
		animation->addSpriteFrameWithFileName("slash4.png");
		CCAnimate* animate = CCAnimate::create(animation);
		CCRepeatForever* repeat = CCRepeatForever::create(animate);
		player->stopAllActions();
		player->runAction(repeat);
	}

	

*/
}


void HelloWorld::next(CCObject* pSender)
{
	CCAnimation* animation = CCAnimation::create();
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	animation->setDelayPerUnit(0.03f);
	animation->setRestoreOriginalFrame(true);
	animation->addSpriteFrameWithFileName("speed0.png");
	animation->addSpriteFrameWithFileName("speed1.png");
	animation->addSpriteFrameWithFileName("speed2.png");
	animation->addSpriteFrameWithFileName("speed3.png");
	animation->addSpriteFrameWithFileName("speed4.png");
	animation->addSpriteFrameWithFileName("speed5.png");
	animation->addSpriteFrameWithFileName("speed6.png");
	animation->addSpriteFrameWithFileName("speed7.png");
	animation->addSpriteFrameWithFileName("speed8.png");
	CCAnimate* animate = CCAnimate::create(animation);
	CCRepeatForever* repeat = CCRepeatForever::create(animate);
	CCMoveTo* moveto = CCMoveTo::create(1,ccp(size.width, size.height/4 - 25));
	moveto->setTag(111);
	moveto->update(0.5);
	player->stopAllActions();
	player->runAction(repeat);
	player->runAction(moveto);
	

	
}