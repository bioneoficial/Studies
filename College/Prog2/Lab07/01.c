/*  Uma empresa de manutenção de ônibus e caminhões possui um cadastro de 1000 peças de reposição em um arquivo em disco.
 Para cada peça existe uma série de informações, a saber: 
- nome da peça (40 caracteres) - código da peça (inteiro) - preço unitário (real) - quantidade de peças em estoque (inteiro) -
 código do fornecedor (inteiro) Estas informações estão armazenadas na forma de um registro. 
 Faça um programa em C que leia o arquivo de cadastro desta empresa e imprima o valor total em estoque.
*/


#include <stdio.h>
#include <string.h>

struct pecas
{  char nomePeca[40];
  int codPeca;
  double preco;
  int qtdPeca;
  int codFor;
};
#define length 2
int main(int argc, char* argv[]){
 struct pecas peca[length];
 FILE *arq_repPecas = NULL;
 char *filename = "questao01.txt";
 arq_repPecas = fopen(filename, "w");
 strcpy(peca[0].nomePeca,"Fulano");
 peca[0].codPeca  = 0;
 peca[0].preco = 1.1;
 peca[0].qtdPeca = 1;
 peca[0].codFor = 10;
strcpy(peca[1].nomePeca,"Fulano2");
 peca[1].codPeca  = 2;
 peca[1].preco = 1.2;
 peca[1].qtdPeca = 2;
 peca[1].codFor = 20;
  if (arq_repPecas == NULL) {
  printf("\nArquivo CLIENTE.TXT nao pode ser aberto.");
  printf("\nOcorreu um Erro Grave ! Use alguma tecla para finalizar !");
  getch();
  }else {
    int i = 0;
    double totalValor = 0L;
 // fwrite(peca,sizeof(struct pecas), length, arq_repPecas);
    while(i < length){
        fprintf(arq_repPecas, "Nome Peca: %s\n Código Peca: %d\n Preco Peca: R$%.2lf\n Qtd Peca: %d\n Codigo Fornecedor: %d\n\n",
        peca[i].nomePeca,peca[i].codPeca,peca[i].preco,peca[i].qtdPeca,peca[i].codFor);
    totalValor += peca[i].preco;
    i++;
      }
      fprintf(arq_repPecas,"Valor total em estoque: R$%.2lf", totalValor);
    i = 0;
    while (arq_repPecas != EOF) {
    // printf(" i = %d",i);
     // printf("\n Nome Peca: %s \n",peca[i].nomePeca);
    //  printf("\n Código Peca: %d \n",peca[i].codPeca);
    //  printf("\n Preco Peca: %lf \n",peca[i].preco);
    //  printf("\n Qtd Peca: %d \n",peca[i].qtdPeca);
     // printf("\n Codigo Fornecedor: %d \n",peca[i].codFor);
      i++;
      if(i == length)
        break;
    }
    fclose(arq_repPecas);
    arq_repPecas = NULL;
    printf("\n  FIM!");
  }
  return 0;
}