#include"elem.h"

#ifndef circular
#define circular

typedef struct nodo{

  int dato;
  struct nodo*sig;

}*Circular;

Circular nueva(void);
int es_nueva(Circular);
Circular formar(Circular ,elem);
elem primero(Circular);
Circular desformar(Circular);
Circular rotar(Circular);

#endif
