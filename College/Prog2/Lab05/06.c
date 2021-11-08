#include <stdio.h>

int calculo ( int a, int b);
int main(){
  int x1,x2,y1,y2;
  printf("Insira x1,x2,y1,y2 inteiros e positivos:\n");
  scanf("%d %d %d %d", &x1, &x2, &y1, &y2);
  int difX = x1 > x2 ?  x1 - x2: x2 - x1, difY = y1 > y2? y1 - y2:y2 - y1;
  printf("x1 = %d x2= %d y1= %d y2= %d difX = %d, difY= %d\n",x1,x2,y1,y2,difX,difY);

  printf("Resultado: %d", calculo(difX, difY));

  return 0;
}

int calculo ( int a, int b){
  return (( a * a) - ( b * b))/2;
}