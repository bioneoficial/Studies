#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define MAX_STRING_SIZE 80
/* Escreva um programa que leia uma string - 80 caracteres - e imprima o total de pares de consoantes dobradas (rr e ss). */
int main(){
  srand(time(NULL));
  char string[MAX_STRING_SIZE];
  int cont = 0;
  int ASCII[80];
  for(int i = 0;i < 80;i++){
    //ASCII[i] = rand() % 123; acaba tendo mais interações por causa dos valores invalidos
    ASCII[i] = rand() % 26;
    ASCII[i] += 97;
    if(ASCII[i] < 97 || ASCII[i] > 122){
      i--;
    }else{
    string[i] = ASCII[i];
    };
  };
  for(int i= 0;i < 80;i++){
    if(string[i] == string[i+1]){
      if(string[i] == 'a'|| string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u'){
        i++;
      }else{
      cont++;
      };
    };
  }; 
  printf("Tivemos um total de %d pares de consoantes dobradas", cont);

  return 0;
}