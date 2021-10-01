#include <stdio.h>

float fatorial(int n);
int main(){
  int num;

  printf("Digite 1 numero positivo:\n");
  scanf("%d",&num);

  printf("%d! = %.lf",num,fatorial(num));
  return 0;
}
float fatorial(int num){
  float resp;
  if ( num <= 1 )
    return 1;
  else{
    resp = num * fatorial(num-1);
    return (resp);
  }
}