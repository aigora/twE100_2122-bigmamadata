#include <stdio.h>
#include <ctype.h>
#include <dos.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"


typedef struct{
    char nombre[20];
    int num;
} jugador;

jugador player1;
jugador player2;



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


void printinstruc(){
    int ayuda, piezas, escape, reglas, acabar;

        menuAprendeaJugar:
                printf("\nEn esta seccion encontraras distintas ayudas para comprender mejor el Juego del Ajedrez.\n\n");
                do{
                printf("\t1. Configuracion del Tablero de Ajedrez\n\t2. Movimientos de las Piezas\n\t3. Como Jugar\n\t4. Reglas Especiales\n\t5. Quien Empieza a Jugar\n\t6. Ganar una Partida\n\t7. Salir\n");
                scanf("%d", &ayuda);
                }
                while (ayuda !=  1 && ayuda != 2 && ayuda != 3 && ayuda != 4 && ayuda != 5 && ayuda != 6 && ayuda != 7);

                    switch (ayuda){
                        case 1:
                            printf("\nLa posicion inicial de las piezas es siempre la misma. La segunda fila se encuentra ocupada por 8 peones.\nLas torres ocupan las esquinas, y los dos caballos se situan a sus lados, seguidos por los alfiles.\nAl lado de estos, la reina (o dama) ocupa siempre la casilla de su propio color (la dama blanca en una casilla blanca;\nla negra, en una casilla negra). Por ultimo, el rey se situa al lado de la reina, en la casilla restante.\n");
                            printf("\t(Pulse una tecla para volver)");
                            getch();
                            system("cls");
                            goto menuAprendeaJugar;
                        break;

                        case 2:
                            menuMovimientoPiezas:
                            printf("\nHay 6 tipos de piezas y cada uno tiene su propia forma de moverse. Una pieza no puede moverse atravesando a otra\n(aunque el caballo si puede saltar sobre las demas) y nunca puede desplazarse a una casilla ocupada por otra pieza\nde su color. Sin embargo, las piezas pueden moverse a las casillas ocupadas por las piezas del adversario para\ncapturarlas. De hecho, las piezas se mueven por el tablero para ocupar una casilla con uno de estos tres objetivos:\n\n");
                            printf("\t- Capturar una pieza rival (reemplazandola al ocupar la casilla en la que esta se encontraba).\n\t- Defender a las piezas de su propio bando para evitar que sean capturadas.\n\t- Controlar las casillas importantes del tablero");
                            do{
                            printf("\n\nMovimiento de cada una de las piezas del tablero:\n\t1. Rey\n\t2. Reina o Dama\n\t3. Torre\n\t4. Alfil\n\t5. Caballo\n\t6. Peon\n\t7. Salir\n");
                            scanf("%d", &piezas);
                            }
                            while (piezas !=  1 && piezas != 2 && piezas != 3 && piezas != 4 && piezas != 5 && piezas != 6 && piezas != 7);

                                switch (piezas){
                                    case 1:
                                        printf("\n\nEl rey es la pieza mas importante, pero tambien una de las mas debiles. El rey solo puede avanzar una casilla\nen cualquier direccion: hacia arriba, hacia abajo, hacia los lados o en diagonal. En ningun caso el rey puede moverse\na una casilla en la que estaria en jaque, es decir, en la que pudiera ser capturado.\n");
                                        printf("\t(Pulse una tecla para volver)");
                                        getch();
                                        system("cls");
                                        goto menuMovimientoPiezas;
                                    break;

                                    case 2:
                                        printf("\n\nLa dama (reina) es la pieza mas poderosa. Puede moverse en cualquier direccion (hacia adelante, hacia atras, hacia los\nlados o en diagonal) y tantas casillas como se quiera; siempre y cuando no pase por encima de una pieza de su color.\n");
                                        printf("\t(Pulse una tecla para volver)");
                                        getch();
                                        system("cls");
                                        goto menuMovimientoPiezas;
                                    break;

                                    case 3:
                                        printf("\n\nLa torre puede moverse tantas casillas como quiera, pero solo hacia adelante, hacia atras o hacia los lados. Cuando\ntrabajan juntas son muy poderosas.\n");
                                        printf("\t(Pulse una tecla para volver)");
                                        getch();
                                        system("cls");
                                        goto menuMovimientoPiezas;
                                    break;

                                    case 4:
                                        printf("\n\nEl alfil puede moverse tan lejos como quiera, pero siempre en diagonal. Cada alfil comienza en una casilla de un color\n(claro u oscuro) y debe permanecer toda la partida en ese color. Los dos alfiles trabajan bien juntos ya que uno cubre\nlas debilidades y viceversa.\n");
                                        printf("\t(Pulse una tecla para volver)");
                                        getch();
                                        system("cls");
                                        goto menuMovimientoPiezas;
                                    break;

                                    case 5:
                                        printf("\n\nLos caballos se mueven de una manera muy diferente a la de las otras piezas: avanzan dos casillas en una direccion y,\nluego, una mas en un angulo de 90 grados, dibujando en su desplazamiento una letra 'L' sobre el tablero. Los caballos\ntambien son las unicas piezas que pueden saltar sobre otras.\n");
                                        printf("\t(Pulse una tecla para volver)");
                                        getch();
                                        system("cls");
                                        goto menuMovimientoPiezas;
                                    break;

                                    case 6:
                                        printf("\n\nLos peones tienen la particularidad de que se mueven y capturan de diferentes maneras: se mueven hacia adelante, pero\ncapturan en diagonal. Los peones solo pueden avanzar una casilla en cada jugada, a excepcion de su primer movimiento\nen el que puedan avanzar dos casillas. Los peones solo pueden capturar una casilla situada en diagonal y frente a\nellos. Nunca pueden retroceder, ni siquiera para capturar una pieza. Los peones no pueden moverse si en su camino\nencuentran una pieza que ocupe la casilla situada directamente frente a ellos y tampoco pueden capturarla.\n");
                                        printf("\t(Pulse una tecla para volver)");
                                        getch();
                                        system("cls");
                                        goto menuMovimientoPiezas;
                                    break;

                                    case 7:
                                        system("cls");
                                        goto menuAprendeaJugar;
                                    break;

                                } //cierre switch piezas.

                        break; //case 2, ayuda.


                        case 3:
                            printf("\n\nLa partida solicitara realizar los movimientos segun el turno de cada usuario. Para ello, cada pieza tiene asignada\nuna coordenada compuesta del 0 al 7 para las filas y del mismo tamaño para las columnas. Es decir, la torre izquierda\nde las blancas se correspondera con la coordenada '7.0'.\nPara realizar un movimiento debemos indicar la coordenada de la pieza (por ejemplo, '5.1') seguido de un ' a '(con sus\ndebidos espacios antes y despues) y la coordenada donde se desea desplazar ('6.3'), siempre y cuando el movimiento este\npermitido.\n");
                            printf("\t(Pulse una tecla para volver)");
                            getch();
                            system("cls");
                            goto menuAprendeaJugar;
                            break;


                        case 4:
                            menuReglasEspeciales:
                            printf("\n\nHay unas reglas especiales de ajedrez que fueron creadas para hacer el juego mas divertido e interesante:\n");
                            do{
                            printf("\t1. Coronar un Peon\n\t2. Capturar al Paso (en passant)\n\t3. Enroque\n\t4. Salir\n");
                            scanf("%d", &reglas);
                            }
                            while (reglas !=  1 && reglas != 2 && reglas != 3 && reglas != 4);
                                switch (reglas){
                                    case 1:
                                        printf("\n\nLos peones tienen otra habilidad especial: si llegan al otro extremo del tablero pueden convertirse en cualquier\notra pieza excepto en un rey. A esta jugada se le llama coronacion.\n");
                                        printf("\t(Pulse una tecla para volver)");
                                        getch();
                                        system("cls");
                                        goto menuReglasEspeciales;
                                    break;

                                    case 2:
                                        printf("\n\nLa ultima regla sobre los peones se llama captura en passant. Si un peon avanza dos casillas en su primer movimiento,\ny al hacerlo se situa al lado de un peon rival, este peon enemigo tiene la opcion de capturar al primero ocupando la\ncasilla que aquel hubiera ocupado si solo hubiera avanzado una casilla. Esta jugada especial debe hacerse\ninmediatamente despues del movimiento del primer peon, de lo contrario la opcion de capturar ya no estara disponible.\n");
                                        printf("\t(Pulse una tecla para volver)");
                                        getch();
                                        system("cls");
                                        goto menuReglasEspeciales;
                                    break;

                                    case 3:
                                        printf("\n\nHay otra regla especial denominada enroque. Esta jugada te permite hacer dos cosas importantes en un solo movimiento:\nsituar al rey en una posicion mas segura y sacar a la torre de su esquina para ponerla en juego. En un solo turno\nel jugador puede mover al rey dos casillas hacia un lado y, al mismo tiempo, la torre situada en la esquina de ese\nlado, se coloca junto al rey en la casilla ubicada en el lado opuesto. Sin embargo, para poder hacer un enroque se\ndeben cumplir las siguientes condiciones:\n\t- Debe ser la primera jugada de aquel rey.\n\t- Debe ser la primera jugada de aquella torre.\n\t- No puede haber ninguna pieza entre el rey y la torre.\n\t- El rey no puede estar en jaque ni pasar por una casilla amenazada.\n");
                                        printf("\t(Pulse una tecla para volver)");
                                        getch();
                                        system("cls");
                                        goto menuReglasEspeciales;
                                    break;

                                    case 4:
                                        system("cls");
                                        goto menuAprendeaJugar;
                                    break;
                                }//cierre switch reglas.

                        break; //case 3, ayuda.

                        case 5:
                            printf("\n\nEl jugador con las piezas blancas siempre es el primero en mover. Las blancas realizan la primera jugada, seguida del\nprimer movimiento de las negras, despues mueven blancas de nuevo, y asi sucesiva y alternativamente hasta el final de\nla partida. El jugador que mueve primero tiene una pequeña ventaja porque puede llevar la iniciativa y atacar\ninmediatamente.\n");
                            printf("\t(Pulse una tecla para volver)");
                            getch();
                            system("cls");
                            goto menuAprendeaJugar;
                        break;

                        case 6:
                            menuComoGanar:
                            printf("\n\nHay varias formas de terminar una partida de ajedrez:\n");
                            do{
                            printf("\t1. Jaque Mate\n\t2. En Tablas o Empate\n\t3. Rendirse\n\t4. Perder por tiempo\n\t5. Salir\n");
                            scanf("%d", &acabar);
                            }
                            while (acabar != 1 && acabar != 2 && acabar != 3 && acabar != 4 && acabar != 5);
                                switch (acabar){
                                    case 1:
                                        printf("\n\nEl objetivo del juego es dar jaque mate al rey del adversario. Esto ocurre cuando el rey esta en jaque y no puede salir\nde esa situacion. Solo hay tres formas por las que un rey puede escapar de un jaque:\n\t- Moverse a una casilla segura.\n\t- Bloquear el jaque interponiendo otra pieza de su propio bando.\n\t- Capturar la pieza que amenaza al rey.\n\nSi un rey no puede escapar del jaque, la partida ha terminado.\n");
                                        printf("\t(Pulse una tecla para volver)");
                                        getch();
                                        system("cls");
                                        goto menuComoGanar;
                                    break;

                                    case 2:
                                        printf("\n\nA veces, las partidas de ajedrez terminan sin un ganador, pero en empate (denominado tablas). Hay 5 razones por las que\nuna partida puede terminar en tablas:\n\t- La posicion llega a un punto muerto en el que es el turno de un jugador, pero su rey no esta en jaque y,\n\tsin embargo, no puede hacer ningun movimiento reglamentario. Esto se conoce como 'ahogado'.\n\t- Los jugadores pueden acordar Tablas y dejar de jugar.\n\t- No hay suficientes piezas en el tablero para forzar un jaque mate (ejemplo: un Rey y un Alfil contra otro Rey)\n\t- Un jugador declara Tablas si la misma posicion se repite tres veces (no necesariamente tres veces seguidas).\n\t- Se han efectuado 50 movimientos y ninguno de los jugadores ha movido un peon ni capturado una pieza.\n");
                                        printf("\t(Pulse una tecla para volver)");
                                        getch();
                                        system("cls");
                                        goto menuComoGanar;
                                    break;

                                    case 3:
                                        printf("\n\nUno de los dos jugadores decide rendirse y, por lo tanto, se declara un vencedor.\n");
                                        printf("\t(Pulse una tecla para volver)");
                                        getch();
                                        system("cls");
                                        goto menuComoGanar;
                                    break;

                                    case 4:
                                        printf("\n\nSi el tiempo se acaba para alguno de los dos jugadores, inmediatamente el contrario es el vencedor de la partida.\n");
                                        printf("\t(Pulse una tecla para volver)");
                                        getch();
                                        system("cls");
                                        goto menuComoGanar;
                                    break;

                                    case 5:
                                        system("cls");
                                        goto menuAprendeaJugar;
                                }//cierre switch acabar.

                        break; //case 6, ayuda.


                        case 7:
                            system("cls");
                            menuPrincipal();

                        break;

                    } //Cierre switch ayuda
}



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



