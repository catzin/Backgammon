#include"back.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

Bicola creaTab(void){
  Bicola q = Nueva();
  int i = 0;
  FILE *a = fopen("inicio.txt","r");
  int nums[26];

  for(i=0;i<26;i++){

    fscanf(a,"%d",&(nums[i]));
  }

  for(i=0;i<26;i++){

    q = formarD(q,nums[i]);
  }


   return q;

 }
 void muestraR(void){

   FILE *r = fopen("reglas.txt","r");
   char c;

   while((c = fgetc(r))!= EOF){

     putchar(c);
   }
 }

 void mensaje(void){
   FILE*a = fopen("mensaje.txt","r");
   char c;

   while((c = fgetc(a))!= EOF){

     putchar(c);
   }
 }

 void mensajeR(void){
   printf("¿Conoces las reglas de Backgammon?\n");
   printf("1.SI\n");
   printf("2.NO\n");
   if(lee()!=2){
     limpiaPantalla(lee());
   }
   else{
     muestraR();
     spacio();
     printf("Presiona 1 para continuar\n");
     limpiaPantalla(lee());
   }
 }
 void ImpTab(Bicola q){

   ApNodo aux = (ApNodo)q;
   aux = q ->izq;
   int con = 0;

   while(aux!= NULL){

      imp_elem(aux -> dato);
      aux = aux -> sig;
      con++;

      if(con == 13){
        spacio();
        spacio();
      }

     }

 }

 void spacio(void){

   int i = 0;

   for(i=0;i<2;i++){
     printf("\n");
   }

 }

int bienvenida(void){
  Bicola aux = creaTab();
  int barra = 0;
  int barrab = 0;
  int ops = 0;
  spacio();
  ImpTab(aux);
  spacio();
  printf("¿QUIEREN APOSTAR?");printf("\n");
  printf("1.SI\n");
  printf("2 NO\n");
  scanf("%d",&ops);

  return ops;
}

list hazopB(int ops,char*j1,char*j2){

  list x = vacia();
  int a = 0;
  int b = 0;
  int apuesta = 0;
  int aux = 0;

  switch(ops){

    case 1:
    printf("%s,ingresa dinero a tu cuenta:\n",j1);
    scanf("%d",&a);
    printf("%s, ingresa dinero a tu cuenta:\n",j2);
    scanf("%d",&b);
    printf("Apuesta\n");
    scanf("%d",&apuesta );
    printf("Presiona 1 para finalizar deposito\n");
    scanf("%d",&aux);
    if(aux == 1){

      system("clear");
    }
    break;
    case 2:
    system("clear");
    break;
  }
  x = cons(a,cons(b,cons(apuesta,vacia())));
  return x;
}

  Circular llenaDado(void){

  Circular a = nueva();
  int i = 0;

  for(i=1;i<=6;i++){
    a = formar(a,i);

  }

  return a;
}

int vueltas1(void){

  time_t t;

  int v = 0;

  srand((unsigned)time(&t));

  v = rand() % 4000;

  return v;

}

int vueltas2(void){

  time_t t;

  int v = 0;

  srand((unsigned)time(&t));

  v = rand() % 8700;

  return v;
}

int resultD(Circular q){

  return q->sig->dato;
}

int tiraDado1(Circular q){

  int x = vueltas1();

  int i = 0;

  for(i=0;i<x%6;i++){

    q = rotar(q);

  }
  return resultD(q);
}

int tiraDado2(Circular q){

  int x = vueltas2();

  int i = 0;

  for(i=0;i<x%7;i++){

    q = rotar(q);

  }
  return resultD(q);
}

ApNodo mueve(ApNodo x ,Bicola z,int n){

  int i = 0;
  x = (ApNodo)z ->izq;

  if(n==0){

    return (x);
  }
  else{

    for(i =0;i<n;i++){

      x = x -> sig;

    }
  }
      return x;
}

