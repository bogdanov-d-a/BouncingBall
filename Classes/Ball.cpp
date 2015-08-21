#include "Ball.h"

Ball* Ball::create()
{
	Ball *ret = new Ball();
	ret->initWithFile("ball.png");
	ret->autorelease();
	return ret;
}
