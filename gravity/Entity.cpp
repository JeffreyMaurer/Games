#include "Entity.h"
#include "helper.h"
#include <iostream>
using namespace std;

Entity::Entity(float mass, sf::Vector2f position, sf::Vector2f velocity_) :
velocity(velocity_)
{
	circle = sf::CircleShape(mass*10);
	circle.setFillColor(sf::Color::White);
	circle.setPosition(position);
	circle.setOrigin(mass * 10, mass * 10);
	cout << '\t' << position << endl;
}

void Entity::Draw(sf::RenderWindow& window)
{
	circle.setPosition(circle.getPosition() + velocity);

	window.draw(circle);

}

void Entity::updateForce(sf::Vector2f force_)
{
	if (force_.x < 1e-8 && force_.x > -1e-8)
	{
		force_.x = 0;
	}
	if (force_.y < 1e-8 && force_.y > -1e-8)
	{
		force_.y = 0;
	}
	velocity += force_ / getMass();
}

Entity::~Entity()
{
}
