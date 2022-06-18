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
