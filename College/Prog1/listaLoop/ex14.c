#include <stdio.h>

int main(void) {
  int n,maior,menor,i=0;
  char op;
  do{
    printf("numero:\n");
    scanf("%d",&n);
    if(i==0){
    maior = n;
    menor = n;
    i++;
    }
    if(maior<n){
      maior = n;
    }
    if(menor>n){
      menor = n;
    }
    printf("Keep going? 's' para sim 'n' para nao\n");
    scanf("  %c", &op);
  }while(op == 's' || op == 'S');
  printf("maior:%d\n",maior);
  printf("menor:%d\n",menor);
  return 0;
}