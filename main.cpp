#pragma warning(disable: 4996)

#include <sfml/Graphics.hpp>
#include"Ball.h"
#include"Paddle.h"
#include"constants.h"
#include<iostream>
#include<string>
#include<math.h>
using namespace std;

//top left corner is pos

void reset(Ball&, Paddle&, Paddle&);

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 5;

	sf::RenderWindow window(sf::VideoMode(WindowSize, WindowSize), "Pong!", sf::Style::Default, settings);

	Paddle P1(10, WindowSize / 2 - PaddleLength/2, PaddleWidth, PaddleLength); //x, y, width, length
	Paddle P2(580, WindowSize / 2 - PaddleLength/2, PaddleWidth, PaddleLength); 
	int score1 = 0, score2 = 0;
	Ball ball(WindowSize / 2, WindowSize / 2, 0, 0, BallSize); //x, y, xdir, ydir, size
	sf::Text score; 
	sf::Font font;
	font.loadFromFile("arial.ttf");
	score.setFont(font);
	score.setString("0|0");
	score.setPosition(sf::Vector2f(WindowSize / 2 - 20, 10)); 
	score.setCharacterSize(24);
	score.setColor(sf::Color::White);

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
				if (ball.xdir == 0 && ball.ydir == 0){
					ball.xdir = pow(-1, rand()); 
					ball.newdir();
				}
				break;
			default:
				break;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
			P1.move(UP);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			P1.move(DOWN);
		}

		//update auto moving parts
		ball.move();
		cout << "ydir" << ball.ydir << endl;
		P2.move(ball.ydir);

		//ball collides with paddle
		if (ball.hit(P1) || ball.hit(P2) && !ball.wasHit)
		{
			ball.xdir *= -1;
			ball.newdir();
			ball.wasHit = true;
		}
		//ball collides with wall
		if (ball.x < 0)
		{
			reset(ball, P1, P2);
			score2 += 1;
			score.setString(to_string(score1) + "|" + to_string(score2));
		}
		else if (ball.x > WindowSize)
		{
			reset(ball, P1, P2);
			score1 += 1;
			score.setString(to_string(score1) + "|" + to_string(score2));
		}
		else if (ball.y < 0 || ball.y > WindowSize)
		{
			ball.ydir *= -1;
		}

		window.clear();
		window.draw(ball.circle);
		window.draw(P1.rect);
		window.draw(P2.rect);
		window.draw(score);
		window.display();
	}

	return 0;
}

void reset(Ball& ball, Paddle& P1, Paddle& P2)
{
	ball.xdir = 0; 
	ball.ydir = 0; 
	ball.x = WindowSize / 2; 
	ball.y = WindowSize / 2;
	P2.y = WindowSize / 2 - PaddleLength / 2; 
	P1.y = WindowSize / 2 - PaddleLength / 2;
}

//Junk
/*
sf::Vector2f pos = score.getScale();
cout << pos.x << " " << pos.y << endl;
*/