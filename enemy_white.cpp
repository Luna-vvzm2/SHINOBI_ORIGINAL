#include "enemy_white.h"
#include "enemy.h"
#include "player.h"
#include "collision.h"
#include "map.h"

#include <dxlib.h>

void WhiteAI(Character* p, Enemy* white) {
    for (int i = 0; i < whiteCount; i++) {
        float distance = p->x - white->x[i];

        switch (white->state[i]) {
        case 0:
            if (abs((int)distance) < 100) {
                white->state[i] = 2;
            }
            white->vx[i] = 0;
            break;
        case 1: // ‚â‚ç‚ê
            break;
        case 2: // ’Ç”ö
            if (distance > 100) {
                white->vx[i] = 300.0f;
            }
            else if (distance < -100) {
                white->vx[i] = -300.0f;
            }
            else {
                white->vx[i] = 0;
            }
            break;
        }
    }
}

void WhiteMove(float dt, Enemy* white) {
    for (int i = 0; i < whiteCount; i++) {
        white->x[i] += white->vx[i] * dt;
        white->y[i] += white->vy[i] * dt;

        white->vx[i] = 0.0f;

        if (MapIsGround((int)white->x[i], (int)white->y[i])) {
            white->y[i] = (float)MapGetGroundY((int)white->x[i], (int)white->y[i]);
            white->vy[i] = 0.0f;
        }
        else {
            white->vy[i] += 2500.0f * dt;
            white->y[i] += white->vy[i] * dt;
        }
    }
}

void WhiteDraw(Enemy* white) {
    for (int i = 0; i < whiteCount; i++) {
        DrawBox((int)white->x[i] - 32, (int)white->y[i] - 32, (int)white->x[i], (int)white->y[i], GetColor(250, 250, 250), TRUE);
    }
    DrawFormatString(0, 32, GetColor(0, 250, 0), "%d", whiteCount);
}