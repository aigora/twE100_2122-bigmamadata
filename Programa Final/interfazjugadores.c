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


void interfazjugcol(){

        FILE *Jugador11;
               Jugador11 = fopen("NombreJugador1.txt", "r");

               if (Jugador11 == NULL) {
                perror("No se ha podido abrir.\n");
                return 1;
                }

                fseek(Jugador11, 0, SEEK_END);
                int num_elementos = ftell(Jugador11);
                rewind(Jugador11);

                char *play1 = (char*) calloc(sizeof(char), num_elementos);

                if(play1 == NULL){
                    perror("No se ha podido abrir.\n");
                    return 2;
                }

                int num_elementos_leidos = fread(play1, sizeof(char), num_elementos, Jugador11);
                if(num_elementos_leidos != num_elementos){
                    perror("No se ha podido abrir.\n");
                    return 3;
                }

                 FILE *Color11;
               Color11 = fopen("ColorJugador1.txt", "r");

               if (Color11 == NULL) {
                perror("No se ha podido abrir.\n");
                return 1;
                }

                fseek(Color11, 0, SEEK_END);
                int num_elementos_color = ftell(Color11);
                rewind(Color11);

                char *color11 = (char*) calloc(sizeof(char), num_elementos_color);

                if(color11 == NULL){
                    perror("No se ha podido abrir.\n");
                    return 2;
                }

                int num_elementos_leidos_color = fread(color11, sizeof(char), num_elementos_color, Color11);
                if(num_elementos_leidos_color != num_elementos_color){
                    perror("No se ha podido abrir.\n");
                    return 3;
                }

                 printf("\n\nMueve %s (%s): ", play1, color11);

                 free(play1);
                 fclose(Jugador11);
                 free(color11);
                 fclose(Color11);

}

void interfazjugcol2(){
FILE *Jugador22;
               Jugador22 = fopen("NombreJugador2.txt", "r");

               if (Jugador22 == NULL) {
                perror("No se ha podido abrir.\n");
                return 1;
                }

                fseek(Jugador22, 0, SEEK_END);
                int num_elementos2 = ftell(Jugador22);
                rewind(Jugador22);

                char *play2 = (char*) calloc(sizeof(char), num_elementos2);

                if(play2 == NULL){
                    perror("No se ha podido abrir.\n");
                    return 2;
                }

                int num_elementos_leidos2 = fread(play2, sizeof(char), num_elementos2, Jugador22);
                if(num_elementos_leidos2 != num_elementos2){
                    perror("No se ha podido abrir.\n");
                    return 3;
                }

                FILE *Color22;
               Color22 = fopen("ColorJugador2.txt", "r");

               if (Color22 == NULL) {
                perror("No se ha podido abrir.\n");
                return 1;
                }

                fseek(Color22, 0, SEEK_END);
                int num_elementos_color2 = ftell(Color22);
                rewind(Color22);

                char *color22 = (char*) calloc(sizeof(char), num_elementos_color2);

                if(color22 == NULL){
                    perror("No se ha podido abrir.\n");
                    return 2;
                }

                int num_elementos_leidos_color2 = fread(color22, sizeof(char), num_elementos_color2, Color22);
                if(num_elementos_leidos_color2 != num_elementos_color2){
                    perror("No se ha podido abrir.\n");
                    return 3;
                }

                printf("\n\nMueve %s (%s): ", play2, color22);

                free(play2);
                fclose(Jugador22);
                free(color22);
                fclose(Color22);
}

