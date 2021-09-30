#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/* Carregue um vetor de 50 elementos inteiros e não ordenados. Leia um determinado número e pesquise se o mesmo existe no
VETOR. Caso exista, imprimir seu valor e em que posição ele está, caso contrário, exiba uma mensagem. */


int main(){
   srand(time(NULL));
  int num[50],guess;
  
    for(int i = 0; i < 50;i++){
      num[i] = rand() % 100;
    };
    printf("Digite um número positivo inteiro:\n");
    scanf("%d", &guess);
    for(int i = 0; i < 50;i++){
      if(guess == num[i]) { 
        printf("Valor: %d Index: %d.\n",num[i],i);
        break;
      };
      if(i == 49){
        printf("Valor não encontrado.\n");
      };
    };

  return 0;
}