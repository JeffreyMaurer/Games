#include "Constants.h"
#include<cmath>

std::ostream& operator<<(std::ostream& os, sf::Vector2f a)
{
	os << a.x << '\n' << a.y << '\n';
	return os;
}