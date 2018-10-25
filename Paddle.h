#pragma once
#include<SFML\Graphics.hpp>

class Paddle
{
public:
	float x, y, width, length;
	sf::RectangleShape rect;
	Paddle(float x, float y, float width, float length);
	void move(float i);
	~Paddle();
};

