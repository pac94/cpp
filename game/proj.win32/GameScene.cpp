#include "GameScene.h"
#include "MenuScene.h"
#include "AppMacros.h"
#include "GameOverScene.h"
USING_NS_CC;


CCScene* Game::scene()
{

	CCScene *scene = CCScene::create();


	Game *layer = Game::create();


	scene->addChild(layer);
	layer->setTouchEnabled(TRUE);

	return scene;
}


bool Game::init()
{

	if ( !CCLayer::init() )
	{
		return false;
	}

	visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	truc = 0;
	time = 0;
	obsDelay = 0;
	ringDelay = 0;
	randobs = 0;
	rings = new CCArray;
	obstacles = new CCArray;

	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		this,
		menu_selector(Game::menuCloseCallback));

	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
		origin.y + pCloseItem->getContentSize().height/2));


	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 1);


	label = CCLabelTTF::create("", "Arial bold", 24);
	label->setColor(ccc3(0,0,0));
	this->addChild(label, 0);
	label->setPosition( ccp(visibleSize.width/8, visibleSize.height-20) );

	CCSprite* toto = CCSprite::create("sky_evening.png");
	toto->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	this->addChild(toto,-2);

	CCSprite* toto1 = CCSprite::create("terre.png");
	toto1->setPosition(ccp(0, 20));
	this->addChild(toto1,-2);
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	sonic = new Player();
	sonic->introAction();
	this->addChild(sonic->sprite,0);
	_backgroundNode = CCParallaxNodeExtras::node(); 
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

	_backgroundNode->addChild(_spacedust1, 0 , dustSpeed , ccp(0,size.height * 0.70) ); 
	_backgroundNode->addChild(_spacedust2, 0 , dustSpeed , ccp( _spacedust1->getContentSize().width,size.height * 0.70)); 
	_backgroundNode->addChild(_galaxy,-1, bgSpeed , ccp(0,size.height * 0.2));
	_backgroundNode->addChild(_planetsunrise,-1 , bgSpeed,ccp(_galaxy->getContentSize().width,size.height * 0.2));  
	_backgroundNode->addChild(_galaxy2,-1 , bgSpeed,ccp(_galaxy->getContentSize().width * 2,size.height * 0.2));   
	_backgroundNode->addChild(_spacialanomaly,-2, bgSpeed,ccp(0,size.height * 0.5));      
	_backgroundNode->addChild(_spacialanomaly2,-2, bgSpeed,ccp(_spacialanomaly->getContentSize().width,size.height /2));
	_backgroundNode->addChild(_spacialanomaly3,-2, bgSpeed,ccp(_spacialanomaly->getContentSize().width * 2,size.height /2));
	i = y= inAction = 0;
	this->scheduleUpdate();
	Mytest = 0;

	return true;
}

void Game::update(float dt) {
	i++;
	time = time + dt;
	ringDelay = ringDelay +dt;
	obsDelay = obsDelay + dt;
	if(ringDelay > 0.4)
	{
		this->addCoins();
		ringDelay = 0;
	}

	if(obsDelay > randobs)
	{
		this->addObstacle();
		obsDelay = 0;
		randobs = (rand() %8)* 0.2 + 1.4;
	}

	CCSize size = CCDirector::sharedDirector()->getWinSize();
	CCObject* jt = NULL;
	if(i >500 && y == 0)
	{
		y = 1;
		sonic->runAction();
	}
	if(sonic->sprite->getPositionX() > (size.width/2 -5) && y == 1)
	{
		inAction = 0;
		sonic->fastAction();
		y =2;
	}
	if(sonic->sprite->numberOfRunningActions() < 1)
	{
		inAction = 0;
		sonic->fastAction();
	}

	CCRect sonicRect = CCRectMake( sonic->sprite->getPosition().x - (sonic->sprite->getContentSize().width/2),
		sonic->sprite->getPosition().y - (sonic->sprite->getContentSize().height/2),
		sonic->sprite->getContentSize().width,
		sonic->sprite->getContentSize().height);

	CCARRAY_FOREACH(obstacles, jt)
	{
		CCSprite*target = dynamic_cast<CCSprite*>(jt);
		CCRect coinRect = CCRectMake( target->getPosition().x - (target->getContentSize().width/2),
			target->getPosition().y - (target->getContentSize().height/2),
			target->getContentSize().width,
			target->getContentSize().height);

		if(sonicRect.intersectsRect(coinRect))
		{
			this->removeChild(target,true);
			obstacles->removeObject(target);
			CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("New_Super_Mario_Bros_Death_Sound_Effect.mp3", false);
			CCScene *s = GameOverScene::scene();
			CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5,s));
		}
	}



	CCARRAY_FOREACH(rings, jt)
	{
		CCSprite*target = dynamic_cast<CCSprite*>(jt);
		CCRect coinRect = CCRectMake( target->getPosition().x - (target->getContentSize().width/2),
			target->getPosition().y - (target->getContentSize().height/2),
			target->getContentSize().width,
			target->getContentSize().height);

		if(sonicRect.intersectsRect(coinRect))
		{
			sonic->score++;
			this->removeChild(target,true);
			rings->removeObject(target);
			//CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("Sonic_Ring_Sound_Effect.mp3", false);
		}
	}
	this->showScore(sonic->score);


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

