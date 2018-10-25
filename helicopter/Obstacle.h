#pragma once
#include<SFML\Graphics.hpp>

class Obstacle
{
public:
	//float x; const float y, z;
	sf::Vector3f pos;
	sf::CircleShape rect;
	Obstacle(float x, int ymin, int ymax);
	Obstacle(float x, int ymin, int ymax, const float _z);
	void move(float speed = 0);
	~Obstacle();
};

