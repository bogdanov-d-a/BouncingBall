#include "Wall.h"

Wall* Wall::create()
{
	Wall *pRet = new (std::nothrow) Wall();
	if (pRet && pRet->init())
	{
		pRet->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(pRet);
	}
	return pRet;
}

bool Wall::init()
{
	if (!initWithFile("wall.png"))
		return false;

	return true;
}
