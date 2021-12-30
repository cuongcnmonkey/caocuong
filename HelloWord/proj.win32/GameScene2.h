#pragma once
#ifndef __GAME_SCENE2_H__
#define __GAME_SCENE2_H__

#include "cocos2d.h"
#include "BoardView.h"


class GameScene2 : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(GameScene2);


    Layer* showBoard();

    void showProgressTimer();

    void gamePikachuOver();

    void GamePause(Ref* a);

    void GameResume(Ref* a);


private:
    Board* board;
    cocos2d::Label* scoreLabel;
    ProgressTimer* progressTimer;
    MenuItemImage* overlayWindowItem;
    BoardView* boardView = nullptr;

};

#endif // __GAME_SCENE_H__


