#pragma once
#include<SFML\Graphics.hpp>
#include"Bounds.h"
#include"constants.h"
#include"Obstacle.h"
#include<list>
using namespace std;
class Player
{
public:
	const float mass;
	sf::Vector3f pos, vel;
	int lives, score;
	sf::Text livesText, scoreText;
	sf::Texture texture, smoke;
	//sf::CircleShape heli; //TODO:  have a helicopter picture as it's texture
	sf::Sprite heli;
	list<sf::Sprite> track;
	Player(float x, float y);
	Player(float x, float y, float z);
	void Constructor(float x, float y);
	void move(float speed, int dir);
	void LoseLife();
	void addScore();
	bool collide(Bounds& stalag);
	bool collide(list<Obstacle>& r);
	void addSmoke();
	void moveSmoke(float acceleration);
	~Player();
};

