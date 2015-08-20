#pragma once

#include "cocos2d.h"
#include "Box2D\Box2D.h"

class PhysicsEngine
{
public:
    PhysicsEngine(cocos2d::CCLayer *parent, int pixelsPerMeter);
    ~PhysicsEngine();

    b2Body *createBody(const b2BodyDef &bodyDef) const;
    void deleteBodyLater(b2Body *body);

    /// Updates physics world.
    void tick(float dt);

	cocos2d::CCPoint getBodyPosition(b2Body *body) const;
    float getBodyRotation(b2Body *body) const;
    float getCocosAngleFromBox2d(float angle) const;
    float getBox2dAngleFromCocos(float angle) const;
    int getPtmRatio() const;

	b2Vec2 getNodePosition(cocos2d::CCNode *node) const;
	b2Vec2 getNodePointPosition(cocos2d::CCNode *node, const cocos2d::CCPoint &point) const;

private:
    b2World *mWorld;
    std::set<b2Body *> mBodiesToDelete;
    int mPixelsPerMeter;
	cocos2d::CCLayer *m_parent = nullptr;
};
