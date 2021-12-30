#include "UI.h"
#include "SonarFrameworks.h"
#include "Definitions.h"
#include "GameScene11.h"
#include "TicTacToe.h"
#include "MainMenuScene.h"

UI::UI(cocos2d::Layer* layer)
{

}

void UI::ShowGameOver(cocos2d::Layer* layer)
{
    Size screenSize = Director::getInstance()->getVisibleSize();

    auto retryItem = MenuItemImage::create(RETRY_BUTTON, RETRY_BUTTON_PRESSED, CC_CALLBACK_1(UI::Retry, this));
    retryItem->setPosition(Point(430,180));

    auto mainMenuItem = MenuItemImage::create(HOME_BUTTON, HOME_BUTTON_PRESSED, CC_CALLBACK_1(UI::GoToGameScene1, this));
    mainMenuItem->setScale(1.4);
    mainMenuItem->setPosition(Point(430,0));

    auto mainMainMenu = MenuItemImage::create("HOME.png", "HOME.png", CC_CALLBACK_1(UI::GoToGameMenu, this));
    mainMainMenu->setScale(0.9);
    mainMainMenu->setPosition(Point(430, -180));

    Menu* menu = Menu::create( retryItem, mainMenuItem, mainMainMenu, NULL);
    menu->setPosition(Point(-300,-300));
    layer->addChild(menu);

    EaseBounceOut* menuActionEasing = EaseBounceOut::create(MoveTo::create(MENU_MOVE_BOUNCE_DURATION, SonarCocosHelper::UI::GetScreenCenter()));
    Sequence* menuShowSeq = Sequence::create(DelayTime::create(PIECE_FADE_IN_TIME * 2.5), menuActionEasing, NULL);
    menu->runAction(menuShowSeq);
}

void UI::Retry(cocos2d::Ref* pSender)
{
    Scene* scene = GameScene11::createScene();
    TransitionFade* transition = TransitionFade::create(SCENE_TRANSITION_TIME, scene);

    Director::getInstance()->replaceScene(transition);
}

void UI::GoToGameScene1(cocos2d::Ref* pSender)
{
    Scene* scene = TicTacToe::createScene();
    TransitionFade* transition = TransitionFade::create(SCENE_TRANSITION_TIME, scene);

    Director::getInstance()->replaceScene(transition);
}

void UI::GoToGameMenu(cocos2d::Ref* pSender)
{
    Scene* scene = MainMenuScene::createScene();
    TransitionFade* transition = TransitionFade::create(SCENE_TRANSITION_TIME, scene);

    Director::getInstance()->replaceScene(transition);
}