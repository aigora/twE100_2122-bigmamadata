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
#include "menupausa.h"

void portadachess(){
    FILE *Bienvenida;
    char mensaje;

    Bienvenida = fopen ("Chess.txt","r");

    if (Bienvenida == NULL){
        printf("Error al abrir el archivo");
    }

    else{
        system("cls");
        fseek (Bienvenida, 0, SEEK_SET);

        for (mensaje = 0; mensaje != EOF;){
            mensaje = fgetc(Bienvenida);
            printf("%c", mensaje);
        }
    }
    fclose(Bienvenida);
}

void ganador1(){
    FILE *Ganador1;
    char mensaje1;

    Ganador1 = fopen ("Ganador1.txt","r");

    if (Ganador1 == NULL){
        printf("Error al abrir el archivo");
    }

    else{
        system("cls");
        fseek (Ganador1, 0, SEEK_SET);

        for (mensaje1 = 0; mensaje1 != EOF;){
            mensaje1 = fgetc(Ganador1);
            printf("%c", mensaje1);
        }
    }
    fclose(Ganador1);
}

void ganador2(){
    FILE *Ganador2;
    char mensaje2;

    Ganador2 = fopen ("Ganador2.txt","r");

    if (Ganador2 == NULL){
        printf("Error al abrir el archivo");
    }

    else{
        system("cls");
        fseek (Ganador2, 0, SEEK_SET);

        for (mensaje2 = 0; mensaje2 != EOF;){
            mensaje2 = fgetc(Ganador2);
            printf("%c", mensaje2);
        }
    }
    fclose(Ganador2);
}

int victoria(){
        FILE *Victoria;

        Victoria = fopen("Ganador.txt", "r");

        int n = 0;

        if (Victoria == NULL) {
        perror("No se ha podido abrir.\n");
        return 0;
        }
        while(!feof(Victoria)){
            fscanf(Victoria, "%d", &n);
        }

        fclose(Victoria);

        return n;
}

void reconocimientoganador1(){

    FILE *Reconocimiento1;

    Reconocimiento1 = fopen("Ganador.txt", "w");

    int reconocimiento1 = 1;

    if (Reconocimiento1 == NULL) {
        printf("No se ha podido abrir.\n");
        exit(1);
    }
    fprintf(Reconocimiento1, "%d", reconocimiento1);

    fclose (Reconocimiento1);
}

void reconocimientoganador2(){

    FILE *Reconocimiento2;

    Reconocimiento2 = fopen("Ganador.txt", "w");

    int reconocimiento2 = 2;

    if (Reconocimiento2 == NULL) {
        printf("No se ha podido abrir.\n");
        exit(1);
    }
    fprintf(Reconocimiento2, "%d", reconocimiento2);

    fclose (Reconocimiento2);
}




