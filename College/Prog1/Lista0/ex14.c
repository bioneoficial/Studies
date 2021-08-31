#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  float preco,precofinal;
  printf("Insira o preço do produto\n");
  scanf("%f",&preco);
  
if(preco<0) {
  main("pause");
}

  if(preco<500) {
precofinal = preco * 0.913 ;
printf("o preço ficou em %.f$ com um desconto de 8.7%%",precofinal);
  }
  else {
    precofinal = preco * 0.9;
    printf("o preço ficou em %.f$ com um desconto de 10%%",precofinal);
  }
  return 0;
}

/* Se o preço for menor que R$500,00, conceda um desconto de 8,7%.  Acima deste valor, conceda um desconto de 10%. */