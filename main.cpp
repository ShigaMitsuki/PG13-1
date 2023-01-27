#include <Novice.h>
#include "Player.h"
#include "Enemy.h"

const char kWindowTitle[] = "学籍番号";


int Enemy::isAlive = 1;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Player player;


	Enemy* enemy1 = new Enemy({300,300});
	Enemy* enemy2 = new Enemy({ 0,500 });

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		player.Update();

		enemy1->Update();
		enemy2->Update();

		for (int i = 0; i < MAXBULLETCOUNT; i++) {
			enemy1->Hit({ player.bullet[i].Pos.x,player.bullet[i].Pos.y });
			enemy2->Hit({player.bullet[i].Pos.x,player.bullet[i].Pos.y});
		}

		if (keys[DIK_R]) {
			Enemy::isAlive = 1;
		}


		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		player.Draw();

		enemy1->Draw();
		enemy2->Draw();

		Novice::ScreenPrintf(0, 0, "EnemyA isAlive = %d", enemy1->isAlive);
		Novice::ScreenPrintf(0, 20, "EnemyB isAlive = %d", enemy2->isAlive);
		Novice::ScreenPrintf(0, 40, "WASD : Mlayer Move");
		Novice::ScreenPrintf(0, 60, "shot : Space");
		Novice::ScreenPrintf(0, 80, "enemy respawn : R");

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete enemy1;
	delete enemy2;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
