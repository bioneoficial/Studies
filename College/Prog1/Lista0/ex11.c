#include <stdio.h>

int main(void) {
  float N;
  printf("Digite um número\n");
  scanf("%f",&N);
if(N>=20 && N<=90){
printf("O número %.f está entre 20 e 90",N);
}
else {

printf("O número %.f não está entre 20 e 90",N);
}
  return 0;
}

/*Construir um programa que indique se o número digitado está compreendido entre 20 e 90 ou não. */