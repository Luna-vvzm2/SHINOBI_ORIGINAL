#include "fps.h"
#include <dxlib.h>

float SetFPS() {
	float FrameTime;
	int ScreenFlipCount, StartTime;

	// ScreenFlip を実行した回数を数えるカウンタを初期化
	ScreenFlipCount = 0;

	// 画面が１回更新されるまで待つ
	ScreenFlip();

	// 計測開始時刻を保存
	StartTime = GetNowCount();

	// ０．５秒間に実行できる ScreenFlip の回数を計測
	for (;;)
	{
		// 画面が１回更新されるまで待つ
		ScreenFlip();

		// 計測開始から0.5秒経過していたらループから抜ける
		if (GetNowCount() - StartTime >= 500)
			break;

		// ScreenFlip を実行した回数をインクリメント
		ScreenFlipCount++;
	}

	// ScreenFlip を実行した回数と計測時間から画面一回更新辺りの時間を算出する
	FrameTime = 500.0f / ScreenFlipCount;

	return FrameTime / 1000.0f;
}