#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "instrucciones.h"
#include "torneo.h"
#include "cargapartida.h"
#include "nuevapartida.h"
#include "interfazjugadores.h"
#include "interfazjugadoresmenu.h"
#include "interfazpartida.h"
#include "seleccioncolor.h"


void ficheroColorUp(){
    char colorUp[20];
    strcpy(colorUp, "Blancas");
    cambio (colorUp, 20);


    FILE *ColorUp;

    ColorUp = fopen("ColorUp.txt", "w");
    if (ColorUp == NULL) {
        printf("No se ha podido abrir.\n");
        exit(1);
    }
    fprintf (ColorUp, "%s", colorUp);

    fclose (ColorUp);
}

void ficheroColorDown(){
    char colorDown[20];
    strcpy(colorDown, "Negras");
    cambio (colorDown, 20);


    FILE *ColorDown;

    ColorDown = fopen("ColorDown.txt", "w");
    if (ColorDown == NULL) {
        printf("No se ha podido abrir.\n");
        exit(1);
    }
    fprintf (ColorDown, "%s", colorDown);

    fclose (ColorDown);
}

void interfazparcolUp(){

                 FILE *ColorUp;
               ColorUp = fopen("ColorUp.txt", "r");

               if (ColorUp == NULL) {
                perror("No se ha podido abrir.\n");
                return 1;
                }

                fseek(ColorUp, 0, SEEK_END);
                int num_elementos_colorup = ftell(ColorUp);
                rewind(ColorUp);

                char *colorUp = (char*) calloc(sizeof(char), num_elementos_colorup);

                if(colorUp == NULL){
                    perror("No se ha podido abrir.\n");
                    return 2;
                }

                int num_elementos_leidos_colorup = fread(colorUp, sizeof(char), num_elementos_colorup, ColorUp);
                if(num_elementos_leidos_colorup != num_elementos_colorup){
                    perror("No se ha podido abrir.\n");
                    return 3;
                }

                 printf("      %s       ", colorUp);

                 free(colorUp);
                 fclose(ColorUp);
}


void interfazparcolDown(){

                 FILE *ColorDown;
               ColorDown = fopen("ColorDown.txt", "r");

               if (ColorDown == NULL) {
                perror("No se ha podido abrir.\n");
                return 1;
                }

                fseek(ColorDown, 0, SEEK_END);
                int num_elementos_colordown = ftell(ColorDown);
                rewind(ColorDown);

                char *colorDown = (char*) calloc(sizeof(char), num_elementos_colordown);

                if(colorDown == NULL){
                    perror("No se ha podido abrir.\n");
                    return 2;
                }

                int num_elementos_leidos_colordown = fread(colorDown, sizeof(char), num_elementos_colordown, ColorDown);
                if(num_elementos_leidos_colordown != num_elementos_colordown){
                    perror("No se ha podido abrir.\n");
                    return 3;
                }

                 printf("      %s       ", colorDown);

                 free(colorDown);
                 fclose(ColorDown);
}
