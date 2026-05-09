#pragma once

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
	bool stick;
	bool dodge;
	bool squat;

	int attackType;
	bool attack;
	bool hit;

	int autoGofu;
	int attackGofu;
	int katana;

	int combo;

	int animationNo;
}Character;

void PlayerInit(Character* p);
void PlayerUpdate(Character* p, float dt);
void PlayerMove(Character* p, float dt);
void PlayerJump(Character* p, float dt);
void PlayerGravity(Character* p, float dt);
void PlayerAttack(Character* p);
void PlayerWeakAttack(Character* p);
void PlayerStrongAttack(Character* p);

void PlayerDraw(Character* p);
