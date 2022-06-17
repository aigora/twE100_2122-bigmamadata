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


void seleccion1(){

    FILE *Seleccion1;

    Seleccion1 = fopen("SeleccionColor.txt", "w");

    int seleccion1 = 1;

    if (Seleccion1 == NULL) {
        printf("No se ha podido abrir.\n");
        exit(1);
    }
    fprintf(Seleccion1, "%d", seleccion1);

    fclose (Seleccion1);
}

void seleccion2(){

    FILE *Seleccion2;

    Seleccion2 = fopen("SeleccionColor.txt", "w");

    int seleccion2 = 2;

    if (Seleccion2 == NULL) {
        printf("No se ha podido abrir.\n");
        exit(1);
    }
    fprintf(Seleccion2, "%d", seleccion2);

    fclose (Seleccion2);
}

int obtencion(){
        FILE *Obtencion1;

        Obtencion1 = fopen("SeleccionColor.txt", "r");

        int n = 0;

        if (Obtencion1 == NULL) {
        perror("No se ha podido abrir.\n");
        return 0;
        }
        while(!feof(Obtencion1)){
            fscanf(Obtencion1, "%d", &n);
        }

        fclose(Obtencion1);

        return n;
}

