/* Escreva uma função chamada de potencia que calcula a potência entre dois números inteiros não
negativos (base e expoente) passados como parâmetros e retorna este valor. */
#include <stdio.h>
int potencia(int base, int expoente);
int main(){
  printf("%d", potencia(5,3));
  return 0;
}
int potencia(int base, int expoente){
  int cont = 1, n = base;
  if(base < 0 || expoente < 0)
    return 0;
  if(expoente == 0)
    return 1;
  for( ;cont < expoente; cont++)
    base *= n;
  return base;
}