int Daops(Dados z){
  Dados *ptr = &z;
  int op = 0;
  int x = 0;

  printf("1. Mover 2 fichas : %d y %d posiciones\n", ptr -> dado1,ptr -> dado2);
  printf("2. Mover 1 ficha  : %d posiciones\n", ptr -> dado2 + ptr -> dado1);

  scanf("%d",&op);
  return op;
}

int lee(void){
  int x = 0;

  scanf("%d",&x);

  return x;
}

int leepico(void){
  int picoB = 0;
  printf("Elige pico inicio\n");
  scanf("%d",&picoB);
  printf("\n");

  return picoB;
}

int leepico2(void){

  int picoB = 0;
  printf("Elige pico destino\n");
  scanf("%d",&picoB);
  printf("\n");

  return picoB;

}

void ajusta(int *n){
  switch (*n) {

    case 1: *n = 25;break;
    case 2: *n = 24;break;
    case 3: *n = 23;break;
    case 4: *n = 22;break;
    case 5: *n = 21;break;
    case 6: *n = 20;break;
    case 7: *n = 18;break;
    case 8: *n = 16;break;
    case 9: *n = 17;break;
    case 10:*n =15;break;
    case 11:*n =14;break;
    case 12:*n =13;break;
    case 13:*n = 0;break;
    case 14:*n = 1;break;
    case 15:*n = 2;break;
    case 16:*n = 3;break;
    case 17:*n = 4;break;
    case 18:*n = 5;break;
    case 19:*n = 6;break;
    case 20:*n = 7;break;
    case 21:*n = 8;break;
    case 22:*n = 10;break;
    case 23:*n = 11;break;
    case 24:*n = 12;break;

  }
}

void comeFichaN(ApNodo Iz,ApNodo De,Bicola Tab){
  ApNodo aux;

  aux = mueve(aux,Tab,6);

  aux -> dato = (aux -> dato)++;
  De -> dato = 0;
  Iz -> dato = (Iz -> dato)-1;
  De -> dato = (De -> dato)+1;

}

void comeFichaB(ApNodo Iz,ApNodo De,Bicola Tab){
  ApNodo aux;

  aux = mueve(aux,Tab,19);

  aux -> dato = (aux -> dato)--;
  De -> dato = 0;
  Iz -> dato = (Iz -> dato)+1;
  De -> dato = (De -> dato)-1;

}

void hazmovN(ApNodo Iz,ApNodo De, int pico,int n, Bicola Tab){

  Iz = (ApNodo)Tab -> izq;
  De = (ApNodo)Tab -> der;
  ApNodo aux = Iz;
  int dato = 0;
  int pico2 = 0;
  ajusta(&pico);
  ajusta(&n);

  int ver = 0;

  Iz = mueve(Iz,Tab,pico); // posiciona en pico origen
  De = mueve(De,Tab,n); // posiciona en pico destino

  if(Iz -> dato >0){

    if((De -> dato < 0)&&(De -> dato != -1) ){
      printf("Movimiento invalidado\n");
    }

    if(De -> dato == -1){

      comeFichaN(Iz,De,Tab);
    }

    else{

      Iz -> dato = Iz -> dato -1;
      De -> dato = De -> dato +1;

    }
  }
}
void hazmovB(ApNodo Iz,ApNodo De, int pico,int n, Bicola Tab){
  Iz = (ApNodo)Tab -> izq;
  De = (ApNodo)Tab -> der;
  ApNodo aux = Iz;
  int dato = 0;
  int pico2 = 0;
  ajusta(&pico);
  ajusta(&n);

  int ver = 0;

  Iz = mueve(Iz,Tab,pico); // posiciona en pico origen
  De = mueve(De,Tab,n); // posiciona en pico destino


  if(Iz -> dato < 0){

    if((Iz -> dato > 0)&&(De -> dato != 1) ){
      printf("Movimiento invalidado\n");
    }

    if(De -> dato == 1){

      comeFichaB(Iz,De,Tab);
    }

    else{

      Iz -> dato = Iz -> dato +1;
      De -> dato = De -> dato -1;

    }
  }

}

