#pragma once

#include "cocos2d.h"
#include "Box2D\Box2D.h"
#include "ObjectKeeper.h"

class PhysicsEngine;
class NodePhysicsPuppeteer;

class Wall : public cocos2d::Sprite
{
public:
	static Wall* create(PhysicsEngine *physEngine, b2Vec2 const& startPos, cocos2d::Size const& size);
	bool init(PhysicsEngine *physEngine, b2Vec2 const& startPos, cocos2d::Size const& size);

private:
	ObjectKeeper<NodePhysicsPuppeteer> m_puppeteer;
};
