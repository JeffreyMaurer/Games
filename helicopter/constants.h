#pragma once
#include<iostream>
//#include"Player.h"
using namespace std;

const int WindowSize = 600;
const int stalagVertexCount = 14; //must always be an even number that's greater than 6
const int VertexOffset = 6;
const float moveSpeed = 5;
const int HillSize = WindowSize / 6;
const float PlayerSize = 30;
const float PlayerX = WindowSize / 4;
const float PlayerAcceleration = 0.3f;
const float PlayerMaxSpeed = 4.0f;
const float UnstuckFactor = 1;
const int ObstacleSize = 30;
const float gravity = 0.1f;
const float player_mass = 5.0f;
const int maxHighScore = 5;

enum class eDir {NO_MOVEMENT = 0x80, GRAVITY = 0x01, UP = 0x02, 
	DOWN = 0x04, IN = 0x08, OUT = 0x10, RIGHT = 0x20, LEFT = 0x40};

template < typename T, typename K >
float dist(T& a, K& b)
{
	//cout << sqrt(pow(a.pos.x - b.pos.x, 2) + pow(a.pos.y - b.pos.y, 2) * 2 + pow(a.pos.z - b.pos.z, 2)) << endl;
	return sqrt(pow(a.pos.x - b.pos.x, 2) / 1.5f + pow(a.pos.y - b.pos.y, 2) * 2 + pow(a.pos.z - b.pos.z, 2));
}