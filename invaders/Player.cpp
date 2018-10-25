#include "Player.h"
#include"constants.h"
#include<string>
using namespace std;

Player::Player(float x = WindowSize / 2, float y = PlayerY)
{
	this->x = x;
	this->y = y;
	this->score = 0;
	this->lives = 3;
	static sf::Font pfont;
	pfont.loadFromFile("arial.ttf");
	this->scoreText  = sf::Text(to_string(score), pfont, 24);
	this->scoreText.setFillColor(sf::Color::White);
	this->scoreText.setPosition(0, 0);
	this->livesText = sf::Text("lives: " + to_string(lives), pfont, 24);
	this->livesText.setFillColor(sf::Color::White);
	this->livesText.setPosition(0, WindowSize - 30);
	this->body = sf::RectangleShape(sf::Vector2f(PlayerLength, PlayerHeight));
	this->body.setOrigin(PlayerLength / 2, PlayerHeight / 2);
	this->body.setFillColor(sf::Color::Cyan);
	this->turret = sf::RectangleShape(sf::Vector2f(TurretWidth, TurretHeight));
	this->turret.setOrigin(TurretWidth / 2, TurretHeight / 2);
	this->body.setPosition(x, y);
	this->turret.setPosition(x, y - PlayerHeight / 2 - TurretHeight / 2);
}

void Player::move(float i)
{
	x += i*PlayerSpeed;

	if (x <= 0) {
		x = 1;
	}
	else if (x >= WindowSize) {
		x = WindowSize - 1;
	}

	body.setPosition(x, y);
	turret.setPosition(x, y - PlayerHeight / 2 - TurretHeight / 2);

}

void Player::updateScore(int points)
{
	score += points;
	scoreText.setString(to_string(score));
}

bool Player::hit(InvaderBullet b)
{
	if (dist(*this, b) < ((PlayerHeight + PlayerLength) / 4) + bulletSize)
	{
		lives--;
		livesText.setString("lives: " + to_string(lives));
		x = WindowSize / 2;
		body.setPosition(x, y);
		turret.setPosition(x, y - PlayerHeight / 2 - TurretHeight / 2);
		return true;
	}
	else return false;
}

Player::~Player()
{
}
