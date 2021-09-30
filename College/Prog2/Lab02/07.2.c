#include <stdio.h>
#include <string.h>
/* Escreva um pequeno programa que lê do teclado uma string e imprimir quantos caracteres dessa string são dígitos. Por
exemplo: */
int main(){
  char str[100];
  printf("Digite string:\n");
  gets(str);
 // FIZ ESSA BASEADA EM DIGITOS(NUMEROS) E NA 7.1 BASEADO NO INPUT/OUTPUT DO PDF. 48 a 57 

  int length = strlen(str);
 int cont = 0, ascii = 0;
for(int i = 0; i < length; i++){
ascii = str[i];
  if(ascii >= 48 && ascii <= 57){
    cont++;
  };
};
  printf("String possui %d dígitos\n",cont);
  return 0;
}
