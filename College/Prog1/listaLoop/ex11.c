#include <stdio.h>

int main() {
  int n,i=0,st=0,soma=0;
  scanf("%d",&n);
    for(i=0;i<n;i++){
     if(i != 0){
    if(n % i == 0){
      st = i;
      soma += st;
    }
    }
  }
  if(soma == n){
    printf("Seu número é perfeito, meooow");
  }
  else{
    printf("As imperfeições fazem parte da vida...e do seu número :c");
  }
  return 0;
}