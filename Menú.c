//Menú de Inicio.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct{
    char nombre[20];
    int num;
} jugador;

void cambio (char palabra[], int n);
int buscarNumero(int numero, int vector[], int n);

int main(){
    jugador player1;
    jugador player2;

    int seleccion, modalidad, dificultad, color, x, guardada, torneo, i, j, y, continuar, ayuda, piezas, escape, reglas, acabar, jugartorneo, jugar, aux2;
    int min = 1, aux = 0, fstop;
    int num_aletorio, numeros[20] = {0};

    menuPrincipal:
    do{
    printf("Bienvenido al AJEDREZ!\nElija una de las opciones siguientes:\n\n");
    printf("\t1. Nueva Partida\n\t2. Cargar Partida Anterior\n\t3. Modo Torneo\n\t4. Instrucciones de Juego\n\t5. Ranking\n\t6. Salir del Juego\n");
    scanf("%i", &seleccion);
    }

    while (seleccion != 1 && seleccion != 2 && seleccion != 3 && seleccion != 4 && seleccion != 5 && seleccion != 6);

        switch(seleccion){
            case 1:
                menuNuevaPartida:
                do{
                printf("\nElija un modo de juego:\n\n");
                printf("\t1. Contrarreloj (Tiempo Cronometrado)\n\t2. Normal\n\t3. Salir\n");
                scanf("%i", &modalidad);
                fflush(stdin);
                }
                while (modalidad !=  1 && modalidad != 2 && modalidad != 3);
                //(modalidad <=  1 && modalidad >= 2 && modalidad != 3);

                    switch (modalidad){
                        case 1:
                            do{
                            printf("\nElija la Dificultad del Modo:\n");
                            printf("\t1. Principiante (15 minutos)\n\t2. Normal (10 minutos)\n\t3. Experto (5 minutos)\n\t4. Salir\n");
                            scanf("%i", &dificultad);
                            fflush(stdin);
                            }
                            while (dificultad != 1 && dificultad != 2 && dificultad != 3 && dificultad != 4);

                                 switch (dificultad){
                                      case 1:
                                        printf("\nHa seleccionado el NIVEL PRINCIPIANTE.\n\nPor favor, ingrese el nombre del Jugador 1:\t");
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

                                      break; //case 1, dificultad.


                                      case 2:
                                        printf("\nHa seleccionado el NIVEL INTERMEDIO.\n\nPor favor, ingrese el nombre del Jugador 1:\t");
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

                                      break; //case 2, dificultad.


                                      case 3:
                                        printf("\nHa seleccionado el NIVEL AVANZADO.\n\nPor favor, ingrese el nombre del Jugador 1:\t");
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

                                      break; //case 3, dificultad.

                                      case 4:
                                        system("cls");
                                        goto menuNuevaPartida;
                                      break;

                                    }//fin dificultad.

                        break; //case 1, modalidad.

                        case 2:
                            printf("\nHa seleccionado la modalidad de juego NORMAL. Aqui no habra tiempo de partida.\n\nPor favor, ingrese el nombre del Jugador 1:\t");
                            fgets(player1.nombre, 20, stdin);
                            cambio (player1.nombre, 20);
                            fflush(stdin);

                            printf("Ingrese el nombre del Jugador 2:\t");
                            fgets(player2.nombre, 20, stdin);
                            cambio (player2.nombre, 20);
                            fflush(stdin);

                            do{
                            printf("\nIntroduzca el color deseado por %s:\n", player1);
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

                        break; //case 2, modalidad.

                        case 3:
                            system("cls");
                            goto menuPrincipal;
                        break;
                    } //cierre switch modalidad.

             break; //case 1, selección.

             case 2:
                do{
                printf("\nElija una de la partidas a continuar:\n\n");
                printf("\t1. Datos 1 (a la espera de ver tema Ficheros)\n\t2. Datos 2 (a la espera de ver tema Ficheros)\n\t3. Datos 3 (a la espera de ver tema Ficheros)\n\t4. Salir\n");
                scanf("%i", &guardada);
                fflush(stdin);
                }
                while (guardada != 1 && guardada != 2 && guardada != 3 && guardada != 4);

                switch (guardada){
                    case 4:
                    system("cls");
                    goto menuPrincipal;
                    break;

                    }
             break; //case 2, selección.

             case 3:
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
                        jugador players[torneo];
                        }
                        while (torneo != 4 && torneo != 8);

                        //aux2 == torneo;
                        //jugador players[aux2];
                        //jugador players[torneo];
                        printf("\n");

                        for (i = 0; i < torneo; i++){
                        printf("Introduzca el Nombre del Jugador %d:\t", i + 1);
                        jugador players[torneo];
                        scanf("%s", players[i].nombre);
                        aux = aux + 1;
                        players[i].num = aux;
                        }

                        printf("\n\n");

                        srand(time(NULL));

                        for(i = 0; i < torneo; i++){
                            do{
                            num_aletorio = min + rand()% (torneo - min + 1);
                            fstop = buscarNumero (num_aletorio, numeros, torneo);
                            }
                            while(fstop);

                        numeros[i] = num_aletorio;
                        }


                        if (torneo == 4){

                        printf("Los emparejamientos seran los siguientes:\n\tSemifinal 1:");

                        for (i = 0; i < torneo - 3; i++){
                            for (j = 0; j < torneo; j++){
                                jugador players[torneo];
                                if (numeros [i] == players[j].num){
                                //jugador players[torneo];
                                printf(" %s", players[j].nombre);
                                fflush(stdin);
                                }
                            }
                        }

                        printf(" VS ");

                        for (i = 1; i < torneo - 2; i++){
                            for (j = 0; j < torneo; j++){
                                jugador players[torneo];
                                if (numeros [i] == players[j].num){
                                //jugador players[torneo];
                                printf("%s", players[j].nombre);
                                fflush(stdin);
                                }
                            }
                        }

                        printf("\n\tSemifinal 2:");

                        for (i = 2; i < torneo - 1; i++){
                            for (j = 0; j < torneo; j++){
                                jugador players[torneo];
                                if (numeros [i] == players[j].num){
                                //jugador players[torneo];
                                printf(" %s", players[j].nombre);
                                fflush(stdin);
                                }
                            }
                        }

                        printf(" VS ");

                        for (i = 3; i < torneo; i++){
                            for (j = 0; j < torneo; j++){
                                jugador players[torneo];
                                if (numeros [i] == players[j].num){
                                //jugador players[torneo];
                                printf("%s", players[j].nombre);
                                fflush(stdin);
                                }
                            }
                        }

                        }//Cierre if (torneo == 4)


                        if (torneo == 8){

                        printf("Los emparejamientos seran los siguientes:\n\tCuartos de Final 1:");
                        for (i = 0; i < torneo - 7; i++){
                            for (j = 0; j < torneo; j++){
                                jugador players[torneo];
                                if (numeros [i] == players[j].num){
                                //jugador players[torneo];
                                printf(" %s", players[j].nombre);
                                fflush(stdin);
                                }
                            }
                        }

                        printf(" VS ");

                        for (i = 1; i < torneo - 6; i++){
                            for (j = 0; j < torneo; j++){
                                jugador players[torneo];
                                if (numeros [i] == players[j].num){
                                printf("%s", players[j].nombre);
                                fflush(stdin);
                                }
                            }
                        }

                        printf("\n\tCuartos de Final 2:");

                        for (i = 2; i < torneo - 5; i++){
                            for (j = 0; j < torneo; j++){
                                jugador players[torneo];
                                if (numeros [i] == players[j].num){
                                printf(" %s", players[j].nombre);
                                fflush(stdin);
                                }
                            }
                        }

                        printf(" VS ");

                        for (i = 3; i < torneo - 4; i++){
                            for (j = 0; j < torneo; j++){
                                jugador players[torneo];
                                if (numeros [i] == players[j].num){
                                printf("%s", players[j].nombre);
                                fflush(stdin);
                                }
                            }
                        }

                        printf("\n\tCuartos de Final 3:");

                        for (i = 4; i < torneo - 3; i++){
                            for (j = 0; j < torneo; j++){
                                jugador players[torneo];
                                if (numeros [i] == players[j].num){
                                printf(" %s", players[j].nombre);
                                fflush(stdin);
                                }
                            }
                        }

                        printf(" VS ");

                        for (i = 5; i < torneo - 2; i++){
                            for (j = 0; j < torneo; j++){
                                jugador players[torneo];
                                if (numeros [i] == players[j].num){
                                printf("%s", players[j].nombre);
                                fflush(stdin);
                                }
                            }
                        }

                        printf("\n\tCuartos de Final 4:");

                        for (i = 6; i < torneo - 1; i++){
                            for (j = 0; j < torneo; j++){
                                jugador players[torneo];
                                if (numeros [i] == players[j].num){
                                printf(" %s", players[j].nombre);
                                fflush(stdin);
                                }
                            }
                        }

                        printf(" VS ");

                        for (i = 7; i < torneo; i++){
                            for (j = 0; j < torneo; j++){
                                jugador players[torneo];
                                if (numeros [i] == players[j].num){
                                printf("%s", players[j].nombre);
                                fflush(stdin);
                                }
                            }
                        }

                        } //Cierre if (torneo == 8)

                        do{
                        printf("\n\nDesea continuar con el primer partido:\n\t1. Si\n\t2. Salir\n");
                        scanf("%d", &jugar);
                        }
                        while (jugar != 1 && jugar != 2);


                        switch (jugar){
                            case 1:
                                printf("\nConstruccion");
                            break;

                            case 2:
                                system("cls");
                                goto menuTorneo;
                            break;
                        }

                    break; //case 1, jugartorneo.

                    case 2:
                        system("cls");
                        goto menuPrincipal;
                    break;

                } //Cierre switch jugatorneo.

             break; //case 3, selección.

             case 4:
                menuAprendeaJugar:
                printf("\nEn esta seccion encontraras distintas ayudas para comprender mejor el Juego del Ajedrez.\n\n");
                do{
                printf("\t1. Configuracion del Tablero de Ajedrez\n\t2. Movimientos de las Piezas\n\t3. Reglas Especiales\n\t4. Quien Empieza a Jugar\n\t5. Ganar una Partida\n\t6. Salir\n");
                scanf("%d", &ayuda);
                }
                while (ayuda !=  1 && ayuda != 2 && ayuda != 3 && ayuda != 4 && ayuda != 5 && ayuda != 6);

                    switch (ayuda){
                        case 1:
                            printf("\nLa posicion inicial de las piezas es siempre la misma. La segunda fila se encuentra ocupada por 8 peones. Las torres ocupan las esquinas, y los dos caballos se situan a sus lados, seguidos por los alfiles. Al lado de estos, la reina (o dama) ocupa siempre la casilla de su propio color (la dama blanca en una casilla blanca; la negra, en una casilla negra). Por ultimo, el rey se situa al lado de la reina, en la casilla restante.\n");
                            printf("\t(Pulse una tecla para volver)");
                            getch();
                            system("cls");
                            goto menuAprendeaJugar;
                        break;

                        case 2:
                            menuMovimientoPiezas:
                            printf("\nHay 6 tipos de piezas y cada uno tiene su propia forma de moverse. Una pieza no puede moverse atravesando a otra (aunque el caballo si puede saltar sobre las demas) y nunca puede desplazarse a una casilla ocupada por otra pieza de su color. Sin embargo, las piezas pueden moverse a las casillas ocupadas por las piezas del adversario para capturarlas. De hecho, las piezas se mueven por el tablero para ocupar una casilla con uno de estos tres objetivos:\n\n");
                            printf("\t- Capturar una pieza rival (reemplazandola al ocupar la casilla en la que esta se encontraba).\n\t- Defender a las piezas de su propio bando para evitar que sean capturadas.\n\t- Controlar las casillas importantes del tablero");
                            do{
                            printf("\n\nMovimiento de cada una de las piezas del tablero:\n\t1. Rey\n\t2. Reina o Dama\n\t3. Torre\n\t4. Alfil\n\t5. Caballo\n\t6. Peon\n\t7. Salir\n");
                            scanf("%d", &piezas);
                            }
                            while (piezas !=  1 && piezas != 2 && piezas != 3 && piezas != 4 && piezas != 5 && piezas != 6 && piezas != 7);

                                switch (piezas){
                                    case 1:
                                        printf("\n\nEl rey es la pieza mas importante, pero tambien una de las mas debiles. El rey solo puede avanzar una casilla en cualquier direccion: hacia arriba, hacia abajo, hacia los lados o en diagonal. En ningun caso el rey puede moverse a una casilla en la que estaria en jaque, es decir, en la que pudiera ser capturado.\n");
                                        printf("\t(Pulse una tecla para volver)");
                                        getch();
                                        system("cls");
                                        goto menuMovimientoPiezas;
                                    break;

                                    case 2:
                                        printf("\n\nLa dama (reina) es la pieza mas poderosa. Puede moverse en cualquier direccion (hacia adelante, hacia atras, hacia los lados o en diagonal) y tantas casillas como se quiera; siempre y cuando no pase por encima de una pieza de su color.\n");
                                        printf("\t(Pulse una tecla para volver)");
                                        getch();
                                        system("cls");
                                        goto menuMovimientoPiezas;
                                    break;

                                    case 3:
                                        printf("\n\nLa torre puede moverse tantas casillas como quiera, pero solo hacia adelante, hacia atras o hacia los lados. Cuando trabajan juntas son muy poderosas.\n");
                                        printf("\t(Pulse una tecla para volver)");
                                        getch();
                                        system("cls");
                                        goto menuMovimientoPiezas;
                                    break;

                                    case 4:
                                        printf("\n\nEl alfil puede moverse tan lejos como quiera, pero siempre en diagonal. Cada alfil comienza en una casilla de un color (claro u oscuro) y debe permanecer toda la partida en ese color. Los dos alfiles trabajan bien juntos ya que uno cubre las debilidades y viceversa.\n");
                                        printf("\t(Pulse una tecla para volver)");
                                        getch();
                                        system("cls");
                                        goto menuMovimientoPiezas;
                                    break;

                                    case 5:
                                        printf("\n\nLos caballos se mueven de una manera muy diferente a la de las otras piezas: avanzan dos casillas en una direccion y luego una mas en un angulo de 90 grados, dibujando en su desplazamiento una letra 'L' sobre el tablero. Los caballos tambien son las unicas piezas que pueden saltar sobre otras.\n");
                                        printf("\t(Pulse una tecla para volver)");
                                        getch();
                                        system("cls");
                                        goto menuMovimientoPiezas;
                                    break;

                                    case 6:
                                        printf("\n\nLos peones tienen la particularidad de que se mueven y capturan de diferentes maneras: se mueven hacia adelante, pero capturan en diagonal. Los peones solo pueden avanzar una casilla en cada jugada, a excepcion de su primer movimiento en el que puedan avanzar dos casillas. Los peones solo pueden capturar una casilla situada en diagonal y frente a ellos. Nunca pueden retroceder, ni siquiera para capturar una pieza. Los peones no pueden moverse si en su camino encuentran una pieza que ocupe la casilla situada directamente frente a ellos y tampoco pueden capturarla.\n");
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
                            menuReglasEspeciales:
                            printf("\n\nHay unas reglas especiales de ajedrez que fueron creadas para hacer el juego mas divertido e interesante:\n");
                            do{
                            printf("\t1. Coronar un Peon\n\t2. Capturar al Paso (en passant)\n\t3. Enroque\n\t4. Salir\n");
                            scanf("%d", &reglas);
                            }
                            while (reglas !=  1 && reglas != 2 && reglas != 3 && reglas != 4);
                                switch (reglas){
                                    case 1:
                                        printf("\n\nLos peones tienen otra habilidad especial: si llegan al otro extremo del tablero pueden convertirse en cualquier otra pieza excepto en un rey.A esta jugada se le llama coronacion.\n");
                                        printf("\t(Pulse una tecla para volver)");
                                        getch();
                                        system("cls");
                                        goto menuReglasEspeciales;
                                    break;

                                    case 2:
                                        printf("\n\nLa ultima regla sobre los peones se llama captura en passant. Si un peon avanza dos casillas en su primer movimiento, y al hacerlo se situa al lado de un peon rival, este peon enemigo tiene la opcion de capturar al primero ocupando la casilla que aquel hubiera ocupado si solo hubiera avanzado una casilla. Esta jugada especial debe hacerse inmediatamente despues del movimiento del primer peon, de lo contrario la opcion de capturar ya no estara disponible.\n");
                                        printf("\t(Pulse una tecla para volver)");
                                        getch();
                                        system("cls");
                                        goto menuReglasEspeciales;
                                    break;

                                    case 3:
                                        printf("\n\nHay otra regla especial denominada enroque. Esta jugada te permite hacer dos cosas importantes en un solo movimiento: situar al rey en una posicion mas segura y sacar a la torre de su esquina para ponerla en juego. En un solo turno el jugador puede mover al rey dos casillas hacia un lado y, al mismo tiempo, la torre situada en la esquina de ese lado, se coloca junto al rey en la casilla ubicada en el lado opuesto. Sin embargo, para poder hacer un enroque se deben cumplir las siguientes condiciones:\n\t- Debe ser la primera jugada de aquel rey\n\t- Debe ser la primera jugada de aquella torre\n\t- No puede haber ninguna pieza entre el rey y la torre\n\t- El rey no puede estar en jaque ni pasar por una casilla amenazada\n");
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

                        case 4:
                            printf("\n\nEl jugador con las piezas blancas siempre es el primero en mover. Las blancas realizan la primera jugada, seguida del primer movimiento de las negras, despues mueven blancas de nuevo, y asi sucesiva y alternativamente hasta el final de la partida. El jugador que mueve primero tiene una pequeña ventaja porque puede llevar la iniciativa y atacar inmediatamente.\n");
                            printf("\t(Pulse una tecla para volver)");
                            getch();
                            system("cls");
                            goto menuAprendeaJugar;
                        break;

                        case 5:
                            menuComoGanar:
                            printf("\n\nHay varias formas de terminar una partida de ajedrez:\n");
                            do{
                            printf("\t1. Jaque Mate\n\t2. En Tablas o Empate\n\t3. Rendirse\n\t4. Perder por tiempo\n\t5. Salir\n");
                            scanf("%d", &acabar);
                            }
                            while (acabar != 1 && acabar != 2 && acabar != 3 && acabar != 4 && acabar != 5);
                                switch (acabar){
                                    case 1:
                                        printf("\n\nEl objetivo del juego es dar jaque mate al rey del adversario. Esto ocurre cuando el rey esta en jaque y no puede salir de esa situacion. Solo hay tres formas por las que un rey puede escapar de un jaque:\n\t- Moverse a una casilla segura.\n\t- Bloquear el jaque interponiendo otra pieza de su propio bando\n\t- Capturar la pieza que amenaza al rey\nSi un rey no puede escapar del jaque, la partida ha terminado.\n");
                                        printf("\t(Pulse una tecla para volver)");
                                        getch();
                                        system("cls");
                                        goto menuComoGanar;
                                    break;

                                    case 2:
                                        printf("\n\nA veces, las partidas de ajedrez terminan sin un ganador, pero en empate (denominado tablas). Hay 5 razones por las que una partida puede terminar en tablas:\n\t- La posición llega a un punto muerto en el que es el turno de un jugador, pero su rey no esta en jaque y, sin embargo, no puede hacer ningun movimiento reglamentario. Esto se conoce como 'ahogado'\n\t- Los jugadores pueden acordar Tablas y dejar de jugar\n\t- No hay suficientes piezas en el tablero para forzar un jaque mate (ejemplo: un Rey y un Alfil contra otro Rey)\n\t- Un jugador declara Tablas si la misma posicion se repite tres veces (no necesariamente tres veces seguidas)\n\t- Se han efectuado 50 movimientos y ninguno de los jugadores ha movido un peon ni capturado una pieza\n");
                                        printf("\t(Pulse una tecla para volver)");
                                        getch();
                                        system("cls");
                                        goto menuComoGanar;
                                    break;

                                    case 3:
                                        printf("\n\nUno de los dos jugadores decide rendirse y, por lo tanto, se declara un vencedor\n");
                                        printf("\t(Pulse una tecla para volver)");
                                        getch();
                                        system("cls");
                                        goto menuComoGanar;
                                    break;

                                    case 4:
                                        printf("\n\nSi el tiempo se acaba para alguno de los dos jugadores, inmediatamente el contrario es el vencedor de la partida\n");
                                        printf("\t(Pulse una tecla para volver)");
                                        getch();
                                        system("cls");
                                        goto menuComoGanar;
                                    break;

                                    case 5:
                                        system("cls");
                                        goto menuAprendeaJugar;
                                }//cierre switch acabar.

                        break; //case 5, ayuda.

                        case 6:
                            system("cls");
                            goto menuPrincipal;
                        break;

                    } //cierre switch ayuda.

             break; //case 4, modalidad.

             case 5:
                printf("Ranking");
                printf("\t(Pulse una tecla para volver)");
                getch();
                system("cls");
                goto menuPrincipal;
             break;

             case 6:

             break;

        } //cierre switch seleccion.

    //} //cierre do inicio programa.

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

int buscarNumero(int numero, int vector[], int n){
    int i, stop = 0;

    for (i = 0; i < n && stop == 0; i++){
        if(vector[i] == numero)
            stop = 1;
    }
    return stop;
}
