#include <stdio.h>

int main(){
  printf("insira 2 numeros positivos:\n");
  int a,b,i, sum = 0;
  scanf("%d %d", &a, &b);
  if(a > b){
    printf("A soma dos numeros entre %d e %d",b,a);
    for(i = b+1; i < a;i++){
      sum += i;
    };
  }else if(b > a){
    printf("A soma dos numeros entre %d e %d",a,b);
    for(i = a+1; i < b;i++){
      sum += i;
    };
  }else{
    sum = 0;
printf("A soma dos numeros entre %d e %d foi: %d",a,b,sum);
return 0;
  };
  printf(" foi %d", sum);



  return 0;
}