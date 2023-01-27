#include "Enemy.h"
#include <Novice.h>

Enemy::Enemy(Vec2 pos)
{
	Pos = pos;
	Speed = 8;

	Rad = 16;

}

void Enemy::Update()
{
	if (isAlive == 1) {
		Pos.x += Speed;

		if (Pos.x + Rad > 1280) {
			Pos.x = 1280 - Rad;
			Speed *= -1;
		}
		else if (Pos.x - Rad < 0) {
			Pos.x = Rad;
			Speed *= -1;
		}
	}
}

void Enemy::Draw()
{
	if (isAlive == 1) {
		Novice::DrawEllipse(Pos.x, Pos.y, Rad, Rad, 0, RED, kFillModeSolid);
	}
}

void Enemy::Hit(Vec2 TargetPos)
{
	float x = TargetPos.x - Pos.x;
	float y = TargetPos.y - Pos.y;

	float xy = (x * x) + (y * y);

	if (xy < 16 * 16) {
		isAlive = 0;
	}
}
