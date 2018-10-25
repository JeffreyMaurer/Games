#include "Bounds.h"
#include"constants.h"
#include<iostream>
using namespace std;

Bounds::Bounds()
{
	this->mite = sf::VertexArray(sf::TriangleStrip, stalagVertexCount);
	this->tite = sf::VertexArray(sf::TriangleStrip, stalagVertexCount);

	this->slopeMite = (mite[5].position.y - mite[3].position.y) / (WindowSize / 4);
	this->slopeTite = (tite[5].position.y - tite[3].position.y) / (WindowSize / 4);


	mite[3].color = sf::Color::Blue;
	mite[5].color = sf::Color::Red;
	tite[3].color = sf::Color::Blue;
	tite[5].color = sf::Color::Red;

	for (int i = 0; i < stalagVertexCount; i++)
	{
		//mite[i].color = (sf::Color::White);
		tite[i].color = (sf::Color::White);

		if (!(i % 2))
		{
			mite[i].position = sf::Vector2f(WindowSize * i / (stalagVertexCount - VertexOffset), WindowSize);
			tite[i].position = sf::Vector2f(WindowSize * i / (stalagVertexCount - VertexOffset), 0);
			//cout << "even x: " << mite[i].position.x << endl;
		}
		else
		{
			mite[i].position = sf::Vector2f(WindowSize * (i - 1) / (stalagVertexCount - VertexOffset), WindowSize - (rand() % WindowSize / 10) - WindowSize / 5);
			tite[i].position = sf::Vector2f(WindowSize * (i - 1) / (stalagVertexCount - VertexOffset), (rand() % WindowSize / 10) + WindowSize / 5);
			//cout << "odd x: " << mite[i].position.x << endl;
		}
	}
}

void Bounds::move(float speed)
{
	//make sure that the bounds don't go off screen
	if (mite[3].position.x < 0)
	{
		for (int i = 0; i < stalagVertexCount - 2; i++)
		{
			mite[i].position = mite[i+2].position;
			tite[i].position = tite[i+2].position;
		}

		slopeMite = (mite[5].position.y - mite[3].position.y) / (WindowSize / 4);
		slopeTite = (tite[5].position.y - tite[3].position.y) / (WindowSize / 4);

		//make new territory procedurally
		mite[stalagVertexCount - 1].position = sf::Vector2f(WindowSize * (stalagVertexCount - 2) / (stalagVertexCount - VertexOffset), WindowSize - (rand() % HillSize) - WindowSize / 20);
		tite[stalagVertexCount - 1].position = sf::Vector2f(WindowSize * (stalagVertexCount - 2) / (stalagVertexCount - VertexOffset), (rand() % HillSize) + WindowSize / 20);
		mite[stalagVertexCount - 2].position = sf::Vector2f(WindowSize * (stalagVertexCount - 2) / (stalagVertexCount - VertexOffset), WindowSize);
		tite[stalagVertexCount - 2].position = sf::Vector2f(WindowSize * (stalagVertexCount - 2) / (stalagVertexCount - VertexOffset), 0);
	}
	
	//shift everything
	for (int i = 0; i < stalagVertexCount; i++)
	{
		mite[i].position.x -= moveSpeed + speed;
		tite[i].position.x -= moveSpeed + speed;
	}
}

float Bounds::MiteBounds(char what)
{
	if (what == 'P'){
		float miteBound = mite[3].position.y + slopeMite * (WindowSize / 4 - mite[3].position.x);
		return miteBound;
	}
	else if (what == 'O')
	{
		float slope = (mite[stalagVertexCount - 1].position.y - mite[stalagVertexCount - 3].position.y) / (mite[stalagVertexCount - 1].position.x - mite[stalagVertexCount - 3].position.x);
		float miteBound = mite[stalagVertexCount - 3].position.y + slope * (WindowSize - mite[stalagVertexCount - 3].position.x);
		return miteBound;
	}
} 

float Bounds::TiteBounds(char what)
{
	if (what == 'P'){
		float titeBound = tite[3].position.y + slopeTite * (WindowSize / 4 - tite[3].position.x);
		return titeBound;
	}
	else if (what == 'O')
	{
		float slope = (tite[stalagVertexCount - 1].position.y - tite[stalagVertexCount - 3].position.y) / (tite[stalagVertexCount - 1].position.x - tite[stalagVertexCount - 3].position.x);
		float titeBound = tite[stalagVertexCount - 3].position.y + slope * (WindowSize - tite[stalagVertexCount - 3].position.x);
		return titeBound;
	}
}

Bounds::~Bounds()
{
}
