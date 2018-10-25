#include "Obstacle.h"
#include "constants.h"
#include<iostream>
using namespace std;

Obstacle::Obstacle(float x, int ymin, int ymax) : 
pos(x, ((rand() % (ymax - (ymin + ObstacleSize))) + ymin + ObstacleSize), WindowSize / 2)
{
	this->rect = sf::CircleShape( ObstacleSize);
	this->rect.setOrigin(ObstacleSize, ObstacleSize);
	this->rect.setPosition(pos.x, pos.y);
	this->rect.setFillColor(sf::Color::Magenta);
}

Obstacle::Obstacle(float x, int ymin, int ymax, const float _z) : 
pos(x, ((rand() % (ymax - (ymin + ObstacleSize))) + ymin + ObstacleSize), _z)
{
	this->rect = sf::CircleShape(ObstacleSize);
	this->rect.setOrigin(ObstacleSize, ObstacleSize);
	this->rect.setPosition(pos.x, pos.y);
	this->rect.setFillColor(sf::Color::Magenta);
}

void Obstacle::move(float speed)
{
	pos.x -= speed + moveSpeed;
	rect.setPosition(pos.x, pos.y);
}

Obstacle::~Obstacle()
{
}
