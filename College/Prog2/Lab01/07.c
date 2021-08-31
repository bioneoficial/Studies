#include <stdio.h>

int main(){
  int soma = 0;
  for( int i =  0; i<=50; i += 2){    
    if(i % 2 == 0){
      soma += i;
    }
  };
  printf("A soma dos pares de 0 a 50 foi %d", soma);
  return 0;
}