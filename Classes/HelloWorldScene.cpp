#include "HelloWorldScene.h"
#include "PhysicsEngine.h"
#include "Ball.h"
#include "Wall.h"

USING_NS_CC;

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
	,m_ball(nullptr)
	,m_wall(nullptr)
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

	m_physEngine = PhysicsEngine::create(this, 32);
	addChild(m_physEngine);

	m_ball = Ball::create(m_physEngine, b2Vec2(ballStartX / m_physEngine->getPtmRatio(), ballStartY / m_physEngine->getPtmRatio()), ballRadius / m_physEngine->getPtmRatio(), this);
	this->addChild(m_ball);

	m_wall = Wall::create(m_physEngine, b2Vec2(wallX / m_physEngine->getPtmRatio(), wallY / m_physEngine->getPtmRatio()), Size(wallWidth / m_physEngine->getPtmRatio(), wallHeight / m_physEngine->getPtmRatio()));
	this->addChild(m_wall);

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
