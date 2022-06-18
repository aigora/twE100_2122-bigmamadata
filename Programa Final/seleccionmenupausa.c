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


void seleccionmenu1(){

    FILE *Seleccionmenu1;

    Seleccionmenu1 = fopen("SeleccionMenu.txt", "w");

    int seleccionmenu1 = 1;

    if (Seleccionmenu1 == NULL) {
        printf("No se ha podido abrir.\n");
        exit(1);
    }
    fprintf(Seleccionmenu1, "%d", seleccionmenu1);

    fclose (Seleccionmenu1);
}

void seleccionmenu2(){

    FILE *Seleccionmenu2;

    Seleccionmenu2 = fopen("SeleccionMenu.txt", "w");

    int seleccionmenu2 = 2;

    if (Seleccionmenu2 == NULL) {
        printf("No se ha podido abrir.\n");
        exit(1);
    }
    fprintf(Seleccionmenu2, "%d", seleccionmenu2);

    fclose (Seleccionmenu2);
}

int obtencionmenu(){
        FILE *Obtencionmenu1;

        Obtencionmenu1 = fopen("SeleccionMenu.txt", "r");

        int n = 0;

        if (Obtencionmenu1 == NULL) {
        perror("No se ha podido abrir.\n");
        return 0;
        }
        while(!feof(Obtencionmenu1)){
            fscanf(Obtencionmenu1, "%d", &n);
        }

        fclose(Obtencionmenu1);

        return n;
}

void borradoobtencionmenu(){
    FILE *Borradoobtencionmenu;

    Borradoobtencionmenu = fopen("SeleccionMenu.txt", "w");

    int borradoobtencionmenu = 0;

    if (Borradoobtencionmenu == NULL) {
        printf("No se ha podido abrir.\n");
        exit(1);
    }
    fprintf(Borradoobtencionmenu, "%d", borradoobtencionmenu);

    fclose (Borradoobtencionmenu);
}


