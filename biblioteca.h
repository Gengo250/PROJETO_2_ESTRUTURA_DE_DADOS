#ifndef Biblioteca_Include
#define Biblioteca_Include
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no{
  Sistema sistema;
  struct no *esquerda, *direita;
}NoArv;

typedef struct {
  NoArv *raiz;
}Arv;

typedef struct Sistema{
  char Cliente[50];
  int ID;
  float valor_transacao;
  int matricula_do_vendedor;
  char Vendedor[50];
  Data data_transacao;
} Sistema;

typedef struct data{
  int dia, mes, ano;
} Data;



Sistema cadastro(){
  Sistema pessoa;
  printf("Digite o nome do Vendedor: ");
  scanf("%49[^\n]", &pessoa.Vendedor);

  printf("Digite o nome do Cliente atendido: ");
  scanf("%49[^\n]", &pessoa.Cliente);

  // fazer depois a matricula do vendedor e o ID;

  printf("Digite o valor de transição da venda: ");
  scanf("%.2f", &pessoa.valor_transacao);

}




#endif