#include <stdio.h>

int main(void) {
  printf("Quantas diarias do encanador serão contratadas?\n ");
    float dias, vt,vtd,d;
  scanf("%f",&dias);
  vt= dias * 30;
vtd= vt * 0.92;
d = vt - vtd;
printf("O valor total das diárias contratadas é $%.f\n com os 8%% de desconto ficaria $%.f \n ou seja, teve um desconto de $%.f",vt,vtd,d);
  return 0;
}