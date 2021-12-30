#include "GameScene2.h"
#include "Definitions.h"
#include "Board.h"
#include "BoardView.h"
#include "GamePikachuOver.h"
#include "SonarFrameworks.h"


#include "AudioEngine.h"

USING_NS_CC;



Scene* GameScene2::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = GameScene2::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}


// on "init" you need to initialize your instance
bool GameScene2::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }



    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto backgroundSprite = Sprite::create("background.png");
    backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    this->addChild(backgroundSprite);

    showBoard();

    showProgressTimer();

    return true;
}

Layer* GameScene2::showBoard()
{
    std::vector<int> count(16, 4);
    Board* board = new Board(8, 8, 16, count);
    auto boardView = BoardView::createBoardView(board,this);

    this->addChild(boardView, 1);
    float x = (Director::getInstance()->getVisibleSize().width - boardView->getContentSize().width) / 2;
    float y = (Director::getInstance()->getVisibleSize().height - boardView->getContentSize().height) / 2;
    boardView->setPosition({ x, y });

    return boardView;
    
}

void GameScene2::showProgressTimer()
{
    auto screenSize = Director::getInstance()->getVisibleSize();
    auto board1 = getBoundingBox();

    progressTimer = ProgressTimer::create(Sprite::create("ProgressCircle.png"));
    progressTimer->setType(ProgressTimer::Type::RADIAL);
    progressTimer->setMidpoint(Vec2(0.5f, 0.5f));
    progressTimer->setReverseDirection(true);
    progressTimer->setPercentage(100);
    progressTimer->setScale((screenSize.height - board1.getMaxY()) / 1.5f / progressTimer->getContentSize().width);
    progressTimer->setPosition(1000,600);
    progressTimer->setScale(0.2);
 //   progressTimer->setName("pro_time");
    this->addChild(progressTimer);
    auto time = ProgressFromTo::create(TIMEPIKACHU, 100, 0);
    

    //call den func sau action
    progressTimer->runAction(Sequence::create(time, CallFunc::create([=]() {
        gamePikachuOver();
    }), NULL));
    
   

    auto playItem = MenuItemImage::create("Pause Button.png", "Resume.png", CC_CALLBACK_1(GameScene2::GamePause, this));
    playItem->setPosition(Point(1000, 350));
    playItem->setScale(0.2);
    auto menu = Menu::create(playItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);

    

//    this->scheduleOnce(schedule_selector(GameScene2::gamePikachuOver), TIMEPIKACHU);

}

void GameScene2::gamePikachuOver()
{
    auto scene = GamePikachuOver::createScene();

    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}


void GameScene2::GamePause(Ref* a)
{
    Size screenSize = Director::getInstance()->getVisibleSize();

    overlayWindowItem = MenuItemImage::create(GAME_OVER_WINDOW, GAME_OVER_WINDOW, GAME_OVER_WINDOW, NULL);

    overlayWindowItem->setScale(1.2);

    Menu* menu = Menu::create(overlayWindowItem, NULL);
    menu->setPosition(Vec2(SonarCocosHelper::UI::GetScreenCenter().x, SonarCocosHelper::UI::GetScreenCenter().y + screenSize.height));
    this->addChild(menu, 2);

    EaseBounceOut* menuActionEasing = EaseBounceOut::create(MoveTo::create(MENU_MOVE_BOUNCE_DURATION, SonarCocosHelper::UI::GetScreenCenter()));
    Sequence* menuShowSeq = Sequence::create(DelayTime::create(PIECE_FADE_IN_TIME * 0), menuActionEasing, NULL);
    menu->runAction(menuShowSeq);

    auto playItem1 = MenuItemImage::create("a.png", "Resume.png", CC_CALLBACK_1(GameScene2::GameResume, this));
    playItem1->setPosition(Point(1000, 350));
    playItem1->setScale(0.2);
    progressTimer->pauseSchedulerAndActions();

    auto menu1 = Menu::create(playItem1, NULL);
    menu1->setPosition(Point::ZERO);

    this->addChild(menu1);
    CCLOG("%d", int(time));
}

void GameScene2::GameResume(Ref* a) {

    auto playItem1 = MenuItemImage::create("Pause Button.png", "Resume.png", CC_CALLBACK_1(GameScene2::GamePause, this));
    playItem1->setPosition(Point(1000, 350));
    playItem1->setScale(0.2);
    progressTimer->resumeSchedulerAndActions();
    auto menu1 = Menu::create(playItem1, NULL);
    menu1->setPosition(Point::ZERO);
    this->addChild(menu1);
    overlayWindowItem->removeFromParent();
}
