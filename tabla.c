#include "stdio.h"
#include "defs.h"


const int TablaBit[64] ={
63, 30, 3, 32, 25, 41, 22, 33, 15, 50, 42, 13, 11, 53, 19, 34, 61, 29, 2,
  51, 21, 43, 45, 10, 18, 47, 1, 54, 9, 57, 0, 35, 62, 31, 40, 4, 49, 5, 52,
  26, 60, 6, 23, 44, 46, 27, 56, 16, 7, 39, 48, 24, 59, 14, 12, 55, 38, 28,
  58, 20, 37, 17, 36, 8
}; //tpdps los valores de nuestro bit

//coje el primer bit menos significativo en la tabla y devuelbe el indice del cuadrado en el que estaba y lo deja en 0( esta funcion esta sacada de internet pues no sabia como reiniziar los valores)
int BitPop(U64 *bb)
{
  U64 b = *bb ^ (*bb - 1);
  unsigned int fold = (unsigned) ((b & 0xffffffff) ^ (b >> 32));
  *bb &= (*bb - 1);
  return TablaBit [(fold * 0x783a9b23) >> 26];
}
int CountBits(U64 b)//un simple contador de bits
{
    int i;
    for(i = 0; b; i++, b&= b -1)
    return i;
}


void PrintTablaBit(U64 bb)//tb = tabla bits
{
    U64 moviYO = 1ULL;

    int colubna = 0;
    int rango = 0;
    int cd = 0;
    int cd64 = 0;

    printf("\n");

     for(rango = RANGO_8; rango >= RANGO_1; --rango)//ya construimos nuestra tabla con un for anidado pero ahora del reves en el rango de 8 a 1
    {
        for(colubna = COLUBNA_A; colubna <= COLUBNA_H; ++colubna)
        {
            cd = CR2CD(colubna,rango);//con esta macro ya conseguims los valores individuales de 120
           cd64 = CD64(cd);// para poder pasarlo a el valor 64

            if((moviYO << cd64) & bb)//si se detecta un bit en esa posicion
                printf("X");
            else
                printf("-");
        }
        printf("\n");
    }
    printf("\n\n");
}
