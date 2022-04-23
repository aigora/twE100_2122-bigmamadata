//ESTE HEATHER NOS VA HA FACILITAR EL TRABAJO CON VARIABLES EN NUESTRO PROGRAMA

#ifndef DEFS_H
#define DEFS_H

#include "stdlib.h"






typedef unsigned long long U64;//numero de 64 bits para posiciones y conteo en nuestra tabla de 64 espacios muy conveniente

#define NOMBRE "ajedrez serio"
#define TAB_CD_NUM 120// ya sebemos el numero de espacios que tendra nuestra tabla, 120, ya que del 21-98, se jugara nuestro tablero y en el resto usaremos los valores para indicar que el movimiento es imposible pues se sale de la tabla

#define MAXMOVIMIENTOS 2048//maximos movimientos posibles (internet)



enum { VACIO, Pb, Ab, Tb, Cb, Rb, Mb, Pn, An, Tn, Cn, Rn, Mn};// asignamos que cada piza sera un vlor numerico;
enum { COLUBNA_A, COLUBNA_B, COLUBNA_C ,COLUBNA_D, COLUBNA_E, COLUBNA_F, COLUBNA_G, COLUBNA_H, COLUBNA_VACIO};//Asignamos numero a las coordenadas de las colubnas de letras, ocuparan la posicion de 11-19 en nuertra tabla;
enum { RANGO_1, RANGO_2, RANGO_3, RANGO_4, RANGO_5, RANGO_6, RANGO_7, RANGO_8, RANGO_VACIO};// asignamso la segunda parte de la coordenada del 1 al 8 y las pondremos en la vertcal izquierda de la tabla;

enum { BLANCO, NEGRO, AMBAS};// ASIGNAMOS VALORES NUMERICOS A LOS COLORE 0 BLANCO 1 NEGRO 2 AMBOS;

enum {
  A1 = 21, B1, C1, D1, E1, F1, G1, H1,
  A2 = 31, B2, C2, D2, E2, F2, G2, H2,
  A3 = 41, B3, C3, D3, E3, F3, G3, H3,
  A4 = 51, B4, C4, D4, E4, F4, G4, H4,
  A5 = 61, B5, C5, D5, E5, F5, G5, H5,
  A6 = 71, B6, C6, D6, E6, F6, G6, H6,
  A7 = 81, B7, C7, D7, E7, F7, G7, H7,
  A8 = 91, B8, C8, D8, E8, F8, G8, H8, NO_CD
  };//DESCRIBIMOS LAS POSICIONES DE LA TABLA DEL 21 AL 98, INCULLENDO NO_CD ( NO CUADRADO) PARA NO INCLUIDO EN LA TABLA

enum { FALSE, TRUE };//DESCRIBIMOS DOS VARIABLES DE VERDADERO FALSO DONDE FALSE SERA  0 Y TRUE SERA 1;


enum { ERBR = 1, ERBM = 2, ERNR = 4, ERNM = 8};// AQUI ASIGNAREMOS LA POSIVILIDAD DE ENROCAR O NO  (1 0 0 0)

typedef struct {//estructura para deshacer movimentos

   int movimiento;
   int Permtorre;
   int enPas;
   U64 posicion;


}S_DESHACER;


typedef struct{// una struct para la tabla

  int piezas[TAB_CD_NUM];//numero total de cuadrados en tabla
  U64 peones[3];// para los peones usamos tre tipos, balnco negro y ambos.// 00000010 1=peon

  int ReyCd[2]; //localizacion del rey

  int side;//turno movimento
  int enPas;// aui guardaremos los movimentos en passont

  int ply;// contador de semimovimentos en la busqueda actual
  int suPly;// semimovimientos totales

  int Permtorre;// permitir un enroque o no

  U64 posicion;// posicion en  la tabla

  int NumPizs[13];// numero de pizas en la tabla por numero (peon 1-....-rey 12)
  int pizsGran[3];// numero de pizas grandes en la tabla por color(todo lo que no sea peon)
  int pizsTM[3];// numero de torres y reinas
  int pizsAC[3];//numero de alfiles y caballos

  S_DESHACER historia[MAXMOVIMIENTOS];//aqui se ceda todo movimiento guardado

  // lista de piezas
  int listpizs[13][10];//una lista para guardar las pizas de la tabal con el numero de pizas y el total en tabla
  // el funcionamiento seguira este patron listpizs[Cn][0] = E1; y con todos los valores asignado la pieza aparecera en su sitio


}S_TABLA;


//macros

#define CR2CD(c,r) ( (21 + (c) ) + ( (r) * 10 ) ) // eso nos debuelve el cuadrado equivalente a cada combinacion de colubna y rango
#define CD64(cd120)  Cd120aCD64[cd120]

#define POP(b) BitPop(b)
#define CNT(b)  CountBits(b)// me facilito la llamada de ests funciones
#define QuitBit(tb,cd) ((tb) &= QuitMark[(cd)])//operacion en macro
#define PonerBit(tb,cd) ((tb) |= PonMark[(cd)])

//global

extern int Cd120aCD64[TAB_CD_NUM];// aqui podremos cambiar los valores de la tabla de 120 a la de 64
extern int Cd64aCD120[64];//vicebersa
extern U64 PonMark[64];//usaremos esto para asignar 1 a sespacios vacios
extern U64 QuitMark[64];// usaremos esto para vaciar 1 asignados
/*funciones*/

//inicio.c

extern void Todoinicio();//aqui habilitamos la llamada a nuesta funcion
extern void inicioCd120a64();
extern void inicioBitMark();

//tablabits.c

extern void PrintTablaBit(U64 tb);
extern int BitPop (U64 *tb);
extern int CountBits(U64 b);
#endif
