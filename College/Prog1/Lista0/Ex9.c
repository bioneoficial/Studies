#include <stdio.h>
#include <math.h>

int main() {

   float litros, preco=0;
   int area, Tlata=0,Tgalao=0,precoL=80,precoG=25;

   printf("Informe a área a ser pintada:\n ");
   scanf("%d", &area);
  
   litros = (area/6) * 1.1;
  Tlata = ceil((int)litros / 18);
  preco=Tlata * precoL;

  printf("\nÉ necessario %d latas para pintura, custo $%.1f\n", Tlata, preco);

  Tgalao = ceil(litros /3.6);
  preco=Tgalao *precoG;

  printf("\nÉ necessario %d galão(ões) para pintura, custo $%.1f\n", Tgalao, preco);
  
   int galao2,lata2,i;
  galao2 = ceil(litros / 3.6);

  while(galao2 >= 5) 
  {
    lata2 ++;
    galao2 -= 5;
  }

  preco = lata2 * precoL + galao2 * precoG;
  
  printf("\nComprando %d latas e %d galoes com o custo total de $%.1f\n",lata2 ,galao2,preco );

   return 0;

}