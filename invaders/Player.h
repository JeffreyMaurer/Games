#pragma once
#include<SFML\Graphics.hpp>
#include"Bullet.h"
class Player
{
public:
	float x, y;
	sf::RectangleShape body, turret;
	int score, lives;
	sf::Text scoreText, livesText;
	void updateScore(int points);
	bool hit(InvaderBullet b);
	Player(float x, float y);
	void move(float i);
	~Player();
};

