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


void printcargarpartida(){
    int guardada;

    do{
        printf("\nDesea Cargar la ultima partida cargada:\n\n");
        printf("\t1. Continuar\n\t2. Salir\n");
        scanf("%i", &guardada);
        fflush(stdin);
        }

        while (guardada != 1 && guardada != 2);


        switch (guardada){
            case 1:
                //Poner archivo Fichero!!!!!!!!!!!!!!!!!!!

            break;


            case 2:
                system("cls");
                menuPrincipal();

            break;
        }
}
