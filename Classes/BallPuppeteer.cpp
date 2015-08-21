#include "BallPuppeteer.h"
#include "HelloWorldScene.h"

BallPuppeteer *BallPuppeteer::create(cocos2d::CCNode *node, const b2BodyDef &bodyDef, PhysicsEngine *engine, HelloWorld *parent)
{
	BallPuppeteer *ret = new BallPuppeteer(node, parent);
	ret->init(bodyDef, engine);
	ret->autorelease();
	return ret;
}

BallPuppeteer::BallPuppeteer(cocos2d::CCNode *node, HelloWorld *parent)
	: NodePhysicsPuppeteer(node)
	, m_parent(parent)
{}

void BallPuppeteer::didBeginContact(const PhysicsContactInfo &info)
{
	m_parent->ShiftCamera(-5);
}

void BallPuppeteer::didEndContact(const PhysicsContactInfo &info)
{
	m_parent->ShiftCamera(5);
}
