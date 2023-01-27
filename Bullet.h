#pragma once
class Bullet
{
private:
	struct Vec2
	{
		float x;
		float y;
	};

	
	int Speed;
	bool isAlive;

	int Rad;

public:

	Vec2 Pos;

	Bullet();

	void Update();

	void Draw();

	bool Shot(Vec2 pos);
};

