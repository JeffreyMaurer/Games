#pragma once
#include<SFML\Graphics.hpp>
#include"helper.h"
using namespace std;

class Entity
{
public:
	sf::Vector2f velocity;//, force;
	sf::CircleShape circle;
	//sf::RectangleShape vect;
public:
	Entity(float mass, sf::Vector2f position, sf::Vector2f velocity);

	float        getMass()     const { return circle.getRadius() / 10; }
	void         setMass(float mass) { circle.setRadius(mass * 10); circle.setOrigin(mass * 10, mass * 10); }
	sf::Vector2f getVelocity() const { return velocity; }
	sf::Vector2f getPosition() const { return circle.getPosition(); }
	void         bounce()            { velocity = sf::Vector2f{ -velocity.x, -velocity.y }; }
	
	void Draw(sf::RenderWindow& window);
	void updateForce(sf::Vector2f force);

	~Entity();
};

