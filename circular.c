#include<stdio.h>
#include<stdlib.h>
#include"circular.h"
#include"elem.h"

Circular nueva(void){

  return NULL;

}

int es_nueva(Circular q){

  return q == NULL;

}


Circular formar(Circular q ,elem e){

  Circular t = (Circular)malloc(sizeof(struct nodo));

  t -> dato = e;

  if(es_nueva(q)){

    q = t;
    q -> sig = q;

  }

  else{

    t -> sig = q -> sig;
     q->sig =  t;

  }
  return t;
}

elem primero(Circular q){

  return q -> sig -> dato;
}

Circular desformar(Circular q){

  Circular t;

    t = (Circular)malloc(sizeof(struct nodo));

      if(q == q->sig){

          return nueva();

          }

     else{

            t = q->sig;
            q -> sig = q->sig->sig;


            free(t);

            return q;

          }
  }


Circular rotar(Circular q){

  return q->sig;
}
