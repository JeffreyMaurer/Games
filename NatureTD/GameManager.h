#pragma once
#include<vector>
#include<list>
#include<deque>
#include<memory>
#include"SFML\Graphics.hpp"
#include"Tower.h"
#include"Bullet.h"
#include"Lepton.h"

class GameManager
{
private:
	sf::ContextSettings settings;
	sf::RenderWindow window;
	std::vector<std::unique_ptr<Tower> > towers;
	std::list<Bullet> bullets;
	std::deque<Lepton> leptons;
	int numFrames;
	bool gameEnd;
	void wait();
	void Input();
	bool Logic();
	void Draw();
public:
	GameManager();
	void Run();
	~GameManager();
};

