#include "defs.h"

 int Cd120aCD64[TAB_CD_NUM];// aqui podremos cambiar los valores de la tabla de 120 a la de 64
 int Cd64aCD120[64];//vicebersa

 U64 PonMark[64];//usaremos esto para asignar 1 a sespacios vacios
 U64 QuitMark[64];// usaremos esto para vaciar 1 asignados


void inicioBitMark()
{
    int indice = 0;

    for (indice = 0; indice<64; indice++)//transformammos todos los valores a 0
    {
        PonMark[indice] = 0ULL;
        QuitMark[indice] = 0ULL;
    }
    for (indice = 0; indice<64; indice++)//transformammos todos los valores a 0
    {
        PonMark[indice] = (1ULL << indice);//desplazamos
        QuitMark[indice] = ~PonMark[indice];//todo lo que sea 1 en ponmark ahora es un cero y vixeversa '~'
    }

}


void inicioCd120a64()
{
    int indice = 0;
    int colubna = COLUBNA_A;
    int rango = RANGO_1;
    int cd = A1;
    int cd64 = 0;
    int Cd120aCD64[TAB_CD_NUM];
    int Cd64aCD120[64];

    for (indice = 0; indice<TAB_CD_NUM; ++indice)//aqui cambiamos todos los valores del indice a 65 para que no sea valido
    {
        Cd120aCD64[indice] = 65;
    }
    for (indice = 0; indice<64; ++indice)//aqui tambien se devuelve un valor imposible para hacer falichek mas tarde
    {
        Cd64aCD120[indice] = 120;
    }

    for(rango = RANGO_1; rango <= RANGO_8; ++rango)//ya construimos nuestra tabla con un for anidado
    {
        for(colubna = COLUBNA_A; colubna <= COLUBNA_H; ++colubna)
        {
            cd = CR2CD(colubna,rango);//con esta macro ya conseguims los valores individuales
            Cd64aCD120[cd64] = cd;// para poder pasarlo a el valor 120
            Cd120aCD64[cd] = cd64;//para pasarso al 64
            cd64++;// incrementar para continuar en orden
        }
    }
}
/* for (indice = 0; indice<TAB_CD_NUM; ++indice)
  {
    if(indice%10==0) printf("\n");
    printf("%5d",Cd120aCD64[indice]);
  }

  printf("\n");
  printf("\n");

  for (indice = 0; indice<64; ++indice)
  {
      if(indice%8==0) printf("\n");
    printf("%5d",Cd64aCD120[indice]);//imprimir cada numero en 5  espacios
  }
    return 0;

}
*///esto solo es para comprovar que funciona
void Todoinicio(){

    inicioCd120a64();
    inicioBitMark();
}
