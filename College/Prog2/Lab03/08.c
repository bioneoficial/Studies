#include <stdio.h>

int omega(int n);
void prime(int n);
int main(){
  printf("de um valor inteiro e positivo\n:");
  int num;
  scanf("%d", &num);
  printf("%d", omega(num));
  printf("\nOs numeros primos são:\n");
  for(int i=1;i<100;i++){
    prime(i);
  }
  return 0;
}
int omega(int n){
  int cont = 1, res = 0;
  while(cont < n){
    if(n % cont == 0){
      res += cont;
    }
    cont++;
  }
    return res;
}
void prime(int n){
  int cont = 1, res = 0;
  while(cont <= n){
    if(n % cont == 0){
      res++;
    }
    cont++;
  }
  if(res == 2){
    //return n;
    printf("%d\t",n);
  }
}
//separei em 2 funções

/* Escreva uma função omega(n:integer):integer que retorne a soma dos
divisores de n exceto ele próprio. Exemplo: omega(15) = 1+3+5 = 9
Usando a função omega solicitada acima, escreva um programa que imprima
todos os números primos entre 2 e 10000.*/