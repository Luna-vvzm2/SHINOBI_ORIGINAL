#include <Dxlib.h>

#include "player.h"
#include "enemy.h"
#include "map.h"
#include "input.h"
#include "collision.h"

// グローバル変数定義
const int GameWidth = 1280;
const int GameHeight = 720;



int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR IpCmdLine, _In_ int nCmdShow) {
	
	SetMainWindowText("SHINOBI");

	SetGraphMode(GameWidth, GameHeight, 32);

	// 全画面はFALSE、ウィンドウが動かせるようにするならTRUE
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1) return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	// マウスカーソルの表示
	SetMouseDispFlag(TRUE);

	// マップデータ読み込み
	MapLoad("map.csv", "obj.csv");

	int kunai = 0;
	int money = 0;

	Character player;

	PlayerInit(&player);

	while (true) {
		if (ProcessMessage() != 0) break;

		ClearDrawScreen();

		// dt更新
		static int prevTime = GetNowCount();

		int nowTime = GetNowCount();
		float dt = (nowTime - prevTime) / 1000.0f;
		prevTime = nowTime;

		// 入力処理
		InputUpdate();
		PlayerUpdate(&player, dt);
		

		// escで実行停止
		if (CheckHitKey(KEY_INPUT_ESCAPE)) {
			return 0;
		}

		// 更新処理
		// 描画処理
		MapDraw();
		PlayerDraw(&player);
		DrawFormatString(0, 0, GetColor(255,255,255), "%f", dt);
		ScreenFlip();
	}

	DxLib_End();
	return 0;
}