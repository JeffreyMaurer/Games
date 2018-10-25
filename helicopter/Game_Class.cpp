#include "Game_Class.h"
#include<iostream>
#include<fstream>
#include<algorithm>
#include<functional>
using namespace std;

Game_Class::Game_Class() :
settings(0, 0, 5),
window(sf::VideoMode(WindowSize, WindowSize), "Helicopter!", sf::Style::Default, settings),
P(PlayerX, WindowSize / 2),
gameEnd(false)
{
	srand(time(0));
	settings.antialiasingLevel = 5;
	window.setFramerateLimit(60);
	font.loadFromFile("arial.ttf");
	numFrames = 0;
	acceleration = 0;
	sbuffer.loadFromFile("heli2.wav");
	heli_sound.setBuffer(sbuffer);
	heli_sound.setVolume(20);
}

void Game_Class::Start_Screen()
{
	sf::Text Start = sf::Text("Helicopter!", font, 80);
	Start.setFillColor(sf::Color::Cyan);
	Start.setOutlineColor(sf::Color::Red);
	Start.setOutlineThickness(2.0);
	Start.setOrigin(Start.getLocalBounds().width / 2, 0);// Start.getLocalBounds().height / 2);
	Start.setPosition(WindowSize / 2, 0);// WindowSize / 4);

	sf::Text start2 = sf::Text("Press space to start the game", font, 40);
	start2.setFillColor(sf::Color::White);
	start2.setOrigin(start2.getLocalBounds().width / 2, 0);
	start2.setPosition(WindowSize / 2, WindowSize / 2 - PlayerSize * 3);
	start2.setOutlineColor(sf::Color::Black);
	start2.setOutlineThickness(2.0);

	window.clear();
	window.draw(stalag.mite);
	window.draw(stalag.tite);
	window.draw(P.heli);
	window.draw(P.livesText);
	window.draw(P.scoreText);
	window.draw(Start);
	window.draw(start2);
	for (auto o : obstacles)
	{
		window.draw(o.rect);
	}
	window.display();
	wait();
}

void Game_Class::wait()
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

void Game_Class::Run()
{
	heli_sound.play();
	heli_sound.setLoop(true);
	while (window.isOpen() && !gameEnd)
	{
		Input();
		Logic();
		Draw();
	}
}

void Game_Class::Input()
{
	sf::Event _event;
	window.pollEvent(_event);
	if (_event.type == sf::Event::Closed)
	{
		window.close();
	}

	//Where shall the player move? incorporates gravity, btw
	int move_flags(0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		move_flags+= static_cast<int>(eDir::UP);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		move_flags += static_cast<int>(eDir::DOWN);
	}
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		move_flags += static_cast<int>(eDir::LEFT);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		move_flags += static_cast<int>(eDir::RIGHT);
	}
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		move_flags += static_cast<int>(eDir::IN);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		move_flags += static_cast<int>(eDir::OUT);
	}*/

	P.move(PlayerAcceleration, move_flags);
}

bool Game_Class::Logic()
{
	//summon a new obstacle
	if (!(numFrames % 60))
	{
		cout << numFrames << endl;
		obstacles.push_back(Obstacle(WindowSize + ObstacleSize / 2, stalag.TiteBounds('O'), stalag.MiteBounds('O')));
	}

	//new smoke
	if (!(numFrames % 5))
	{
		P.addSmoke();
	}

	//move all obstacles
	for (auto& o : obstacles)
	{
		o.move(acceleration);
	}
	//remove an obstacle if it goes ofscreen
	if (obstacles.size())
	{
		if (obstacles.front().pos.x < -ObstacleSize)
		{
			obstacles.pop_front();
		}
	}
	//move the smoke trail
	P.moveSmoke(acceleration);
	//move the stage
	stalag.move(acceleration);
	acceleration += 0.001;


	//did the character hit something?
	if (P.collide(stalag) || P.collide(obstacles))
	{
		heli_sound.pause();
		//do you still have lives to lose?
		if (P.lives > 0)
		{
			P.LoseLife();
			P.pos.y = WindowSize / 2;

			window.clear();
			window.draw(P.heli);
			window.draw(stalag.mite);
			window.draw(stalag.tite);
			window.draw(P.livesText);
			window.draw(P.scoreText);
			for (auto& o : obstacles)
			{
				window.draw(o.rect);
			}
			window.display();

			P.collide(obstacles);
			while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				sf::Event _event;
				window.pollEvent(_event);
				if (_event.type == sf::Event::Closed)
				{
					window.close();
				}
			}
			P.move(0, static_cast<int>(eDir::NO_MOVEMENT));
			obstacles.clear();
			heli_sound.play();
		}
		else
		{
			gameEnd = true;
			sf::Text loser = sf::Text("GAME OVER!\n" + to_string(P.score), font, 70);
			loser.setFillColor(sf::Color::Red);
			loser.setOrigin(loser.getLocalBounds().width / 2, loser.getLocalBounds().height / 2);
			loser.setPosition(WindowSize / 2, WindowSize / 2);
			window.clear();
			window.draw(loser);
			window.display();
			while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				sf::Event _event;
				window.pollEvent(_event);
				if (_event.type == sf::Event::Closed)
				{
					window.close();
				}
			}
			if (Highscore(P.score))
			{
				New_Highscore(P.score);
			}
			return false; //break the game loop
		}
	}
	//increment score
	P.addScore();

	numFrames++;
}

void Game_Class::Draw()
{
	window.clear();
	window.draw(stalag.mite);
	window.draw(stalag.tite);
	window.draw(P.livesText);
	window.draw(P.scoreText);
	for (auto& s : P.track)
	{
		window.draw(s);
	}
	for (auto& o : obstacles)
	{
		if (P.pos.z >= o.pos.z) window.draw(o.rect);
	}
	window.draw(P.heli);
	for (auto& o : obstacles)
	{
		if (P.pos.z < o.pos.z) window.draw(o.rect);
	}
	window.display();
}

bool Game_Class::Highscore(int score)
{
	ifstream HS("HighScore.txt");
	vector<int> scores;
	string line;
	while (getline(HS, line))
	{
		scores.push_back(atoi(line.c_str()));
	}
	for (int i = 0; i < scores.size(); i++)
	{
		if (score > scores[i]) return true;
	}
	return false;
}

void Game_Class::New_Highscore(int score)
{
	ifstream iHS("HighScore.txt");
	vector<int> scores;
	vector<string> Sscores;
	string line;
	scores.push_back(P.score);
	while (getline(iHS, line))
	{
		Sscores.push_back(line);
		scores.push_back(atoi(line.c_str()));
	}
	sort(scores.begin(), scores.end(), greater<int>());
	ofstream oHS("HighScore.txt");
	for (int i = 0; i < scores.size() && i < maxHighScore; i++)
	{
		oHS << scores[i] << '\n';
	}
}

Game_Class::~Game_Class()
{
}
