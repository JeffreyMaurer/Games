#pragma once
#include<sfml/Graphics.hpp>
#include"Entity.h"
#include<vector>
using namespace std;

class Manager
{
private:
	sf::ContextSettings settings;
	sf::RenderWindow window;
	vector<Entity> entities;
	bool gameEnd;
	void wait();
	void Input();
	bool Logic();
	void Draw();
public:
	Manager();
	void Run();
	~Manager();
};

