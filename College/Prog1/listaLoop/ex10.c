#include <stdio.h>

int main() {
  int n,prev,actual,next,cont; 
  printf("Digite um numero n: ");
  scanf("%d", &n);
  
  prev   = 0;
  actual = 1;
  cont = 1;
  
  while (cont < n) {
    next  = actual + prev;  /* proximo numero de Fibonacci */
    prev   = actual;
    actual = next;
    cont = cont + 1;
  }
  printf("Finobacci = %d\n", actual);
  
  return 0;
}
