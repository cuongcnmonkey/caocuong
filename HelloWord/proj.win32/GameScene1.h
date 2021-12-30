#pragma once
#ifndef __GAME_SCENE1_H__
#define __GAME_SCENE1_H__
#include "cocos2d.h"

class GameScene1 : public cocos2d::Layer
{
public:
    
    static cocos2d::Scene* createScene();

    
    virtual bool init();

    CREATE_FUNC(GameScene1);

private:
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    
    void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    
    void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
    
    void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event);

    void InitGridRects();
    void InitGridPieces();

    void CheckAndPlacePiece(cocos2d::Touch* touch);
    
    void CheckWin(int x, int y);
    
    void Check3PiecesForMatch(int x1, int y1, int x2, int y2, int x3, int y3);

    cocos2d::Sprite* gridSprite;
    cocos2d::Rect gridSpaces[3][3];
    cocos2d::Sprite* gridPieces[3][3];
    int gridArray[3][3];

    int turn;

    int gameState;
};

#endif // __GAME_SCENE_H__
