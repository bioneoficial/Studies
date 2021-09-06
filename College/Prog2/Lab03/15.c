#include <stdio.h>
int dividir(int dividendo, int divisor, int resto){
  int res;
resto = dividendo % divisor;
res = dividendo / divisor;
return printf("A divisão de %d por %d resulta em %d com resto %d",dividendo,divisor,res,resto);
}
int main(){
  printf("De valor para dividendo e divisor:\n");
  int n1,n2,resto;
  scanf("%d %d",&n1,&n2);
  dividir(n1,n2,resto);
  return 0;
}
/* Escreva uma função divisão, que retorne a divisão inteira de dividendo
por divisor e armazena no parâmetro resto, passado por referência o resto
da divisão. Construa um programa utilizando esta função. */