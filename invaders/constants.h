#pragma once
#include"Bullet.h"

const float bulletSpeed = 5.0;
const float bulletSize = 10;
const int WindowSize = 800;
const int PlayerLength = 70;
const int PlayerHeight = 30;
const int TurretWidth = 5;
const int TurretHeight = 12;
const int PlayerY = WindowSize - 20;
const float PlayerSpeed = 4.5;
const float LEFT = -1;
const float RIGHT = 1;
const float DOWN = 0;
const int InvaderLength = 50;
const int InvaderHeight = 30;
const int EyeSize = 7;
const int numInvaders = 7;
const int numRow = 4;
const float downSpeed = 5;
const int maxNumBullets = 3;
const int bulletWait = 100;
const int InvaderBulletWait = 30;
const int levelPoints = 5;

template<typename T>
float dist(T& a, Bullet& b)
{
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}