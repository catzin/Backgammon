#include"jugador.h"
#include"back.h"
#include<stdio.h>
#include"elem.h"
#include<stdlib.h>
#include<time.h>

char *llenanom(char*a){

  a = (char*)calloc(20,sizeof(char));
  scanf("%s",a);

  return a;

}

Dados tiraDados(void){

Circular x = nueva();
Circular y = nueva();

x = llenaDado();
y = llenaDado();

Dados a;
Dados *ptr = &a;

ptr -> dado1 = tiraDado1(x);
ptr -> dado2 = tiraDado2(y);

return a;

}

void impDados(Dados a){

Dados *ptr = &a;

imp_elem(ptr -> dado1);
imp_elem(ptr -> dado2);
}
