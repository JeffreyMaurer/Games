#pragma once
#include<SFML\Graphics.hpp>
#include"Paddle.h"
using namespace std;

class Ball
{
public:
	float x, y, xdir, ydir;
	sf::CircleShape circle;
	bool wasHit;
	Ball(float x, float y, float xdir, float ydir,float size);
	void move();
	void newdir();
	bool hit(Paddle p);
	~Ball();
};

