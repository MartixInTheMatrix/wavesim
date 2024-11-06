#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "ondes.h"
#include "graphes.h"

void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;

    clock_t start_time = clock();

    while (clock() < start_time + milli_seconds);
}

void auto_mode(int nombre_iterations, int del, graphe* G, onde* w, onde* z){
    for(int i=0; i<=del; i++){
        delay(nombre_iterations * 100);

        reset_frame(*G);
        add_frame(*G, *w, i, blue);
        add_frame(*G, *z, 0, green);

        display(*G);
    }
}
int main(){
    bool running = true;
    int origine = 0;

    onde* w = cree(1, 8, sinus);
    onde* z = cree(2, 8, sinus);

    graphe* G = creegraphe(100, 2*w->amplitude, 't', 'u');
    
    while(running){
        reset_frame(*G);
        add_frame(*G, *w, origine, blue);
        add_frame(*G, *z, 0, green);

        display(*G);
        printf("> ");
        char cmd;
        scanf("%c", &cmd);

        if(cmd == 'q'){
            running = false;
        }else if(cmd == 'a'){
            int nb, t;
            printf("Combien d'images voulez voir par seconde ? ");
            scanf("%d", &nb);
            printf("Combien de temps (en secondes) voulez vous que l'animation dure ? ");
            scanf("%d", &t);
            auto_mode(nb, t, G, w, z);
        }
        origine++;
    }

}