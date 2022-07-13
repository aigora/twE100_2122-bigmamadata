struct COORDENADAS
{   int fila;
    int col;
};


typedef struct{
    char nombre[20];
    int num;
} jugador;


void printcargarpartida();
void printinstruc();
int interfazjugcol();
int interfazjugcol2();
void creafichero1(char n[]);
void creafichero2(char n[]);
void creacolor1(char color1[]);
void creacolor2(char color2[]);
void ficheroColorUp();
void ficheroColorDown();
int interfazparcolUp();
void interfazparcolDown();
void menupausa();
void menuPrincipal();
void cambio (char palabra[], int n);
void printnuevapartida();
void portadachess();
void ganador1();
void ganador2();
int victoria();
void reconocimientoganador1();
void reconocimientoganador2();
void seleccion1();
void seleccion2();
int obtencion();
int obtencionsalidamenu();
void salidamenuprincipal();
void seleccionmenu1();
void seleccionmenu2();
int obtencionmenu();
void borradoobtencionmenu();
int buscarNumero(int numero, int vector[], int n);
void printtorneo();
int mov_valido2(struct COORDENADAS Curr,struct COORDENADAS New, char tablero[8][8]);
int mov_valido(struct COORDENADAS Curr,struct COORDENADAS New, char tablero[8][8]);
int rn_enjake2(struct COORDENADAS,char tablero[8][8]);
int rb_enjake2(struct COORDENADAS, char tablero[8][8]);
int rn_enjake();
int rb_enjake();
int n_total_mov_validos();
int b_total_mov_validos();
void n_jakemate();
void b_jakemate();
void n_jake();
void b_jake();
void n_reyaogado();
void b_reyaogado();
void n_promocion();
void b_promocion();
void tabla();
void guardar();
void cargar();
void cargarnuevo();
void mainchess();
void reanudarpartida1();
void reanudarpartida2();
void reanudarpartida0();
int obtencionreanudarpartida();
void MovimientoPiezas();
void Reglasespeciales();
void Comoganar();
void mueve1();
void mueve2();


