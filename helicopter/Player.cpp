#include "Player.h"
#include"constants.h"
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;

Player::Player(float x, float y) :
pos(x, y, WindowSize / 2),
mass(player_mass)
{
	Constructor(x, y);
}

Player::Player( float x, float y, float z) :
pos(x, y, z),
mass(player_mass)
{
	Constructor(x, y);
}

void Player::Constructor(float x, float y)
{
	this->texture.loadFromFile("heli2.png");
	this->heli.setTexture(texture);
	//this->heli.setFillColor(sf::Color::Yellow);
	this->heli.setOrigin(PlayerSize, PlayerSize/2);
	this->heli.setPosition(x, y);
	this->score = 0;
	this->lives = 3;
	static sf::Font pfont;
	pfont.loadFromFile("arial.ttf");
	this->scoreText = sf::Text(to_string(score), pfont, 24);
	this->scoreText.setFillColor(sf::Color::Black);
	this->scoreText.setPosition(0, 0);
	this->livesText = sf::Text("lives: " + to_string(lives), pfont, 24);
	this->livesText.setFillColor(sf::Color::Black);
	this->livesText.setPosition(0, WindowSize - 30);
//	this->heli.setTexture(&texture);
	this->smoke.loadFromFile("smoke2.png");
}

void Player::move(float speed, int dir)
{
	if (dir & static_cast<int>(eDir::NO_MOVEMENT))
	{
		pos.y = WindowSize / 2;
		vel = sf::Vector3f(0,0,0);
	}
	if (dir & static_cast<int>(eDir::UP))
	{
		vel.y -= speed;
	}
	if (dir & static_cast<int>(eDir::DOWN))
	{
		vel.y += speed;
	}
	/*if (dir & static_cast<int>(eDir::RIGHT))
	{
		vel.x += speed;
	}
	if (dir & static_cast<int>(eDir::LEFT))
	{
		vel.x -= speed;
	}
	if (dir & static_cast<int>(eDir::IN))
	{
		vel.z -= speed;
	}
	if (dir & static_cast<int>(eDir::OUT))
	{
		vel.z += speed;
	}*/
	vel.y += gravity;
	float air_resistance = -vel.x * 0.05f;
	vel.x += air_resistance;

	if (vel.y > PlayerMaxSpeed)
	{
		vel.y = PlayerMaxSpeed;
	}
	if (vel.y < -PlayerMaxSpeed)
	{
		vel.y = -PlayerMaxSpeed;
	}
	float rotate = vel.y / PlayerMaxSpeed * 10.0f;
	heli.setRotation(rotate);

	pos += vel;
	if (pos.x < 0)
	{
		pos.x = 0;
		vel.x = 0;
	}
	if (pos.x > WindowSize)
	{
		pos.x = WindowSize;
		vel.x = 0;
	}
	heli.setPosition(pos.x, pos.y);
	
	if (pos.z > 600)
	{
		pos.z = 600;
	}
	if (pos.z < 0)
	{
		pos.z = 0;
	}
	float scale = 0.5 - (pos.z - WindowSize) / WindowSize;
	heli.setScale(scale, scale);
}

bool Player::collide(Bounds& stalag)
{
	if (pos.y + PlayerSize*heli.getScale().x / 2 + UnstuckFactor >= stalag.MiteBounds('P') ||
		pos.y - PlayerSize*heli.getScale().x / 2 - UnstuckFactor <= stalag.TiteBounds('P'))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Player::collide(list<Obstacle>& r)
{
	if (r.size() == 0) return false;

	for (auto& o : r)
	{
		if (dist((*this), o) < (PlayerSize + ObstacleSize))
		{
			cout << "dist " << dist((*this), o) << endl;
			cout << "cutoff " << PlayerSize + ObstacleSize << endl;
			return true;
		}
	}
	return false;
}

void Player::LoseLife()
{
	lives--;
	livesText.setString("lives: " + to_string(lives));
}

void Player::addScore()
{
	score++;
	scoreText.setString(to_string(score));
}

void Player::addSmoke()
{
	sf::Sprite sprite;
	sprite.setTexture(smoke);
	sprite.setPosition(pos.x, pos.y);
	sprite.setOrigin(10, 15);
	track.push_back(sprite);
}

void Player::moveSmoke(float acceleration)
{
	if (!track.size())
	{
		if (track.front().getPosition().x < 0)
		{
			track.pop_front();
		}
	}
	for (auto& s : track)
	{
		float x = s.getPosition().x - moveSpeed - acceleration;
		s.setPosition(x, s.getPosition().y);
	}
}

Player::~Player()
{
}
