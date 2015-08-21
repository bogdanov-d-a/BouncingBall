#include "BallPuppeteer.h"
#include "HelloWorldScene.h"

USING_NS_CC;

BallPuppeteer *BallPuppeteer::create(Node *node, const b2BodyDef &bodyDef, PhysicsEngine *engine, HelloWorld *parent)
{
	BallPuppeteer *pRet = new (std::nothrow) BallPuppeteer(node, parent);
	if (pRet && pRet->init(bodyDef, engine))
	{
		pRet->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(pRet);
	}
	return pRet;
}

BallPuppeteer::BallPuppeteer(Node *node, HelloWorld *parent)
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
