#pragma once
#include "Bullet.h"

const int MAXBULLETCOUNT = 16;

class Player
{
private:

	struct Vec2
	{
		float x;
		float y;
	};

	Vec2 Pos;
	int Speed;

	int Rad;

	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	
	
public:

	Bullet bullet[MAXBULLETCOUNT];

	Player();

	void Update();

	void Draw();
};