void Game::addCoins()
{
	Coin *ring = new Coin();
	rings->addObject(ring->sprite);
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	int minY = ring->sprite->getContentSize().height/2 + winSize.height/4;
	int maxY = (winSize.height)*3/4 - ring->sprite->getContentSize().height/2;
	int rangeY = maxY - minY;

	int actualY = ( rand() % rangeY ) + minY;


	ring->sprite->setPosition( 
		ccp(winSize.width + (ring->sprite->getContentSize().width/2), 
		actualY) );
	this->addChild(ring->sprite);


	int minDuration = (int)2.0;
	int maxDuration = (int)4.0;
	int rangeDuration = maxDuration - minDuration;

	int actualDuration = ( rand() % rangeDuration )
		+ minDuration;


	CCFiniteTimeAction* actionMove = 
		CCMoveTo::create( (float)actualDuration, 
		ccp(0 - ring->sprite->getContentSize().width/2, actualY) );
	CCFiniteTimeAction* actionMoveDone = 
		CCCallFuncN::create( this, 
		callfuncN_selector(Game::spriteMoveFinished));
	ring->rotateAction();
	ring->sprite->runAction( CCSequence::create(actionMove, actionMoveDone, NULL) );
}

void Game::spriteMoveFinished(CCNode* sender)
{
	CCSprite *ring = (CCSprite*)sender;
	this->removeChild(ring, true);
}

void Game::showScore(int score)
{
	const int labelLength = 100;
	char scoreLabelText[labelLength];
	sprintf(scoreLabelText,"Score: %d", score);
	label->setString(scoreLabelText);

}

void Game::addObstacle()
{

	Obstacle* obs = new Obstacle(rand()%2 +1);
	obstacles->addObject(obs->sprite);
	obs->sprite->setPosition( 
		ccp(visibleSize.width + (obs->sprite->getContentSize().width/2), 
		visibleSize.height/6) );
	this->addChild(obs->sprite,0);
	CCFiniteTimeAction* actionMove = 
		CCMoveTo::create( (float)2.0, 
		ccp(0 - obs->sprite->getContentSize().width/2, visibleSize.height/6) );
	CCFiniteTimeAction* actionMoveDone = 
		CCCallFuncN::create( this, 
		callfuncN_selector(Game::spriteMoveFinished));
	obs->sprite->runAction( CCSequence::create(actionMove, actionMoveDone, NULL) );


}
void Game::menuCloseCallback(CCObject* pSender)
{

	CCScene *s = Menu::scene();
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5,s));

}
Game::Game(void)
{
}


Game::~Game(void)
{
}

void Game::ccTouchesBegan(CCSet* touches, CCEvent* event)
{
	CCTouch* touch = (CCTouch*)( touches->anyObject() );
	CCPoint location = touch->getLocationInView();
	pos.x = location.x;
	pos.y = location.y;

}

void Game::ccTouchesEnded(CCSet* touches, CCEvent* event)
{
	if(inAction == 0)
	{

		CCTouch* touch = (CCTouch*)( touches->anyObject() );
		CCPoint location = touch->getLocationInView();
		CCSize size = CCDirector::sharedDirector()->getWinSize();
		CCAnimation* animation = CCAnimation::create();


		if(fabs(pos.x - location.x) < 20 && fabs(pos.y - location.y) < 20)
		{	
			inAction = 1;
			sonic->jumpAction();
		}
	}

}