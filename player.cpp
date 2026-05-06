#include "player.h"
#include "collision.h"
#include "map.h"
#include "input.h"
#include <Dxlib.h>

void PlayerInit(Character* p) {
    p->hp = 100;
    p->houGauge = 0;
    p->houCharge = 0;

    p->jutsuGauge = 0;
    p->jutsuCharge = false;

    p->x = 100.0f;
    p->y = 300.0f;
    p->vx = 0.0f;
    p->vy = 0.0f;

    p->dir = true;

    p->jump = false;
    p->stick = false;
    p->dodge = false;
    p->squat = false;

    p->attack = false;
    p->hit = false;

    p->combo = 0;
}

void PlayerUpdate(Character* p, float dt) {
    PlayerMove(p, dt);
    PlayerJump(p);
    PlayerGravity(p, dt);
    PlayerAttack(p);
}

void PlayerMove(Character* p, float dt) {
    p->vx = 0;

    if (InputPress(KEY_INPUT_A)) {
        p->vx = -500.0f;
        p->dir = false;
    }
    if (InputPress(KEY_INPUT_D)) {
        p->vx = 500.0f;
        p->dir = true;
    }

    p->x += p->vx * dt;
}

void PlayerJump(Character* p) {
    if (!p->jump && InputTrigger(KEY_INPUT_SPACE)) {
        p->vy = -500.0f;
        p->jump = true;
    }
}

void PlayerGravity(Character* p, float dt) {
    p->vy += 1500.0f * dt;

    p->y += p->vy * dt;

    if (MapIsGround(p->x, p->y)) {
        p->y = MapGetGroundY(p->x, p->y);
        p->vy = 0.0f;
        p->jump = false;
    }
}

void PlayerAttack(Character* p) {
    if (InputTrigger(KEY_INPUT_I)) {
        PlayerWeakAttack(p);
    }

    if (InputTrigger(KEY_INPUT_O)) {
        PlayerStrongAttack(p);
    }
}

void PlayerWeakAttack(Character* p) {
    p->attack = true;
    p->attackType = 1;
}

void PlayerStrongAttack(Character* p) {
    p->attack = true;
    p->attackType = 2;
}

void PlayerDraw(Character* p) {
    DrawBox(p->x - 32.0f, p->y - 32.0f, p->x, p->y, GetColor(200, 255, 255), TRUE);
}