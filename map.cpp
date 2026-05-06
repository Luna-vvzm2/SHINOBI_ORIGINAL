#include "map.h"
#include <dxlib.h>
#include <errno.h>
#include <windows.h>

const int mapWidth = 190;
const int mapHeight = 20;

static int mapData[mapHeight][mapWidth];

void MapLoad() {
    // ファイル読み込み
	FILE* fp = nullptr;
	errno_t err = fopen_s(&fp, "map.csv", "r");

	if (err != 0 || fp == nullptr) {
		printf("open failed: %d\n", err);
		char buf[64];
		sprintf_s(buf, "err=%d\n", err);
		OutputDebugStringA(buf);
		return;
	}
	else {
		printf("open success\n");
		OutputDebugStringA("open success\n");
	}

	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			fscanf_s(fp, "%d%*[,]", &mapData[i][j]);
		}
	}
	fclose(fp);
	return;
}

void MapUpdate() {
    // スクロール処理など
}

void MapDraw() {
    // 描画
	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			if (mapData[i][j] == 1) {
				DrawBox(j * 32, i * 32, (j + 1) * 32, (i + 1) * 32, GetColor(200, 200, 200), TRUE);
				//DrawFormatString(j * 32, i * 32, GetColor(255, 0, 0), "%d", mapData[i][j]);
			}
		}
	}
	
}

bool MapIsGround(int x, int y) {
    int tx = x / 32;
    int ty = y / 32;

    return mapData[ty][tx] == 1;
}

int MapGetGroundY(int x, int y) {
    int ty = y / 32;
    return ty * 32;
}