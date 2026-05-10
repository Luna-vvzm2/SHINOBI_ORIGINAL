#include "enemy.h"
#include "player.h"
#include "map.h"
#include "enemy_white.h"
#include "enemy_yellow.h"
#include "enemy_arrow.h"
#include "enemy_healer.h"
#include "enemy_armor.h"
#include "enemy_gunner.h"
#include "enemy_Yoroi.h"
#include "enemy_Sekienki.h"
#include <stdlib.h> // rand

#include <dxlib.h>

int whiteCount = 0;
int yellowCount = 0;
int arrowCount = 0;
int healerCount = 0;
int armorCount = 0;
int gunnerCount = 0;

void EnemyInit(Enemy* white, Enemy* yellow, Enemy* arrow, Enemy* healer, Enemy* armor, Enemy* gunner, Boss* Yoroi, Boss* Sekienki){
    whiteCount = 0;
    yellowCount = 0;
    arrowCount = 0;
    healerCount = 0;
    armorCount = 0;
    gunnerCount = 0;

    for (int i = 0; i < mapHeight; i++) {
        for (int j = 0; j < mapWidth; j++) {
            switch (objData[i][j]) {
            case 1:
                EnemyInitWhite(white, j, i, whiteCount);
                whiteCount++;
                break;
            case 2:
                EnemyInitYellow(yellow, j, i, yellowCount);
                yellowCount++;
                break;
            case 3:
                EnemyInitArrow(arrow, j, i, arrowCount);
                arrowCount++;
                break;
            case 4:
                EnemyInitHealer(healer, j, i, healerCount);
                healerCount++;
                break;
            case 5:
                EnemyInitArmor(armor, j, i, armorCount);
                armorCount++;
                break;
            case 6:
                EnemyInitGunner(gunner, j, i, gunnerCount);
                gunnerCount++;
                break;
            case 7:
                EnemyInitYoroi(Yoroi, j, i);
                break;
            case 8:
                EnemyInitSekienki(Sekienki, j, i);
                break;
            }
        }
    }
}

void EnemyUpdate(float dt, Character* p, Enemy* white, Enemy* yellow, Enemy* arrow, Enemy* healer, Enemy* armor, Enemy* gunner, Boss* Yoroi, Boss* Sekienki) {
    EnemyAI(p, white, yellow, arrow, healer, armor, gunner, Yoroi, Sekienki);
    EnemyMove(dt, white, yellow, arrow, healer, armor, gunner, Yoroi, Sekienki);
    EnemyAttack(p, white, yellow, arrow, healer, armor, gunner, Yoroi, Sekienki);
}

void EnemyAI(Character* p, Enemy* white, Enemy* yellow, Enemy* arrow, Enemy* healer, Enemy* armor, Enemy* gunner, Boss* Yoroi, Boss* Sekienki) {
    WhiteAI(p, white);
}

void EnemyMove(float dt, Enemy* white, Enemy* yellow, Enemy* arrow, Enemy* healer, Enemy* armor, Enemy* gunner, Boss* Yoroi, Boss* Sekienki) {
    WhiteMove(dt, white);
}

void EnemyAttack(Character* p, Enemy* white, Enemy* yellow, Enemy* arrow, Enemy* healer, Enemy* armor, Enemy* gunner, Boss* Yoroi, Boss* Sekienki) {

}

void EnemyDraw(Enemy* white, Enemy* yellow, Enemy* arrow, Enemy* healer, Enemy* armor, Enemy* gunner, Boss* Yoroi, Boss* Sekienki) {
    WhiteDraw(white);
    DrawFormatString(0, 64, GetColor(0, 0, 250), "%d", whiteCount);
}

void EnemyInitWhite(Enemy* e, int x, int y, int num) {
    e->hp[num] = e->hpMax = 50;

    e->guard[num] = e->guardMax = 50;

    e->metsuMax = 100;
    e->metsuGauge[num] = 0;

    e->x[num] = (float)x * mapTile;
    e->y[num] = (float)y * mapTile;

    e->vx[num] = 0.0f;
    e->vy[num] = 0.0f;

    e->bullet[num] = e->bulletMax = 3;

    e->attackType[num] = 0;
    e->state[num] = 0;

    e->metsu[num] = false;

    e->animationNo[num] = 0;
}

