#ifndef TOPO_H_
#define TOPO_H_
typedef struct point {
    int x;
    int y;
} point;

// Each topography expects that it will be represented by an underlying 2d grid
// i.e. a direction is just a function width, height, point -> point
// in the ideal world this would be curried so one could do
// topolgy t = TORUS(4,4);
// p = (*t.north)((point){0,0});
typedef struct topology {
    point (*north)(int, int, point);
    point (*west)(int, int, point);
    point (*south)(int, int, point);
    point (*east)(int, int, point);
} topology;

point torus_north(int, int, point);
point torus_west(int, int, point);
point torus_south(int, int, point);
point torus_east(int, int, point);

#define TORUS \
(topology){&torus_north, &torus_west, &torus_south, &torus_east}

#endif
