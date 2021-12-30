#include "MainMenuScene.h"
#include "GameScene.h"
#include "TicTacToe.h"
#include "GameScene2.h"
#include "Definitions.h"
#include "SonarFrameworks.h"

USING_NS_CC;

Scene* MainMenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = MainMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


    auto backgroundSprite = Sprite::create("background_1.png");
    backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
     
    this->addChild(backgroundSprite);

    auto titleSprite = Sprite::create("Title.png");
    titleSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height - titleSprite->getContentSize().height));

    this->addChild(titleSprite);

    auto playItem = MenuItemImage::create("Play Button Clicked.png", "Play Button.png", CC_CALLBACK_1(MainMenuScene::GoToGameScene, this));
    playItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    auto menu = Menu::create(playItem, NULL);
    menu->setPosition(Point::ZERO);

    this->addChild(menu);

    auto playItem1 = MenuItemImage::create("play1.png", "Play Button.png", CC_CALLBACK_1(MainMenuScene::GoToGameScene1, this));
    playItem1->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y-100));
    playItem1->setScale(0.07);
    auto menu1 = Menu::create(playItem1, NULL);
    menu1->setPosition(Point::ZERO);

    this->addChild(menu1);

    SonarCocosHelper::GameCenter::signIn();

    auto playItem2 = MenuItemImage::create("play_game.png", "Play Button.png", CC_CALLBACK_1(MainMenuScene::GoToGameScene2, this));
    playItem2->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y-200));
    playItem2->setScale(0.4);
    auto menu2 = Menu::create(playItem2, NULL);
    menu2->setPosition(Point::ZERO);

    this->addChild(menu2);

    return true;
}


void MainMenuScene::GoToGameScene(cocos2d::Ref* sender)
{
    auto scene = GameScene::createScene();

    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void MainMenuScene::GoToGameScene1(cocos2d::Ref* sender)
{
    auto scene = TicTacToe::createScene();

    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void MainMenuScene::GoToGameScene2(cocos2d::Ref* sender)
{
    auto scene = GameScene2::createScene();

    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

