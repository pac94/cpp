#include "MenuScene.h"
#include "ParamScene.h"
#include "AppMacros.h"
#include "GameScene.h"

CCScene* Menu::scene()
{
   
    CCScene *scene = CCScene::create();
    
    
    Menu *layer = Menu::create();

    
    scene->addChild(layer);

    
    return scene;
}


bool Menu::init()
{
    
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "quitter.png",
                                        "quitter.png",
                                        this,
                                        menu_selector(Menu::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/1.3 ,
                                origin.y + pCloseItem->getContentSize().height * 1.5));

    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);
    
    CCMenuItemImage *pStartItem = CCMenuItemImage::create(
                                        "deb.png",
                                        "deb.png",
                                        this,
                                        menu_selector(Menu::menuStartCallback));
    
	CCMoveTo* startToCenter = CCMoveTo::create(0.6,ccp(origin.x + visibleSize.width/2,
                            (origin.y + visibleSize.height - pStartItem->getContentSize().height)*0.50)); 

    
    pStartItem->setPosition(ccp(origin.x + visibleSize.width,
                            (origin.y + visibleSize.height - pStartItem->getContentSize().height)*0.50));
	pStartItem->runAction(startToCenter);

	CCMenu* p2Menu = CCMenu::create(pStartItem, NULL);
    p2Menu->setPosition(CCPointZero);
    this->addChild(p2Menu, 1);
    

    CCSize size = CCDirector::sharedDirector()->getWinSize();

	CCSprite* bgSprite = CCSprite::create("bg_menu.png");

    bgSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    this->addChild(bgSprite, 0);
    CCSprite* pSprite = CCSprite::create("menu.png");
	CCMoveTo* menuToCenter = CCMoveTo::create(0.5,ccp(size.width / 2, size.height - 90)); 


    pSprite->setPosition(ccp(0, size.height - 90));
	pSprite->runAction(menuToCenter);
    this->addChild(pSprite, 0);
    
	player = CCSprite::create("yes6.png");
		
		player->setPosition(ccp(size.width/7 - 10, size.height/4 + 10));
		this->addChild(player, 0);

		this->schedule( schedule_selector(Menu::playAnimation), 7.0 );
    return true;
}


void Menu::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


void Menu::menuParamCallback(CCObject* pSender)
{
CCScene *s = Param::scene();
			CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5,s));
}


void Menu::menuStartCallback(CCObject* pSender)
{
CCScene *s = Game::scene();
			CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5,s));
}


void Menu::playAnimation(float dt)
{
			CCAnimation* animation = CCAnimation::create();
		animation->setDelayPerUnit(0.09f);
		animation->setRestoreOriginalFrame(true);

		animation->addSpriteFrameWithFileName("yes1.png");
		animation->addSpriteFrameWithFileName("yes2.png");
		animation->addSpriteFrameWithFileName("yes3.png");
		animation->addSpriteFrameWithFileName("yes4.png");
		animation->addSpriteFrameWithFileName("yes5.png");
		animation->addSpriteFrameWithFileName("yes6.png");
		
		CCAnimate* animate = CCAnimate::create(animation);
		animate->setTag(333);
		player->runAction(animate);
}
