#include<stdio.h>
#include<ctype.h>
#include<dos.h>
#include<time.h>
#include<stdlib.h>
#include "defs.h"

char tablero[8][8]={     't','c','a','m','r','a','c','t',
                        'p','p','p','p','p','p','p','p',
                        '\0','\0','\0','\0','\0','\0','\0','\0',
                        '\0','\0','\0','\0','\0','\0','\0','\0',
                        '\0','\0','\0','\0','\0','\0','\0','\0',
                        '\0','\0','\0','\0','\0','\0','\0','\0',
                        'P','P','P','P','P','P','P','P',
                        'T','C','A','M','R','A','C','R'      };


void tabla()//esto se bugea
{   struct COORDENADAS pos;
    printf("\n");
    printf("   0 1 2 3 4 5 6 7\n");
    for(pos.fila=0;pos.fila<8;++pos.fila)
    {   printf("%d ",pos.fila);
        for(pos.col=0;pos.col<8;++pos.col)
            printf("%-2c",tablero[pos.fila][pos.col]);
        printf("\n");

    }
return tablero[8][8];


}

void guardador()
{

 printf ("pulse s para guardar, n para continuar:");
 struct COORDENADAS  pos;
    char sn;

    FILE* guardado;

    scanf(" %c", sn);

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
 else
 {
     printf("continua");
 }




}


