#ifndef __DIEMCAO_H__
#define __DIEMCAO_H__
#include <iostream>

#include <fstream>

#include <string>

#include<vector>

#include <cstdlib>

#include <ctime>

#include<list>


using namespace std;





#include "cocos2d.h"

class DiemCao : public cocos2d::Layer
{
public:

    string m_dra;
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    // implement the "static create()" method manually
    CREATE_FUNC(DiemCao);

private:
    void Score();

};

#endif // __SPLASH_SCENE_H__#pragma once
