#include <stdio.h>

int fatorial(int n){
 float resp;
  if ( n <= 1 )
    return 1;
  else{
    resp = n * fatorial(n-1);
    return (resp);
  }
}

int main(){
  printf("A) %d\n", fatorial(5));
  int n,k;
  printf("Insira valor para n e k:\n");
  scanf("%d %d", &n, &k);
  float final = fatorial(n) / fatorial((n-k));
  printf("B) %.2f",final);
  return 0;
}

/* Usando a função fatorial do item (a), escreva um programa que capture via teclado dois números
inteiros, representando n e k, e imprima o valor do número total de arranjos, An,k. Pode-se
assumir que o usuário sempre fornecerá valores válidos. */