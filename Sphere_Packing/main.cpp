#include<iostream>
#include<SFML\Graphics.hpp>
#include "Point_Charge.h"
#include "helper.h"
using namespace std;

//start with 2D

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 10;

	sf::RenderWindow window(sf::VideoMode(WindowSize+10, WindowSize+10), "Sphere Packing", sf::Style::Default, settings);

	//window.setFramerateLimit(30);

	vector<Point_Charge> points;

	for (int i = 0; i < 1; i++)
	{
		points.emplace_back(true);
	}

	int num_frames = 0;
	time_t now = time(0);
	int count = 0;
	while (window.isOpen())
	{
		//user input
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close(); break;
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					points.emplace_back();
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					points.emplace_back(true);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					points.emplace_back(false, true);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
				{
					points.emplace_back(false, false, true);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
				{
					points.emplace_back(false, false, false, true);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
				{
					points.emplace_back(false, false, false, false, true);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
				{
					points.emplace_back(false, false, false, false, false, true);
				}
				break;
			default:
				break;
			}
		}

		//update auto moving parts
		for (auto& point : points)
		{
			point.move(points);
		}

		window.clear();
		for (auto& point : points)
		{
			point.show(window);
		}
		window.display();
		num_frames++;
		if (time(0) - now) cout << num_frames / (time(0) - now) << endl;
	}

	system("pause");
	return 0;
}