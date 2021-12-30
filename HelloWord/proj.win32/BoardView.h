#pragma once
#include <cocos2d.h>
#include "Board.h"
USING_NS_CC;


class BoardView : public Layer
{
	Board* board;

	float squareSize, width, height;

	std::vector<std::vector<Sprite*>> pokemons;

public:
	//CC_SYNTHESIZE(GameScene2*, gamescene, Gamescene);
	static Layer* createBoardView(Board* board, cocos2d::Layer* layer);

	void showBoard(cocos2d::Layer* layer);
	cocos2d::Layer* gameSceneLayer;

	Sprite* addPokemon(int row, int column, int type);

	bool onTouchPokemon(Touch* touch, Event* event);

	void connectPokemons(int x, int y, int _x, int _y);

	FiniteTimeAction* getConnectEffect(int x, int y, int _x, int _y);

	Vec2 positionOf(int row, int column);

	std::pair<int, int> findRowAndColumnOfSprite(Node* pokemon);

	void removePokemon(int row, int column);

	void createChoosePokemonEffect(Node* pokemon);

	void removeChoosePokemonEffect();

	void createRemovePokemonEffect(Node* pokemon);

	int score1 = 0;
	cocos2d::Label* scoreLabel;

//	void setScore1(int x);
//	int getScore1();


	CREATE_FUNC(BoardView);
};