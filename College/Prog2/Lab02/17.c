#include <stdio.h>
#include <time.h>

/* Carregar uma matriz A 90 X 90 de inteiros. Gerar uma matriz B, onde cada elemento corresponderá a subtração entre o
elemento de A e o valor do elemento da diagonal principal que está na referida linha. */
int main(){
  srand(time(NULL));
  int A[90][90],B[90][90],push[90] = {0}; 
  for(int i = 0; i< 90; i++){
    for(int k =0;k<90;k++){
      A[i][k] = rand() % 10;
      if(i == k){
        push[i] = A[i][k];
      };
    };
  };
   for(int i = 0; i< 90; i++){
    for(int k =0;k<90;k++){
      B[i][k] = rand() % 10;
      if(push[i] == A[i][k] && i == k){
        B[i][k] -= push[i];
      };
    };
  };
  return 0;
}