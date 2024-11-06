#include <stdio.h>
#include <stdbool.h>

#ifndef ONDES
#define ONDES
/*
    A FAIRE 
    Support des types créneau, sinusoidal, triangulaire(deja fait)
    outils d'observation des ondes (ui interactif)
*/

enum types {
    sinus,
    creneau,
    triangle
};

struct Onde {
    int freq;
    int amplitude;
    enum types type;
};

typedef struct Onde onde ;

onde* cree(int freq, int amplitude, enum types type);
int valeur(onde* w, int t);
onde* derivee(onde* w); // derivée de la tension pour voir variations
int* energie(onde* w); // bilan d'énergie

#endif