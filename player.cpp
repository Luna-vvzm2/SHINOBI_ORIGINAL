#include "player.h"
#include "collision.h"
#include "map.h"
#include "input.h"
#include <Dxlib.h>

void PlayerInit(Character* p) {
    p->x = 100.0f;
    p->y = 300.0f;
    p->vx = 0.0f;
    p->vy = 0.0f;

    p->hp = 100;

    p->houGauge = 0;
    p->houCharge = 0;

    p->jutsuGauge = 0;
    p->jutsuCharge = false;

    p->dir = true;
    p->jump = true;
    p->jumpCount = 0;
    p->jumpTime = 0.0f;
    p->stick = false;
    p->dodge = false;
    p->squat = false;

    p->attackType = 0;
    p->attack = false;
    p->hit = false;

    p->autoGofu = 0;
    p->attackGofu = 0;
    p->katana = 0;

    p->combo = 0;

    p->animationNo = 0;
}

float maxJumpTime = 1.5f;

void PlayerUpdate(Character* p, float dt) {
    PlayerMove(p, dt);
    PlayerJump(p, dt);
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
        if (!p->dir) {
            p->vx = 0.0f;
        }
        else{
            p->vx = 500.0f;
        }
        p->dir = true;
    }

    p->x += p->vx * dt;
}

void PlayerJump(Character* p, float dt) {
    if (InputTrigger(KEY_INPUT_SPACE)) {
        if (p->jumpCount == 0) {
            p->vy = -800.0f;
            p->jump = true;
            p->jumpCount++;

            p->jumpTime = 0.0f;
        }
        else if (p->jumpCount == 1) {
            p->vy = -700.0f;
            p->jumpCount++;
        }
    }

    if (InputPress(KEY_INPUT_SPACE) && p->jumpCount == 1 && p->jumpTime < maxJumpTime) {
        p->vy += -1000.0f * dt;
        p->jumpTime += dt;
    }
}

void PlayerGravity(Character* p, float dt) {
    if (p->jump) {
        p->vy += 2500.0f * dt;
        p->y += p->vy * dt;
    }

    if (MapIsGround((int)p->x, (int)p->y)) {
        p->y = (float)MapGetGroundY((int)p->x, (int)p->y);
        p->vy = 0.0f;
        p->jump = false;
        p->jumpTime = 0.0f;
        p->jumpCount = 0;
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
    DrawBox((int)p->x - 32, (int)p->y - 32, (int)p->x, (int)p->y, GetColor(200, 255, 255), TRUE);
}