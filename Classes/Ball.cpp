#include "Ball.h"
#include "PhysicsEngine.h"
#include "BallPuppeteer.h"

USING_NS_CC;

Ball* Ball::create(PhysicsEngine *physEngine, b2Vec2 const& startPos, float radius, HelloWorld *scene)
{
	Ball *ret = new Ball(physEngine, startPos, radius, scene);
	ret->initWithFile("ball.png");
	ret->autorelease();
	return ret;
}

Ball::Ball(PhysicsEngine *physEngine, b2Vec2 const& startPos, float radius, HelloWorld *scene)
{
	b2BodyDef ballBodyDef;
	ballBodyDef.type = b2_dynamicBody;
	ballBodyDef.position = startPos;
	physEngine->createBody(ballBodyDef);

	auto m_ballPuppeteer = BallPuppeteer::create(this, ballBodyDef, physEngine, scene);
	addChild(m_ballPuppeteer);

	b2CircleShape circle;
	circle.m_radius = radius;

	b2FixtureDef ballShapeDef;
	ballShapeDef.shape = &circle;
	ballShapeDef.density = 1.0f;
	ballShapeDef.friction = 0.2f;
	ballShapeDef.restitution = 0.8f;
	m_ballPuppeteer->getBody()->CreateFixture(&ballShapeDef);
}