int checkBarraN(ApNodo Iz,Bicola Tab){
  ApNodo aux;
  int x = 0;
  aux = mueve(aux,Tab,19);

  if( aux -> dato >0){

    x = 1;
  }

  return x;

}


void sacaFichaN(int aux ,ApNodo Iz,ApNodo De,Bicola Tab){

  Iz = mueve(Iz,Tab,12-(aux-1));
  De = mueve(De,Tab,19);
  Iz -> dato = (Iz -> dato)+ (De -> dato);
  De -> dato = (De -> dato) - 1;

}

void sacaFichaB(int aux ,ApNodo Iz,ApNodo De,Bicola Tab){

  Iz = mueve(Iz,Tab,25-(aux-1));
  De = mueve(De,Tab,6);
  Iz -> dato = (Iz -> dato) - (De -> dato);
  De -> dato = (De -> dato) + 1;

}

int checkBarraB(ApNodo Iz,Bicola Tab){
  ApNodo aux;
  int x = 0;
  aux = mueve(aux,Tab,6);

  if( aux -> dato < 0){
    x = 1;
  }
  return x;
}

  void limpiaPantalla(int x){

    if(x == 1){
      system("clear");
    }

  }

  Bicola creaTabEspecial(void){
    Bicola q = Nueva();
    int i = 0;
    FILE *a = fopen("tab3.txt","r");
    int nums[26];

    ApNodo aux;

    for(i=0;i<26;i++){

      fscanf(a,"%d",&(nums[i]));
    }

    for(i=0;i<26;i++){

      q = formarD(q,nums[i]);
    }

     return q;

   }

   int suma15(ApNodo De, Bicola Tab){
     int i = 0 ;
     De = (ApNodo)Tab ->der;
     int suma = 0;

     for(i=0;i<6;i++){

       suma += De -> dato;

       De = De -> ant;
     }

     return  suma;
   }


   int checkDesformaB(ApNodo De, Bicola Tab){
     int i = 0 ;
     De = (ApNodo)Tab ->der;
     int suma = 0;
     int aux = 0;

     for(i=0;i<6;i++){

       suma += De -> dato;

       De = De -> ant;
     }

     if(suma == 15){

       aux = 1;

     }
     return  aux;
   }

   int checkDesformaN(ApNodo Iz, Bicola Tab){
     int i = 0 ;
     Iz = (ApNodo)Tab ->izq;
     int suma = 0;
     int aux = 0;

     for(i=1;i<8;i++){

       Iz = Iz -> sig;
     }

     for(i=0;i<5;i++){

       suma += Iz ->dato;

       Iz = Iz -> sig;
     }

     if(suma == 15){

       aux = 1;
     }

     return aux;
   }

  void TiraAdesformarN(ApNodo Iz,ApNodo De,int pico, int n,Bicola Tab){

    ajusta(&pico);
    ajusta(&n);
    Iz = mueve(Iz,Tab,pico);
    De = mueve(De,Tab,n);
    if(n > 7){

      Iz -> dato = (Iz -> dato)-1;
    }

    else{

      Iz -> dato = (Iz -> dato)+1;
    }
  }

  void TiraAdesformarB(ApNodo Iz,ApNodo De,int pico, int n,Bicola Tab){

    ajusta(&pico);
    ajusta(&n);
    Iz = mueve(Iz,Tab,pico);
    De = mueve(De,Tab,n);
    if(n > 7){

      Iz -> dato = (Iz -> dato)+1;
    }

    else{

      Iz -> dato = (Iz -> dato)-1;
    }
  }



  void juegaN(ApNodo Iz,ApNodo De,char*j1,Dados a,Bicola Tab){
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




  }


  void juegaB(ApNodo Iz,ApNodo De,char *j2,Dados a,Bicola Tab){
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
