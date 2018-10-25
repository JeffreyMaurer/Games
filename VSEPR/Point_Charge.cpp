#include "Point_Charge.h"
#include "helper.h"
#include<random>
#include<iostream>
using namespace std;

Point_Charge::Point_Charge(bool _y, bool _z, bool _w, bool _a, bool _b, bool _c)
{

	minstd_rand gen;
	gen.seed(random_device{}());
	uniform_real_distribution<double> random_number(0, WindowSize);

	x = random_number(gen);
	y = _y ? random_number(gen) : WindowSize / 2;
	z = _z ? random_number(gen) : WindowSize / 2;
	w = _w ? random_number(gen) : WindowSize / 2;
	a = _a ? random_number(gen) : WindowSize / 2;
	b = _b ? random_number(gen) : WindowSize / 2;
	c = _c ? random_number(gen) : WindowSize / 2;

	point = sf::CircleShape(size);
	dot = sf::CircleShape(1);
	//point.setFillColor(sf::Color(w / WindowSize * 0xFF, w / WindowSize * 0xFF00, w / WindowSize * 0xFF0000, 0xFF));
	point.setFillColor(sf::Color(a / WindowSize * 0xFF, b / WindowSize * 0xFF, 
		c / WindowSize * 0xFF, w / WindowSize * 0xFF));
	dot.setFillColor(sf::Color::White);
	point.setOrigin(sf::Vector2f(size, size));
	dot.setOrigin(sf::Vector2f(size / 2, size / 2));
	point.setPosition(x, y);
	dot.setPosition(x, y);
	point.setScale(z / (WindowSize / 2) + 0.3, z / (WindowSize / 2) + 0.3);
}

void Point_Charge::move(vector<Point_Charge>& points)
{
	force net = net_force(points);
	x += net.magX / mass;
	y += net.magY / mass;
	z += net.magZ / mass;
	w += net.magW / mass;
	a += net.magA / mass;
	b += net.magB / mass;
	c += net.magC / mass;
	double dist_middle = sqrt(pow(WindowSize / 2 - x, 2) + pow(WindowSize / 2 - y, 2) + 
		pow(WindowSize / 2 - z, 2) + pow(WindowSize / 2 - w, 2) + pow(WindowSize / 2 - a, 2) + 
		pow(WindowSize / 2 - b, 2) + pow(WindowSize / 2 - c, 2));
	if (dist_middle > WindowSize / 2)
	{
		x = WindowSize / 2 - (WindowSize / 2) * ((WindowSize / 2) - x) / dist_middle;
		y = WindowSize / 2 - (WindowSize / 2) * ((WindowSize / 2) - y) / dist_middle;
		z = WindowSize / 2 - (WindowSize / 2) * ((WindowSize / 2) - z) / dist_middle;
		w = WindowSize / 2 - (WindowSize / 2) * ((WindowSize / 2) - w) / dist_middle;
		a = WindowSize / 2 - (WindowSize / 2) * ((WindowSize / 2) - a) / dist_middle;
		b = WindowSize / 2 - (WindowSize / 2) * ((WindowSize / 2) - b) / dist_middle;
		c = WindowSize / 2 - (WindowSize / 2) * ((WindowSize / 2) - c) / dist_middle;
	}
	/*if (x > WindowSize) x = WindowSize;
	if (x < 0) x = 0;
	if (y > WindowSize) y = WindowSize;
	if (y < 0) y = 0;*/
	point.setPosition(x, y);
	dot.setPosition(x, y);
	point.setScale(z / (WindowSize / 2) + 0.3, z / (WindowSize / 2) + 0.3);
	point.setFillColor(sf::Color(a / WindowSize * 0xFF, b / WindowSize * 0xFF,
		c / WindowSize * 0xFF, w / WindowSize * 0xFF));
	//point.setFillColor(sf::Color(w / WindowSize * 0xFF, w / WindowSize * 0xFF00, w / WindowSize * 0xFF0000, 0xFF));
}

force Point_Charge::net_force(vector<Point_Charge>& points)
{
	force net;
	for (auto& point : points)
	{
		if (&point == this) continue;
		double r = sqrt(pow(point.x - x, 2) + pow(point.y - y, 2) + pow(point.z - z, 2) + 
			pow(point.w - w, 2) + pow(point.a - a, 2) + pow(point.b - b, 2) + pow(point.c - c, 2));
		net.magY += -(point.y - y) / r / r;
		net.magX += -(point.x - x) / r / r;
		net.magZ += -(point.z - z) / r / r;
		net.magW += -(point.w - w) / r / r;
		net.magA += -(point.a - a) / r / r;
		net.magB += -(point.b - b) / r / r;
		net.magC += -(point.c - c) / r / r;
	}
	return net;
}

Point_Charge::~Point_Charge() {}
