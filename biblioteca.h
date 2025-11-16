#ifndef Biblioteca_Include
#define Biblioteca_Include
#include <stdio.h>
#include <stdlib.h>

typedef struct no{
  Sistema sistema;
  struct no *esquerda, *direita;
}NoArv;

typedef struct {
  NoArv *raiz;
}ArvB;

typedef struct data{
  int dia, mes, ano;
} Data;

typedef struct Sistema{
  char Cliente[50];
  int ID;
  float valor_transacao;
  int matricula_do_vendedor;
  char Vendedor[50];
  Data data_transacao;
} Sistema;




#endif