#ifndef biblioteca
#define biblioteca
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> 

typedef struct data
{
  int dia, mes, ano;
} Data;
typedef struct Sistema
{
  char Cliente[50];
  int ID;
  float valor_transacao;
  int matricula_do_vendedor;
  char Vendedor[50];
  Data data_transacao;
} Sistema;

typedef struct no
{
  Sistema sistema;
  struct no *esquerda, *direita;
} NoArv;

typedef struct arv
{
  NoArv *raiz;
} Arv;

Sistema cadastro()
{
  Sistema pessoa;

  printf("Digite o nome do Vendedor: ");
  scanf(" %49s", pessoa.Vendedor);

  printf("Digite o nome do Cliente atendido: ");
  scanf(" %49s", pessoa.Cliente);

  printf("Digite o valor de transicao da venda: ");
  scanf("%f", &pessoa.valor_transacao);

  pessoa.ID = 1000 + rand() % 9000;
  printf("ID da venda gerado: %d\n", pessoa.ID);

  pessoa.matricula_do_vendedor = 100 + rand() % 900;

  printf("Matrícula do vendedor: V%d\n", pessoa.matricula_do_vendedor);

  printf("Digite a data da transacao (dd mm aaaa): ");
  scanf("%d %d %d",
        &pessoa.data_transacao.dia,
        &pessoa.data_transacao.mes,
        &pessoa.data_transacao.ano);

  return pessoa;
}

Arv *inicializaarv();
void removerArvoreNo(NoArv *raiz);
void LiberaArvore(Arv *a);
NoArv *aux_insere(NoArv *no, Sistema s);
void insere_arv(Arv *a);
void imprime_sistema(NoArv *aux);
void imprime_arv(Arv *a);
void imprime_sistema(NoArv *aux);
void BuscarVendas(Arv *a,int op);
NoArv *busca_pelo_nome(NoArv *raiz, char nome_vendedor[49]);
NoArv *busca_pela_matricula(NoArv *raiz, int matricula);
void imprime_vendas_vendedor(NoArv *raiz);


Arv *inicializaarv()
{
  Arv *a = (Arv *)malloc(sizeof(Arv));
  if (a == NULL)
  {
    printf("Erro de memoria\n");
    return a;
  }
  a->raiz = NULL;
  return a;
}

void removerArvoreNo(NoArv *raiz)
{
  if (raiz != NULL)
  {
    removerArvoreNo(raiz->esquerda);
    removerArvoreNo(raiz->direita);
    free(raiz);
  }
}
void LiberaArvore(Arv *a)
{
  if (a == NULL)
  {
    printf("Erro!\n");
  }
  else if (a->raiz == NULL)
  {
    printf("\nArvore vazia\n");
  }
  else
  {
    removerArvoreNo(a->raiz);
    a->raiz = NULL;
    printf("\nArvore removida e liberada\n");
  }
}

NoArv *aux_insere(NoArv *no, Sistema s)
{
  int flag;
  NoArv *pai;
  NoArv *novo = (NoArv *)malloc(sizeof(NoArv));
  novo->sistema = s;
  novo->direita = NULL;
  novo->esquerda = NULL;
  if (no == NULL)
  {
    return novo;
  }
  else
  {
    pai = no;
    flag = 0;
    while (flag == 0)
    {

      if (s.ID < pai->sistema.ID)
      {
        if (pai->esquerda == NULL)
        {
          pai->esquerda = novo;
          flag = 1;
        }
        else
        {
          pai = pai->esquerda;
        }
      }
      else
      {
        if (s.ID > pai->sistema.ID)
        {
          if (pai->direita == NULL)
          {
            pai->direita = novo;
            flag = 1;
          }
          else
          {
            pai = pai->direita;
          }
        }
        else
        {
          printf("ID %d ja existe. Cadratro cancelado.\n", s.ID);
          free(novo);
          flag = 1;
        }
      }
    }
  }
  return no;
}

void insere_arv(Arv *a)
{
  Sistema sis = cadastro();
  a->raiz = aux_insere(a->raiz, sis);
}


void imprime_arv(Arv *a)
{
  imprime_sistema(a->raiz);
}
void imprime_sistema(NoArv *aux)
{
  if (aux != NULL)
  {

    imprime_sistema(aux->esquerda);

    printf("ID: %d | Vendedor: %s | Matrícula: V%d | Cliente: %s | Data da Transacao: %02d/%02d/%04d | Valor($): %.2f\n",
           aux->sistema.ID,
           aux->sistema.Vendedor,
           aux->sistema.matricula_do_vendedor,
           aux->sistema.Cliente,
           aux->sistema.data_transacao.dia,
           aux->sistema.data_transacao.mes,
           aux->sistema.data_transacao.ano,
           aux->sistema.valor_transacao);

    imprime_sistema(aux->direita);
  }
}
void BuscarVendas(Arv *a, int op){
  switch(op){
    case 1:
      NoArv *aux = NULL;
      char nome[49];
      printf("Nome do Vendedor: ");
      scanf("%49s", nome);
      aux = busca_pelo_nome(a->raiz, nome);
      imprime_vendas_vendedor(aux);
    break;
    case 2:
      NoArv *aux2 = NULL;
      int matricula;
      printf("Digite a matricula do Vendedor: ");
      scanf("%d", &matricula);
      aux2 = busca_pela_matricula(a->raiz, matricula);
      imprime_vendas_vendedor(aux2);
    break;
  }
}
NoArv *busca_pelo_nome(NoArv *raiz, char nome_vendedor[49]){
  if(raiz == NULL){
    return NULL;
  }
  if(strcmp(nome_vendedor, raiz->sistema.Vendedor) == 0){
    return raiz;
  }

  NoArv *p = busca_pelo_nome(raiz->esquerda, nome_vendedor);
    if (p != NULL) {
        return p;
    }
    return busca_pelo_nome(raiz->direita, nome_vendedor);
}
NoArv *busca_pela_matricula(NoArv *raiz, int matricula){
  if(raiz == NULL){
    return NULL;
  }
  if(matricula == raiz->sistema.matricula_do_vendedor){
    return raiz;
  }
  NoArv *p = busca_pela_matricula(raiz->esquerda, matricula);
    if (p != NULL) {
        return p;
    }

    return busca_pela_matricula(raiz->direita, matricula);
}
void imprime_vendas_vendedor(NoArv *raiz){
  if(raiz != NULL){
     printf("ID: %d | Cliente: %s | Data da Transacao: %02d/%02d/%04d | Valor($): %.2f\n"
            , raiz->sistema.ID, raiz->sistema.Cliente, raiz->sistema.data_transacao
            , raiz->sistema.valor_transacao);
  } else {
    printf("Nenhuma venda encontrada.\n");
  }
  
}

#endif