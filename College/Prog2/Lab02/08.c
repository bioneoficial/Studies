#include <stdio.h>
#include <string.h>
// Carregar uma frase de até 1000 caracteres e trocar todas as possíveis ocorrências da letra n antes das letras p ou b pela letra m.
int main(){
char str[1000];
printf("Lança a braba aí:\n");
gets(str);
int strLength =  strlen(str), ascii = 0;
for(int i = 0; i < strLength;i++){
  ascii = str[i];
  if(ascii == 78 || ascii == 110){
    ascii = str[i+1];
    if(ascii ==66 || ascii ==98 || ascii == 80|| ascii == 112){
      str[i] = 109;
      printf("%c\t",str[i]);
    };
  };
};
  return 0;
}