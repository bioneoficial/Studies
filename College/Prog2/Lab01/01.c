#include <stdio.h>

int main(){
  int m = 0, n= 0, lado1 =0, lado2 = 0, hipo = 0;
  printf("Insira valor de M e N, sendo M maior que N:\n");
  scanf("%d %d", &m, &n);
  if(m>n){
    lado1 = (m*m) - ( n * n);
    lado2 = 2 * m * n;
    hipo = (m*m) + ( n * n);
    printf("Lado1 = %d Lado2 = %d Hipo = %d",lado1,lado2,hipo);
  }
  return 0;
}