#include "BallPuppeteer.h"

BallPuppeteer *BallPuppeteer::create(cocos2d::CCNode *node, const b2BodyDef &bodyDef, PhysicsEngine *engine)
{
	BallPuppeteer *ret = new BallPuppeteer();
	ret->init(node, bodyDef, engine);
	ret->autorelease();
	return ret;
}