void ficheroColorUp(){
    char colorUp[20];
    strcpy(colorUp, "Blancas");
    cambio (colorUp, 20);


    FILE *ColorUp;

    ColorUp = fopen("ColorUp.txt", "w");
    if (ColorUp == NULL) {
        printf("No se ha podido abrir.\n");
        exit(1);
    }
    fprintf (ColorUp, "%s", colorUp);

    fclose (ColorUp);
}



void ficheroColorDown(){
    char colorDown[20];
    strcpy(colorDown, "Negras");
    cambio (colorDown, 20);


    FILE *ColorDown;

    ColorDown = fopen("ColorDown.txt", "w");
    if (ColorDown == NULL) {
        printf("No se ha podido abrir.\n");
        exit(1);
    }
    fprintf (ColorDown, "%s", colorDown);

    fclose (ColorDown);
}



void interfazparcolUp(){

                 FILE *ColorUp;
               ColorUp = fopen("ColorUp.txt", "r");

               if (ColorUp == NULL) {
                perror("No se ha podido abrir.\n");
                return 1;
                }

                fseek(ColorUp, 0, SEEK_END);
                int num_elementos_colorup = ftell(ColorUp);
                rewind(ColorUp);

                char *colorUp = (char*) calloc(sizeof(char), num_elementos_colorup);

                if(colorUp == NULL){
                    perror("No se ha podido abrir.\n");
                    return 2;
                }

                int num_elementos_leidos_colorup = fread(colorUp, sizeof(char), num_elementos_colorup, ColorUp);
                if(num_elementos_leidos_colorup != num_elementos_colorup){
                    perror("No se ha podido abrir.\n");
                    return 3;
                }

                 printf("      %s       ", colorUp);

                 free(colorUp);
                 fclose(ColorUp);
}



