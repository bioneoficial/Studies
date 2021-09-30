#include <stdio.h>

int desenho(int a, int b, char op);
int main(){
  char op = 'c';
  int a,b;
  printf("De valor de A e B:\n");
  scanf("%d %d",&a,&b);
  printf("%d 'c' foram printados\n", desenho(a,b,op));
  return 0;
}
int desenho(int a, int b, char op){
  int cont = 0,rei = 0;
  for(int i =0;i<a;i++){
    i != 0 && i != a-1 ? printf("c"):rei++;
    for(int j=0;j<b;j++){
      i == 0 ? printf("c"):i == a-1 ? printf("c"):j == b-2 ? printf("c"):printf(" ");
    };
    printf("\n");
  };
  cont = (a *2) + ((b - 2) * 2);
  return cont;
}
/* Elabore uma função que receba 2 números inteiros a e b e um caracter
c. A função deve imprimir uma "moldura" de tamanho a x b, feita usando um
caracter c e devolver o número de caracteres impressos. O programa deve
executar a função e imprimir seu valor de retorno. 5x5 = 16c 4x4 = 12c  6x6 =20c*/