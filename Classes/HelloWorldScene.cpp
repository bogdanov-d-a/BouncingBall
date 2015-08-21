#include "HelloWorldScene.h"
#include "PhysicsEngine.h"
#include "Ball.h"
#include "Wall.h"
#include "NodePhysicsPuppeteer.h"

USING_NS_CC;

#define PTM_RATIO 32

Scene* HelloWorld::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	
	// 'layer' is an autorelease object
	auto layer = HelloWorld::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

HelloWorld::HelloWorld()
	:m_physEngine(nullptr)
	,m_ballSprite(nullptr)
	,m_wallSprite(nullptr)
	,m_wallPuppeteer(nullptr)
{}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !Layer::init() )
	{
		return false;
	}
	
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 3. add your codes below...

	float ballStartX = 240;
	float ballStartY = 540;
	float ballRadius = 50;

	float wallX = 240;
	float wallY = 75;
	float wallWidth = 300;
	float wallHeight = 50;

	m_physEngine = PhysicsEngine::create(this, PTM_RATIO);
	addChild(m_physEngine);

	m_ballSprite = Ball::create(m_physEngine, b2Vec2(ballStartX / m_physEngine->getPtmRatio(), ballStartY / m_physEngine->getPtmRatio()), ballRadius / m_physEngine->getPtmRatio(), this);
	this->addChild(m_ballSprite);

	// Create wall
	b2BodyDef wallBodyDef;
	wallBodyDef.type = b2_staticBody;
	wallBodyDef.position.Set(wallX / PTM_RATIO, wallY / PTM_RATIO);
	m_physEngine->createBody(wallBodyDef);

	// Add wall sprite
	m_wallSprite = Wall::create();
	this->addChild(m_wallSprite);

	m_wallPuppeteer = NodePhysicsPuppeteer::create(m_wallSprite, wallBodyDef, m_physEngine);
	m_wallSprite->addChild(m_wallPuppeteer);

	b2PolygonShape polygon;
	polygon.SetAsBox(wallWidth / 2 / PTM_RATIO, wallHeight / 2 / PTM_RATIO);

	b2FixtureDef wallShapeDef;
	wallShapeDef.shape = &polygon;
	wallShapeDef.density = 1.0f;
	wallShapeDef.friction = 0.2f;
	wallShapeDef.restitution = 0.8f;
	m_wallPuppeteer->getBody()->CreateFixture(&wallShapeDef);

	return true;
}

void HelloWorld::update(float dt)
{
	Layer::update(dt);
	m_physEngine->tick(dt);
}

void HelloWorld::onEnter()
{
	Layer::onEnter();
	scheduleUpdate();
}

void HelloWorld::onExit()
{
	unscheduleUpdate();
	Layer::onExit();
}

void HelloWorld::ShiftCamera(float dy)
{
	setPosition(getPosition() + Vec2(0, dy));
}