void interfazparcolDown(){

                 FILE *ColorDown;
               ColorDown = fopen("ColorDown.txt", "r");

               if (ColorDown == NULL) {
                perror("No se ha podido abrir.\n");
                return 1;
                }

                fseek(ColorDown, 0, SEEK_END);
                int num_elementos_colordown = ftell(ColorDown);
                rewind(ColorDown);

                char *colorDown = (char*) calloc(sizeof(char), num_elementos_colordown);

                if(colorDown == NULL){
                    perror("No se ha podido abrir.\n");
                    return 2;
                }

                int num_elementos_leidos_colordown = fread(colorDown, sizeof(char), num_elementos_colordown, ColorDown);
                if(num_elementos_leidos_colordown != num_elementos_colordown){
                    perror("No se ha podido abrir.\n");
                    return 3;
                }

                 printf("      %s       ", colorDown);

                 free(colorDown);
                 fclose(ColorDown);
}



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

    int modalidad, color, x = 0, indicacion = 0, aux = 0;
    char color1[20] = {}, color2[20] = {};

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

                            creafichero1(player1.nombre);

                            printf("Ingrese el nombre del Jugador 2:\t");
                            fgets (player2.nombre, 20, stdin);
                            cambio (player2.nombre, 20);
                            fflush (stdin);

                            creafichero2(player2.nombre);

                            do{
                            printf("\nIntroduzca el color deseado por %s:\n", player1.nombre);
                            fflush(stdin);
                            printf("\t1. Negras\n\t2. Blancas\n\t3. Aleatorio\n");
                            scanf("%d", &color);
                            }

                            while(color != 1 && color != 2 && color != 3);


                            if(color == 1){
                            printf("\nEl Jugador %s sera el Color Negro.\n", player1.nombre);
                            strcpy(color1, "Negras");
                            cambio (color1, 20);

                            creacolor1(color1);
                            seleccion1();

                            printf("El Jugador %s sera el Color Blanco.\n", player2.nombre);
                            strcpy(color2, "Blancas");
                            cambio (color2, 20);

                            creacolor2(color2);

                            }

                            else if (color == 2){
                            printf("\nEl jugador %s sera el Color Blanco.\n", player1.nombre);
                            strcpy(color1, "Blancas");
                            cambio (color1, 20);


                            creacolor1(color1);
                            seleccion2();


                            printf("El Jugador %s sera el Color Negro.\n", player2.nombre);
                            strcpy(color2, "Negras");
                            cambio (color2, 20);

                            creacolor2(color2);

                            }

                            else {
                            srand(time(NULL));
                            x = rand() % (2-1+1) + 1;

                                if (x == 1){
                                    printf("\nEl Jugador %s sera el Color Negro.\n", player1.nombre);
                                    strcpy(color1, "Negras");
                                    cambio (color1, 20);
                                    creacolor1(color1);
                                    seleccion1();

                                    printf("El Jugador %s sera el Color Blanco.\n", player2.nombre);
                                    strcpy(color2, "Blancas");
                                    cambio (color2, 20);
                                    creacolor2(color2);

                                    }


                                if (x == 2) {
                                    printf("\nEl jugador %s sera el Color Blanco.\n", player1.nombre);
                                    strcpy(color1, "Blancas");
                                    cambio (color1, 20);
                                    creacolor1(color1);
                                    seleccion2();

                                    printf("El Jugador %s sera el Color Negro.\n", player2.nombre);
                                    strcpy(color2, "Negras");
                                    cambio (color2, 20);
                                    creacolor2(color2);

                                    }


                                }

                            printf("\n\n¿PREPARADOS? VA A EMPEZAR LA PARTIDA, %s VS %s\n", player1.nombre, player2.nombre);
                            printf("\t(Pulse una tecla para empezar)");
                            getch();
                            system("cls");
                            mainchess1();
                            mainchess2();

                            aux = victoria();

                            if(aux == 1){
                              printf("\tEl ganador es:");
                              ganador1();
                            }

                            if(aux == 2){
                              printf("\tEl ganador es:");
                              ganador2();
                            }

                            printf("\n\n\t(Pulse una tecla para continuar al menu principal)");
                            getch();
                            menuPrincipal();


                            free(color1);
                            free(color2);

                        break; //case 1, modalidad.


                        case 2:
                            system("cls");
                            menuPrincipal();

                        break;

                    } //Cierre Switch Modalidad


}



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



int buscarNumero(int numero, int vector[], int n){
    int i, stop = 0;

    for (i = 0; i < n && stop == 0; i++){
        if(vector[i] == numero)
            stop = 1;
    }
    return stop;
}



