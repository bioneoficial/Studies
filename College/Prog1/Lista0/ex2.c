#include <stdio.h>

int main(void) {
  float a,b,soma,produto;
  int resto;
  printf("Digite 1 número \n");
  scanf("%f",&a);
  printf("Digite outro número \n");
   scanf("%f",&b);
soma = a+b;
produto = a *(b*b);
resto = (int)a % (int)b;
printf("A soma dos 2 números é %.f\nO produto  do primeiro número pelo quadrado do segundo é %.f\no resto da divisao do primeiro número pelo segundo é %d",soma,produto,resto);
  return 0;
}