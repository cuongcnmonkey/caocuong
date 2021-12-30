#include "TicTacToe.h"
#include "Definitions.h"
#include "GameScene1.h"
#include "GameScene11.h"

USING_NS_CC;

Scene* TicTacToe::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = TicTacToe::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool TicTacToe::init()
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


    auto playItem = MenuItemImage::create("play_game.png", "Play Button.png", CC_CALLBACK_1(TicTacToe::GoToGameScene1, this));
    playItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 100));
    playItem->setScale(0.4);
    auto menu = Menu::create(playItem, NULL);
    menu->setPosition(Point::ZERO);

    this->addChild(menu);

    auto playItem1 = MenuItemImage::create("play_game.png", "Play Button.png", CC_CALLBACK_1(TicTacToe::GoToGameScene11, this));
    playItem1->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 100));
    playItem1->setScale(0.4);
    auto menu1 = Menu::create(playItem1, NULL);
    menu1->setPosition(Point::ZERO);

    this->addChild(menu1);
    

    return true;
}


void TicTacToe::GoToGameScene1(cocos2d::Ref* sender)
{
    auto scene = GameScene1::createScene();

    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void TicTacToe::GoToGameScene11(cocos2d::Ref* sender)
{
    auto scene = GameScene11::createScene();

    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