void printtorneo(){
    int torneo = 0, i = 0, j = 0, jugartorneo = 0, jugar, color, x;
    int min = 1, aux = 0, fstop;
    int num_aletorio, numeros[20] = {0};
    char s1[20], s2[20], s3[20], s4[20], s5[20], s6[20], s7[20], s8[20], color1[20], color2[20];

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
                        scanf("%s", players[i].nombre); //Asignación de nombres a jugadores.
                        aux = aux + 1;
                        players[i].num = aux; //Asignación a cada jugador de un número desde el 1 al 4-8.
                        }

                        printf("\n\n");

                        srand(time(NULL));

                        for(i = 0; i < torneo; i++){ //Creación de una serie de los números anteriores sin repetición.
                            do{
                            num_aletorio = min + rand()% (torneo - min + 1);
                            fstop = buscarNumero (num_aletorio, numeros, torneo);
                            }
                            while(fstop);

                        numeros[i] = num_aletorio;
                        }


                        if (torneo == 4){

                        printf("Los emparejamientos seran los siguientes:\n\tSemifinal 1:"); //Asignaremos a esa serie de números los nombres escogidos anteriormente y que ya tenían un previo número asignado.

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


                        if (torneo == 8){ //Asignaremos a esa serie de números los nombres escogidos anteriormente y que ya tenían un previo número asignado.

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
                        creafichero1(s1);
                        creafichero2(s2);
                        printf("\n\nRecuerda los emparejamientos del torneo para los proximos partidos.\n\tDesea continuar con la eleccion de fichas del: %s VS %s.\n\t\t1. Si\n\t\t2. Salir\n", s1, s2);
                        scanf("%d", &jugar);
                        }

                        while (jugar != 1 && jugar != 2);

                            switch (jugar){
                                case 1:
                                    do{
                                    printf("\nIntroduzca el color deseado por %s:\n", s1);
                                    fflush(stdin);
                                    printf("\t1. Negras\n\t2. Blancas\n\t3. Aleatorio\n");
                                    scanf("%d", &color);
                                    }

                                    while(color != 1 && color != 2 && color != 3);


                                    if(color == 1){
                                    printf("\nEl Jugador %s sera el Color Negro.\n", s1);
                                    strcpy(color1, "Negras");
                                    cambio (color1, 20);

                                    creacolor1(color1);
                                    seleccion1();

                                    printf("El Jugador %s sera el Color Blanco.\n", s2);
                                    strcpy(color2, "Blancas");
                                    cambio (color2, 20);

                                    creacolor2(color2);

                                    }

                                    else if (color == 2){
                                    printf("\nEl jugador %s sera el Color Blanco.\n", s1);
                                    strcpy(color1, "Blancas");
                                    cambio (color1, 20);


                                    creacolor1(color1);
                                    seleccion2();


                                    printf("El Jugador %s sera el Color Negro.\n", s2);
                                    strcpy(color2, "Negras");
                                    cambio (color2, 20);

                                    creacolor2(color2);

                                    }

                                    else {
                                    srand(time(NULL));
                                    x = rand() % (2-1+1) + 1;

                                        if (x == 1){
                                            printf("\nEl Jugador %s sera el Color Negro.\n", s1);
                                            strcpy(color1, "Negras");
                                            cambio (color1, 20);
                                            creacolor1(color1);
                                            seleccion1();

                                            printf("El Jugador %s sera el Color Blanco.\n", s2);
                                            strcpy(color2, "Blancas");
                                            cambio (color2, 20);
                                            creacolor2(color2);

                                            }


                                        if (x == 2) {
                                            printf("\nEl jugador %s sera el Color Blanco.\n", s1);
                                            strcpy(color1, "Blancas");
                                            cambio (color1, 20);
                                            creacolor1(color1);
                                            seleccion2();

                                            printf("El Jugador %s sera el Color Negro.\n", s2);
                                            strcpy(color2, "Negras");
                                            cambio (color2, 20);
                                            creacolor2(color2);

                                            }


                                        }

                                    printf("\n\n¿PREPARADOS? VA A EMPEZAR LA PARTIDA, %s VS %s\n", s1, s2);
                                    printf("\t(Pulse una tecla para empezar)");
                                    getch();
                                    system("cls");
                                    mainchess1();
                                    mainchess2();

                                    aux = victoria();

                                    if(aux == 1){
                                      printf("\tEl ganador es:");
                                      ganador1();
                                    }

                                    if(aux == 2){
                                      printf("\tEl ganador es:");
                                      ganador2();
                                    }

                                    printf("\n\n\t(Pulse una tecla para continuar al menu principal)");
                                    getch();
                                    menuPrincipal();

                                break;



                                case 2:
                                    system("cls");
                                    goto menuTorneo;
                                    free(s1);
                                    free(s2);
                                    free(s3);
                                    free(s4);
                                    free(s5);
                                    free(s6);
                                    free(s7);
                                    free(s8);
                                    free(torneo);
                                    free(color1);
                                    free(color2);
                                    free(i);
                                    free(j);
                                    free(jugartorneo);
                                    free(jugar);
                                    free(color);
                                    free(x);
                                    free(aux);
                                    free(num_aletorio);
                                    free(min);
                                    free(fstop);
                                    free(numeros[20]);
                                    free(players);

                                break;
                            }

                    break; //case 1, jugartorneo.

            }//Cierre Switch Jugartorneo.
}




char tablero[8][8]={     't','c','a','m','r','a','c','t',
                        'p','p','p','p','p','p','p','p',
                        '\0','\0','\0','\0','\0','\0','\0','\0',
                        '\0','\0','\0','\0','\0','\0','\0','\0',
                        '\0','\0','\0','\0','\0','\0','\0','\0',
                        '\0','\0','\0','\0','\0','\0','\0','\0',
                        'P','P','P','P','P','P','P','P',
                        'T','C','A','M','R','A','C','R'      };


void tabla()//esto se bugea
{   struct COORDENADAS pos;
    printf("\n");
    printf("   0 1 2 3 4 5 6 7\n");
    for(pos.fila=0;pos.fila<8;++pos.fila)
    {   printf("%d ",pos.fila);
        for(pos.col=0;pos.col<8;++pos.col)
            printf("%-2c",tablero[pos.fila][pos.col]);
        printf("\n");

    }
return tablero[8][8];


}




