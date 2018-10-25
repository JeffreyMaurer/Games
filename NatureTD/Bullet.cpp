#include "Bullet.h"
#include "Constants.h"
#include<cmath>

Bullet::Bullet(float x, float y, sf::CircleShape c_, float theta) :
pos(x, y),
vel(Constants::bulletSpeed*cos(theta), -Constants::bulletSpeed*sin(theta)),
c(c_)
{
	c.setPosition(pos);
}

void Bullet::update() 
{ 
	pos += vel;
	c.move(vel);
}

//float Bullet::x() { return pos.x; }
//float Bullet::y() { return pos.y; }

//const sf::CircleShape& Bullet::drawable() const { return c; }

Bullet::~Bullet()
{
}
