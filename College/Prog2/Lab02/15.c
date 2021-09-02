#include <stdio.h>
#include <time.h>

// Carregar uma matriz 10 X 10, de inteiros, ordenados e sem repetição, desenvolva um programa que verifique se um determinado
//número dado existe na matriz, caso não exista emitir mensagem correspondente.
int main(){
  srand(time(NULL));
  int matriz[10][10], flag = 0;
  for(int i =0; i < 10 ; i++){
     for(int k = 0; k < 10;k++){
       matriz[i][k] = rand() % 100;
     }
  }
     printf("Insert a positive integer(number):\n");
     int guess = 0;
     scanf("%d", &guess);

    for(int i =0; i < 10 ; i++){
      for(int k = 0; k < 10;k++){
          if(guess == matriz[i][k]){
          flag++;
          printf("O número %d existe na matriz[%d][%d]!\n",matriz[i][k],i,k);
          }
      }
    }
     if(flag == 0){
       printf("The number %d does not exist in our variable!\n",guess);
     } 
  return 0;
}