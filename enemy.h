#pragma once

struct Character;

typedef struct Enemy{
	int num; // “G‚Ìí—Ş‚²‚Æ‚Ì”
	int hpMax;
	int hp[10];

	int guardMax;
	int guard[10]; //ƒA[ƒ}[‚ÌŒ»İ’l

	int metsuMax; // ˆŒYƒQ[ƒW‚ÌãŒÀ’l
	int metsuGauge[10]; // ˆŒYƒQ[ƒW‚Ì—­‚Ü‚è‹ï‡
	bool metsu[10]; //–Åó‘Ô‚©”Û‚©

	int x[10], y[10];
	int vx[10], vy[10];

	int bulletMax;
	int bullet[10];
	int bulletX[30];
	int bulletY[30];

	int attackType[10];
	int state[10];

	int animationNo[10];
}Enemy;

typedef struct {
	int hpMax;
	int hp;

	int metsuMax; // ˆŒYƒQ[ƒW‚ÌãŒÀ’l
	int metsuGauge; // ˆŒYƒQ[ƒW‚Ì—­‚Ü‚è‹ï‡
	bool metsu;

	int x, y;
	int vx, vy;

	int bulletMax;
	int bullet;
	int bulletX;
	int bulletY;

	int attackType;
	int state;

	int animationNo;
}Boss;

void EnemyInit(Enemy* white, Enemy* yellow, Enemy* arrow, Enemy* healer, Enemy* armor, Enemy* gunner, Boss* Yoroi, Boss* Sekienki);
void EnemyInitWhite(Enemy* e, int x, int y, int num);
void EnemyInitYellow(Enemy* e, int x, int y, int num);
void EnemyInitArrow(Enemy* e, int x, int y, int num);
void EnemyInitHealer(Enemy* e, int x, int y, int num);
void EnemyInitArmor(Enemy* e, int x, int y, int num);
void EnemyInitGunner(Enemy* e, int x, int y, int num);
void EnemyInitYoroi(Boss* e, int x, int y);
void EnemyInitSekienki(Boss* e, int x, int y);

void EnemyUpdate(Character* p, Enemy* white, Enemy* yellow, Enemy* arrow, Enemy* healer, Enemy* armor, Enemy* gunner, Boss* Yoroi, Boss* Sekienki);
void EnemyAI(Character* p, Enemy* white, Enemy* yellow, Enemy* arrow, Enemy* healer, Enemy* armor, Enemy* gunner, Boss* Yoroi, Boss* Sekienki);
void EnemyMove(Enemy* white, Enemy* yellow, Enemy* arrow, Enemy* healer, Enemy* armor, Enemy* gunner, Boss* Yoroi, Boss* Sekienki);
void EnemyAttack(Character* p, Enemy* white, Enemy* yellow, Enemy* arrow, Enemy* healer, Enemy* armor, Enemy* gunner, Boss* Yoroi, Boss* Sekienki);
void EnemyDraw(Enemy* white, Enemy* yellow, Enemy* arrow, Enemy* healer, Enemy* armor, Enemy* gunner, Boss* Yoroi, Boss* Sekienki);

