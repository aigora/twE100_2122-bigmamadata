void cargar()
{


  char tablero[8][8];

  struct COORDENADAS pos;

  





      FILE *carga = fopen("guardado.txt", "r");

      if (carga== NULL)
      {
          fclose(carga);
          printf("error al abrir el fichero");
      }
      else
        {
           for(pos.fila=0;pos.fila<8;++pos.fila)
         {
          for(pos.col=0;pos.col<8;++pos.col)


            fscanf(carga, "%c", &tablero[8][8]);


         }

        }

      fclose(carga);

}

