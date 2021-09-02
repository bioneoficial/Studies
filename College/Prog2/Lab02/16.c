#include <stdio.h>
#include <time.h>

/* Carregar duas matrizes A e B de tamanho 50 X 50, de números reais, desenvolva um programa que gere uma MATRIZ C,
resultante da soma das matrizes A e B. */
int main(){
  int A[50][50],B[50][50],C[50][50];
  srand(time(NULL));
  for(int i = 0; i< 50; i++){
    for(int k =0;k<50;k++){
      A[i][k] = rand() % 10;
      B[i][k] = rand() % 10;
    };
  };
  for(int i = 0; i< 50; i++){
    for(int k =0;k<50;k++){
      C[i][k] = A[i][k] + B[i][k];
    };
  };
  return 0;
}