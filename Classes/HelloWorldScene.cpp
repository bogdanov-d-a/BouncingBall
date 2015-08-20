#include "HelloWorldScene.h"

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
	:m_physWorld(b2Vec2(0.0f, -9.8f))
	,m_ballBody(nullptr)
	,m_ballSprite(nullptr)
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

	float sceneWidth = 480;
	float sceneHeight = 640;

	float ballStartX = sceneWidth / 2;
	float ballStartY = sceneHeight - 100;
	float ballRadius = 50;

	float wallX = sceneWidth / 2;
	float wallY = 75;
	float wallWidth = 300;
	float wallHeight = 50;

	{
		m_ballSprite = Sprite::create("ball.png");
		addChild(m_ballSprite);

		b2BodyDef ballBodyDef;
		ballBodyDef.type = b2_dynamicBody;
		ballBodyDef.position.Set(ballStartX / ptmRatio, ballStartY / ptmRatio);
		ballBodyDef.userData = m_ballSprite;
		m_ballBody = m_physWorld.CreateBody(&ballBodyDef);

		b2CircleShape circle;
		circle.m_radius = ballRadius / ptmRatio;

		b2FixtureDef ballShapeDef;
		ballShapeDef.shape = &circle;
		ballShapeDef.density = 1.0f;
		ballShapeDef.friction = 0.2f;
		ballShapeDef.restitution = 0.8f;
		m_ballBody->CreateFixture(&ballShapeDef);
	}

	{
		auto wallSprite = Sprite::create("wall.png");
		wallSprite->setPosition(ccp(wallX, wallY));
		addChild(wallSprite);

		b2BodyDef wallBodyDef;
		wallBodyDef.type = b2_staticBody;
		wallBodyDef.position.Set(wallX / ptmRatio, wallY / ptmRatio);
		auto wallBody = m_physWorld.CreateBody(&wallBodyDef);

		b2PolygonShape polygon;
		polygon.SetAsBox(wallWidth / 2 / ptmRatio, wallHeight / 2 / ptmRatio);

		b2FixtureDef wallShapeDef;
		wallShapeDef.shape = &polygon;
		wallShapeDef.density = 1.0f;
		wallShapeDef.friction = 0.2f;
		wallShapeDef.restitution = 0.8f;
		wallBody->CreateFixture(&wallShapeDef);
	}

	//updateSprites();

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

const float HelloWorld::ptmRatio = 32.0f;
