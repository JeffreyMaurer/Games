#include "Bullet.h"
#include"constants.h"

Bullet::Bullet(float x, float y)
{
	this->x = x;
	this->y = y;
	this->triangle = sf::CircleShape(bulletSize, 3);
	this->triangle.setScale(0.3, 1);
	this->triangle.setOrigin(sf::Vector2f(bulletSize, bulletSize/2));
	this->triangle.setPosition(x, y);
}


Bullet::~Bullet()
{
}

PlayerBullet::PlayerBullet(float x, float y) : Bullet(x, y) 
{
	triangle.setFillColor(sf::Color::White);
}

void PlayerBullet::move()
{
	y -= bulletSpeed;
	triangle.setPosition(x, y);
}

InvaderBullet::InvaderBullet(float x, float y) : Bullet(x, y) 
{
	triangle.setRotation(180);
	triangle.setFillColor(sf::Color::Red);

}

void InvaderBullet::move()
{
	y += bulletSpeed;
	triangle.setPosition(x, y);
}