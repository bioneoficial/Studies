#include <stdio.h>

int main(void) {
  int num,cont=0;
  for(int i = 0; i < 100; i++){
    scanf("%d", &num);
    if(num < 0){
      cont++;
    }
  }
  printf("%d num neg",cont);
  return 0;
}