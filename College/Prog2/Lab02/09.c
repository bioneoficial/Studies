#include <stdio.h>

int main(){
  char ENT[100],SAI[100];
  int entLength = 0, saiLength = 0;
  printf("Insira string:\n");
  gets(ENT);
while(ENT[entLength] != '\0'){
  if(ENT[entLength] != ' '){
    SAI[saiLength] = ENT[entLength];
    saiLength++;
  }
  entLength++;
};
 printf("Length of the string: %d\n", entLength);
 printf("Length of the string: %d\n", saiLength);
 printf("%s\n",SAI);
  return 0;
}

/* Escreva um programa em C que receba um texto, na string ENT, e devolva, em SAI, este mesmo texto tendo sido eliminado
todos os espaços brancos. Exiba o tamanho das strings ENT e SAI (sem utilizar a função strlen). */