#include <stdio.h>

int main(void) {
 int temp,i,cont;
 float med=0;;
 for(i=0;i<365;i++){
  scanf("%d",&temp);
  if(temp>27){
    cont++;
  }
  med += temp;
 }
 printf("Média %.1f\n",med);
 printf("N dias>27 %d\n",cont);
 
  return 0;
}