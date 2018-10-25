#include"helper.h"
#include<math.h>
#include<iostream>
using namespace std; 

const float operator*(const sf::Vector2f& left, const sf::Vector2f& right)
{
	return left.x*right.x + left.y*right.y;
}

std::ostream& operator<<(std::ostream& os, const sf::Vector2f& input)
{
	os << input.x << endl << '\t' << input.y;
	return os;
}

/*double angle(const Entity& one, const Entity& two)
{
	sf::Vector2f normal(one.getPosition() - two.getPosition());
	
	if (!normal.x && !normal.y)
	{
		return 0.0f;
	}

	float theta = -(atan((double) (normal.y / normal.x)) - Constants::pi / 2);

	if (normal.x < 0)
	{
		return (theta - Constants::pi / 2);
	}
	else
	{
		return (theta + Constants::pi / 2);
	}
}

//f_g = M*m/r^2
void gravity(Entity& one, Entity& two)
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

void collide(Entity& one, Entity& two)
{
	if (dist(one, two) <= ((one.getMass() + two.getMass()) * 10))
	{
		int x = 0;
	}
}

/*float angleBetween(Entity& one, Entity& two)
{
	float len1 = sqrtf(powf(one.getPosition().x, 2) + powf(one.getPosition().y, 2));
	float len2 = sqrtf(powf(two.getPosition().x, 2) + powf(two.getPosition().y, 2));

	float dot = one.getPosition() * two.getPosition();
	float a = dot / (len1 * len2);

	if (a >= 1.0)
		return 0.0;
	else if (a <= -1.0)
		return Constants::pi;
	else
		return acos(a); // 0..PI
}*/