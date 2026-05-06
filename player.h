#pragma once

typedef struct Character {
	int hp;

	int houGauge;
	int houCharge;

	int jutsuGauge;
	bool jutsuCharge;

	float x, y;
	float vx, vy;

	bool dir;
	bool jump;
	bool stick;
	bool dodge;
	bool squat;

	int attackType;
	bool attack;
	bool hit;

	int gohu;
	int katana;

	int combo;
}Character;

void PlayerInit(Character* p);
void PlayerUpdate(Character* p, float dt);
void PlayerMove(Character* p, float dt);
void PlayerJump(Character* p);
void PlayerGravity(Character* p, float dt);
void PlayerAttack(Character* p);
void PlayerWeakAttack(Character* p);
void PlayerStrongAttack(Character* p);

void PlayerDraw(Character* p);
