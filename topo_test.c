#include <assert.h>
#include "topo.h"

int main(int argc, char **argv) {
    // TORUS test
    point p = {0, 0};
    p = (*TORUS.north)(2,2,p);
    assert(p.x == 0);
    assert(p.y == 1);
    p = (*TORUS.north)(2,2,p);
    assert(p.y == 0);
}
