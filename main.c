#include"back.h"
#include"jugador.h"

int main(void){

  int aux = 0;
  int n = 0;
  spacio();
  Dados a;
  Bicola Tab = creaTab();
  char *j1,*j2;
  list cuentas = vacia();
  ApNodo Iz,De,x;
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
  aux = 1;
  int aux2 = 0;

  do{
    n = tiraPrimero(j1,j2);

  }while(n==0);
  printf("Presiona 1 para continuar\n");
  limpiaPantalla(lee());

  if(n==1){
    juegaN(Iz,De,j1,a,Tab);

  }
  else{

    juegaB(Iz,De,j2,a,Tab);
  }

  while(aux != 0){

    juegaN(Iz,De,j1,a,Tab);
    juegaB(Iz,De,j2,a,Tab);

  }

return 0;
}
