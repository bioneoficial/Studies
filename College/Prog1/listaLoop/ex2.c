#include <stdio.h>

int main(void) {
  int preco,qtd, gastoT=0;
  printf("digite, numericamente, o preço do produto e a quantidade do mesmo separados por um espaço, Ex: '10 5'\n");

  for(int i=0;i<5;i++){
    scanf("%d %d", &preco, &qtd);
    gastoT =gastoT + preco * qtd;
  }
  printf("Gasto: %d",gastoT);
  return 0;
}