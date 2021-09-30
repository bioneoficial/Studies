#include <stdio.h>

int main(){
  int a,b,c;
  printf("insira 3 valores: \n");
  scanf("%d %d %d",&a,&b,&c);
  if(a>b && a>c){
     b > c ? printf("a= %d b= %d c= %d", a,b,c):printf("a= %d c= %d b= %d", a,c,b);
     }else if(b > a && b > c){
         a > c? printf("b= %d a= %d c= %d", b,a,c):printf("b= %d c= %d a= %d", b,c,a);
     }else if(c > a && c > b){
       a>b ? printf("c= %d a= %d b= %d", c,a,b): printf("c= %d b= %d a= %d", c,b,a);
     };
     return 0;
} 