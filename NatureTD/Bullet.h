#pragma once
#include"SFML\Graphics.hpp"
class Bullet
{
	sf::Vector2f pos, vel;
	sf::CircleShape c;
public:
	Bullet(float x, float y, sf::CircleShape c_, float theta_);
	void update();

	inline float x() { return pos.x; }
	inline float y() { return pos.y; }
	inline const sf::CircleShape& drawable() const { return c; }

	~Bullet();
};