int mov_valido2(struct COORDENADAS Curr,struct COORDENADAS New)
{
    char unidad,newunidad;
    int color,fila,col,i,j;

    unidad=tablero[Curr.fila][Curr.col];
    newunidad=tablero[New.fila][New.col];

    if(isalpha(newunidad))
            color=islower(newunidad);
    else
            color=-1;

    if(unidad=='T')
    {   if(New.fila==Curr.fila-1&&New.col==Curr.col&&color!=0)
            return 1;
        else if(New.fila==Curr.fila-1&&New.col==Curr.col-1&&color!=0)
            return 1;
        else if(New.fila==Curr.fila&&New.col==Curr.col-1&&color!=0)
            return 1;
        else if(New.fila==Curr.fila+1&&New.col==Curr.col-1&&color!=0)
            return 1;
        else if(New.fila==Curr.fila+1&&New.col==Curr.col&&color!=0)
            return 1;
        else if(New.fila==Curr.fila+1&&New.col==Curr.col+1&&color!=0)
            return 1;
        else if(New.fila==Curr.fila&&New.col==Curr.col+1&&color!=0)
            return 1;
        else if(New.fila==Curr.fila-1&&New.col==Curr.col+1&&color!=0)
            return 1;
        else
            return 0;
    }

    else if(unidad=='t')
    {   if(New.fila==Curr.fila-1&&New.col==Curr.col&&color<=0)
            return 1;
        else if(New.fila==Curr.fila-1&&New.col==Curr.col-1&&color<=0)
            return 1;
        else if(New.fila==Curr.fila&&New.col==Curr.col-1&&color<=0)
            return 1;
        else if(New.fila==Curr.fila+1&&New.col==Curr.col-1&&color<=0)
            return 1;
        else if(New.fila==Curr.fila+1&&New.col==Curr.col&&color<=0)
            return 1;
        else if(New.fila==Curr.fila+1&&New.col==Curr.col+1&&color<=0)
            return 1;
        else if(New.fila==Curr.fila&&New.col==Curr.col+1&&color<=0)
            return 1;
        else if(New.fila==Curr.fila-1&&New.col==Curr.col+1&&color<=0)
            return 1;
        else
            return 0;
    }

    else if(unidad=='M')
    {  tablero[Curr.fila][Curr.col]='T';
       i=mov_valido2(Curr,New);

       tablero[Curr.fila][Curr.col]='A';
       j=mov_valido2(Curr,New);

       tablero[Curr.fila][Curr.col]='M';

       return i+j;
    }

    else if(unidad=='m')
    {  tablero[Curr.fila][Curr.col]='t';
       i=mov_valido2(Curr,New);

       tablero[Curr.fila][Curr.col]='a';
       j=mov_valido2(Curr,New);

       tablero[Curr.fila][Curr.col]='m';

       return i+j;
    }

    else if(unidad=='P')
    {

            if(New.fila==Curr.fila-1&&New.col==Curr.col+1)
                    if(color>0)
                            return 1;
                    else
                            return 0;
            else if(New.fila==Curr.fila-1&&New.col==Curr.col-1)
                    if(color>0)
                            return 1;
                    else
                            return 0;
            else if(New.fila==Curr.fila-1&&New.col==Curr.col)
                    if(color<0)
                        return 1;
                    else
                        return 0;
            else if(New.fila==Curr.fila-2&&New.col==Curr.col&&Curr.fila==6)
                    if(color<0&&tablero[New.fila+1][New.col]=='\0')
                        return 1;
                    else
                        return 0;
            else
                        return 0;

    }



    else if(unidad=='p')
    {

            if(New.fila==Curr.fila+1&&New.col==Curr.col+1)
                    if(color==0)
                            return 1;
                    else
                            return 0;
            else if(New.fila==Curr.fila+1&&New.col==Curr.col-1)
                    if(color==0)
                            return 1;
                    else
                            return 0;
            else if(New.fila==Curr.fila+1&&New.col==Curr.col)
                    if(color<0)
                        return 1;
                    else
                        return 0;
            else if(New.fila==Curr.fila+2&&New.col==Curr.col&&Curr.fila==1)
                    if(color<0&&tablero[New.fila-1][New.col]=='\0')
                        return 1;
                    else
                        return 0;
            else
                        return 0;

    }




    else if(unidad=='T')
    {
            if(New.col==Curr.col)
            {   if(New.fila<Curr.fila)
                {   for(fila=Curr.fila-1;fila>New.fila;--fila)
                        if(tablero[fila][Curr.col]!='\0')
                                return 0;
                    if(color>0||color<0)
                        return 1;
                    else
                        return 0;
                }
                else if(New.fila>Curr.fila)
                {   for(fila=Curr.fila+1;fila<New.fila;++fila)
                        if(tablero[fila][Curr.col]!='\0')
                                return 0;
                    if(color>0||color<0)
                        return 1;
                    else
                        return 0;
                }
                else
                    return 0;
            }
            else if(New.fila==Curr.fila)
            {   if(New.col<Curr.col)
                {   for(col=Curr.col-1;col>New.col;--col)
                        if(tablero[Curr.fila][col]!='\0')
                                return 0;
                    if(color>0||color<0)
                        return 1;
                    else
                        return 0;
                }
                else if(New.col>Curr.col)
                {   for(col=Curr.col+1;col<New.col;++col)
                        if(tablero[Curr.fila][col]!='\0')
                                return 0;
                    if(color>0||color<0)
                        return 1;
                    else
                        return 0;
                }
                else
                    return 0;
            }
            else
                return 0;

    }




    else if(unidad=='t')
    {
            if(New.col==Curr.col)
            {   if(New.fila<Curr.fila)
                {   for(fila=Curr.fila-1;fila>New.fila;--fila)
                        if(tablero[fila][Curr.col]!='\0')
                                return 0;
                    if(color==0||color<0)
                        return 1;
                    else
                        return 0;
                }
                else if(New.fila>Curr.fila)
                {   for(fila=Curr.fila+1;fila<New.fila;++fila)
                        if(tablero[fila][Curr.col]!='\0')
                                return 0;
                    if(color==0||color<0)
                        return 1;
                    else
                        return 0;
                }
                else
                    return 0;
            }
            else if(New.fila==Curr.fila)
            {   if(New.col<Curr.col)
                {   for(col=Curr.col-1;col>New.col;--col)
                        if(tablero[Curr.fila][col]!='\0')
                                return 0;
                    if(color==0||color<0)
                        return 1;
                    else
                        return 0;
                }
                else if(New.col>Curr.col)
                {   for(col=Curr.col+1;col<New.col;++col)
                        if(tablero[Curr.fila][col]!='\0')
                                return 0;
                    if(color==0||color<0)
                        return 1;
                    else
                        return 0;
                }
                else
                    return 0;
            }
            else
                return 0;

    }





    else if(unidad=='C')
    {
        if((New.fila==Curr.fila-2)&&(New.col==Curr.col+1)&&color!=0)
                return 1;
        else if((New.fila==Curr.fila-2)&&(New.col==Curr.col-1)&&color!=0)
                return 1;
        else if((New.fila==Curr.fila-1)&&(New.col==Curr.col-2)&&color!=0)
                return 1;
        else if((New.fila==Curr.fila+1)&&(New.col==Curr.col-2)&&color!=0)
                return 1;
        else if((New.fila==Curr.fila+2)&&(New.col==Curr.col-1)&&color!=0)
                return 1;
        else if((New.fila==Curr.fila+2)&&(New.col==Curr.col+1)&&color!=0)
                return 1;
        else if((New.fila==Curr.fila+1)&&(New.col==Curr.col+2)&&color!=0)
                return 1;
        else if((New.fila==Curr.fila-1)&&(New.col==Curr.col+2)&&color!=0)
                return 1;
        else
                return 0;

    }



    else if(unidad=='c')
    {
        if((New.fila==Curr.fila-2)&&(New.col==Curr.col+1)&&color<=0)
                return 1;
        else if((New.fila==Curr.fila-2)&&(New.col==Curr.col-1)&&color<=0)
                return 1;
        else if((New.fila==Curr.fila-1)&&(New.col==Curr.col-2)&&color<=0)
                return 1;
        else if((New.fila==Curr.fila+1)&&(New.col==Curr.col-2)&&color<=0)
                return 1;
        else if((New.fila==Curr.fila+2)&&(New.col==Curr.col-1)&&color<=0)
                return 1;
        else if((New.fila==Curr.fila+2)&&(New.col==Curr.col+1)&&color<=0)
                return 1;
        else if((New.fila==Curr.fila+1)&&(New.col==Curr.col+2)&&color<=0)
                return 1;
        else if((New.fila==Curr.fila-1)&&(New.col==Curr.col+2)&&color<=0)
                return 1;
        else
                return 0;

    }



   else if(unidad=='A')
   {

        if(Curr.fila-New.fila==New.col-Curr.col)
        {
            if(New.col>Curr.col)
            {   for(fila=Curr.fila-1,col=Curr.col+1;fila>New.fila;--fila,++col)
                        if(tablero[fila][col]=='\0')
                                continue;
                        else
                                return 0;
                if(color!=0)
                        return 1;
                else
                        return 0;

            }
            else if(New.col<Curr.col)
            {   for(fila=Curr.fila+1,col=Curr.col-1;fila<New.fila;++fila,--col)
                        if(tablero[fila][col]=='\0')
                                continue;
                        else
                                return 0;
                if(color!=0)
                        return 1;
                else
                        return 0;

            }
            else
                return 0;
        }
        else if(Curr.fila-New.fila==Curr.col-New.col)
        {
            if(New.col>Curr.col)
            {   for(fila=Curr.fila+1,col=Curr.col+1;fila<New.fila;++fila,++col)
                        if(tablero[fila][col]=='\0')
                                continue;
                        else
                                return 0;
                if(color!=0)
                        return 1;
                else
                        return 0;

            }
            else if(New.col<Curr.col)
            {   for(fila=Curr.fila-1,col=Curr.col-1;fila>New.fila;--fila,--col)
                        if(tablero[fila][col]=='\0')
                                continue;
                        else
                                return 0;
                if(color!=0)
                        return 1;
                else
                        return 0;

            }
            else
                return 0;
        }
        else
            return 0;
   }



   else if(unidad=='a')
   {

        if(Curr.fila-New.fila==New.col-Curr.col)
        {
            if(New.col>Curr.col)
            {   for(fila=Curr.fila-1,col=Curr.col+1;fila>New.fila;--fila,++col)
                        if(tablero[fila][col]=='\0')
                                continue;
                        else
                                return 0;
                if(color<=0)
                        return 1;
                else
                        return 0;

            }
            else if(New.col<Curr.col)
            {   for(fila=Curr.fila+1,col=Curr.col-1;fila<New.fila;++fila,--col)
                        if(tablero[fila][col]=='\0')
                                continue;
                        else
                                return 0;
                if(color<=0)
                        return 1;
                else
                        return 0;

            }
            else
                return 0;
        }
        else if(Curr.fila-New.fila==Curr.col-New.col)
        {
            if(New.col>Curr.col)
            {   for(fila=Curr.fila+1,col=Curr.col+1;fila<New.fila;++fila,++col)
                        if(tablero[fila][col]=='\0')
                                continue;
                        else
                                return 0;
                if(color<=0)
                        return 1;
                else
                        return 0;

            }
            else if(New.col<Curr.col)
            {   for(fila=Curr.fila-1,col=Curr.col-1;fila>New.fila;--fila,--col)
                        if(tablero[fila][col]=='\0')
                                continue;
                        else
                                return 0;
                if(color<=0)
                        return 1;
                else
                        return 0;

            }
            else
                return 0;
        }
        else
            return 0;
   }

   else
        return 0;



}

