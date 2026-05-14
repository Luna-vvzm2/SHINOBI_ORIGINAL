#include "player.h"
#include "collision.h"
#include "map.h"
#include "input.h"
#include <Dxlib.h>

void PlayerInit(Character* p) {
    p->x = 100.0f;
    p->y = 500.0f;
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

    p->attack = false;
    p->attackType = 0;
    p->weakAttackIdx = 0;
    p->strongAttackIdx = 0;
    p->attackTimer = 0.0f;
    p->state = IDLE;

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
    PlayerAttack(p, dt);
    if (p->attack) {
        p->attackTimer -= dt;
        if (p->attackTimer <= 0) {
            p->attack = false;
            p->weakAttackIdx = 0;
            p->strongAttackIdx = 0;
        }
    }
}

void PlayerMove(Character* p, float dt) {
    p->vx = 0;

    if (InputPress(KEY_INPUT_A)) {
        p->vx = -500.0f;
        p->dir = false;
        p->state = RUN;
    }
    if (InputPress(KEY_INPUT_D)) {
        if (!p->dir) {
            p->vx = 0.0f;
        }
        else{
            p->vx = 500.0f;
        }
        p->dir = true;
        p->state = RUN;
    }

    p->x += p->vx * dt;
}

void PlayerJump(Character* p, float dt) {
    if (InputTrigger(KEY_INPUT_SPACE)) {
        if (p->jumpCount == 0) {
            p->vy = -900.0f;
            p->jump = true;
            p->jumpCount++;

            p->jumpTime = 0.0f;
            p->state = JUMP;
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
        p->vy += 2800.0f * dt;
        p->y += p->vy * dt;
    }
    else {
        p->state = FALL;
    }

    if (MapIsGround((int)p->x, (int)p->y)) {
        p->y = (float)MapGetGroundY((int)p->x, (int)p->y);
        p->vy *= 0.99;
        p->jump = false;
        p->jumpTime = 0.0f;
        p->jumpCount = 0;
        p->state = IDLE;
    }
}

void PlayerAttack(Character* p, float dt) {
    if (InputTrigger(KEY_INPUT_I)) {
        PlayerWeakAttack(p, dt);
    }

    if (InputTrigger(KEY_INPUT_O)) {
        PlayerStrongAttack(p, dt);
    }
}

void PlayerWeakAttack(Character* p, float dt) {
    if (p->weakAttackIdx < 4) {
        p->attack = true;
        p->state = ATTACK;
        p->attackType = 1;
        p->attackTimer = 0.2f;
        p->weakAttackIdx++;
    }
}

void PlayerStrongAttack(Character* p, float dt) {
    if (p->strongAttackIdx < 2) {
        p->attack = true;
        p->state = ATTACK;
        p->attackType = 2;
        p->attackTimer = 0.3f;
        p->strongAttackIdx++;
    }
}

void PlayerDraw(Character* p) {
    switch (p->state) {
    case IDLE:
        DrawBox((int)p->x - 32, (int)p->y - 64, (int)p->x, (int)p->y, GetColor(200, 255, 255), TRUE);
        break;
    case RUN:
        DrawBox((int)p->x - 32, (int)p->y - 64, (int)p->x, (int)p->y, GetColor(200, 255, 255), TRUE);
        break;
    case SQUAT:
        DrawBox((int)p->x - 32, (int)p->y - 32, (int)p->x, (int)p->y, GetColor(200, 255, 255), TRUE);
        break;
    case JUMP:
        DrawBox((int)p->x - 32, (int)p->y - 64, (int)p->x, (int)p->y - 10, GetColor(200, 255, 255), TRUE);
        break;
    case ATTACK:
        DrawBox((int)p->x - 32, (int)p->y - 64, (int)p->x + 10, (int)p->y, GetColor(200, 255, 255), TRUE);
        break;
    case HIT:
        DrawBox((int)p->x - 40, (int)p->y - 55, (int)p->x, (int)p->y, GetColor(200, 255, 255), TRUE);
        break;
    case DEAD:
        DrawBox((int)p->x - 64, (int)p->y - 32, (int)p->x, (int)p->y, GetColor(200, 255, 255), TRUE);
        break;
    }
}