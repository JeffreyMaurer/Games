#include "Manager.h"
#include"helper.h"
#include<iostream>

using namespace std;

Manager::Manager() :
settings(0, 0, 5),
window(sf::VideoMode(600, 400), "Gravity", sf::Style::Default, settings),
gameEnd(false)
{
	window.setFramerateLimit(30);
}

void Manager::Run()
{
	while (window.isOpen() && !gameEnd)
	{
		Input();
		Logic();
		Draw();
	}
}

void Manager::wait() 
{
	while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		sf::Event _event;
		window.pollEvent(_event);
		if (_event.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}

void Manager::Input() 
{
	sf::Event event_;
	window.pollEvent(event_);
	if (event_.type == sf::Event::MouseButtonPressed)
	{
		sf::Clock clock;
		entities.push_back(Entity(0, sf::Vector2f(event_.mouseButton.x, event_.mouseButton.y), sf::Vector2f(0, 0)));
		while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
		{
			entities.back().Draw(window);
			window.display();
			entities.back().setMass(clock.getElapsedTime().asSeconds());
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
	{
		gameEnd = true;
	}
}
bool Manager::Logic() 
{
	for (int i = 0; i < entities.size(); i++)
	{
		for (int j = i + 1; j < entities.size(); j++)
		{
			gravity(entities[i], entities[j]);
		}
	}
	cout << entities.size() << endl;
	return true; 
}
void Manager::Draw() 
{
	window.clear(sf::Color::Black);
	for (auto& entity : entities)
	{
		entity.Draw(window);
	}
	window.display();
}

Manager::~Manager()
{
}
