#pragma once
#include<SFML\Graphics.hpp>
#include<iostream>

namespace Constants
{
	const double pi = 3.141592653589793238463;
};

const float   operator*(const sf::Vector2f& left, const sf::Vector2f& right);
std::ostream& operator<<(std::ostream& os, const sf::Vector2f& input);
template<typename T>
inline
float  dist(const T& one, const T& two);

template<typename T>
void   gravity(T& one, T& two);

template<typename T>
inline
bool   collide(T& one, T& two);

template<typename T>
double angle(const T& one, const T& two);

template<typename T>
inline 
float dist(const T& one, const T& two)
{
	return sqrtf(powf(one.getPosition().x - two.getPosition().x, 2) + 
		         powf(one.getPosition().y - two.getPosition().y, 2));
}

template<typename T>
void gravity(T& one, T& two)
{
	float masses = one.getMass() * two.getMass();
	float dist2 = powf(dist(one, two), 2);
	float force_magnitude = masses / dist2;

	//cout << "distance between\t" << dist(one, two) << endl;
	//cout << "force between   \t" << force_magnitude << endl;

	sf::Vector2f force_one(-force_magnitude * cos(angle(one, two) + Constants::pi),
		force_magnitude * sin(angle(one, two) + Constants::pi));

	sf::Vector2f force_two(-force_magnitude * cos(angle(one, two)),
		force_magnitude * sin(angle(one, two)));

	cout << "force2\t" << force_two << endl;

	one.updateForce(force_one * 500.0f);
	two.updateForce(force_two * 500.0f);
}

template<typename T>
inline
bool collide(T& one, T& two)
{
	if (dist(one, two) <= ((one.getMass() + two.getMass()) * 10))
	{
		one.bounce();
		two.bounce();
		return true;
	}
}

template<typename T>
double angle(const T& one, const T& two)
{
	sf::Vector2f normal(one.getPosition() - two.getPosition());

	if (!normal.x && !normal.y)
	{
		return 0.0f;
	}

	float theta = -(atan((double)(normal.y / normal.x)) - Constants::pi / 2);

	if (normal.x < 0)
	{
		return (theta - Constants::pi / 2);
	}
	else
	{
		return (theta + Constants::pi / 2);
	}
}

//float angleBetween(Entity& one, Entity& two);