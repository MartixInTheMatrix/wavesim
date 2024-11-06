#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ondes.h"

/*
    Object manipulation
*/

onde* cree(int freq, int amplitude, enum types type){
    onde* w = (onde*)malloc(sizeof(onde));
    w->amplitude = amplitude;
    w->freq = freq;
    w->type = type;
    return w;
}

int valeur(onde* w, int t){
    int u=0;
    if(w->type == triangle){
        // u(t+1) = u(t) +- freq
        int p = w->freq;
        for(int i=0; i<=t; i++){
            if(u>=2*w->amplitude || u<0){
                p = -p;
            }
            u = u + p;
        }
    }else if(w->type == sinus){
        u = w->amplitude - w->amplitude*cos(2*t*w->freq*3.1); // u(t) = Acos(om*t + phi)
    }
    return u;
}