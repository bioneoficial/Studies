#include <stdio.h>
#include <time.h>
// Faça um programa para ler cada elemento de uma matriz 140 X 40 de inteiros, calcular e imprimir a soma dos elementos
#define row 140
#define col 40
int main(){
  srand(time(NULL));
  int matriz[row][col] = {0},sum = 0 ;

   for(int i =0; i < row ; i++){
     for(int k = 0; k < col;k++){
       matriz[i][k] = rand() % 100;
     };
  };

  for(int i =0; i < row ; i++){
    for(int k = 0; k < col;k++){
       sum += matriz[i][k];
     };
  };
  printf("A soma de todos os elementos da matriz foi %d", sum);
  return 0;
}