#include <stdio.h>

int main(void) {
  int n,soma=0;
      printf("Vem de n\n");
  scanf("%d",&n);
  soma += n;
  while(n>0){
    printf("Vem de n\n");
  scanf("%d",&n);
  if(n>0){
  soma += n;
  }
  }
  printf("Soma foi:%d\n",soma);

  return 0;
}