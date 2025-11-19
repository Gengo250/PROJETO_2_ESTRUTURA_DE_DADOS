#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "biblioteca.h"


int main(){
  srand(time(NULL)); 
  int op;
  Arv *a = inicializaarv();
  
  do{
    printf("+--------------------------------------------------------------+\n");
    printf("| %-60s |\n","        SISTEMA DA EMPRESA ");
    printf("| %-60s |\n", "");
    printf("| %-60s |\n", " 1 - Inserir uma nova venda");
    printf("| %-60s |\n", " 2 - Listar todas as vendas");
    printf("| %-60s |\n", " 3 - Buscar as vendas de um determidado vendedor");
    printf("| %-60s |\n", " 4 - Listar vendas acima ou abaixo de um valor definido");
    printf("| %-60s |\n", " 5 - Exibir estatisticas");
    printf("| %-60s |\n", " 6 - Remocao de uma Venda");
    printf("| %-60s |\n", " 7 - Sair");
    printf("+--------------------------------------------------------------+\n");
    printf("Escolha sua opcao: ");
    scanf("%d", &op);

    switch(op){
      case 1:
        insere_arv(a);
      break;
      case 2:
        imprime_arv(a);
      break;
      case 3:
      break;
      case 4:
      break;
      case 5:
      break;
      case 6:
      case 7:
        printf("Saindo do Sistema ...");
        LiberaArvore(a);
      break;
    }
  }while(op != 7);
}