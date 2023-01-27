#include "Bullet.h"
#include <Novice.h>

Bullet::Bullet()
{
	isAlive = false;
	Pos = { 0,800 };
	Speed = 16;

	Rad = 16;
}

void Bullet::Update()
{
	if (isAlive == true) {
		Pos.y -= Speed;

		if (Pos.y < 0) {
			isAlive = false;
		}
	}
}

void Bullet::Draw()
{
	if (isAlive == true) {
		Novice::DrawEllipse(Pos.x, Pos.y, Rad, Rad, 0, WHITE, kFillModeSolid);
	}
}

bool Bullet::Shot(Vec2 pos)
{
	if (isAlive == false) {
		Pos = pos;
		isAlive = true;
		return true;
	}
	return false;
}
