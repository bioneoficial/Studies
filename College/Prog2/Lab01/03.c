#include <stdio.h>

int main(){
  printf("Insira um valor para as polegadas:\n");
  int pol;
  float cm;
  scanf("%d", &pol);
  cm = pol * 2.54;
  printf("%d pol = %.2f cm",pol, cm);
  
  return 0;
}