#include <stdio.h>

int main(){
  printf("1 - some dois numeros, 2- raiz quadrada de um numero\n");
  short int op,a,b;
  scanf("%hd", &op);
  
  switch (op)
  {
  case 1:
  printf("insira 2 numeros:\n");
  scanf("%hd %hd",&a,&b);
  printf("a= %d b= %d\n",a,b);
    printf("A soma e: %d", a + b);
    break;
  
  case 2:
    printf("insira 1 numero:\n");
    scanf("%hd",&a);
    printf("a raiz quadrada de %d = %d",a, a * a);
  break;

  default:
  printf("Opção inválida");
    break;
  };
  return 0;
}