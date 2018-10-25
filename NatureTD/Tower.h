#pragma once
#include<deque>
#include<memory>
#include"SFML\Graphics.hpp"
#include"Lepton.h"
#include"Bullet.h"
class Tower
{
private:
	static sf::Texture texture;
protected:
	sf::Vector2f pos;
	sf::Sprite sprite;
	Lepton* closestLepton;
public:
	Tower(float x, float y);
	void update(std::deque<Lepton> leptons, int numFrames);
	inline float x() { return pos.x; }
	inline float y() { return pos.y; }
	inline const sf::Vector2f& Pos() { return pos; }
	virtual const sf::Sprite& drawable() const;
	//virtual std::unique_ptr<Bullet>& shoot();
	virtual ~Tower();
};

