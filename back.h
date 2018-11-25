#include "jugador.h"
#include "bicola.h"
#include "circular.h"
#include "lista.h"

Bicola creaTab(void);
Bicola creaTabEspecial(void);
void mensajeR(void);
void muestraR(void);
void mensaje(void);
void limpiaPantalla(int);
void spacio(void);
int lee(void);
int leepico(void);
int leepico2(void);
void ImpTab(Bicola);
int vueltas1(void);
int vueltas2(void);
int resultD(Circular);
int tiraDado1(Circular);
int tiraDado2(Circular);
Circular llenaDado(void);
ApNodo mueve(ApNodo,Bicola,int);
void ajusta(int*);
ApNodo mueve2(ApNodo,Bicola,int);
int Daops(Dados);
void hazmovN(ApNodo,ApNodo,int,int,Bicola);
void hazmovB(ApNodo,ApNodo,int,int, Bicola);
void comeFichaN(ApNodo,ApNodo,Bicola);
void comeFichaB(ApNodo,ApNodo,Bicola);
int checkBarraN(ApNodo,Bicola);
int checkBarraB(ApNodo,Bicola);
void sacaFichaN(int,ApNodo,ApNodo,Bicola);
void sacaFichaB(int,ApNodo,ApNodo,Bicola);
int verifica(ApNodo,ApNodo,Bicola);
void hazVerifica(int,ApNodo,ApNodo,Bicola);
int suma15(ApNodo, Bicola);
int checkDesformaN(ApNodo, Bicola);
int checkDesformaB(ApNodo, Bicola);
void juegaN(ApNodo,ApNodo,char*,Dados,Bicola);
void juegaB(ApNodo,ApNodo,char*,Dados,Bicola);
void TiraAdesformarN(ApNodo,ApNodo,int,int,Bicola);
void TiraAdesformarB(ApNodo,ApNodo,int,int,Bicola);
int bienvenida(void);
list hazopB(int,char*,char*);
