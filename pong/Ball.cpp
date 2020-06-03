#include "Ball.h"
#include"constants.h"
Ball::Ball(float x, float y, float xdir, float ydir, float size)
{
	this->x = x;
	this->y = y;
	this->xdir = xdir;
	this->ydir = ydir;
	this->wasHit = false;
	this->circle = sf::CircleShape(size);
	this->circle.setFillColor(sf::Color::Blue);
	this->circle.setOrigin(sf::Vector2f(size, size));
	this->circle.setPosition(x, y);
}

void Ball::move()
{
	x += xdir*BallSpeed;
	y += ydir*BallSpeed;
	this->circle.setPosition(x, y);
	if (x > 30 || x < 570) wasHit = false;
}

void Ball::newdir()
{
	ydir = (float)((rand() % 7) - 3) / 2.0;
}

bool Ball::hit(Paddle p)
{
	if ((this->x > p.x && this->x < p.x + p.width ) && 
		(this->y > p.y && this->y < (p.y + p.length))) return true;
	else return false;
}

Ball::~Ball()
{
}
