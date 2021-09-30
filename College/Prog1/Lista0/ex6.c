#include <stdio.h>
#include <stdlib.h>

int main() {

  int a,s,m,h;

  printf("Digite o valor em segundos:\n");
  scanf("%d",&a);
  if(a >= 0){
    h = a / 3600;
    m = (a % 3600) / 60;
    s = a % 60;

    printf("\n%d Segundos são %d Hora(s) %d Minuto(s) e %d Segundo(s).",a, h, m, s);
    
  return 0;
}else{
  main("pause");
}
}