#include <stdio.h>
#include <math.h>
#include<stdlib.h>
int main() {
  //Escreva um programa que recebe uma altura h e determina a que distância está o horizonte
  float d,h,r=6378150;
  printf("Determine a altura em metros e lhe daremos a distancia do horizonte\n\n");
  scanf("%f",&h);
  if(h<0){
    main("pause");
  }
  d = sqrt(h*h) + (2*r*h);
  printf("\n%.f metros, longin non? rs",d);
  return 0;
}


// d = \sqrt{h^2 + 2rh}

/* [Alturas de alguns locais interessantes:](https://www.notion.so/4069c77e8e7940649185fa26c1f19b4e) */