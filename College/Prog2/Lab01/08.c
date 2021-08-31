#include <stdio.h>

int main(){
  int idade, sum = 0, cont = 0;
  float med;
  while(1){
  printf("insira uma idade:\n");
  scanf("%d", &idade);
  if(idade == 0){
    break;
  }
    sum += idade;
    cont++;
  };
  med = (float)sum / cont;
  printf("A media de idade e %.2f\n",med);
  return 0;
}