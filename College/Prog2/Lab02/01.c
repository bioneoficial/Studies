/* Carregue um vetor de inteiros com 100 posições e desenvolva um programa para:

a) Exibir o maior elemento e sua posição;
b) Imprimir a soma dos elementos que estão nos índices pares;
c) Exiba a soma dos elementos impares.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
  srand(time(NULL));
  int num[100];
int sumEven = 0, big = 0,sumOdd = 0, index = 0;
  for(int i = 0; i < 100; i++){
    num[i] = rand() % 10000;
    if(num[i] > big){
      big = num[i];
      index = i;
    }
  };
    printf("num[%d] = %d is the biggest one!\n",index,big);
  for(int i = 0; i < 100; i++){
    if(num[i] % 2 == 0){
      sumEven += num[i];
    };
  };
  printf("Sum of the Even Numbers is: %d.\n", sumEven); 
  for(int i = 0; i < 100; i++){
    if(num[i] % 2 != 0){
      sumOdd += num[i];
    };
  };
    printf("Sum of the odds numbers is: %d.\n", sumOdd);
  return 0;
}