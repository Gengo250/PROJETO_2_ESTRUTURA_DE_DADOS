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

    struct tm *hoje;

    time_t segundos;

    time(&segundos);

    hoje = localtime(&segundos);

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
do {
  printf("Digite a data da transacao (dd mm aaaa): ");
  scanf("%d %d %d",
        &pessoa.data_transacao.dia,
        &pessoa.data_transacao.mes,
        &pessoa.data_transacao.ano);
  }while(pessoa.data_transacao.dia>31 || pessoa.data_transacao.dia <1 || pessoa.data_transacao.mes <1 || pessoa.data_transacao.mes>12 || pessoa.data_transacao.ano<1990 || pessoa.data_transacao.ano >hoje->tm_year+1900 || (pessoa.data_transacao.dia>hoje->tm_mday && pessoa.data_transacao.mes>=hoje->tm_mon+1 && pessoa.data_transacao.ano>hoje->tm_year+1900));
  
  
  
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
void BuscarVendas(Arv *a, int op);
NoArv *busca_pelo_nome(NoArv *raiz, char nome_vendedor[49]);
NoArv *busca_pela_matricula(NoArv *raiz, int matricula);
void imprime_vendas_vendedor(NoArv *raiz);
void ListaVendas(Arv *a, int valor);
void imprimeVendasMaior(NoArv *raiz, int valor);
void imprimeVendasMenor(NoArv *raiz, int valor);
void exibirEstatisticas(Arv *a);
void numeroTotalVendas(Arv *a);
int numeroVendas(NoArv *raiz);
void faturamentoTotal(Arv *a);
float faturamento(NoArv *raiz);
void removeVenda(Arv *a, int id);
NoArv *remover(NoArv *raiz, int id);
void empty_stdin (void);


void empty_stdin (void)
{
    int c = getchar();

    while (c != '\n' && c != EOF)
        c = getchar();
}


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
void BuscarVendas(Arv *a, int op)
{ do{
  switch (op)
  {
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
  default:
    printf("Valor inválido!!!\n");
  break;
  }
}while(op != 1 && op != 2);
}
NoArv *busca_pelo_nome(NoArv *raiz, char nome_vendedor[49])
{
  if (raiz == NULL)
  {
    return NULL;
  }
  if (strcmp(nome_vendedor, raiz->sistema.Vendedor) == 0)
  {
    return raiz;
  }

  NoArv *p = busca_pelo_nome(raiz->esquerda, nome_vendedor);
  if (p != NULL)
  {
    return p;
  }
  return busca_pelo_nome(raiz->direita, nome_vendedor);
}
NoArv *busca_pela_matricula(NoArv *raiz, int matricula)
{
  if (raiz == NULL)
  {
    return NULL;
  }
  if (matricula == raiz->sistema.matricula_do_vendedor)
  {
    return raiz;
  }
  NoArv *p = busca_pela_matricula(raiz->esquerda, matricula);
  if (p != NULL)
  {
    return p;
  }

  return busca_pela_matricula(raiz->direita, matricula);
}
void imprime_vendas_vendedor(NoArv *raiz)
{
  if (raiz != NULL)
  {
    printf("ID: %d | Cliente: %s | Data da Transacao: %02d/%02d/%04d | Valor($): %.2f\n",
           raiz->sistema.ID,
           raiz->sistema.Cliente,
           raiz->sistema.data_transacao.dia,
           raiz->sistema.data_transacao.mes,
           raiz->sistema.data_transacao.ano,
           raiz->sistema.valor_transacao);
  }
  else
  {
    printf("Nenhuma venda encontrada.\n");
  }
}

