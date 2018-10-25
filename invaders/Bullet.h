#pragma once
#include<SFML\Graphics.hpp>

class Bullet
{
public:
	float x, y;
	sf::CircleShape triangle;
	Bullet(float x, float y);
	virtual void move() = 0;
	~Bullet();
};

class PlayerBullet : public Bullet
{
public:
	PlayerBullet(float x, float y);
	void move();
};

class InvaderBullet : public Bullet
{
public:
	InvaderBullet(float x, float y);
	void move();
};