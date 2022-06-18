//Menú de Inicio.

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
#include "portadachess.h"

void menuPrincipal(){
    int seleccion;

    menuPrincipal:
    portadachess();
    do{
    printf("\nBienvenido al AJEDREZ!\nElija una de las opciones siguientes:\n\n");
    printf("\t1. Nueva Partida\n\t2. Cargar Partida Anterior\n\t3. Modo Torneo\n\t4. Instrucciones de Juego\n\t5. Salir del Juego\n");
    scanf("%i", &seleccion);
    system("cls");
    }

    while (seleccion != 1 && seleccion != 2 && seleccion != 3 && seleccion != 4 && seleccion != 5);

        switch(seleccion){
            case 1:
                printnuevapartida();

             break;



             case 2:
                printcargarpartida();

             break; //case 2, selección.



             case 3:
                    printtorneo(); //Función de Torneo.

                case 6:
                    system("cls");
                    goto menuPrincipal;

                break;

             break; //case 3, selección.



             case 4:
                 printinstruc(); //Función de Instrucciones.

             break; //case 4, modalidad.



            case 5:
                exit(0);
            break;



        } //cierre switch seleccion.

    return 0;

} //cierre main;