int mov_valido2(struct COORDENADAS Curr,struct COORDENADAS New)
{
    char unidad,newunidad;
    int color,fila,col,i,j;

    unidad=tablero[Curr.fila][Curr.col];
    newunidad=tablero[New.fila][New.col];

    if(isalpha(newunidad))
            color=islower(newunidad);
    else
            color=-1;

    if(unidad=='T')
    {   if(New.fila==Curr.fila-1&&New.col==Curr.col&&color!=0)
            return 1;
        else if(New.fila==Curr.fila-1&&New.col==Curr.col-1&&color!=0)
            return 1;
        else if(New.fila==Curr.fila&&New.col==Curr.col-1&&color!=0)
            return 1;
        else if(New.fila==Curr.fila+1&&New.col==Curr.col-1&&color!=0)
            return 1;
        else if(New.fila==Curr.fila+1&&New.col==Curr.col&&color!=0)
            return 1;
        else if(New.fila==Curr.fila+1&&New.col==Curr.col+1&&color!=0)
            return 1;
        else if(New.fila==Curr.fila&&New.col==Curr.col+1&&color!=0)
            return 1;
        else if(New.fila==Curr.fila-1&&New.col==Curr.col+1&&color!=0)
            return 1;
        else
            return 0;
    }

    else if(unidad=='t')
    {   if(New.fila==Curr.fila-1&&New.col==Curr.col&&color<=0)
            return 1;
        else if(New.fila==Curr.fila-1&&New.col==Curr.col-1&&color<=0)
            return 1;
        else if(New.fila==Curr.fila&&New.col==Curr.col-1&&color<=0)
            return 1;
        else if(New.fila==Curr.fila+1&&New.col==Curr.col-1&&color<=0)
            return 1;
        else if(New.fila==Curr.fila+1&&New.col==Curr.col&&color<=0)
            return 1;
        else if(New.fila==Curr.fila+1&&New.col==Curr.col+1&&color<=0)
            return 1;
        else if(New.fila==Curr.fila&&New.col==Curr.col+1&&color<=0)
            return 1;
        else if(New.fila==Curr.fila-1&&New.col==Curr.col+1&&color<=0)
            return 1;
        else
            return 0;
    }

    else if(unidad=='M')
    {  tablero[Curr.fila][Curr.col]='T';
       i=mov_valido2(Curr,New);

       tablero[Curr.fila][Curr.col]='A';
       j=mov_valido2(Curr,New);

       tablero[Curr.fila][Curr.col]='M';

       return i+j;
    }

    else if(unidad=='m')
    {  tablero[Curr.fila][Curr.col]='t';
       i=mov_valido2(Curr,New);

       tablero[Curr.fila][Curr.col]='a';
       j=mov_valido2(Curr,New);

       tablero[Curr.fila][Curr.col]='m';

       return i+j;
    }

    else if(unidad=='P')
    {

            if(New.fila==Curr.fila-1&&New.col==Curr.col+1)
                    if(color>0)
                            return 1;
                    else
                            return 0;
            else if(New.fila==Curr.fila-1&&New.col==Curr.col-1)
                    if(color>0)
                            return 1;
                    else
                            return 0;
            else if(New.fila==Curr.fila-1&&New.col==Curr.col)
                    if(color<0)
                        return 1;
                    else
                        return 0;
            else if(New.fila==Curr.fila-2&&New.col==Curr.col&&Curr.fila==6)
                    if(color<0&&tablero[New.fila+1][New.col]=='\0')
                        return 1;
                    else
                        return 0;
            else
                        return 0;

    }



    else if(unidad=='p')
    {

            if(New.fila==Curr.fila+1&&New.col==Curr.col+1)
                    if(color==0)
                            return 1;
                    else
                            return 0;
            else if(New.fila==Curr.fila+1&&New.col==Curr.col-1)
                    if(color==0)
                            return 1;
                    else
                            return 0;
            else if(New.fila==Curr.fila+1&&New.col==Curr.col)
                    if(color<0)
                        return 1;
                    else
                        return 0;
            else if(New.fila==Curr.fila+2&&New.col==Curr.col&&Curr.fila==1)
                    if(color<0&&tablero[New.fila-1][New.col]=='\0')
                        return 1;
                    else
                        return 0;
            else
                        return 0;

    }




    else if(unidad=='T')
    {
            if(New.col==Curr.col)
            {   if(New.fila<Curr.fila)
                {   for(fila=Curr.fila-1;fila>New.fila;--fila)
                        if(tablero[fila][Curr.col]!='\0')
                                return 0;
                    if(color>0||color<0)
                        return 1;
                    else
                        return 0;
                }
                else if(New.fila>Curr.fila)
                {   for(fila=Curr.fila+1;fila<New.fila;++fila)
                        if(tablero[fila][Curr.col]!='\0')
                                return 0;
                    if(color>0||color<0)
                        return 1;
                    else
                        return 0;
                }
                else
                    return 0;
            }
            else if(New.fila==Curr.fila)
            {   if(New.col<Curr.col)
                {   for(col=Curr.col-1;col>New.col;--col)
                        if(tablero[Curr.fila][col]!='\0')
                                return 0;
                    if(color>0||color<0)
                        return 1;
                    else
                        return 0;
                }
                else if(New.col>Curr.col)
                {   for(col=Curr.col+1;col<New.col;++col)
                        if(tablero[Curr.fila][col]!='\0')
                                return 0;
                    if(color>0||color<0)
                        return 1;
                    else
                        return 0;
                }
                else
                    return 0;
            }
            else
                return 0;

    }




    else if(unidad=='t')
    {
            if(New.col==Curr.col)
            {   if(New.fila<Curr.fila)
                {   for(fila=Curr.fila-1;fila>New.fila;--fila)
                        if(tablero[fila][Curr.col]!='\0')
                                return 0;
                    if(color==0||color<0)
                        return 1;
                    else
                        return 0;
                }
                else if(New.fila>Curr.fila)
                {   for(fila=Curr.fila+1;fila<New.fila;++fila)
                        if(tablero[fila][Curr.col]!='\0')
                                return 0;
                    if(color==0||color<0)
                        return 1;
                    else
                        return 0;
                }
                else
                    return 0;
            }
            else if(New.fila==Curr.fila)
            {   if(New.col<Curr.col)
                {   for(col=Curr.col-1;col>New.col;--col)
                        if(tablero[Curr.fila][col]!='\0')
                                return 0;
                    if(color==0||color<0)
                        return 1;
                    else
                        return 0;
                }
                else if(New.col>Curr.col)
                {   for(col=Curr.col+1;col<New.col;++col)
                        if(tablero[Curr.fila][col]!='\0')
                                return 0;
                    if(color==0||color<0)
                        return 1;
                    else
                        return 0;
                }
                else
                    return 0;
            }
            else
                return 0;

    }





    else if(unidad=='C')
    {
        if((New.fila==Curr.fila-2)&&(New.col==Curr.col+1)&&color!=0)
                return 1;
        else if((New.fila==Curr.fila-2)&&(New.col==Curr.col-1)&&color!=0)
                return 1;
        else if((New.fila==Curr.fila-1)&&(New.col==Curr.col-2)&&color!=0)
                return 1;
        else if((New.fila==Curr.fila+1)&&(New.col==Curr.col-2)&&color!=0)
                return 1;
        else if((New.fila==Curr.fila+2)&&(New.col==Curr.col-1)&&color!=0)
                return 1;
        else if((New.fila==Curr.fila+2)&&(New.col==Curr.col+1)&&color!=0)
                return 1;
        else if((New.fila==Curr.fila+1)&&(New.col==Curr.col+2)&&color!=0)
                return 1;
        else if((New.fila==Curr.fila-1)&&(New.col==Curr.col+2)&&color!=0)
                return 1;
        else
                return 0;

    }



    else if(unidad=='c')
    {
        if((New.fila==Curr.fila-2)&&(New.col==Curr.col+1)&&color<=0)
                return 1;
        else if((New.fila==Curr.fila-2)&&(New.col==Curr.col-1)&&color<=0)
                return 1;
        else if((New.fila==Curr.fila-1)&&(New.col==Curr.col-2)&&color<=0)
                return 1;
        else if((New.fila==Curr.fila+1)&&(New.col==Curr.col-2)&&color<=0)
                return 1;
        else if((New.fila==Curr.fila+2)&&(New.col==Curr.col-1)&&color<=0)
                return 1;
        else if((New.fila==Curr.fila+2)&&(New.col==Curr.col+1)&&color<=0)
                return 1;
        else if((New.fila==Curr.fila+1)&&(New.col==Curr.col+2)&&color<=0)
                return 1;
        else if((New.fila==Curr.fila-1)&&(New.col==Curr.col+2)&&color<=0)
                return 1;
        else
                return 0;

    }



   else if(unidad=='A')
   {

        if(Curr.fila-New.fila==New.col-Curr.col)
        {
            if(New.col>Curr.col)
            {   for(fila=Curr.fila-1,col=Curr.col+1;fila>New.fila;--fila,++col)
                        if(tablero[fila][col]=='\0')
                                continue;
                        else
                                return 0;
                if(color!=0)
                        return 1;
                else
                        return 0;

            }
            else if(New.col<Curr.col)
            {   for(fila=Curr.fila+1,col=Curr.col-1;fila<New.fila;++fila,--col)
                        if(tablero[fila][col]=='\0')
                                continue;
                        else
                                return 0;
                if(color!=0)
                        return 1;
                else
                        return 0;

            }
            else
                return 0;
        }
        else if(Curr.fila-New.fila==Curr.col-New.col)
        {
            if(New.col>Curr.col)
            {   for(fila=Curr.fila+1,col=Curr.col+1;fila<New.fila;++fila,++col)
                        if(tablero[fila][col]=='\0')
                                continue;
                        else
                                return 0;
                if(color!=0)
                        return 1;
                else
                        return 0;

            }
            else if(New.col<Curr.col)
            {   for(fila=Curr.fila-1,col=Curr.col-1;fila>New.fila;--fila,--col)
                        if(tablero[fila][col]=='\0')
                                continue;
                        else
                                return 0;
                if(color!=0)
                        return 1;
                else
                        return 0;

            }
            else
                return 0;
        }
        else
            return 0;
   }



   else if(unidad=='a')
   {

        if(Curr.fila-New.fila==New.col-Curr.col)
        {
            if(New.col>Curr.col)
            {   for(fila=Curr.fila-1,col=Curr.col+1;fila>New.fila;--fila,++col)
                        if(tablero[fila][col]=='\0')
                                continue;
                        else
                                return 0;
                if(color<=0)
                        return 1;
                else
                        return 0;

            }
            else if(New.col<Curr.col)
            {   for(fila=Curr.fila+1,col=Curr.col-1;fila<New.fila;++fila,--col)
                        if(tablero[fila][col]=='\0')
                                continue;
                        else
                                return 0;
                if(color<=0)
                        return 1;
                else
                        return 0;

            }
            else
                return 0;
        }
        else if(Curr.fila-New.fila==Curr.col-New.col)
        {
            if(New.col>Curr.col)
            {   for(fila=Curr.fila+1,col=Curr.col+1;fila<New.fila;++fila,++col)
                        if(tablero[fila][col]=='\0')
                                continue;
                        else
                                return 0;
                if(color<=0)
                        return 1;
                else
                        return 0;

            }
            else if(New.col<Curr.col)
            {   for(fila=Curr.fila-1,col=Curr.col-1;fila>New.fila;--fila,--col)
                        if(tablero[fila][col]=='\0')
                                continue;
                        else
                                return 0;
                if(color<=0)
                        return 1;
                else
                        return 0;

            }
            else
                return 0;
        }
        else
            return 0;
   }

   else
        return 0;



}

