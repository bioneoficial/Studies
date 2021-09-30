#include <stdio.h>

int fat(int a){
  int  fato = a - 1;
  while(fato > 0){
      a *= fato;
      fato--;
  }
  return a;
}

int main(){
  printf("De um valor inteiro e positivo:\n");
  int num;
  scanf("%d",&num);
  printf("%d", fat(num));
return 0;
}

/*
Faça uma função que receba um valor inteiro e positivo, calcule e
retorne o seu fatorial. Construa um programa que utilize essa função. */