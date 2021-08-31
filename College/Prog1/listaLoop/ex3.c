#include <stdio.h>

int main(void) {
  int age,i;
  float med=0;
  for(i = 0; i<5;i++){
    scanf("%d", &age);
    med += age;
  }
  med = med / i;
  printf("Média: %.1f", med);
  return 0;
}