#pragma once
class Enemy
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
public:

	static int isAlive;

	Enemy(Vec2 pos);

	void Update();

	void Draw();

	void Hit(Vec2 TargetPos);
};

