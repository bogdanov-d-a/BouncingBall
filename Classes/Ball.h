#pragma once

#include "cocos2d.h"
#include "Box2D\Box2D.h"
#include "ObjectKeeper.h"

class PhysicsEngine;
class HelloWorld;
class BallPuppeteer;

class Ball : public cocos2d::Sprite
{
public:
	static Ball* create(PhysicsEngine *physEngine, b2Vec2 const& startPos, float radius, HelloWorld *scene);
	bool init(PhysicsEngine *physEngine, b2Vec2 const& startPos, float radius, HelloWorld *scene);

private:
	ObjectKeeper<BallPuppeteer> m_puppeteer;
};
