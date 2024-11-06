#include <stdio.h>
#include <stdbool.h>
#include "ondes.h"

#ifndef GRAPHES
#define GRAPHES

enum color {
    blue = 1,
    green = 2,
    red = 3
};

struct Graphe {
    int* frame;
    int width;
    int height;
    char* axis;
};

typedef struct Graphe graphe;

void add_frame(graphe G, onde w, int origine, enum color color);
void reset_frame(graphe G);

void display(graphe G);

graphe* creegraphe(int width, int height, char x_axis, char y_axis);

#endif