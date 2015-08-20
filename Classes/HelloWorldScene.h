#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Box2D\Box2D.h"
#include "PhysicsEngine.h"
#include "BallPuppeteer.h"

class HelloWorld : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	HelloWorld();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();
	
	// implement the "static create()" method manually
	CREATE_FUNC(HelloWorld);

	virtual void update(float dt) override;
	virtual void onEnter() override;
	virtual void onExit() override;

private:
	PhysicsEngine *m_physEngine;
	cocos2d::Sprite *m_ballSprite;
	BallPuppeteer *m_ballPuppeteer;
	cocos2d::Sprite *m_wallSprite;
	NodePhysicsPuppeteer *m_wallPuppeteer;
};

#endif // __HELLOWORLD_SCENE_H__
