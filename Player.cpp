#include "Player.h"
#include <Novice.h>
Player::Player()
{
	Pos = { 640 , 640 };
	Speed = 12;

	Rad = 32;
}

void Player::Update()
{
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);

	if (keys[DIK_W]) {
		Pos.y -= Speed;
	}if (keys[DIK_A]) {
		Pos.x -= Speed;
	}if (keys[DIK_S]) {
		Pos.y += Speed;
	}if (keys[DIK_D]) {
		Pos.x += Speed;
	}

	if (keys[DIK_SPACE] != 0 && preKeys[DIK_SPACE] == 0) {
		for (int i = 0; i < MAXBULLETCOUNT; i++) {
			if (bullet[i].Shot({ Pos.x,Pos.y })) {
				break;
			}
		}
	}

	for (int i = 0; i < MAXBULLETCOUNT; i++) {
		bullet[i].Update();
	}
}

void Player::Draw()
{

	for (int i = 0; i < MAXBULLETCOUNT; i++) {
		bullet[i].Draw();
	}

	Novice::DrawEllipse(Pos.x, Pos.y, Rad, Rad, 0, GREEN, kFillModeSolid);

}
