#pragma once
#include<SFML\Graphics.hpp>

class Bounds
{
public:
	sf::VertexArray mite, tite; //bottom and top bounds
	float slopeMite, slopeTite; //mite and tite's respective slopes for the line that the player will touch
	Bounds();
	void move(float speed = 0); //move the stage past the player
	float MiteBounds(char what); //get the mite bound
	float TiteBounds(char what); //get the tite bound
	~Bounds();
};

