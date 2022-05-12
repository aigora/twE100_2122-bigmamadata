#include<stdio.h>
#include<ctype.h>
#include<dos.h>
#include<time.h>
#include<stdlib.h>

 struct COORDENADAS//estructura principal
{   int fila;
    int col;
};

void main()
{


  FILE *guardado;

  char  sn;

  struct COORDENADAS pos;


  //tras esta linaea deberia de estar todo el codigo del ajedrez, pero lo que yo no se es como guardar el estado moomentaneo de un programa, refiriendome ha este caso al estado de la tabla

  char tablero[8][8]={     't','c','a','m','r','a','c','t',
                        'p','p','p','p','p','p','p','p',
                        '\0','\0','\0','\0','\0','\0','\0','\0',
                        '\0','\0','\0','\0','\0','\0','\0','\0',
                        '\0','\0','\0','\0','\0','\0','\0','\0',
                        '\0','\0','\0','\0','\0','\0','\0','\0',
                        'P','P','P','P','P','P','P','P',
                        'T','C','A','M','R','A','C','R'      };


 scanf( " %c", &sn);

if( sn=='s')
 {

      guardado = fopen("partidaguardada.txt", "w");
      if (guardado == NULL)
      {
      printf("Error al abrir el fichero.\n");
      return -1;
      }
      else
      {
       fprintf(guardado,"   0 1 2 3 4 5 6 7\n");
       for (pos.fila=0;pos.fila<8;++pos.fila)
         {
            fprintf(guardado,"%d |",pos.fila);
            for(pos.col=0;pos.col<8;++pos.col)
            fprintf(guardado,"%-2c",tablero[pos.fila][pos.col]);
            fprintf(guardado,"\n");
         }
       fclose(guardado);
      }

 }
 fclose(guardado);
return 0;
}

