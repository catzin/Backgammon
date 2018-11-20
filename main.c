#include"back.h"
#include"jugador.h"

int main(void){

  int aux = 0;
  int aux2 = 0;
  int n = 0;
  int b = 0;
  spacio();
  Dados a;
  Bicola Tab = creaTab();
  char *j1;
  char *j2;
  list cuentas = vacia();
  ApNodo Iz;
  ApNodo De;
  ApNodo x;
  mensaje();
  mensajeR();
  spacio();
  printf("A continuación ingresen nombres de jugador:\n");
  spacio();
  printf("Nombre para jugador fichas Negras:\n");
  j1 = llenanom(j1);
  spacio();
  printf("Nombre para jugador fichas Blancas:\n");
  j2 = llenanom(j2);
  spacio();
  printf("Presiona 1 para continuar\n");
  limpiaPantalla(lee());
  cuentas = hazopB(bienvenida(),j1,j2);

  while(1){

    ImpTab(Tab);
    spacio();
    spacio();
    printf("%s ,Presiona 1 para tirar dados\n",j1);
    if(lee()==1){
      a = tiraDados();
    }
    printf("\n");
    printf("Resultado de tus dados:\n");
    impDados(a);
    spacio();
    if(checkBarraN(Iz,Tab) == 1){

      printf("*TIENES FICHAS EN BARRA*\n");
      printf("*Estás Obligado a iniciar en el pico 24*\n");
      spacio();
      printf("Ingresa numero de posiciones a mover:\n");
      sacaFichaN(lee(),Iz,De,Tab);

    }

    else{

      printf("Opciones de tiro:\n");
      if(Daops(a) == 1){
        printf("Para primera ficha:\n");
        hazmovN(Iz,De,leepico(),leepico2(),Tab);
        printf("\n");
        printf("Para segunda ficha:\n");
        hazmovN(Iz,De,leepico(),leepico2(),Tab);
      }
      else{
        printf("Para 1 ficha:\n");
        hazmovN(Iz,De,leepico(),leepico2(),Tab);
      }
      spacio();
      spacio();
      ImpTab(Tab);
      spacio();

      printf("Presiona 1 para finalizar turno\n");
      spacio();
      limpiaPantalla(lee());
    }

    ImpTab(Tab);
    spacio();
    spacio();
    printf("%s , Presiona 1 para tirar dados\n",j2);
    if(lee()==1){
      a = tiraDados();
    }
    printf("Resultado de tus dados:\n");
    printf("\n");
    impDados(a);
    spacio();

    if(checkBarraB(Iz,Tab) == 1){

      printf("*TIENES FICHAS EN BARRA*\n");
      printf("*Estás Obligado a iniciar en el pico 1*\n");
      spacio();
      printf("Ingresa numero de posiciones a mover:\n");
      sacaFichaB(lee(),Iz,De,Tab);
    }

    else{

      printf("Opciones de tiro:\n");
      spacio();
      if(Daops(a) == 1){
        spacio();
        printf("Para primera ficha:\n");
        spacio();
        hazmovB(Iz,De,leepico(),leepico2(),Tab);
        printf("\n");
        printf("Para segunda ficha:\n");
        spacio();
        hazmovB(Iz,De,leepico(),leepico2(),Tab);
      }
      else{
        printf("Para 1 ficha:\n");
        spacio();
        hazmovB(Iz,De,leepico(),leepico2(),Tab);
      }
      spacio();
      spacio();
      ImpTab(Tab);
      spacio();
      printf("Presiona 1 para finalizar turno\n");
      spacio();
      limpiaPantalla(lee());
    }

  }

return 0;
}
