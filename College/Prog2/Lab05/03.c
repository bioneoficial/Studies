/* Faça um programa completo que utilize a função potencia. O programa deve ler a base e o expoente
e imprimir o resultado. */

#include <stdio.h>
int potencia(int base, int expoente);
int main(){
  int base,expoente;
    printf("Insira base e expoente:\n");
    scanf("%d %d", &base, &expoente);
  printf("%d", potencia(base,expoente));
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