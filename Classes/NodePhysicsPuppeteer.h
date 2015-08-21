#pragma once
#include "PhysicsPuppeteer.h"
#include "cocos2d.h"
#include "Box2D\Box2D.h"

class NodePhysicsPuppeteer : public PhysicsPuppeteer
{
public:
	static NodePhysicsPuppeteer *create(cocos2d::CCNode *node, const b2BodyDef &bodyDef, PhysicsEngine *engine);
	void didUpdatePhysics() override;
	void willUpdatePhysics(float dt) override;

protected:
	NodePhysicsPuppeteer();
	void init(cocos2d::CCNode *node, const b2BodyDef &bodyDef, PhysicsEngine *engine);
	cocos2d::CCNode *getNode() const;

private:
	cocos2d::CCNode *m_node;
};
