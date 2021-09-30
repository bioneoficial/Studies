#include <stdio.h>

int potenciaInt(int base, int expoente);
int main(){
  printf("insira valor base e valor expoente:\n");
  int base,expoente;
  scanf("%d %d",&base,&expoente);
  printf("%d é o valor final\n", potenciaInt(base,expoente));
  return 0;
}

int potenciaInt(int base, int expoente){
  int i = 1,res = base;
  if(expoente > 1){
    while(i < expoente){
      res = res * base;
      i++;
    }
  }
  return res ;
}
/* Escreva uma função potenciaInt(base, expoente) que retorne o valor de
baseexpoente. Não use nenhuma das funções da biblioteca matemática. */