/* Escreva uma função que calcule a soma dos números pares e a soma dos números impares de 0 até um
número inteiro n passado como parâmetro. A função deve exibir a soma dos pares e a soma dos
impares.
*/
#include <stdio.h>

void sum(int n){
  int sumOdd = 0, sumEven = 0;
  for(int i = 0; i <= n; i++){
    if(i % 2 == 0){
     sumEven += i;
    }else{
      sumOdd += i;
    }
  }
  printf("Soma dos pares = %d \t Soma dos ímpares = %d",sumEven,sumOdd);
}

int main(){
  printf("Insira um valor inteiro e positivo:\n");
  int n;
  scanf("%d", &n);
  sum(n);
  return 0;
}