#pragma once
#include<list>
#include"Bounds.h"
#include"constants.h"
#include"Obstacle.h"
#include"Player.h"
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"

class Game_Class
{
private:
	sf::ContextSettings settings;
	sf::RenderWindow window;
	Bounds stalag;
	sf::Texture* t;
	Player P;
	list<Obstacle> obstacles;
	sf::Font font;
	sf::SoundBuffer sbuffer;
	sf::Sound heli_sound;
	int numFrames;
	bool gameEnd;
	float acceleration;
	void wait();
	void Input();
	bool Logic();
	void Draw();
	bool Highscore(int score);
	void New_Highscore(int score);
public:
	Game_Class();
	void Start_Screen();
	void Run();
	~Game_Class();
};