int mov_valido(struct COORDENADAS Curr,struct COORDENADAS New)
{

    int s;
    char unidad,newunidad;
    struct COORDENADAS pos;

    unidad=tablero[Curr.fila][Curr.col];
    newunidad=tablero[New.fila][New.col];

    s=mov_valido2(Curr,New);

    if(s==0)
        return 0;
    else if(s==1)
    {
        if(islower(unidad)==0)
        {   tablero[New.fila][New.col]=unidad;
            tablero[Curr.fila][Curr.col]='\0';
            for(pos.fila=0;pos.fila<8;++pos.fila)
                for(pos.col=0;pos.col<8;++pos.col)
                    if(rb_enjake2(pos))
                    {   tablero[New.fila][New.col]=newunidad;
                        tablero[Curr.fila][Curr.col]=unidad;
                        return 0;
                    }
             tablero[New.fila][New.col]=newunidad;
             tablero[Curr.fila][Curr.col]=unidad;
             return 1;
        }
        else if(islower(unidad)>0)
        {   tablero[New.fila][New.col]=unidad;
            tablero[Curr.fila][Curr.col]='\0';
            for(pos.fila=0;pos.fila<8;++pos.fila)
                for(pos.col=0;pos.col<8;++pos.col)
                    if(rn_enjake2(pos))
                    {   tablero[New.fila][New.col]=newunidad;
                        tablero[Curr.fila][Curr.col]=unidad;
                        return 0;
                    }
             tablero[New.fila][New.col]=newunidad;
             tablero[Curr.fila][Curr.col]=unidad;
             return 1;
        }


    }


}


