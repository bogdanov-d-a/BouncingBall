#include "NodePhysicsPuppeteer.h"
#include "PhysicsEngine.h"

USING_NS_CC;

NodePhysicsPuppeteer *NodePhysicsPuppeteer::create(Node *node, const b2BodyDef &bodyDef, PhysicsEngine *engine)
{
	NodePhysicsPuppeteer *ret = new NodePhysicsPuppeteer();
	ret->init(node, bodyDef, engine);
	ret->autorelease();
	return ret;
}

void NodePhysicsPuppeteer::didUpdatePhysics()
{
	m_node->setPosition(getEngine()->getBodyPosition(getBody()));
	m_node->setRotation(getEngine()->getBodyRotation(getBody()));
}

void NodePhysicsPuppeteer::willUpdatePhysics(float dt)
{}

NodePhysicsPuppeteer::NodePhysicsPuppeteer()
	: m_node(nullptr)
{}

bool NodePhysicsPuppeteer::init(Node *node, const b2BodyDef &bodyDef, PhysicsEngine *engine)
{
	if (!PhysicsPuppeteer::init(bodyDef, engine))
	{
		return false;
	}

	m_node = node;
	return true;
}

Node *NodePhysicsPuppeteer::getNode() const
{
	return m_node;
}
