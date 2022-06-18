#include "stdio.h"
#include "defs.h"















void mainchess()
{
    int turno=0;







    struct COORDENADAS Curr,New;

    tabla();






    while(1)
    {



        if(turno%2==0)
        {

            printf("\nMueven blancas:\n");
            scanf("%d.%d a %d.%d",&Curr.fila,&Curr.col,&New.fila,&New.col);
           if(Curr.fila == 10 && Curr.col==0 && New.fila== 10&& New.col== 0){
                guardar();

           }
           else
            {



            if(isupper(tablero[Curr.fila][Curr.col])>0)
            {
                if(mov_valido(Curr,New))
                {
                    tablero[New.fila][New.col]=tablero[Curr.fila][Curr.col];
                    tablero[Curr.fila][Curr.col]=' ';
                    b_promocion();
                    n_jakemate();
                    n_reyaogado();
                    n_jake();

                }
                else
                {   printf("\nmovimiento no valido, intenta de nuevo\n");

                    ++turno;
                }
            }
            else
            {   printf("\nle toca a las blancas\n");

                ++turno;
            }
            system("cls");
            tabla();
            ++turno;

        }
        }
        else
        {

            printf("\nMueven negras: ");
            scanf("%d.%d a %d.%d",&Curr.fila,&Curr.col,&New.fila,&New.col);

            if(Curr.fila == 10 && Curr.col==0 && New.fila== 10 && New.col== 0){
                guardar();

            }

            else{
               if(islower(tablero[Curr.fila][Curr.col])>0)
               {   if(mov_valido(Curr,New))
                {   tablero[New.fila][New.col]=tablero[Curr.fila][Curr.col];
                    tablero[Curr.fila][Curr.col]=' ';
                     n_promocion();
                    b_jakemate();
                    b_reyaogado();
                    b_jake();

                }
                else
                {   printf("\nmovimiento no valido, intenta de nuevo\n");//se bugea

                    ++turno;
                }
            }
            else
            {   ++turno;
                printf("\nle toca a las negras\n");

            }
            system("cls");
            tabla();
            ++turno;

        }


    }
    }


  return 0;
}
