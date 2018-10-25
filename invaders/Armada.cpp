#include "Armada.h"
#include"constants.h"
#include<algorithm>

Armada::Armada()
{
	this->dir = RIGHT;

	for (int j = 1; j <= numRow; j++){

		for (int i = 0; i < numInvaders; i++)
		{
			Invader b(WindowSize*(i + 1) / (numInvaders + 1), InvaderHeight * 2 * (j + 1));
			invaders.push_back(b);
		}
	}
}

static bool compx(Invader a, Invader b)
{
	return (a.x > b.x);
}

static bool compy(Invader a, Invader b)
{
	return (a.y < b.y);
}

float Armada::getRight() 
{
	if (!invaders.size()) return 0;
	vader_container::iterator result;
	result = min_element(invaders.begin(), invaders.end(), compx);
	return result->x;
}

float Armada::getLeft() 
{
	if (!invaders.size()) return 0;
	vader_container::iterator result;
	result = max_element(invaders.begin(), invaders.end(), compx);
	return result->x;
}

float Armada::getBottom()
{
	if (!invaders.size()) return 0;
	vader_container::iterator result;
	result = max_element(invaders.begin(), invaders.end(), compy);
	return result->y;
}

void Armada::move(float speed) 
{
	for (auto& invader : invaders)
	{
		invader.move(this->dir, speed);
	}
}

void Armada::turnAround() //whether it should turn is dealt with in main
{
	for (auto& invader : invaders)
	{
		invader.move(DOWN, 0);
	}
	this->dir = (-1)*dir;
}



int Armada::hit(PlayerBullet& will) 
{
	int numHit(0);

	for (auto invader = invaders.begin(); invader != invaders.end();)
	{
		if (dist(*invader, will) < ((InvaderHeight + InvaderLength) / 4) + bulletSize)
		{
			invader = invaders.erase(invader);
			numHit++;
			continue;
		}
		invader++;
	}
	return numHit;
}

bool Armada::is_empty()
{
	return this->invaders.empty();
}

Armada::~Armada()
{
}
