#include "enemy.h"
#include "player.h"
#include <stdlib.h> // rand

void EnemyInit(Enemy* e, int x, int y, int type) {
    e->type = type;
    e->hp = 50;

    e->guard = 0;

    e->metsuGauge = 0;
    e->metsuMax = 100;

    e->x = x;
    e->y = y;

    e->vx = 0;
    e->vy = 0;

    e->bullet = 3;

    e->attack = false;
    e->hit = false;
    e->metsu = false;
}

void EnemyUpdate(Enemy* e, Character* p) {
    EnemyAI(e, p);
    EnemyMove(e);
    EnemyAttack(e);
}

void EnemyAI(Enemy* e, Character* p) {
    if (p->x < e->x) {
        e->vx = -2;
    }
    else {
        e->vx = 2;
    }
}

void EnemyMove(Enemy* e) {
    e->x += e->vx;
}

void EnemyAttack(Enemy* e) {
    e->attack = false;

    if (rand() % 120 == 0) {
        e->attack = true;
        e->attackType = 1;
    }
}

