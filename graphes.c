#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ondes.h"
#include "graphes.h"

/*
    UI
*/

void add_frame(graphe G, onde w, int origine, enum color color){
    for(int i = 0; i<=G.width; i++){
        G.frame[G.width*valeur(&w, (i+origine)) +i] = color;
    }
}

void reset_frame(graphe G){
    for(int i=0; i<=G.width; i++){
        for(int j=0; j<=G.height;j++){
            G.frame[j*G.width + i] = 0;
        }
    }
}

void display(graphe G){
    printf("\n\n\n\n\n\n");
    for(int j=0; j<G.height; j++){
        for(int i=0; i<G.width; i++){
            if(G.frame[G.width*j + i] == 0){
                if(j==G.height/2){
                    printf("-");
                    if(i==(G.width-1)){
                        printf("\x1b[32m u(t) = 0, Ampitude = %dV \x1b[0m", (G.height/2));
                    }
                }else{
                    printf(" ");
                }
            }else{
                if(G.frame[G.width*j + i] == blue){
                    printf("\x1b[34m#\x1b[0m");
                } else if(G.frame[G.width*j + i] == green){
                    printf("\x1b[32m#\x1b[0m");
                } else {
                    printf("\x1b[31m#\x1b[0m");
                }
            }     
        }
        printf("\n");
    }
    printf("\n");
}

graphe* creegraphe(int width, int height, char x_axis, char y_axis){
    graphe* G = (graphe*)malloc(sizeof(graphe));
    G->axis = (char*)malloc(sizeof(char)*2);
    G->axis[0] = x_axis;
    G->axis[1] = y_axis;
    G->width = width;
    G->height = height;
    G->frame = (int*)malloc(sizeof(int)*width*height);
    return G;
}