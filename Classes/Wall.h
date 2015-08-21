#pragma once

#include "cocos2d.h"

class Wall : public cocos2d::Sprite
{
public:
	static Wall* create();
	bool init();
};
