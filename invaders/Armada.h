#pragma once
#include<vector>
#include<list>
#include"Invader.h"
#include"Bullet.h"
using namespace std;

typedef vector<Invader> vader_container;

class Armada
{
public:
	vader_container invaders;
	float dir;
	Armada();
	float getRight();
	float getLeft();
	float getBottom();
	void move(float speed);
	int hit(PlayerBullet& will);
	void attack();
	void turnAround();
	bool is_empty();
	~Armada();
};

static bool comp(Invader a, Invader b);
