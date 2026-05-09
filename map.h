#pragma once
const int mapWidth = 190;
const int mapHeight = 20;

static int mapData[mapHeight][mapWidth];
static int objData[mapHeight][mapWidth];

void MapLoad(const char* mapfilename, const char* objfilename);
void MapUpdate();
void MapDraw();

// “–‚½‚è”»’è
bool MapIsGround(int x, int y);
int  MapGetGroundY(int x, int y);
