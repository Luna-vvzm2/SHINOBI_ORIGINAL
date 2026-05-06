#include "collision.h"
#include <cmath>

bool CollisionCheckRect(const Rect& a, const Rect& b) {
    return (a.x < b.x + b.w &&
        a.x + a.w > b.x &&
        a.y < b.y + b.h &&
        a.y + a.h > b.y);
}

bool CollisionCheckCircle(int x1, int y1, int r1, int x2, int y2, int r2) {
    int dx = x1 - x2;
    int dy = y1 - y2;
    return (dx * dx + dy * dy) <= (r1 + r2) * (r1 + r2);
}