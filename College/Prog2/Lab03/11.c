#include <stdlib.h>
#include <time.h>
#include <stdio.h>
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
int troca( int vetor[], int index){
  int temp = 0;
  qsort (vetor, index, sizeof(int), compare);
  temp = vetor[0];
  vetor[0] = vetor[index-1];
  vetor[index-1] = temp;
  return vetor;
}
int main(){
  srand(time(NULL));
  int vetor[80];
  for(int i = 0; i<80; i++){
    vetor[i] = (rand() % 100) + 1;
  }
   vetor[80] = troca(vetor,80);
  return 0;
}
/* Faça um procedimento que carregue um vetor com 80 posições e encontre
o maior e menor valor. Após isto, o procedimento deverá trocar o maior
valor com a primeira posição e o menor valor com a última posição. */