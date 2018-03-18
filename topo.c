#include "topo.h"

// Idea -> function that goes from point to result

struct point torus_north(int w, int h, struct point p) {
    struct point q;
    q.x = p.x;
    q.y = (p.y == h - 1) ? 0 : p.y + 1;
    return q;
}

struct point torus_west(int w, int h, struct point p) {
    struct point q;
    q.x = (p.x == 0) ? w - 1 : p.x - 1;
    q.y = p.y;
    return q;
}

struct point torus_south(int w, int h, struct point p) {
    struct point q;
    q.x = p.x;
    q.y = (p.y == 0) ? h - 1 : p.y - 1;
    return q;
}

struct point torus_east(int w, int h, struct point p) {
    struct point q;
    q.x = (p.x == w - 1) ? 0 : p.x - 1;
    q.y = p.y;
    return q;
}

// TODO: Calculates the point p reflected over the midpoint of 1..l
int flip(int p, int l) {
    int m = l/2;
    return 0;
}

// Reflect over other axis when we wrap around
struct point mobius_west(int w, int h, struct point p) {
    struct point q;
    return q;
}

struct point mobius_east(int w, int h, struct point p) {
    struct point q;
    return q;
}
