#include "stdio.h"
#include "defs.h"






void mainchess()
{
    int turno=0;

    char tablero[8][8]={     't','c','a','m','r','a','c','t',
                        'p','p','p','p','p','p','p','p',
                        '\0','\0','\0','\0','\0','\0','\0','\0',
                        '\0','\0','\0','\0','\0','\0','\0','\0',
                        '\0','\0','\0','\0','\0','\0','\0','\0',
                        '\0','\0','\0','\0','\0','\0','\0','\0',
                        'P','P','P','P','P','P','P','P',
                        'T','C','A','M','R','A','C','R'      };





    struct COORDENADAS Curr,New;

    tabla();





    while(1)
    {



        if(turno%2==0)
        {
            printf("\nMueven blancas: ");
            scanf("%d.%d a %d.%d",&Curr.fila,&Curr.col,&New.fila,&New.col);



            if(isupper(tablero[Curr.fila][Curr.col])>0)
            {
                if(mov_valido(Curr,New))
                {
                    tablero[New.fila][New.col]=tablero[Curr.fila][Curr.col];
                    tablero[Curr.fila][Curr.col]='\0';
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
        else
        {
            printf("\nMueven negras: ");
            scanf("%d.%d a %d.%d",&Curr.fila,&Curr.col,&New.fila,&New.col);

            if(islower(tablero[Curr.fila][Curr.col])>0)
            {   if(mov_valido(Curr,New))
                {   tablero[New.fila][New.col]=tablero[Curr.fila][Curr.col];
                    tablero[Curr.fila][Curr.col]='\0';
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

  return 0;
}
