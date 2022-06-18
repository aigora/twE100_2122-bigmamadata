#include <stdio.h>
#include "defs.h"
#include "nuevapartida.h"
#include "interfazjugadores.h"
#include "interfazpartida.h"
#include "seleccioncolor.h"
#include <stdlib.h>
#include <conio.h>

void menupausa(){
    int pausa;

    menuPausa:
    do{
    system("cls");
    printf("Menu de Pausa.\tElija una de las opciones siguientes:\n\n");
    printf("\t1. Reanudar Partida\n\t2. Guardar Partida\n\t3. Salir al Menu Principal\n\t4. Salir del Juego\n");
    scanf("%i", &pausa);
    system("cls");
    }

    while (pausa != 1 && pausa != 2 && pausa != 3 && pausa != 4);

        switch(pausa){
            case 1:
                mainchess2();
                mainchess1();

            break;


            case 2:
                //Situar Función de Guardado de la partida creado por Alex.
                system("cls");
                menuPrincipal();
            break;


            case 3:
                system("cls");
                menuPrincipal();
            break;


            case 4:
                exit(0);
            break;

        }

}