int mov_valido(struct COORDENADAS Curr,struct COORDENADAS New)
{

    int s;
    char unidad,newunidad;
    struct COORDENADAS pos;

    unidad=tablero[Curr.fila][Curr.col];
    newunidad=tablero[New.fila][New.col];

    s=mov_valido2(Curr,New);

    if(s==0)
        return 0;
    else if(s==1)
    {
        if(islower(unidad)==0)
        {   tablero[New.fila][New.col]=unidad;
            tablero[Curr.fila][Curr.col]='\0';
            for(pos.fila=0;pos.fila<8;++pos.fila)
                for(pos.col=0;pos.col<8;++pos.col)
                    if(rb_enjake2(pos))
                    {   tablero[New.fila][New.col]=newunidad;
                        tablero[Curr.fila][Curr.col]=unidad;
                        return 0;
                    }
             tablero[New.fila][New.col]=newunidad;
             tablero[Curr.fila][Curr.col]=unidad;
             return 1;
        }
        else if(islower(unidad)>0)
        {   tablero[New.fila][New.col]=unidad;
            tablero[Curr.fila][Curr.col]='\0';
            for(pos.fila=0;pos.fila<8;++pos.fila)
                for(pos.col=0;pos.col<8;++pos.col)
                    if(rn_enjake2(pos))
                    {   tablero[New.fila][New.col]=newunidad;
                        tablero[Curr.fila][Curr.col]=unidad;
                        return 0;
                    }
             tablero[New.fila][New.col]=newunidad;
             tablero[Curr.fila][Curr.col]=unidad;
             return 1;
        }


    }


}


int b_total_mov_validos()
{
    int num_mov_validos=0;
    struct COORDENADAS Curr,New;

    for(Curr.fila=0;Curr.fila<8;++Curr.fila)
        for(Curr.col=0;Curr.col<8;++Curr.col)

            if(isupper(tablero[Curr.fila][Curr.col])>0)

                for(New.fila=0;New.fila<8;++New.fila)
                    for(New.col=0;New.col<8;++New.col)

                        if(mov_valido(Curr,New))
                            ++num_mov_validos;



    return num_mov_validos;
}



int n_total_mov_validos()
{
    int num_mov_validos=0;
    struct COORDENADAS Curr,New;

    for(Curr.fila=0;Curr.fila<8;++Curr.fila)
        for(Curr.col=0;Curr.col<8;++Curr.col)

            if(isupper(tablero[Curr.fila][Curr.col])>0)

                for(New.fila=0;New.fila<8;++New.fila)
                    for(New.col=0;New.col<8;++New.col)

                        if(mov_valido(Curr,New))
                            ++num_mov_validos;



    return num_mov_validos;
}


void b_jakemate()
{
    if(rb_enjake()==1&&b_total_mov_validos()==0)
    {       printf("\nJake mate, ganan negras\n");
            exit(0);
    }

}

