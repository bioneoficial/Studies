#include <stdio.h>
#include <string.h>
/* Escreva um pequeno programa que lê do teclado uma string e imprimir quantos caracteres dessa string são dígitos. Por
exemplo: */
int main(){
  char str[100];
  printf("Digite string:\n");
  gets(str);
 // scanf("%[^\n]%*c", str);
 //fgets(str, 100, stdin);
  int length = strlen(str);
 int cont = 0, ascii = 0;
for(int i = 0; i < length; i++){
ascii = str[i];
  if(ascii >= 65 && ascii <= 90 ||  ascii >= 97 && ascii <= 122){
    cont++;
  };
};
  printf("String possui %d dígitos\n",cont);
  return 0;
}
