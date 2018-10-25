#include "Invader.h"


Invader::Invader(float x, float y)
{
	this->y = y;
	this->x = x;
	this->body = sf::RectangleShape(sf::Vector2f(InvaderLength, InvaderHeight));
	this->claw1 = sf::RectangleShape(sf::Vector2f(TurretWidth, TurretHeight));
	this->claw2 = sf::RectangleShape(sf::Vector2f(TurretWidth, TurretHeight));
	this->eye1 = sf::RectangleShape(sf::Vector2f(EyeSize, EyeSize));
	this->eye2 = sf::RectangleShape(sf::Vector2f(EyeSize, EyeSize));
	this->body.setFillColor(sf::Color::Red);
	const sf::Color Dark_red = sf::Color(151, 5, 5, 255);
	this->claw1.setFillColor(Dark_red);
	this->claw2.setFillColor(Dark_red);
	this->eye1.setFillColor(sf::Color::Black);
	this->eye2.setFillColor(sf::Color::Black);
	this->body.setOrigin(InvaderLength / 2, InvaderHeight / 2);
	this->claw1.setOrigin(TurretWidth / 2, TurretHeight / 2);
	this->claw2.setOrigin(TurretWidth / 2, TurretHeight / 2);
	this->eye1.setOrigin(EyeSize / 2, EyeSize / 2);
	this->eye2.setOrigin(EyeSize / 2, EyeSize / 2);
	this->body.setPosition(x, y);
	this->claw1.setPosition(x + 10, y + InvaderHeight / 2 + TurretHeight / 2);
	this->claw2.setPosition(x - 10, y + InvaderHeight / 2 + TurretHeight / 2);
	this->eye1.setPosition(x + 14, y - 5);
	this->eye2.setPosition(x - 14, y - 5);
}

void Invader::move(float dir, float speed)
{
	if (dir == RIGHT || dir == LEFT)
	{
		x += dir*speed;
	}
	else if (dir == DOWN)
	{
		y += downSpeed;
	}
	this->body.setPosition(x, y);
	this->claw1.setPosition(x + 10, y + InvaderHeight / 2 + TurretHeight / 2);
	this->claw2.setPosition(x - 10, y + InvaderHeight / 2 + TurretHeight / 2);
	this->eye1.setPosition(x + 14, y - 5);
	this->eye2.setPosition(x - 14, y - 5);

}

Invader::~Invader()
{
}
