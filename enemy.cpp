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

Enemy white;
Enemy yellow;
Enemy arrow;
Enemy healer;
Enemy armor;
Enemy gunner;
Boss Yoroi;
Boss Sekienki;

void EnemyInit(Enemy* white, Enemy* yellow, Enemy* arrow, Enemy* healer, Enemy* armor, Enemy* gunner, Boss* Yoroi, Boss* Sekienki){
    static int whiteCount = 0;
    static int yellowCount = 0;
    static int arrowCount = 0;
    static int healerCount = 0;
    static int armorCount = 0;
    static int gunnerCount = 0;

    for (int i = 0; i < mapHeight; i++) {
        for (int j = 0; j < mapWidth; j++) {
            switch (objData[i][j]) {
            case 1:
                EnemyInitWhite(white, j, i, whiteCount);
                whiteCount++;
                break;
            case 2:
                EnemyInitYellow(yellow, j, i, yellowCount);
                yellowCount;
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

void EnemyUpdate(Enemy* white, Enemy* yellow, Enemy* arrow, Enemy* healer, Enemy* armor, Enemy* gunner, Boss* Yoroi, Boss* Sekienki) {
    EnemyAI(white, yellow, arrow, healer, armor, gunner, Yoroi, Sekienki);
    EnemyMove(white, yellow, arrow, healer, armor, gunner, Yoroi, Sekienki);
    EnemyAttack(white, yellow, arrow, healer, armor, gunner, Yoroi, Sekienki);
}

void EnemyAI(Enemy* white, Enemy* yellow, Enemy* arrow, Enemy* healer, Enemy* armor, Enemy* gunner, Boss* Yoroi, Boss* Sekienki) {
}

void EnemyMove(Enemy* white, Enemy* yellow, Enemy* arrow, Enemy* healer, Enemy* armor, Enemy* gunner, Boss* Yoroi, Boss* Sekienki) {
}

void EnemyAttack(Enemy* white, Enemy* yellow, Enemy* arrow, Enemy* healer, Enemy* armor, Enemy* gunner, Boss* Yoroi, Boss* Sekienki) {
}

void EnemyInitWhite(Enemy* e, int x, int y, int num) {
    e->hp[num] = e->hpMax = 50;

    e->guard[num] = e->guardMax = 50;

    e->metsuMax = 100;
    e->metsuGauge[num] = 0;

    e->x[num] = x;
    e->y[num] = y;

    e->vx[num] = 0;
    e->vy[num] = 0;

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

    e->x[num] = x;
    e->y[num] = y;

    e->vx[num] = 0;
    e->vy[num] = 0;

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

    e->x[num] = x;
    e->y[num] = y;

    e->vx[num] = 0;
    e->vy[num] = 0;

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

    e->x[num] = x;
    e->y[num] = y;

    e->vx[num] = 0;
    e->vy[num] = 0;

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

    e->x[num] = x;
    e->y[num] = y;

    e->vx[num] = 0;
    e->vy[num] = 0;

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

    e->x[num] = x;
    e->y[num] = y;

    e->vx[num] = 0;
    e->vy[num] = 0;

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

    e->x = x;
    e->y = y;

    e->vx = 0;
    e->vy = 0;

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

    e->x = x;
    e->y = y;

    e->vx = 0;
    e->vy = 0;

    e->bullet = e->bulletMax = 3;

    e->attackType = 0;
    e->state = 0;

    e->animationNo = 0;
}
