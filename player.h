#pragma once

#define IDLE 0
#define RUN 1
#define SQUAT 2
#define JUMP 3
#define FALL 4
#define ATTACK 5
#define HIT 6
#define DODGE 7
#define DEAD 8

typedef struct Character {
	float x, y;
	float vx, vy;

	int hp;

	int houGauge;
	int houCharge;

	int jutsuGauge;
	bool jutsuCharge;

	bool dir;
	bool jump;
	int jumpCount;
	float jumpTime;

	bool attack;
	int attackType;
	int weakAttackIdx;
	int strongAttackIdx;
	float attackTimer;
	int state;

	int autoGofu;
	int attackGofu;
	int katana;

	int combo;

	int animationNo;
	int frameCount;
}Character;

void PlayerInit(Character* p);
void PlayerUpdate(Character* p, float dt);
void PlayerMove(Character* p, float dt);
void PlayerJump(Character* p, float dt);
void PlayerGravity(Character* p, float dt);
void PlayerAttack(Character* p, float dt);
void PlayerWeakAttack(Character* p, float dt);
void PlayerStrongAttack(Character* p, float dt);

void PlayerDraw(Character* p);
