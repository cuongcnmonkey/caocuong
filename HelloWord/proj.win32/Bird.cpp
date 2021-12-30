#include "Bird.h"
#include "Definitions.h"

USING_NS_CC;

Bird::Bird(cocos2d::Layer* layer)
{
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();

    flappyBird = Sprite::create("character_01.png");
    flappyBird->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    auto characterAnimation = Animation::create();
    characterAnimation->setDelayPerUnit(0.15f);

    characterAnimation->setLoops(-1);
    characterAnimation->addSpriteFrame(Sprite::create("character/character_01.png")->getSpriteFrame());
    characterAnimation->addSpriteFrame(Sprite::create("character/character_02.png")->getSpriteFrame());
    characterAnimation->addSpriteFrame(Sprite::create("character/character_03.png")->getSpriteFrame());
    characterAnimation->addSpriteFrame(Sprite::create("character/character_04.png")->getSpriteFrame());
    characterAnimation->addSpriteFrame(Sprite::create("character/character_05.png")->getSpriteFrame());
    characterAnimation->addSpriteFrame(Sprite::create("character/character_06.png")->getSpriteFrame());
    Animate* animate = Animate::create(characterAnimation);
    flappyBird->runAction(animate);

    auto flappyBody = PhysicsBody::createCircle(flappyBird->getContentSize().width / 2);

    flappyBody->setCollisionBitmask(BIRD_COLLISION_BITMASK);
    flappyBody->setContactTestBitmask(true);

    flappyBird->setPhysicsBody(flappyBody);

    layer->addChild(flappyBird, 100);

    isFalling = true;
}

//tốc độ lên xuống của bird
void Bird::Fall()
{
    if (true == isFalling)
    {
        flappyBird->setPositionX(visibleSize.width / 2 + origin.x);
        flappyBird->setPositionY(flappyBird->getPositionY() - (BIRD_FALLING_SPEED * visibleSize.height));
    }
    else
    {
        flappyBird->setPositionX(visibleSize.width / 2 + origin.x);
        flappyBird->setPositionY(flappyBird->getPositionY() + (BIRD_FALLING_SPEED * visibleSize.height));
    }
}