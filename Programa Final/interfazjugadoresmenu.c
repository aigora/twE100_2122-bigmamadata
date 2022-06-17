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

typedef struct{
    char nombre[20];
    int num;
} jugador;

jugador player1;
jugador player2;


void creafichero1(char n[]){

 FILE *Jugador1;

    Jugador1 = fopen("NombreJugador1.txt", "w");
    if (Jugador1 == NULL) {
        printf("No se ha podido abrir.\n");
        exit(1);
    }
    cambio (n, 20);
    fprintf (Jugador1, "%s", n);

    fclose (Jugador1);
}

void creafichero2(char n[]){

    FILE *Jugador2;

    Jugador2 = fopen("NombreJugador2.txt", "w");
    if (Jugador2 == NULL) {
        printf("No se ha podido abrir.\n");
        exit(1);
    }
    cambio (n, 20);
    fprintf(Jugador2, "%s", n);

    fclose(Jugador2);
}

void creacolor1(char color1[]){
    FILE *Color1;

    Color1 = fopen("ColorJugador1.txt", "w");

    if (Color1 == NULL) {
        printf("No se ha podido abrir.\n");
        exit(1);
    }
    fprintf (Color1, "%s", color1);

    fclose (Color1);
}

void creacolor2(char color2[]){
    FILE *Color2;

    Color2 = fopen("ColorJugador2.txt", "w");

    if (Color2 == NULL) {
        printf("No se ha podido abrir.\n");
        exit(1);
    }
    fprintf (Color2, "%s", color2);

    fclose (Color2);
}
