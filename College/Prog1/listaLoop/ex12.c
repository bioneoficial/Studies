#include <stdio.h>

int main(void) {
  printf("idade de 100 'cabeça':\n");
  int idade,i,cont=0;
  float percent,soma=0;

  for(i=0;i<100;i++){
    scanf("%d", &idade);
    soma += idade;
    if(idade>21 && idade<65){
      cont++;
    }
  }

  percent = cont*100/i;
  soma = soma/i;
  
  printf("média=%.2f\n",soma);
  printf("a %% é=%.1f %%",percent);

  return 0;
}