int b_total_mov_validos()
{
    int num_mov_validos=0;
    struct COORDENADAS Curr,New;

    for(Curr.fila=0;Curr.fila<8;++Curr.fila)
        for(Curr.col=0;Curr.col<8;++Curr.col)

            if(isupper(tablero[Curr.fila][Curr.col])>0)

                for(New.fila=0;New.fila<8;++New.fila)
                    for(New.col=0;New.col<8;++New.col)

                        if(mov_valido(Curr,New))
                            ++num_mov_validos;



    return num_mov_validos;
}



int n_total_mov_validos()
{
    int num_mov_validos=0;
    struct COORDENADAS Curr,New;

    for(Curr.fila=0;Curr.fila<8;++Curr.fila)
        for(Curr.col=0;Curr.col<8;++Curr.col)

            if(isupper(tablero[Curr.fila][Curr.col])>0)

                for(New.fila=0;New.fila<8;++New.fila)
                    for(New.col=0;New.col<8;++New.col)

                        if(mov_valido(Curr,New))
                            ++num_mov_validos;



    return num_mov_validos;
}


void b_jakemate()
{
    if(rb_enjake()==1&&b_total_mov_validos()==0)
    {       printf("\nJake mate, ganan negras\n");
            exit(0);
    }

}

void n_jakemate()
{
    if((rn_enjake()==1)&&(n_total_mov_validos()==0))
    {       printf("\nJake mate, ganan blancas\n");
            exit(0);
    }

}

void b_jake()
{
    if(rb_enjake()==1&&b_total_mov_validos()>0)
            printf("\nJake\n");

}

void n_jake()
{
    if(rn_enjake()==1&&n_total_mov_validos()>0)
            printf("\nIt's Check\n");

}

void b_reyaogado()
{
    if(rb_enjake()==0&&b_total_mov_validos()==0)
    {   printf("\nEmpate, rey aogado\n");
        exit(0);
    }

}


void n_reyaogado()
{
    if(rn_enjake()==0&&b_total_mov_validos()==0)
    {   printf("\nEmpate, rey aogado\n");
        exit(0);
    }

}

