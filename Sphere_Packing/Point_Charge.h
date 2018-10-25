#pragma once
#include<SFML\Graphics.hpp>
#include<vector>
#include<random>
#include "helper.h"
using namespace std;

class Point_Charge
{
private:
	force net_force(vector<Point_Charge>& points);
public:
	float x, y, z, w, a, b, c;
	sf::CircleShape point, dot;
	Point_Charge(bool _y = false, bool _z = false, bool _w = false, bool _a = false, bool _b = false, bool _c = false);
	void move(vector<Point_Charge>& points);
	inline void show(sf::RenderWindow& window) 	{ window.draw(point); window.draw(dot); }
	~Point_Charge();
};

