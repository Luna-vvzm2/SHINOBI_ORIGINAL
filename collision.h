#pragma once

struct Rect {
    int x, y, w, h;
};

bool CollisionCheckRect(const Rect& a, const Rect& b);
bool CollisionCheckCircle(int x1, int y1, int r1, int x2, int y2, int r2);