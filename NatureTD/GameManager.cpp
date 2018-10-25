#include "GameManager.h"
#include "Constants.h"
#include <iostream>
#include <cmath>

#define PI 3.14159265

GameManager::GameManager() :
settings(0, 0, 5),
window(sf::VideoMode(600, 400), "platformer", sf::Style::Default, settings),
gameEnd(false),
numFrames(0)
{
	//window.setFramerateLimit(30);
	towers.push_back(std::make_unique<Tower>(200, 200));
	leptons.push_back(Lepton(0.0f, 300.0f));
}

void GameManager::Run()
{
	sf::Clock clock;
	while (window.isOpen() && !gameEnd)
	{
		Input();
		Logic();
		Draw();
		sf::Event _event;
		window.pollEvent(_event);
		if (_event.type == sf::Event::Closed)
		{
			window.close();
		}
		numFrames++;
		std::cout << numFrames / clock.getElapsedTime().asSeconds() << std::endl;
	}
}

void GameManager::wait()
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
void GameManager::Input()
{
	sf::Event _event;
	window.pollEvent(_event);
	if (_event.type == sf::Event::Closed)
	{
		window.close();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		bullets.push_back(Bullet(0.0f, 0.0f, sf::CircleShape(5.0f), -PI/4));
	}
}

bool GameManager::Logic()
{
	if (!(numFrames % 10))
		leptons.push_back(Lepton(0.0f, 300.0f));
	else if (!((numFrames % 10) - 5))
		leptons.push_back(Lepton(0.0f, 100.0f));

	//bullet logic
	for (auto bullet = bullets.begin(); bullet != bullets.end();)
	{
		bullet->update();
		if (bullet->x() > 600 || bullet->x() < 0 ||
			bullet->y() > 400 || bullet->y() < 0)
		{
			bullet = bullets.erase(bullet);
		}
		else
		{
			bullet++;
		}
	}

	//Lepton logic
	for (auto& lepton : leptons)
	{
		lepton.update();
	}
	if (!leptons.empty())
	{
		if (leptons.front().x() > 600 || leptons.front().x() < 0 ||
			leptons.front().y() > 400 || leptons.front().y() < 0)
		{
			leptons.pop_front();
		}
	}

	//Tower logic
	if (!leptons.empty())
	{
		for (auto& tower : towers)
		{
			tower->update(leptons, numFrames);
			//bullets.push_back(tower->shoot());
		}

	}

	return false;
}

void GameManager::Draw()
{
	window.clear(sf::Color::Green);
	for (auto& tower : towers)
	{
		window.draw(tower->drawable());
	}
	for (auto& bullet : bullets)
	{
		window.draw(bullet.drawable());
	}
	for (auto& lepton : leptons)
	{
		window.draw(lepton.drawable());
	}
	window.display();
}



GameManager::~GameManager()
{
}