void n_jakemate()
{
    if((rn_enjake()==1)&&(n_total_mov_validos()==0))
    {       printf("\nJake mate, ganan blancas\n");
            exit(0);
    }

}

void b_jake()
{
    if(rb_enjake()==1&&b_total_mov_validos()>0)
            printf("\nJake\n");

}

void n_jake()
{
    if(rn_enjake()==1&&n_total_mov_validos()>0)
            printf("\nIt's Check\n");

}

void b_reyaogado()
{
    if(rb_enjake()==0&&b_total_mov_validos()==0)
    {   printf("\nEmpate, rey aogado\n");
        exit(0);
    }

}


void n_reyaogado()
{
    if(rn_enjake()==0&&b_total_mov_validos()==0)
    {   printf("\nEmpate, rey aogado\n");
        exit(0);
    }

}

int rn_enjake2(struct COORDENADAS Curr)
{

    int i,j,fila,col;
    char unidad;
    struct COORDENADAS rnpos;

    for(i=0;i<8;++i)
        for(j=0;j<8;++j)
            if(tablero[i][j]=='r')
                    goto out;
    out:
    rnpos.fila=i;
    rnpos.col=j;

    unidad=tablero[Curr.fila][Curr.col];

    if(unidad=='R')
    {   if(rnpos.fila==Curr.fila-1&&rnpos.col==Curr.col)
            return 1;
        else if(rnpos.fila==Curr.fila-1&&rnpos.col==Curr.col-1)
            return 1;
        else if(rnpos.fila==Curr.fila&&rnpos.col==Curr.col-1)
            return 1;
        else if(rnpos.fila==Curr.fila+1&&rnpos.col==Curr.col-1)
            return 1;
        else if(rnpos.fila==Curr.fila+1&&rnpos.col==Curr.col)
            return 1;
        else if(rnpos.fila==Curr.fila+1&&rnpos.col==Curr.col+1)
            return 1;
        else if(rnpos.fila==Curr.fila&&rnpos.col==Curr.col+1)
            return 1;
        else if(rnpos.fila==Curr.fila-1&&rnpos.col==Curr.col+1)
            return 1;
        else
            return 0;
    }

    else if(unidad=='M')
    {   tablero[Curr.fila][Curr.col]='T';
        i=rn_enjake2(Curr);

        tablero[Curr.fila][Curr.col]='A';
        j=rn_enjake2(Curr);

        tablero[Curr.fila][Curr.col]='M';

        return i+j;
    }

    else if(unidad=='P')
    {
        if(rnpos.fila==Curr.fila-1&&rnpos.col==Curr.col+1)
                return 1;
        else if(rnpos.fila==Curr.fila-1&&rnpos.col==Curr.col-1)
                return 1;
        else
                return 0;
    }

    else if(unidad=='T')
    {
            if(rnpos.col==Curr.col)
            {   if(rnpos.fila<Curr.fila)
                {   for(fila=Curr.fila-1;fila>rnpos.fila;--fila)
                        if(tablero[fila][Curr.col]=='\0')
                                continue;
                        else
                                return 0;
                    return 1;
                }
                else if(rnpos.fila>Curr.fila)
                {   for(fila=Curr.fila+1;fila<rnpos.fila;++fila)
                        if(tablero[fila][Curr.col]=='\0')
                                continue;
                        else
                                return 0;
                    return 1;
                }

            }
            else if(rnpos.fila==Curr.fila)
            {   if(rnpos.col<Curr.col)
                {   for(col=Curr.col-1;col>rnpos.col;--col)
                        if(tablero[Curr.fila][col]=='\0')
                                continue;
                        else
                                return 0;
                    return 1;
                }
                else if(rnpos.col>Curr.col)
                {   for(col=Curr.col+1;col<rnpos.col;++col)
                        if(tablero[Curr.fila][col]=='\0')
                                continue;
                        else
                                return 0;
                    return 1;
                }

            }
            else
                return 0;

    }

    else if(unidad=='C')
    {
        if((rnpos.fila==Curr.fila-2)&&(rnpos.col==Curr.col+1))
                return 1;
        else if((rnpos.fila==Curr.fila-2)&&(rnpos.col==Curr.col-1))
                return 1;
        else if((rnpos.fila==Curr.fila-1)&&(rnpos.col==Curr.col-2))
                return 1;
        else if((rnpos.fila==Curr.fila+1)&&(rnpos.col==Curr.col-2))
                return 1;
        else if((rnpos.fila==Curr.fila+2)&&(rnpos.col==Curr.col-1))
                return 1;
        else if((rnpos.fila==Curr.fila+2)&&(rnpos.col==Curr.col+1))
                return 1;
        else if((rnpos.fila==Curr.fila+1)&&(rnpos.col==Curr.col+2))
                return 1;
        else if((rnpos.fila==Curr.fila-1)&&(rnpos.col==Curr.col+2))
                return 1;
        else
                return 0;

    }


    else if(unidad=='A')
    {

        if(Curr.fila-rnpos.fila==rnpos.col-Curr.col)
        {
            if(rnpos.col>Curr.col)
            {   for(fila=Curr.fila-1,col=Curr.col+1;fila>rnpos.fila;--fila,++col)
                        if(tablero[fila][col]=='\0')
                                continue;
                        else
                                return 0;
                return 1;

            }
            else if(rnpos.col<Curr.col)
            {   for(fila=Curr.fila+1,col=Curr.col-1;fila<rnpos.fila;++fila,--col)
                        if(tablero[fila][col]=='\0')
                                continue;
                        else
                                return 0;
                return 1;

            }

        }
        else if(Curr.fila-rnpos.fila==Curr.col-rnpos.col)
        {
            if(rnpos.col>Curr.col)
            {   for(fila=Curr.fila+1,col=Curr.col+1;fila<rnpos.fila;++fila,++col)
                        if(tablero[fila][col]=='\0')
                                continue;
                        else
                                return 0;
                return 1;

            }
            else if(rnpos.col<Curr.col)
            {   for(fila=Curr.fila-1,col=Curr.col-1;fila>rnpos.fila;--fila,--col)
                        if(tablero[fila][col]=='\0')
                                continue;
                        else
                                return 0;
                return 1;

            }

        }
        else
            return 0;
    }

    else
        return 0;


}


