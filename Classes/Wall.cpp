#include "Wall.h"
#include "PhysicsEngine.h"
#include "NodePhysicsPuppeteer.h"

USING_NS_CC;

Wall* Wall::create(PhysicsEngine *physEngine, b2Vec2 const& startPos, Size const& size)
{
	Wall *pRet = new (std::nothrow) Wall();
	if (pRet && pRet->init(physEngine, startPos, size))
	{
		pRet->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(pRet);
	}
	return pRet;
}

bool Wall::init(PhysicsEngine *physEngine, b2Vec2 const& startPos, Size const& size)
{
	if (!Sprite::initWithFile("wall.png"))
		return false;

	b2BodyDef wallBodyDef;
	wallBodyDef.type = b2_staticBody;
	wallBodyDef.position = startPos;
	if (!physEngine->createBody(wallBodyDef))
		CCASSERT(false, "Can't create body");

	auto wallPuppeteer = NodePhysicsPuppeteer::create(this, wallBodyDef, physEngine);
	if (!wallPuppeteer)
		return false;
	addChild(wallPuppeteer);

	b2PolygonShape polygon;
	polygon.SetAsBox(size.width / 2, size.height / 2);

	b2FixtureDef wallShapeDef;
	wallShapeDef.shape = &polygon;
	wallShapeDef.density = 1.0f;
	wallShapeDef.friction = 0.2f;
	wallShapeDef.restitution = 0.8f;
	if (!wallPuppeteer->getBody()->CreateFixture(&wallShapeDef))
		CCASSERT(false, "Can't create fixture");

	return true;
}
