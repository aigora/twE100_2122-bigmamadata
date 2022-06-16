#include <stdio.h>
#include <stdlib.h> // libreria para el uso de rand()
#include <time.h>
#include <string.h>

typedef struct{
    char nombre[20];
    int num;
} jugador;

int buscarNumero(int numero, int vector[], int n){
    int i, stop = 0;

    for (i = 0; i < n && stop == 0; i++){
        if(vector[i] == numero)
            stop = 1;
    }
    return stop;
}

void printtorneo(){
    int torneo = 0, i = 0, j = 0, jugartorneo = 0, jugar;
    int min = 1, aux = 0, fstop;
    int num_aletorio, numeros[20] = {0};
    char s1[20], s2[20], s3[20], s4[20], s5[20], s6[20], s7[20], s8[20];

            menuTorneo:
                do{
                printf("\nHa entrado usted en el modo TORNEO, desea continuar:\n\t1. Si\n\t2. Salir\n");
                scanf("%d", &jugartorneo);
                }

                while (jugartorneo != 1 && jugartorneo != 2);

                switch (jugartorneo){
                    case 1:
                        do{
                        printf("\n\nBienvenido al MODO TORNEO. Por favor, indique el numero de participantes totales:\t(4 u 8 jugadores)\n");
                        scanf("%d", &torneo);
                        }

                        while (torneo != 4 && torneo != 8);


                        jugador players[torneo];
                        printf("\n");


                        for (i = 0; i < torneo; i++){
                        printf("Introduzca el Nombre del Jugador %d:\t", i + 1);
                        scanf("%s", players[i].nombre); //Asignaci�n de nombres a jugadores.
                        aux = aux + 1;
                        players[i].num = aux; //Asignaci�n a cada jugador de un n�mero desde el 1 al 4-8.
                        }

                        printf("\n\n");

                        srand(time(NULL));

                        for(i = 0; i < torneo; i++){ //Creaci�n de una serie de los n�meros anteriores sin repetici�n.
                            do{
                            num_aletorio = min + rand()% (torneo - min + 1);
                            fstop = buscarNumero (num_aletorio, numeros, torneo);
                            }
                            while(fstop);

                        numeros[i] = num_aletorio;
                        }


                        if (torneo == 4){

                        printf("Los emparejamientos seran los siguientes:\n\tSemifinal 1:"); //Asignaremos a esa serie de n�meros los nombres escogidos anteriormente y que ya ten�an un previo n�mero asignado.

                        for (i = 0; i < torneo - 3; i++){
                            for (j = 0; j < torneo; j++){
                                if (numeros [i] == players[j].num){
                                printf(" %s", players[j].nombre);
                                strcpy(s1, players[j].nombre);
                                fflush(stdin);
                                }
                            }
                        }


                        printf(" VS ");

                        for (i = 1; i < torneo - 2; i++){
                            for (j = 0; j < torneo; j++){
                                if (numeros [i] == players[j].num){
                                printf("%s", players[j].nombre);
                                strcpy(s2, players[j].nombre);
                                fflush(stdin);
                                }
                            }
                        }


                        printf("\n\tSemifinal 2:");

                        for (i = 2; i < torneo - 1; i++){
                            for (j = 0; j < torneo; j++){
                                if (numeros [i] == players[j].num){
                                printf(" %s", players[j].nombre);
                                strcpy(s3, players[j].nombre);
                                fflush(stdin);
                                }
                            }
                        }


                        printf(" VS ");

                        for (i = 3; i < torneo; i++){
                            for (j = 0; j < torneo; j++){
                                if (numeros [i] == players[j].num){
                                printf("%s", players[j].nombre);
                                strcpy(s4, players[j].nombre);
                                fflush(stdin);
                                }
                            }
                        }

                        }//Cierre if (torneo == 4)


                        if (torneo == 8){ //Asignaremos a esa serie de n�meros los nombres escogidos anteriormente y que ya ten�an un previo n�mero asignado.

                        printf("Los emparejamientos seran los siguientes:\n\tCuartos de Final 1:");
                        for (i = 0; i < torneo - 7; i++){
                            for (j = 0; j < torneo; j++){
                                if (numeros [i] == players[j].num){
                                printf(" %s", players[j].nombre);
                                strcpy(s1, players[j].nombre);
                                fflush(stdin);
                                }
                            }
                        }

                        printf(" VS ");

                        for (i = 1; i < torneo - 6; i++){
                            for (j = 0; j < torneo; j++){
                                if (numeros [i] == players[j].num){
                                printf("%s", players[j].nombre);
                                strcpy(s2, players[j].nombre);
                                fflush(stdin);
                                }
                            }
                        }

                        printf("\n\tCuartos de Final 2:");

                        for (i = 2; i < torneo - 5; i++){
                            for (j = 0; j < torneo; j++){
                                if (numeros [i] == players[j].num){
                                printf(" %s", players[j].nombre);
                                strcpy(s3, players[j].nombre);
                                fflush(stdin);
                                }
                            }
                        }

                        printf(" VS ");

                        for (i = 3; i < torneo - 4; i++){
                            for (j = 0; j < torneo; j++){
                                if (numeros [i] == players[j].num){
                                printf("%s", players[j].nombre);
                                strcpy(s4, players[j].nombre);
                                fflush(stdin);
                                }
                            }
                        }

                        printf("\n\tCuartos de Final 3:");

                        for (i = 4; i < torneo - 3; i++){
                            for (j = 0; j < torneo; j++){
                                if (numeros [i] == players[j].num){
                                printf(" %s", players[j].nombre);
                                strcpy(s5, players[j].nombre);
                                fflush(stdin);
                                }
                            }
                        }

                        printf(" VS ");

                        for (i = 5; i < torneo - 2; i++){
                            for (j = 0; j < torneo; j++){
                                if (numeros [i] == players[j].num){
                                printf("%s", players[j].nombre);
                                strcpy(s6, players[j].nombre);
                                fflush(stdin);
                                }
                            }
                        }

                        printf("\n\tCuartos de Final 4:");

                        for (i = 6; i < torneo - 1; i++){
                            for (j = 0; j < torneo; j++){
                                if (numeros [i] == players[j].num){
                                printf(" %s", players[j].nombre);
                                strcpy(s7, players[j].nombre);
                                fflush(stdin);
                                }
                            }
                        }

                        printf(" VS ");

                        for (i = 7; i < torneo; i++){
                            for (j = 0; j < torneo; j++){
                                if (numeros [i] == players[j].num){
                                printf("%s", players[j].nombre);
                                strcpy(s8, players[j].nombre);
                                fflush(stdin);
                                }
                            }
                        }

                        } //Cierre if (torneo == 8)


                        do{
                        printf("\n\nRecuerda los emparejamientos del torneo para los proximos partidos.\n\tDesea continuar con el primer partido: %s VS %s.\n\t\t1. Si\n\t\t2. Salir\n", s1, s2);
                        scanf("%d", &jugar);
                        }

                        while (jugar != 1 && jugar != 2);

                            switch (jugar){
                                case 1:
                                    printf("\nConstruccion");
                                    getch();
                                break;

                                case 2:
                                    system("cls");
                                    goto menuTorneo;
                                break;
                            }

                    break; //case 1, jugartorneo.


            }//Cierre Switch Jugartorneo.
}