int rb_enjake2(struct COORDENADAS Curr)
{

    int i,j,fila,col;
    char unidad;
    struct COORDENADAS rbpos;

    for(i=0;i<8;++i)
        for(j=0;j<8;++j)
            if(tablero[i][j]=='R')
                    goto out2;
    out2:
    rbpos.fila=i;
    rbpos.col=j;

    unidad=tablero[Curr.fila][Curr.col];
    //////////////////////////////////////////////////////////
    if(unidad=='r')
    {   if(rbpos.fila==Curr.fila-1&&rbpos.col==Curr.col)
            return 1;
        else if(rbpos.fila==Curr.fila-1&&rbpos.col==Curr.col-1)
            return 1;
        else if(rbpos.fila==Curr.fila&&rbpos.col==Curr.col-1)
            return 1;
        else if(rbpos.fila==Curr.fila+1&&rbpos.col==Curr.col-1)
            return 1;
        else if(rbpos.fila==Curr.fila+1&&rbpos.col==Curr.col)
            return 1;
        else if(rbpos.fila==Curr.fila+1&&rbpos.col==Curr.col+1)
            return 1;
        else if(rbpos.fila==Curr.fila&&rbpos.col==Curr.col+1)
            return 1;
        else if(rbpos.fila==Curr.fila-1&&rbpos.col==Curr.col+1)
            return 1;
        else
            return 0;
    }

    else if(unidad=='m')
    {   tablero[Curr.fila][Curr.col]='t';
        i=rb_enjake2(Curr);

        tablero[Curr.fila][Curr.col]='a';
        j=rb_enjake2(Curr);

        tablero[Curr.fila][Curr.col]='m';

        return i+j;
    }

    else if(unidad=='p')
    {
        if(rbpos.fila==Curr.fila+1&&rbpos.col==Curr.col+1)
                return 1;
        else if(rbpos.fila==Curr.fila+1&&rbpos.col==Curr.col-1)
                return 1;
        else
                return 0;
    }

    else if(unidad=='t')
    {
            if(rbpos.col==Curr.col)
            {   if(rbpos.fila<Curr.fila)
                {   for(fila=Curr.fila-1;fila>rbpos.fila;--fila)
                        if(tablero[fila][Curr.col]=='\0')
                                continue;
                        else
                                return 0;
                    return 1;
                }
                else if(rbpos.fila>Curr.fila)
                {   for(fila=Curr.fila+1;fila<rbpos.fila;++fila)
                        if(tablero[fila][Curr.col]=='\0')
                                continue;
                        else
                                return 0;
                    return 1;
                }

            }
            else if(rbpos.fila==Curr.fila)
            {   if(rbpos.col<Curr.col)
                {   for(col=Curr.col-1;col>rbpos.col;--col)
                        if(tablero[Curr.fila][col]=='\0')
                                continue;
                        else
                                return 0;
                    return 1;
                }
                else if(rbpos.col>Curr.col)
                {   for(col=Curr.col+1;col<rbpos.col;++col)
                        if(tablero[Curr.fila][col]=='\0')
                                continue;
                        else
                                return 0;
                    return 1;
                }

            }
            else
                return 0;

    }

    else if(unidad=='c')
    {
        if((rbpos.fila==Curr.fila-2)&&(rbpos.col==Curr.col+1))
                return 1;
        else if((rbpos.fila==Curr.fila-2)&&(rbpos.col==Curr.col-1))
                return 1;
        else if((rbpos.fila==Curr.fila-1)&&(rbpos.col==Curr.col-2))
                return 1;
        else if((rbpos.fila==Curr.fila+1)&&(rbpos.col==Curr.col-2))
                return 1;
        else if((rbpos.fila==Curr.fila+2)&&(rbpos.col==Curr.col-1))
                return 1;
        else if((rbpos.fila==Curr.fila+2)&&(rbpos.col==Curr.col+1))
                return 1;
        else if((rbpos.fila==Curr.fila+1)&&(rbpos.col==Curr.col+2))
                return 1;
        else if((rbpos.fila==Curr.fila-1)&&(rbpos.col==Curr.col+2))
                return 1;
        else
                return 0;

    }


    else if(unidad=='a')
    {

        if(Curr.fila-rbpos.fila==rbpos.col-Curr.col)
        {
            if(rbpos.col>Curr.col)
            {   for(fila=Curr.fila-1,col=Curr.col+1;fila>rbpos.fila;--fila,++col)
                        if(tablero[fila][col]=='\0')
                                continue;
                        else
                                return 0;
                return 1;

            }
            else if(rbpos.col<Curr.col)
            {   for(fila=Curr.fila+1,col=Curr.col-1;fila<rbpos.fila;++fila,--col)
                        if(tablero[fila][col]=='\0')
                                continue;
                        else
                                return 0;
                return 1;

            }

        }
        else if(Curr.fila-rbpos.fila==Curr.col-rbpos.col)
        {
            if(rbpos.col>Curr.col)
            {   for(fila=Curr.fila+1,col=Curr.col+1;fila<rbpos.fila;++fila,++col)
                        if(tablero[fila][col]=='\0')
                                continue;
                        else
                                return 0;
                return 1;

            }
            else if(rbpos.col<Curr.col)
            {   for(fila=Curr.fila-1,col=Curr.col-1;fila>rbpos.fila;--fila,--col)
                        if(tablero[fila][col]=='\0')
                                continue;
                        else
                                return 0;
                return 1;

            }

        }
        else
            return 0;
    }

    else
        return 0;


}



int rb_enjake()
{   struct COORDENADAS pos;

    for(pos.fila=0;pos.fila<8;++pos.fila)
                for(pos.col=0;pos.col<8;++pos.col)
                    if(rb_enjake2(pos))
                        return 1;
    return 0;
}



int rn_enjake()
{   struct COORDENADAS pos;

    for(pos.fila=0;pos.fila<8;++pos.fila)
                for(pos.col=0;pos.col<8;++pos.col)
                    if(rn_enjake2(pos))
                        return 1;
    return 0;
}





void b_promocion()
{   int i=0,j;
    char unidad;
    for(j=0;j<8;++j)
        if(tablero[i][j]=='P')
           while(1)
            {    printf("\nPromociona tu pero a:(M T A C) ");fflush(stdin);
                 scanf("%c",&unidad);
                 switch(unidad)
                 {   case 'M': tablero[i][j]='M';
                               return;
                     case 'T': tablero[i][j]='T';
                               return;
                     case 'A': tablero[i][j]='A';
                               return;
                     case 'C': tablero[i][j]='C';
                               return;
                     default : printf("no valido intenta de nuevo");
                 }

            }


}




void n_promocion()
{   int i=7,j;
    char unidad;
    for(j=0;j<8;++j)
        if(tablero[i][j]=='p')
           while(1)
            {    printf("\nPromociona tu peon a:(m t a c) ");fflush(stdin);
                 scanf("%c",&unidad);
                 switch(unidad)
                 {   case 'm': tablero[i][j]='m';
                               return;
                     case 't': tablero[i][j]='t';
                               return;
                     case 'a': tablero[i][j]='a';
                               return;
                     case 'c': tablero[i][j]='c';
                               return;
                     default : printf("no valido intenta de nuevo");
                 }

            }


}

void delay(double sec)
{
    clock_t start = clock();

    while ((clock() - start) / CLOCKS_PER_SEC < sec)
        ;
}
