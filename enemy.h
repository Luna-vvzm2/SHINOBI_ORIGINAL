#pragma once

struct Character;

typedef struct {
	int type; // “G‚Ìí—Ş
	int hp;

	int guard;

	int metsuGauge; // ˆŒYƒQ[ƒW‚Ì—­‚Ü‚è‹ï‡
	int metsuMax; // ˆŒYƒQ[ƒW‚ÌãŒÀ’l

	int x, y;
	int vx, vy;

	int bullet;

	int attackType;
	bool attack;
	bool hit;

	bool metsu;
}Enemy;

void EnemyInit(Enemy* p, int x, int y, int type);
void EnemyUpdate(Enemy* e, Character* p);
void EnemyAI(Enemy* e, Character* p);
void EnemyMove(Enemy* e);
void EnemyAttack(Enemy* e);


