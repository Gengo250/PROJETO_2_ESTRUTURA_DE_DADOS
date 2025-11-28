#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "biblioteca.h"


int main(){
  srand(time(NULL)); 
  int op, num, id;
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
    printf("| %-60s |\n", " 6 - Remoção de uma Venda");
    printf("| %-60s |\n", " 7 - Sair");
    printf("+--------------------------------------------------------------+\n");
    printf("\nEscolha sua opcao: ");
    scanf("%d", &op);
    printf("\n");
empty_stdin();

    switch(op){
      case 1:
        insere_arv(a);
      break;
      case 2:
        imprime_arv(a);
      break;
      case 3:
        printf("Deseja Buscar as Vendas do Vendedor pelo nome (1) ou  pela matricula(2)?\n");
        scanf("%d", &num);
        BuscarVendas(a, num);
      break;
      case 4:
        printf("Digite um  valor de transação para listar as vendas do Sistema: ");
        scanf("%d", &num);
        ListaVendas(a, num);
      break;
      case 5:
        exibirEstatisticas(a);
      break;
      case 6:
        printf("Qual venda Gostaria de remover?\n");
        printf("Digite o ID do vendedor para remover: ");
        scanf("%d", &id);
        removeVenda(a, id);
      break;
      case 7:
        printf("Saindo do Sistema ...");
        LiberaArvore(a);
      break;
      default:
        printf("\n\n Valor inválido!!!!\n\n");
      break;
    }
  }while(op != 7);
}