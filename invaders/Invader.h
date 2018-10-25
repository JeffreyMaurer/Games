#pragma once
#include<SFML\Graphics.hpp>
#include"constants.h"

class Invader
{
public:
	float x, y;
	sf::RectangleShape body, claw1, claw2, eye1, eye2;
	Invader(float x, float y);
	void move(float dir, float speed);
	~Invader();
};

