#include<iostream>
#include<SFML\Graphics.hpp>
#include"Entity.h"
#include"Manager.h"
#include"helper.h"

using namespace std;

int main()
{
	sf::ContextSettings settings(0, 0, 5);
	sf::RenderWindow window(sf::VideoMode(600, 400), "Gravity", sf::Style::Default, settings);
	Entity one(1, sf::Vector2f(150, 200), sf::Vector2f(0, -1));
	Entity two(1, sf::Vector2f(400, 200), sf::Vector2f(0, 1));
	window.setFramerateLimit(30);
	while (1)
	{
		gravity(one, two);
		collide(one, two);
		window.clear();
		one.Draw(window);
		two.Draw(window);
		window.display();
		cout << '\t' << two.getVelocity() << endl;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			//std::system("pause");
		}
	}
	
	//Manager m;
	//m.Run();

	std::system("pause");
	return 0;
}