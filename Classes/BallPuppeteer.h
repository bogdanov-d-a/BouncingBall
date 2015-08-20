#pragma once

#include "NodePhysicsPuppeteer.h"

class BallPuppeteer : public NodePhysicsPuppeteer
{
public:
	static BallPuppeteer *create(cocos2d::CCNode *node, const b2BodyDef &bodyDef, PhysicsEngine *engine);
};
