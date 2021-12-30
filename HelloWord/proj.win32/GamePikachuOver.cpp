#include "GamePikachuOver.h"
#include "Definitions.h"
#include "MainMenuScene.h"
#include "GameScene2.h"
USING_NS_CC;

Scene* GamePikachuOver::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = GamePikachuOver::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GamePikachuOver::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();



    auto backgroundSprite = Sprite::create("cocos.png");
    backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    this->addChild(backgroundSprite);

    auto retryItem = MenuItemImage::create("Retry Button.png", "Retry Button Clicked.png",
        CC_CALLBACK_1(GamePikachuOver::GoToGameScene, this));
    retryItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 4 * 3));

    auto mainMenuItem = MenuItemImage::create("Menu Button.png", "Menu Button Clicked.png",
        CC_CALLBACK_1(GamePikachuOver::GoToMainMenuScene, this));
    mainMenuItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 4));

    auto menu = Menu::create(retryItem, mainMenuItem, NULL);
    menu->setPosition(Point::ZERO);

    this->addChild(menu);

    return true;
}

void GamePikachuOver::GoToMainMenuScene(cocos2d::Ref* sender)
{
    auto scene = MainMenuScene::createScene();

    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void GamePikachuOver::GoToGameScene(cocos2d::Ref* sender)
{
    auto scene = GameScene2::createScene();

    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
