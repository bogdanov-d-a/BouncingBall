#include "PhysicsPuppeteer.h"
#include "PhysicsEngine.h"

PhysicsPuppeteer::PhysicsPuppeteer()
	: m_body(nullptr)
	, m_engine(nullptr)
{}

PhysicsPuppeteer::~PhysicsPuppeteer()
{
	if (m_body)
	{
		m_engine->deleteBodyLater(m_body);
		m_body = nullptr;
		m_engine->release();
	}
}

bool PhysicsPuppeteer::init(const b2BodyDef &bodyDef, PhysicsEngine *engine)
{
	if (!Node::init())
	{
		return false;
	}

	m_engine = engine;
	m_engine->retain();

	b2BodyDef fixedDef = bodyDef;
	fixedDef.userData = reinterpret_cast<void *>(this);
	m_body = m_engine->createBody(fixedDef);

	return true;
}

PhysicsEngine *PhysicsPuppeteer::getEngine() const
{
	return m_engine;
}

b2Body *PhysicsPuppeteer::getBody() const
{
	return m_body;
}
