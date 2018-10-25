#pragma warning(disable: 4996)

#include <SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>
#include<list> //list best?
#include<vector>
#include<string>
#include"constants.h"
#include"Bullet.h"
#include"Player.h"
#include"Invader.h"
#include"Armada.h"

using namespace std;

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 10;

	sf::RenderWindow window(sf::VideoMode(WindowSize, WindowSize), "Space Invaders!", sf::Style::Default, settings);
	window.setFramerateLimit(60);

	list<PlayerBullet> will;
	list<InvaderBullet> bill;
	Armada armada;// (WindowSize / 2, WindowSize - 100);
	float level = 1.0;


	Player P1(WindowSize/2, PlayerY);
	float invaderSpeed = 1.5;

	sf::Clock bulletTime, frames;
	float numframes(0);

pause:
	//show game board for first time or first time after being hit
	window.clear();
	window.draw(P1.body);
	window.draw(P1.turret);
	for (auto& invader : armada.invaders)
	{
		window.draw(invader.body);
		window.draw(invader.claw1);
		window.draw(invader.claw2);
		window.draw(invader.eye1);
		window.draw(invader.eye2);
	}
	window.draw(P1.scoreText);
	window.draw(P1.livesText);
	window.display();

	//start game by pressing up
	while (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))) {}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.key.code == sf::Keyboard::Space && will.size() < maxNumBullets)
			{
				if (bulletTime.getElapsedTime().asMilliseconds() > bulletWait)
				{
					will.push_back(PlayerBullet(P1.x, P1.y - PlayerHeight / 2 - TurretHeight / 2));
				}
				bulletTime.restart();
			}
		}
		//move character
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			P1.move(LEFT);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			P1.move(RIGHT);
		//probabilistically determine who will shoot a bullet next
		float bottom = armada.getBottom();
		for (auto& invader : armada.invaders)
		{
			if (invader.y == bottom && !(rand() % (armada.invaders.size()*InvaderBulletWait)) && bill.size() < maxNumBullets)
			{
				//cout << "hello" << endl;
				bill.push_back(InvaderBullet(invader.x, invader.y + InvaderHeight / 2));
			}
		}

		//if bullet goes ofscreen, remove it from mem
		if (will.size())
		{
			if (will.front().y < 0) will.pop_front();
		}
		if (bill.size())
		{
			if (bill.front().y > WindowSize) bill.pop_front();
		}
		//move all of the bullets, did any hit?
		for (auto bullet = will.begin(); bullet != will.end();)
		{
			//cout << "hello" << endl;
			bullet->move();
			int points = armada.hit(*bullet);
			if (points)
			{
				P1.updateScore(points);
				bullet = will.erase(bullet);
				continue;
			}
			bullet++;
		}
		//what if you killed the entire armada
		if (armada.is_empty())
		{
			P1.updateScore(levelPoints);
			bill.clear();
			will.clear();
			sf::Font font;
			font.loadFromFile("arial.ttf");
			sf::Text winner = sf::Text("LEVEL UP!", font, 70);
			winner.setFillColor(sf::Color::White);
			winner.setPosition(WindowSize / 4, WindowSize /2);
			window.clear();
			window.draw(P1.body);
			window.draw(P1.turret);
			window.draw(P1.scoreText);
			window.draw(P1.livesText);
			window.draw(winner);
			window.display();
			armada = Armada();
			level++;
			invaderSpeed = pow(level, 0.02) * 1.5;
			while (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))) {}
			continue;
		}
		//bullets hitting the player
		for (auto bullet = bill.begin(); bullet != bill.end();)
		{
			bullet->move();
			if (P1.hit(*bullet))
			{
				if (P1.lives >= 0)
				{
					bill.clear();
					will.clear();
					goto pause;
				}
				else
				{
					goto lose;
				}
			}

			bullet++;
		}
		//move armada
		armada.move(invaderSpeed);
		//what if the armada has reached earth?
		if (armada.getBottom() > WindowSize - 50)
		{
			lose:
			sf::Font font;
			font.loadFromFile("arial.ttf");
			sf::Text loser = sf::Text("GAME OVER!", font, 70);
			loser.setFillColor(sf::Color::Red);
			loser.setPosition(WindowSize / 4, WindowSize / 2);
			window.clear();
			window.draw(loser);
			window.display();
			while (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))) {}
		}
		//what happens when they armada bumps into the edge of the screen?
		if (armada.getRight() > WindowSize - 50 || armada.getLeft() < 50)
		{
			armada.turnAround();
			invaderSpeed += 0.015;
		}

		window.clear();
		for (auto& bullet : will)
		{
			window.draw(bullet.triangle);
		}
		for (auto& bullet : bill)
		{
			window.draw(bullet.triangle);
		}
		window.draw(P1.body);
		window.draw(P1.turret);
		for (auto& invader : armada.invaders)
		{
			window.draw(invader.body);
			window.draw(invader.claw1);
			window.draw(invader.claw2);
			window.draw(invader.eye1);
			window.draw(invader.eye2);
		}
		window.draw(P1.scoreText);
		window.draw(P1.livesText);
		window.display();

		numframes++;
		cout << numframes / (frames.getElapsedTime().asMilliseconds() / 1000) << endl;
	}
	

	return 0;
}

//last things to add
/*
shooting back DONE
win/lose conditions DONE
levels DONE
HASHING Eh
remove gotos--I can do it, but why should I?
*/