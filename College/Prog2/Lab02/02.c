/*Carregue um vetor de números reais com 80 posições e desenvolva um programa para encontrar o maior e o menor valor. Após
isto, o programa deverá trocar o maior valor com o da primeira posição e o menor valor com o da última posição. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  srand(time(NULL));
  int num[80], big = 0, indexBig =0,small = 100, indexSmall = 0;

    for(int i = 0; i < 80; i++){
    num[i] = rand() % 1000;
    if(num[i] > big){ // aqui se encontrar valores iguals não ira atualizar o index, vai considerar o 1 a achar
      big = num[i];
      indexBig = i;
    }
    if(num[i] <= small){ // Aqui atualiza o index do valor menor caso encontre um valor IGUAL, vai considerar o ultimo a achar
      small = num[i];
      indexSmall = i;
    } // fiz os 2 ifs com essas lógicas diferentes para mostrar que pode ocorrer esse tipo de evento.
  };
  printf("num[%d] = %d is the biggest one!\n",indexBig,big);
  printf("num[%d] = %d is the lesser one!\n",indexSmall,small);
  if(num[indexBig] != num[0]){
  num[indexBig] = num[0];
  num[0] = big;
  printf("%d é o novo valor do index 0\n", num[0]);
  printf(" %d é o novo valor do index %d \n",num[indexBig], indexBig);
  }else{
    printf("%d já é o valor do index 0\n", num[indexBig]);
  };
  if(num[indexSmall] != num[79]){
  num[indexSmall] = num[79];
  num[79] = small;
  printf(" %d é o novo valor do index 79 \n",num[79]);
  printf(" %d é o novo valor do index %d \n",num[indexSmall], indexSmall);
  }else{
    printf("%d já é o valor do index 7\n",num[indexSmall]);
  };
  return 0;
}