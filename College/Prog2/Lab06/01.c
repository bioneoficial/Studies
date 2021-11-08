#include <stdio.h>
struct produto
{ int codigo;
char descricao[30];
float preco;
};
#define QTD  2 // mudar para 50, deixei 2 pra facilitar teste
int main(){
  struct produto produtos[QTD];
  for (int i = 0; i < QTD; i++)
  {
    printf("Insira o codigo do produto %d:\n", i);
    scanf("%d", &produtos[i].codigo);
     printf("Insira o preco do produto %d:\n", i);
    scanf("%f", &produtos[i].preco);
     printf("Insira a descricao do produto %d:\n", i);
    scanf("%s",&produtos[i].descricao);
    printf("Código: %d\n",produtos[i].codigo);
      printf("Preço: %.2f\n",produtos[i].preco);
    printf(" Descricao do produto: %s\n", produtos[i].descricao);
    //puts(produtos[i].descricao);
  }
  for(int i = 0; i < QTD; i++){
    printf("Deseja reajustar o preço do produto %d? 'S' ou 'N'\n ",i);
    char op;
    scanf(" %c", &op);
    if(op == 'S'){
      int percent;
       printf("Insira o porcentual para alterar o preço do produto %d:\n", i);
      scanf("%d", &percent);
      printf("deseja aumentar ou diminuir essa porcentagem? '+' para aumentar '-' para diminuir\n");
      scanf(" %c", &op);
      printf("Preço antes do reajuste: %.2f\n",produtos[i].preco);
      if(op == '+'){
        produtos[i].preco = produtos[i].preco + ((produtos[i].preco * percent) / 100);
      }else if(op == '-'){
        produtos[i].preco = produtos[i].preco - ((produtos[i].preco * percent) / 100);
      }
      printf("Preço depois do reajuste: %.2f\n",produtos[i].preco);
    }
  }
  return 0;
}

/* a) Declarar um vetor que armazene os 50 diferentes produtos com o lay-out da estrutura;
b) Cadastrar os produtos
c) Reajustar os preços, conforme percentual informado pelo usuário;
d) Exibir a estrutura antes e depois do reajuste. */