int rn_enjake2(struct COORDENADAS Curr)
{

    int i,j,fila,col;
    char unidad;
    struct COORDENADAS rnpos;

    for(i=0;i<8;++i)
        for(j=0;j<8;++j)
            if(tablero[i][j]=='r')
                    goto out;
    out:
    rnpos.fila=i;
    rnpos.col=j;

    unidad=tablero[Curr.fila][Curr.col];

    if(unidad=='R')
    {   if(rnpos.fila==Curr.fila-1&&rnpos.col==Curr.col)
            return 1;
        else if(rnpos.fila==Curr.fila-1&&rnpos.col==Curr.col-1)
            return 1;
        else if(rnpos.fila==Curr.fila&&rnpos.col==Curr.col-1)
            return 1;
        else if(rnpos.fila==Curr.fila+1&&rnpos.col==Curr.col-1)
            return 1;
        else if(rnpos.fila==Curr.fila+1&&rnpos.col==Curr.col)
            return 1;
        else if(rnpos.fila==Curr.fila+1&&rnpos.col==Curr.col+1)
            return 1;
        else if(rnpos.fila==Curr.fila&&rnpos.col==Curr.col+1)
            return 1;
        else if(rnpos.fila==Curr.fila-1&&rnpos.col==Curr.col+1)
            return 1;
        else
            return 0;
    }

    else if(unidad=='M')
    {   tablero[Curr.fila][Curr.col]='T';
        i=rn_enjake2(Curr);

        tablero[Curr.fila][Curr.col]='A';
        j=rn_enjake2(Curr);

        tablero[Curr.fila][Curr.col]='M';

        return i+j;
    }

    else if(unidad=='P')
    {
        if(rnpos.fila==Curr.fila-1&&rnpos.col==Curr.col+1)
                return 1;
        else if(rnpos.fila==Curr.fila-1&&rnpos.col==Curr.col-1)
                return 1;
        else
                return 0;
    }

    else if(unidad=='T')
    {
            if(rnpos.col==Curr.col)
            {   if(rnpos.fila<Curr.fila)
                {   for(fila=Curr.fila-1;fila>rnpos.fila;--fila)
                        if(tablero[fila][Curr.col]=='\0')
                                continue;
                        else
                                return 0;
                    return 1;
                }
                else if(rnpos.fila>Curr.fila)
                {   for(fila=Curr.fila+1;fila<rnpos.fila;++fila)
                        if(tablero[fila][Curr.col]=='\0')
                                continue;
                        else
                                return 0;
                    return 1;
                }

            }
            else if(rnpos.fila==Curr.fila)
            {   if(rnpos.col<Curr.col)
                {   for(col=Curr.col-1;col>rnpos.col;--col)
                        if(tablero[Curr.fila][col]=='\0')
                                continue;
                        else
                                return 0;
                    return 1;
                }
                else if(rnpos.col>Curr.col)
                {   for(col=Curr.col+1;col<rnpos.col;++col)
                        if(tablero[Curr.fila][col]=='\0')
                                continue;
                        else
                                return 0;
                    return 1;
                }

            }
            else
                return 0;

    }

    else if(unidad=='C')
    {
        if((rnpos.fila==Curr.fila-2)&&(rnpos.col==Curr.col+1))
                return 1;
        else if((rnpos.fila==Curr.fila-2)&&(rnpos.col==Curr.col-1))
                return 1;
        else if((rnpos.fila==Curr.fila-1)&&(rnpos.col==Curr.col-2))
                return 1;
        else if((rnpos.fila==Curr.fila+1)&&(rnpos.col==Curr.col-2))
                return 1;
        else if((rnpos.fila==Curr.fila+2)&&(rnpos.col==Curr.col-1))
                return 1;
        else if((rnpos.fila==Curr.fila+2)&&(rnpos.col==Curr.col+1))
                return 1;
        else if((rnpos.fila==Curr.fila+1)&&(rnpos.col==Curr.col+2))
                return 1;
        else if((rnpos.fila==Curr.fila-1)&&(rnpos.col==Curr.col+2))
                return 1;
        else
                return 0;

    }


    else if(unidad=='A')
    {

        if(Curr.fila-rnpos.fila==rnpos.col-Curr.col)
        {
            if(rnpos.col>Curr.col)
            {   for(fila=Curr.fila-1,col=Curr.col+1;fila>rnpos.fila;--fila,++col)
                        if(tablero[fila][col]=='\0')
                                continue;
                        else
                                return 0;
                return 1;

            }
            else if(rnpos.col<Curr.col)
            {   for(fila=Curr.fila+1,col=Curr.col-1;fila<rnpos.fila;++fila,--col)
                        if(tablero[fila][col]=='\0')
                                continue;
                        else
                                return 0;
                return 1;

            }

        }
        else if(Curr.fila-rnpos.fila==Curr.col-rnpos.col)
        {
            if(rnpos.col>Curr.col)
            {   for(fila=Curr.fila+1,col=Curr.col+1;fila<rnpos.fila;++fila,++col)
                        if(tablero[fila][col]=='\0')
                                continue;
                        else
                                return 0;
                return 1;

            }
            else if(rnpos.col<Curr.col)
            {   for(fila=Curr.fila-1,col=Curr.col-1;fila>rnpos.fila;--fila,--col)
                        if(tablero[fila][col]=='\0')
                                continue;
                        else
                                return 0;
                return 1;

            }

        }
        else
            return 0;
    }

    else
        return 0;


}


