#include <stdio.h>

int main(void) {
  printf("digite um valor inteiro\n");
  int a,b=0,c=0;
  while(1){
  scanf("%d",&a);
   if(a<=0){
    break;
  }
b += a;
c++; 
}
a = b/c;
printf("média %d",a);

  return 0;
}