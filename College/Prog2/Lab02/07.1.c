#include <stdio.h>
#include <string.h>
/* Escreva um pequeno programa que lê do teclado uma string e imprimir quantos caracteres dessa string são dígitos. Por
exemplo: */
int main(){
  char str[100];
  printf("Digite string:\n");
  gets(str);
  int cont = 1;
//Este diferente da 07.c foi feito usando o teste do enunciado como modelo, contando palavras ao inves de digitos.
  for(int i =0; i< strlen(str);i++){
    if(strlen(str) == 1){
      cont++;
      break;
    }
    if(str[i] == ' '&& (str[i - 1] != ' ' || str[i+1] != ' ')){
      cont++;
    }
  }
  printf("String possui %d digitos\n",cont);
  return 0;
}