void EnemyInitYellow(Enemy* e, int x, int y, int num) {
    e->hp[num] = e->hpMax = 50;

    e->guard[num] = e->guardMax = 50;

    e->metsuMax = 100;
    e->metsuGauge[num] = 0;

    e->x[num] = (float)x * mapTile;
    e->y[num] = (float)y * mapTile;

    e->vx[num] = 0.0f;
    e->vy[num] = 0.0f;

    e->bullet[num] = e->bulletMax = 3;

    e->attackType[num] = 0;
    e->state[num] = 0;

    e->metsu[num] = false;

    e->animationNo[num] = 0;
}

void EnemyInitArrow(Enemy* e, int x, int y, int num) {
    e->hp[num] = e->hpMax = 50;

    e->guard[num] = e->guardMax = 50;

    e->metsuMax = 100;
    e->metsuGauge[num] = 0;

    e->x[num] = (float)x * mapTile;
    e->y[num] = (float)y * mapTile;

    e->vx[num] = 0.0f;
    e->vy[num] = 0.0f;

    e->bullet[num] = e->bulletMax = 3;

    e->attackType[num] = 0;
    e->state[num] = 0;

    e->metsu[num] = false;

    e->animationNo[num] = 0;
}

void EnemyInitHealer(Enemy* e, int x, int y, int num) {
    e->hp[num] = e->hpMax = 50;

    e->guard[num] = e->guardMax = 50;

    e->metsuMax = 100;
    e->metsuGauge[num] = 0;

    e->x[num] = (float)x * mapTile;
    e->y[num] = (float)y * mapTile;

    e->vx[num] = 0.0f;
    e->vy[num] = 0.0f;

    e->bullet[num] = e->bulletMax = 3;

    e->attackType[num] = 0;
    e->state[num] = 0;

    e->metsu[num] = false;

    e->animationNo[num] = 0;
}

void EnemyInitArmor(Enemy* e, int x, int y, int num) {
    e->hp[num] = e->hpMax = 50;

    e->guard[num] = e->guardMax = 50;

    e->metsuMax = 100;
    e->metsuGauge[num] = 0;

    e->x[num] = (float)x * mapTile;
    e->y[num] = (float)y * mapTile;

    e->vx[num] = 0.0f;
    e->vy[num] = 0.0f;

    e->bullet[num] = e->bulletMax = 3;

    e->attackType[num] = 0;
    e->state[num] = 0;

    e->metsu[num] = false;

    e->animationNo[num] = 0;
}

void EnemyInitGunner(Enemy* e, int x, int y, int num) {
    e->hp[num] = e->hpMax = 50;

    e->guard[num] = e->guardMax = 50;

    e->metsuMax = 100;
    e->metsuGauge[num] = 0;

    e->x[num] = (float)x * mapTile;
    e->y[num] = (float)y * mapTile;

    e->vx[num] = 0.0f;
    e->vy[num] = 0.0f;

    e->bullet[num] = e->bulletMax = 3;

    e->attackType[num] = 0;
    e->state[num] = 0;

    e->metsu[num] = false;

    e->animationNo[num] = 0;
}

void EnemyInitYoroi(Boss* e, int x, int y) {
    e->hp = e->hpMax = 50;

    e->metsuMax = 100;
    e->metsuGauge = 0;
    e->metsu = false;

    e->x = (float)x * mapTile;
    e->y = (float)y * mapTile;

    e->vx = 0.0f;
    e->vy = 0.0f;

    e->bullet = e->bulletMax = 3;

    e->attackType = 0;
    e->state = 0;

    e->animationNo = 0;
}

void EnemyInitSekienki(Boss* e, int x, int y) {
    e->hp = e->hpMax = 50;

    e->metsuMax = 100;
    e->metsuGauge = 0;
    e->metsu = false;

    e->x = (float)x * mapTile;
    e->y = (float)y * mapTile;

    e->vx = 0.0f;
    e->vy = 0.0f;

    e->bullet = e->bulletMax = 3;

    e->attackType = 0;
    e->state = 0;

    e->animationNo = 0;
}
