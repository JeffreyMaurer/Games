#include "Paddle.h"
#include"constants.h"
#include<iostream>
#include<SFML\Graphics.hpp>
Paddle::Paddle(float x, float y, float width, float length)
{
	this->x = x;
	this->y = y;
	this->length = length;
	this->width = width;
	this->rect = sf::RectangleShape(sf::Vector2f(width, length));
	this->rect.setFillColor(sf::Color::Magenta);
	this->rect.setPosition(x, y);
}

void Paddle::move(float i)
{
	y += i*PaddleSpeed;

	if (y <= -length / 2) {
		y = (-length / 2) + 1;
	}
	else if (y >= WindowSize - (length / 2)) {
		y = WindowSize - (length / 2) - 1;
	}
	rect.setPosition(x, y);
}

Paddle::~Paddle()
{
}
