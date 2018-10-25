#include "Tower.h"
#include"Constants.h"
#include<iostream>

Tower::Tower(float x, float y) :
pos(x, y),
closestLepton(nullptr)
{
	texture.loadFromFile("Tower.png");
	sprite.setTexture(texture);
	sprite.setPosition(pos);
	sprite.setOrigin(25, 25);
}

sf::Texture Tower::texture = sf::Texture();

void Tower::update(std::deque<Lepton> leptons, int numFrames)
{
	Lepton* closestLepton = &leptons.front();
	float closest(INT_MAX);
	float theta(0.0f);
	//std::cout << "frame" << std::endl;
	for (auto& lepton : leptons)
	{
		if (dist(*this, lepton) < closest)
		{
			closestLepton = &lepton;
			closest = dist(*this, *closestLepton);
			//std::cout << dist(*this, lepton) << std::endl;
		}
	}

	
	theta = angle(*this, *closestLepton);
	//std::cout << theta*180.0f/Constants::pi << std::endl;
	sprite.setRotation(theta*180.0f / Constants::pi);
}

const sf::Sprite& Tower::drawable() const { return sprite; }

//std::unique_ptr<Bullet>& Tower::shoot() 
//{ 
//	return std::make_unique<Bullet>(pos.x, pos.y, sf::CircleShape(50.0f), angle(*this, ); 
//}

Tower::~Tower() {}
