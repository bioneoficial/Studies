#include <stdio.h>
#include <math.h>

int main(){
  printf("Insira os valores de A, B, C:\n");
  int a, b, c;
  scanf("%d %d %d",&a, &b, &c);
  int delta,x1, x2;
  delta = (b * b) - (4 * a * c);
  if(delta > 0 || delta == 0){
   x1 = (-b + sqrt(delta)) / (2*a);
   x2 =(-b - sqrt(delta)) / (2*a);
   printf("a = %d b= %d c= %d delta = %d x1 = %d x2= %d",a,b,c,delta,x1,x2);
  }else if(delta < 0){
    printf("Ñ possui raízes reais");
  };
  return 0;
}