#include "GameOverScene.h"
#include "AppMacros.h"

USING_NS_CC;
CCScene* GameOverScene::scene()
{
   
    CCScene *scene = CCScene::create();
   
    
    GameOverScene *layer = GameOverScene::create();

    
    scene->addChild(layer);

    
    return scene;
}


// on "init" you need to initialize your instance
bool GameOverScene::init()
{
    
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();


    
    CCLabelTTF* pLabel = CCLabelTTF::create("GAME OVER", "Arial", TITLE_FONT_SIZE);
    
    
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));

    this->addChild(pLabel, 1);
	 CCLabelTTF* pLabel2 = CCLabelTTF::create("REJOUER", "Arial", TITLE_FONT_SIZE);

	 CCMenuItemLabel *pParamItem = CCMenuItemLabel::create(pLabel2,this, menu_selector(GameOverScene::menuParamCallback));


			CCMoveTo* paramToCenter = CCMoveTo::create(0.6,ccp(origin.x + visibleSize.width/2,
                            (origin.y + visibleSize.height - pParamItem->getContentSize().height)*0.35)); 
    pParamItem->setPosition(ccp(origin.x + visibleSize.width,
                            (origin.y + visibleSize.height - pParamItem->getContentSize().height)*0.35));
	pParamItem->runAction(paramToCenter);
    

	CCMenu* p3Menu = CCMenu::create(pParamItem, NULL);
    p3Menu->setPosition(CCPointZero);
    this->addChild(p3Menu, 1);


	CCLabelTTF* pLabel3 = CCLabelTTF::create("MENU", "Arial", TITLE_FONT_SIZE);
	CCMenuItemLabel *pStartItem = CCMenuItemLabel::create(pLabel3,this,menu_selector(GameOverScene::menuStartCallback));
    
	CCMoveTo* startToCenter = CCMoveTo::create(0.6,ccp(origin.x + visibleSize.width/2,
                            (origin.y + visibleSize.height - pStartItem->getContentSize().height)*0.50)); 

   
    pStartItem->setPosition(ccp(origin.x + visibleSize.width,
                            (origin.y + visibleSize.height - pStartItem->getContentSize().height)*0.50));
	pStartItem->runAction(startToCenter);

	CCMenu* p2Menu = CCMenu::create(pStartItem, NULL);
    p2Menu->setPosition(CCPointZero);
    this->addChild(p2Menu, 1);



    
    return true;
}

void GameOverScene::menuParamCallback(CCObject* pSender)
{
CCScene *s = Game::scene();
			CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5,s));
}

void GameOverScene::menuStartCallback(CCObject* pSender)
{
CCScene *s = Menu::scene();
			CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5,s));
}


void GameOverScene::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

