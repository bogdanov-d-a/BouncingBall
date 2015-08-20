#include "HelloWorldScene.h"

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
	:m_physEngine(this, PTM_RATIO)
	,m_ballSprite(nullptr)
	,m_ballPuppeteer(nullptr)
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

	// Create ball body and shape
	b2BodyDef ballBodyDef;
	ballBodyDef.type = b2_dynamicBody;
	ballBodyDef.position.Set(ballStartX / PTM_RATIO, ballStartY / PTM_RATIO);
	m_physEngine.createBody(ballBodyDef);

	// Create sprite and add it to the layer
	m_ballSprite = Sprite::create("ball.png");
	this->addChild(m_ballSprite);

	m_ballPuppeteer = NodePhysicsPuppeteer::create(m_ballSprite, ballBodyDef, &m_physEngine);
	m_ballSprite->addChild(m_ballPuppeteer);

	b2CircleShape circle;
	circle.m_radius = ballRadius / PTM_RATIO;

	b2FixtureDef ballShapeDef;
	ballShapeDef.shape = &circle;
	ballShapeDef.density = 1.0f;
	ballShapeDef.friction = 0.2f;
	ballShapeDef.restitution = 0.8f;
	m_ballPuppeteer->getBody()->CreateFixture(&ballShapeDef);

	// Create wall
	b2BodyDef wallBodyDef;
	wallBodyDef.type = b2_staticBody;
	wallBodyDef.position.Set(wallX / PTM_RATIO, wallY / PTM_RATIO);
	m_physEngine.createBody(wallBodyDef);

	// Add wall sprite
	m_wallSprite = Sprite::create("wall.png");
	this->addChild(m_wallSprite);

	m_wallPuppeteer = NodePhysicsPuppeteer::create(m_wallSprite, wallBodyDef, &m_physEngine);  // MemLeak
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
	m_physEngine.tick(dt);
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
