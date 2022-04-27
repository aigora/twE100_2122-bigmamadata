#include"defs.h"
//movimientos y funciones de jake, eliminacion y promocion
extern int mov_valido2(struct COORDENADAS Curr,struct COORDENADAS New);
extern int mov_movevalido(struct COORDENADAS,struct COORDENADAS);
extern int rn_enjake2(struct COORDENADAS);
extern int rb_enjake2(struct COORDENADAS);
extern int rn_enjake();
extern int rb_enjake();
extern int n_total_mov_validos();
extern int b_total_mov_validos();
extern void n_jakemate();
extern void b_jakemate();
extern void n_jake();
extern void b_jake();
extern void n_reyaogado();
extern void b_reyaogado();
extern void n_promocion();
extern void b_promocion();



int valid_move2(struct COORDENADAS Curr,struct COORDENADAS New)
{
    char unidad,newunidad;
    int color,fila,col,i,j;

    unidad=tablero[Curr.fila][Curr.col];
    newunidad=tablero[New.fila][New.col];

    if(isalpha(newunidad))
            color=islower(newunidad);
    else
            color=-1;

    if(unidad=='K')
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

    else if(unidad=='k')
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

    else if(unidad=='Q')
    {  tablero[Curr.fila][Curr.col]='R';
       i=mov_valido2(Curr,New);

       tablero[Curr.fila][Curr.col]='B';
       j=mov_valido2(Curr,New);

       tablero[Curr.fila][Curr.col]='Q';

       return i+j;
    }

    else if(unidad=='q')
    {  tablero[Curr.fila][Curr.col]='r';
       i=mov_valido2(Curr,New);

       tablero[Curr.fila][Curr.col]='b';
       j=mov_valido2(Curr,New);

       tablero[Curr.fila][Curr.col]='q';

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




    else if(unidad=='R')
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


    else if(unidad=='r')
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





    else if(unidad=='N')
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



    else if(unidad=='n')
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

/

   else if(unidad=='B')
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



   else if(unidad=='b')
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
