#include <stdio.h>
#include <string.h>
//VOLTAR
/* Escreva um programa que recebe um texto e imprime o mesmo texto, duplicando cada uma das letras deste texto. Exemplo:

texto recebido: INSTITUTO DE INFORMATICA
texto devolvido: IINNSSTTIITTUUTTOO DDEE IINNFFOORRMMAATTIICCAA */
int main(){
  char str[30],newstr[70],teste;
  int k = 0;

  printf("Insira string max 30 caracteres:\n");
  gets(str);
  int c =  strlen(str);
  if(c == 1){
    newstr[0] = str[0];
    newstr[1] = str[0];
    newstr[2] = NULL;
  }else{
  for(int i=0;i < (strlen(str) * 2);i = i + 2){
   if(k > strlen(str)){break;}
    if(i==0){
    newstr[i] = str[i];
    newstr[i+1] = str[i];
    }else{
      newstr[i] = str[k];
      newstr[i+1] = str[k];
    }
    k++;
  }
  }
   puts(newstr);
  

 
  return 0;
}
//VOLTAR