#pragma once
const int mapWidth = 190;
const int mapHeight = 20;

const int mapTile = 32;

extern int mapData[mapHeight][mapWidth];
extern int objData[mapHeight][mapWidth];

void MapLoad(const char* mapfilename, const char* objfilename);
void MapUpdate();
void MapDraw();

// “–‚½‚è”»’è
bool MapIsGround(int x, int y);
int  MapGetGroundY(int x, int y);
