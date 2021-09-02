#include <stdio.h>
#include <string.h>
//Escreva um programa que recebe uma palavra de até 50 caracteres e exibe quantas letras diferentes ela contém.
int main(){
  char str[50];
  printf("Insira string:\n");
  gets(str);
  int ascii[255] = {0}, res = 0;
  for (int i = 0; i < strlen(str); ++i) {
  ascii[str[i]] = 1;
  };
  for (int i = 0; i <= 255; ++i) {
    res += ascii[i];
  };
printf("Temos %d letras unicas", res);
  return 0;
}