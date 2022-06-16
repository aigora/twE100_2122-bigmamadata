void guardar();

void guardar()
{


  FILE *guardado;

  char tablero[8][8];

  struct COORDENADAS pos;

  char sn;





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

    for(pos.fila=0;pos.fila<8;++pos.fila)
    {
        for(pos.col=0;pos.col<8;++pos.col)


            fprintf(tablero[pos.fila][pos.col],guardado);


    }

      }

      fclose(guardado);

 }

return 0;
}
