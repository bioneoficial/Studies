/* Faça um programa completo que utilize a função criada em (3) */

#include <stdio.h>
int potencia(int base, int expoente);
int main(){
  int base,expoente;
    printf("Insira base e expoente para potencia:\n");
    scanf("%d %d", &base, &expoente);
  printf("\nResultado = %d", potencia(base,expoente));
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

// questão duplicada????