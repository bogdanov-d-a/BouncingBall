#pragma once

#include "NodePhysicsPuppeteer.h"

class HelloWorld;

class BallPuppeteer : public NodePhysicsPuppeteer
{
public:
	static BallPuppeteer *create(cocos2d::Node *node, const b2BodyDef &bodyDef, PhysicsEngine *engine, HelloWorld *parent);
	BallPuppeteer(cocos2d::Node *node, HelloWorld *parent);

	void didBeginContact(const PhysicsContactInfo &info) override;
	void didEndContact(const PhysicsContactInfo &info) override;

private:
	HelloWorld *m_parent;
};
