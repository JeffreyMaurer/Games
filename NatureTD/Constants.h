#pragma once
#include<iostream>
#include"SFML\Graphics.hpp"

std::ostream& operator<<(std::ostream& os, sf::Vector2f a);

/*template<typename T, typename K>
float dist(T& one, K& two);

template<typename T, typename K>
float angle(T& one, K& two);*/

template<typename T, typename K>
float dist(T& one, K& two)
{
	float dist = sqrtf(powf(one.x() - two.x(), 2) + powf(one.y() - two.y(), 2));
	//std::cout << dist << std::endl;
	return dist;
}

template<typename T, typename K> //T for tower
float angle(T& one, K& two)
{
	sf::Vector2f normal(two.Pos() - one.Pos());
	//std::cout << normal << std::endl;
	float theta = atanf(normal.y / normal.x);

	//std::cout << theta / Constants::pi * 2 << std::endl;

	if (normal.x < 0)
	{
		return theta - Constants::pi / 2;
	}
	else
	{
		return theta + Constants::pi / 2;
	}

}

namespace Constants
{
	const float bulletSpeed = 5.0f;
	const double pi = 3.1415926;
}