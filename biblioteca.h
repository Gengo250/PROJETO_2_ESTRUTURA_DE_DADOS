#ifndef biblioteca
#define biblioteca
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

typedef struct no{
  Sistema sistema;
  struct no *esquerda, *direita;
}NoArv;

typedef struct arv{
  NoArv *raiz;
}Arv;



Sistema cadastro() {
    Sistema pessoa;

    printf("Digite o nome do Vendedor: ");
    scanf("%49s", pessoa.Vendedor);     // sem &

    printf("Digite o nome do Cliente atendido: ");
    scanf("%49s", pessoa.Cliente);      // sem &

    printf("Digite o valor de transicao da venda: ");
    scanf("%f", &pessoa.valor_transacao);  // "%f" em scanf

    printf("Digite o ID da venda: ");
    scanf("%d", &pessoa.ID);

    return pessoa;   
}


Arv *inicializaarv(Arv*a){
      a = (Arv*) malloc(sizeof(Arv));  
    if (a == NULL) {
       printf("Erro de memoria\n"); 
      return a;
    }
    else{
    a->raiz = NULL;
    return a;
    }
}

NoArv* aux_insere(NoArv *no, Sistema s){
  int flag;
  NoArv *pai;
  NoArv *novo=(NoArv*)malloc(sizeof(NoArv));
  novo->sistema=s;
  novo->direita=NULL;
  novo->esquerda=NULL;
  if(no==NULL){
    return novo;
  }
  else{
    pai=no;
    flag=0;
    while(flag==0){
      if(pai->sistema.ID<s.ID){

        if(pai->direita==NULL){
          pai->direita = novo;
          flag=1;

        }
        else
        {
          pai=pai->direita;
        }

      }
      else{
        if(pai->sistema.ID>s.ID){
            if(pai->esquerda==NULL){
              pai->esquerda = novo;
              flag=1;
            }
            else{
              pai=pai->esquerda;
            }



        }

      }
    }
  }
  return no;
}



void insere_arv(Arv *a){
  Sistema sis = cadastro();
a->raiz=aux_insere(a->raiz, sis);

}



#endif