void ListaVendas(Arv *a, int valor)
{

  if (a == NULL || a->raiz == NULL)
  {
    printf("Sistema vazio! Erro");
  }
  int op;
  do{
     printf("Gostaria de listar vendas acima (1) ou abaixo (2) do valor inserido?\n");
     scanf("%d", &op);
  switch (op)
  {
  case 1:
    imprimeVendasMaior(a->raiz, valor);
    break;
  case 2:
    imprimeVendasMenor(a->raiz, valor);
    break;
  default:
    printf("Valor inválido!!!\n");
    break;
  }
  }while(op != 1 && op != 2);
 
}
void imprimeVendasMaior(NoArv *raiz, int valor)
{
  if (raiz != NULL)
  {

    imprimeVendasMaior(raiz->esquerda, valor);
    if (raiz->sistema.valor_transacao > valor)
    {
      printf("ID: %d | Vendedor: %s | Matrícula: %d | Cliente: %s | Data da Transacao: %02d/%02d/%04d | Valor($): %.2f\n", raiz->sistema.ID, raiz->sistema.Vendedor, raiz->sistema.matricula_do_vendedor,
             raiz->sistema.Cliente, raiz->sistema.data_transacao.dia, raiz->sistema.data_transacao.mes, raiz->sistema.data_transacao.ano,
             raiz->sistema.valor_transacao);
    }

    imprimeVendasMaior(raiz->direita, valor);
  }
}
void imprimeVendasMenor(NoArv *raiz, int valor)
{
  if (raiz != NULL)
  {

    imprimeVendasMenor(raiz->esquerda, valor);

    if (raiz->sistema.valor_transacao < valor)
    {
      printf("ID: %d | Vendedor: %s | Matrícula: %d | Cliente: %s | Data da Transacao: %02d/%02d/%04d | Valor($): %.2f\n", raiz->sistema.ID, raiz->sistema.Vendedor, raiz->sistema.matricula_do_vendedor, raiz->sistema.Cliente, raiz->sistema.data_transacao.dia,
             raiz->sistema.data_transacao.mes, raiz->sistema.data_transacao.ano, raiz->sistema.valor_transacao);
    }

    imprimeVendasMenor(raiz->direita, valor);
  }
}
void exibirEstatisticas(Arv *a)
{
  int num;
  do{
    printf("Deseja ver das estatísticas do Sistema:\n");
    printf("1 - Numero total de Vendas\n");
    printf("2 - Total de faturamento\n");
    scanf("%d", &num);
  switch (num)
  {
  case 1:
    numeroTotalVendas(a);
    break;
  case 2:
    faturamentoTotal(a);
    break;
  default:
    printf("Valor invalido!!!");
    break;
  }
  }while(num != 1 && num != 2);
  
}
void numeroTotalVendas(Arv *a)
{
  int total = numeroVendas(a->raiz);
  if (total == 0)
  {
    printf("\nNenhuma venda listada no Sistema\n");
  }
  else
  {
    printf("\nVendas Listadas no sistema: %d\n", total);
  }
}
int numeroVendas(NoArv *raiz)
{
  if (raiz == NULL)
  {
    return 0;
  }
  return 1 + numeroVendas(raiz->esquerda) + numeroVendas(raiz->direita);
}
void faturamentoTotal(Arv *a)
{
  float f = faturamento(a->raiz);
  if (f == 0)
  {
    printf("\nNenhum faturamento listado no Sistema\n");
  }
  else
  {
    printf("\nTotal de faturamento da empresa: %.2f\n", f);
  }
}
float faturamento(NoArv *raiz)
{
  float soma = 0;
  if (raiz == NULL)
  {
    return 0;
  }
  soma += raiz->sistema.valor_transacao;
  return soma + faturamento(raiz->esquerda) + faturamento(raiz->direita);
}

void removeVenda(Arv *a, int id)
{
  a->raiz = remover(a->raiz, id);
}

NoArv *remover(NoArv *raiz, int id)
{
    if (raiz == NULL)
    {
        printf("\nID %d não encontrado\n", id);
        return NULL;
    }

    if (id < raiz->sistema.ID)
    {
        raiz->esquerda = remover(raiz->esquerda, id);
        return raiz;
    }
    else 
      if (id > raiz->sistema.ID)
        {
        raiz->direita = remover(raiz->direita, id);
        return raiz;
        }

    if (raiz->esquerda == NULL && raiz->direita == NULL)
    {
        free(raiz);
        return NULL;
    }

    if (raiz->esquerda == NULL || raiz->direita == NULL)
    {
        NoArv *filho;

        if (raiz->esquerda != NULL){
          filho = raiz->esquerda;
        } 
        else{
          filho = raiz->direita;
        }
  
        free(raiz);
        return filho;
    }

    NoArv *aux = raiz->esquerda;
    while (aux->direita != NULL)
    {
        aux = aux->direita;
    }

    int id_aux = aux->sistema.ID;
    raiz->sistema = aux->sistema;
    raiz->esquerda = remover(raiz->esquerda, id_aux);

    return raiz;
}


#endif