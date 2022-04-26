//ESTE HEATHER NOS VA HA FACILITAR EL TRABAJO CON VARIABLES EN NUESTRO PROGRAMA

//ESTE HEATHER NOS VA HA FACILITAR EL TRABAJO CON VARIABLES EN NUESTRO PROGRAMA

#include<stdio.h>
#include<ctype.h>
#include<dos.h>
#include<time.h>
#include<stdlib.h>



struct COORDENADAS//estructura principal
{   int linea;
    int color;
};

char tablero[8][8]={     'r','n','b','q','k','b','n','r',//tabla principal
                        'p','p','p','p','p','p','p','p',
                        '\0','\0','\0','\0','\0','\0','\0','\0',
                        '\0','\0','\0','\0','\0','\0','\0','\0',
                        '\0','\0','\0','\0','\0','\0','\0','\0',
                        '\0','\0','\0','\0','\0','\0','\0','\0',
                        'P','P','P','P','P','P','P','P',
                        'R','N','B','Q','K','B','N','R'      };

extern void tabla();
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

void delay(double sec);



void delay(double sec)
{
    clock_t start = clock();

    while ((clock() - start) / CLOCKS_PER_SEC < sec)
        ;
}


