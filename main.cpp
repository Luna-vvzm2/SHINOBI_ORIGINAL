#include <Dxlib.h>

#include "hedder.h"

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

	while (true) {
		if (ProcessMessage() != 0) break;

		ClearDrawScreen();

		// 入力処理

		// escで実行停止
		if (CheckHitKey(KEY_INPUT_ESCAPE)) {
			return 0;
		}

		// 更新処理
		// 描画処理
		ScreenFlip();
	}

	DxLib_End();
	return 0;
}