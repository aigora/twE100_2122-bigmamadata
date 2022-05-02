#include <stdio.h>
#include <stdlib.h>

void main ()
{
  FILE *guardado;

  char tablero[8][8], sn;

  //tras esta linaea deberia de estar todo el codigo del ajedrez, pero lo que yo no se es como guardar el estado moomentaneo de un programa, refiriendome ,en este caso, al estado de la tabla

//suponiendo que ya se han hecho movvimientos se deveria de guardar el tablero

  printf("quieres guardar la partida? s/n");

  scanf( " %c", &sn);

 switch(sn);
 {
   case 's':
   {
      guardado = fopen("partidaguardada.txt", "w");
      if (guardado == NULL)
      {
      printf("Error al abrir el fichero.\n");
      return -1;
      }
      else
      {
       fprintf(guardado, "%-2c|",  tablero[8][8]);
      }
   }
   case 'n':
   {
     //aqui programar para continuar la partida normalmente
   }
  //aqui la programazion necesaria para cargar el programa

 }

return 0;
}

  
