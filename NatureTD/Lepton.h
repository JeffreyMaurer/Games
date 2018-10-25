#pragma once
#include"SFML\Graphics.hpp"
class Lepton
{
private:
	static sf::Texture texture;
protected:
	sf::Vector2f pos, vel;
	sf::Sprite sprite;
public:
	Lepton(float x, float y);
	void update();

	inline float x() { return pos.x; }
	inline float y() { return pos.y; }
	inline const sf::Vector2f& Pos() { return pos; }
	inline const sf::Sprite& drawable() const { return sprite; }
	~Lepton();
};

