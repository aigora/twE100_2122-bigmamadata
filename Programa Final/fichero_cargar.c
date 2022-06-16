void cargar()
{
    FILE *guardado;

  char tablero[8][8];

  struct COORDENADAS pos;

  char sn;

  int

  printf("cargar partida?('s' o 'n'");

  if (sn == 's');
  {
      FILE *guardado = fopen("guardado.txt", "r");

      if (guardado== NULL)
      {
          fclose(guardado);
          printf("error al abrir el fichero");
      }
      else
        {
           for(pos.fila=0;pos.fila<8;++pos.fila)
    {
        for(pos.col=0;pos.col<8;++pos.col)


            fscanf(guardado, "%c", &tablero[][]);


    }

      }

      fclose(guardado);

        }
  }



