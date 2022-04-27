#include "defs.h"


void t()//esto se bugea
{   struct COORDENADAS pos;
    printf("\n");
    printf("   0  1  2  3  4  5  6  7\n");
    for(pos.fila=0;pos.fila<8;++pos.fila)
    {   printf("%d |",pos.fila);
        for(pos.col=0;pos.col<8;++pos.col)
            printf("%-2c|",tablero[pos.fila][pos.col]);
        printf("\n");
    }

}

