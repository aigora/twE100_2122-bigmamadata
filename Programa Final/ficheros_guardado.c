void guardar()
{


  FILE *guardado;

  char tablero[8][8];

  struct COORDENADAS pos;





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


return 0;
}
