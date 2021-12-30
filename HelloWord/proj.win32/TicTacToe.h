#pragma once
#ifndef __TICTACTOE_H__
#define __TICTACTOE_H__
#include "cocos2d.h"

class TicTacToe : public cocos2d::Layer
{
public:

    static cocos2d::Scene* createScene();


    virtual bool init();

    CREATE_FUNC(TicTacToe);

private:
    void GoToGameScene1(cocos2d::Ref* sender);
    void GoToGameScene11(cocos2d::Ref* sender);
};

#endif // __GAME_SCENE_H__
