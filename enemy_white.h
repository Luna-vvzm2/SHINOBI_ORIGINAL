#pragma once

struct Character;
struct Enemy;
struct Boss;

void WhiteAI(Character* p, Enemy* white);
void WhiteMove(float dt, Enemy* white);
void WhiteDraw(Enemy* white);