int rb_enjake2(struct COORDENADAS Curr)
{

    int i,j,fila,col;
    char unidad;
    struct COORDENADAS rbpos;

    for(i=0;i<8;++i)
        for(j=0;j<8;++j)
            if(tablero[i][j]=='R')
                    goto out2;
    out2:
    rbpos.fila=i;
    rbpos.col=j;

    unidad=tablero[Curr.fila][Curr.col];
    //////////////////////////////////////////////////////////
    if(unidad=='r')
    {   if(rbpos.fila==Curr.fila-1&&rbpos.col==Curr.col)
            return 1;
        else if(rbpos.fila==Curr.fila-1&&rbpos.col==Curr.col-1)
            return 1;
        else if(rbpos.fila==Curr.fila&&rbpos.col==Curr.col-1)
            return 1;
        else if(rbpos.fila==Curr.fila+1&&rbpos.col==Curr.col-1)
            return 1;
        else if(rbpos.fila==Curr.fila+1&&rbpos.col==Curr.col)
            return 1;
        else if(rbpos.fila==Curr.fila+1&&rbpos.col==Curr.col+1)
            return 1;
        else if(rbpos.fila==Curr.fila&&rbpos.col==Curr.col+1)
            return 1;
        else if(rbpos.fila==Curr.fila-1&&rbpos.col==Curr.col+1)
            return 1;
        else
            return 0;
    }

    else if(unidad=='m')
    {   tablero[Curr.fila][Curr.col]='t';
        i=rb_enjake2(Curr);

        tablero[Curr.fila][Curr.col]='a';
        j=rb_enjake2(Curr);

        tablero[Curr.fila][Curr.col]='m';

        return i+j;
    }

    else if(unidad=='p')
    {
        if(rbpos.fila==Curr.fila+1&&rbpos.col==Curr.col+1)
                return 1;
        else if(rbpos.fila==Curr.fila+1&&rbpos.col==Curr.col-1)
                return 1;
        else
                return 0;
    }

    else if(unidad=='t')
    {
            if(rbpos.col==Curr.col)
            {   if(rbpos.fila<Curr.fila)
                {   for(fila=Curr.fila-1;fila>rbpos.fila;--fila)
                        if(tablero[fila][Curr.col]=='\0')
                                continue;
                        else
                                return 0;
                    return 1;
                }
                else if(rbpos.fila>Curr.fila)
                {   for(fila=Curr.fila+1;fila<rbpos.fila;++fila)
                        if(tablero[fila][Curr.col]=='\0')
                                continue;
                        else
                                return 0;
                    return 1;
                }

            }
            else if(rbpos.fila==Curr.fila)
            {   if(rbpos.col<Curr.col)
                {   for(col=Curr.col-1;col>rbpos.col;--col)
                        if(tablero[Curr.fila][col]=='\0')
                                continue;
                        else
                                return 0;
                    return 1;
                }
                else if(rbpos.col>Curr.col)
                {   for(col=Curr.col+1;col<rbpos.col;++col)
                        if(tablero[Curr.fila][col]=='\0')
                                continue;
                        else
                                return 0;
                    return 1;
                }

            }
            else
                return 0;

    }

    else if(unidad=='c')
    {
        if((rbpos.fila==Curr.fila-2)&&(rbpos.col==Curr.col+1))
                return 1;
        else if((rbpos.fila==Curr.fila-2)&&(rbpos.col==Curr.col-1))
                return 1;
        else if((rbpos.fila==Curr.fila-1)&&(rbpos.col==Curr.col-2))
                return 1;
        else if((rbpos.fila==Curr.fila+1)&&(rbpos.col==Curr.col-2))
                return 1;
        else if((rbpos.fila==Curr.fila+2)&&(rbpos.col==Curr.col-1))
                return 1;
        else if((rbpos.fila==Curr.fila+2)&&(rbpos.col==Curr.col+1))
                return 1;
        else if((rbpos.fila==Curr.fila+1)&&(rbpos.col==Curr.col+2))
                return 1;
        else if((rbpos.fila==Curr.fila-1)&&(rbpos.col==Curr.col+2))
                return 1;
        else
                return 0;

    }


    else if(unidad=='a')
    {

        if(Curr.fila-rbpos.fila==rbpos.col-Curr.col)
        {
            if(rbpos.col>Curr.col)
            {   for(fila=Curr.fila-1,col=Curr.col+1;fila>rbpos.fila;--fila,++col)
                        if(tablero[fila][col]=='\0')
                                continue;
                        else
                                return 0;
                return 1;

            }
            else if(rbpos.col<Curr.col)
            {   for(fila=Curr.fila+1,col=Curr.col-1;fila<rbpos.fila;++fila,--col)
                        if(tablero[fila][col]=='\0')
                                continue;
                        else
                                return 0;
                return 1;

            }

        }
        else if(Curr.fila-rbpos.fila==Curr.col-rbpos.col)
        {
            if(rbpos.col>Curr.col)
            {   for(fila=Curr.fila+1,col=Curr.col+1;fila<rbpos.fila;++fila,++col)
                        if(tablero[fila][col]=='\0')
                                continue;
                        else
                                return 0;
                return 1;

            }
            else if(rbpos.col<Curr.col)
            {   for(fila=Curr.fila-1,col=Curr.col-1;fila>rbpos.fila;--fila,--col)
                        if(tablero[fila][col]=='\0')
                                continue;
                        else
                                return 0;
                return 1;

            }

        }
        else
            return 0;
    }

    else
        return 0;


}



