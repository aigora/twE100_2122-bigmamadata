#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct{
    char nombre[20];
    int num;
} jugador;


void cambio (char palabra[], int n){
    int i;

    for (i = 0; i < n; i++){
        if (palabra[i] == '\n'){
            palabra[i] = '\0';
        }
    }
}


void printnuevapartida(){
    jugador player1;
    jugador player2;
    int modalidad, color, x = 0;
    menuNuevaPartida:
                do{
                printf("\nDesea continuar con una nueva partida:\n\n");
                printf("\t1. Continuar\n\t2. Salir\n");
                scanf("%i", &modalidad);
                fflush(stdin);
                }
                while (modalidad !=  1 && modalidad != 2);

                    switch (modalidad){
                        case 1:
                            printf("\n\nPor favor, ingrese el nombre del Jugador 1:\t");
                            fgets(player1.nombre, 20, stdin);
                            cambio (player1.nombre, 20);
                            fflush(stdin);

                            printf("Ingrese el nombre del Jugador 2:\t");
                            fgets(player2.nombre, 20, stdin);
                            cambio (player2.nombre, 20);
                            fflush(stdin);

                            do{
                            printf("\nIntroduzca el color deseado por %s:\n", player1);
                            fflush(stdin);
                            printf("\t1. Negras\n\t2. Blancas\n\t3. Aleatorio\n");
                            scanf("%d", &color);
                            }

                            while(color != 1 && color != 2 && color != 3);


                            if(color == 1){
                            printf("\nEl Jugador %s sera el Color Negro.\n", player1);
                            printf("El Jugador %s sera el Color Blanco.\n", player2);
                            }

                            else if (color == 2){
                            printf("\nEl jugador %s sera el Color Blanco.\n", player1);
                            printf("El Jugador %s sera el Color Negro.\n", player2);
                            }

                            else {
                            srand(time(NULL));
                            x = rand() % (2-1+1) + 1;

                                if (x == 1){
                                    printf("\nEl Jugador %s sera el Color Negro.\n", player1);
                                    printf("El Jugador %s sera el Color Blanco.\n", player2);
                                    }

                                else {
                                    printf("\nEl jugador %s sera el Color Blanco.\n", player1);
                                    printf("El Jugador %s sera el Color Negro.\n", player2);
                                    }
                                }

                            printf("\n\n¿PREPARADOS? VA A EMPEZAR LA PARTIDA, %s VS %s\n", player1, player2);
                            printf("\t(Pulse una tecla para empezar)");
                            getch();
                            system("cls");

                        break; //case 1, modalidad.

                    } //Cierre Switch Modalidad


}
