#include <stdio.h>

int main(){
  for(int i = 0; i < 5;i++){
    printf("\nInsira 2 valores inteiros e positivos:\n");
    int a,b;
    scanf("%d %d",&a,&b);
    if(a > b){
      printf("os numeros pares entre %d e %d sao:\n",b,a);
    for(int j = b; j <= a; j++){
      if( j % 2 == 0){
        printf("%d ", j);
      };
    };
    }else if(b > a){
      printf("os numeros pares entre %d e %d sao:\n",a,b);
      for(int j = a; j <= b; j++){
      if( j % 2 == 0){
        printf("%d ", j);
      };
    };
    }else{
      a % 2 == 0 ? printf("%d e par\n",a): printf("%d nao e par\n",b);
    }
  };
  return 0;
}