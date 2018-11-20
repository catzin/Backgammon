
#ifndef jugador
#define jugador

typedef struct d{

  int dado1;
  int dado2;
}Dados;
Dados tiraDados(void);
char *llenanom(char*a);
void impDados(Dados);

#endif