int rb_enjake()
{   struct COORDENADAS pos;

    for(pos.fila=0;pos.fila<8;++pos.fila)
                for(pos.col=0;pos.col<8;++pos.col)
                    if(rb_enjake2(pos))
                        return 1;
    return 0;
}



int rn_enjake()
{   struct COORDENADAS pos;

    for(pos.fila=0;pos.fila<8;++pos.fila)
                for(pos.col=0;pos.col<8;++pos.col)
                    if(rn_enjake2(pos))
                        return 1;
    return 0;
}





void b_promocion()
{   int i=0,j;
    char unidad;
    for(j=0;j<8;++j)
        if(tablero[i][j]=='P')
           while(1)
            {    printf("\nPromociona tu pero a:(M T A C) ");fflush(stdin);
                 scanf("%c",&unidad);
                 switch(unidad)
                 {   case 'M': tablero[i][j]='M';
                               return;
                     case 'T': tablero[i][j]='T';
                               return;
                     case 'A': tablero[i][j]='A';
                               return;
                     case 'C': tablero[i][j]='C';
                               return;
                     default : printf("no valido intenta de nuevo");
                 }

            }


}




void n_promocion()
{   int i=7,j;
    char unidad;
    for(j=0;j<8;++j)
        if(tablero[i][j]=='p')
           while(1)
            {    printf("\nPromociona tu peon a:(m t a c) ");fflush(stdin);
                 scanf("%c",&unidad);
                 switch(unidad)
                 {   case 'm': tablero[i][j]='m';
                               return;
                     case 't': tablero[i][j]='t';
                               return;
                     case 'a': tablero[i][j]='a';
                               return;
                     case 'c': tablero[i][j]='c';
                               return;
                     default : printf("no valido intenta de nuevo");
                 }

            }


}

void delay(double sec)
{
    clock_t start = clock();

    while ((clock() - start) / CLOCKS_PER_SEC < sec)
        ;
}

