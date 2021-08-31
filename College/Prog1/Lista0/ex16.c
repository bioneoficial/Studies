#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
  float a, b, c,delta,raizdelta=0,raiz1,raiz2;  
        printf("Equação do 2o grau: ax² + bx + cx = 0\n");
        printf("Insira o valor de a:\n ");
        scanf("%f", &a);

        printf("Insira o valor de b:\n ");
        scanf("%f", &b);

        printf("Insira o valor de c:\n ");
        scanf("%f", &c);
        if(b ==0 || c==0 || a==0) {
          printf("\n Classificado como Equação INCOMPLETA do 2 grau");
       }
       else {
       printf("\nClassificado como equação COMPLETA do 2 grau\n");
       }

        if(a != 0)
        {
            delta = pow(b,2) - (4*a*c);
            raizdelta = sqrt(delta);
          printf("\nDelta=%.2f\n",delta);
          printf("\n%.1f",raizdelta);

          if(delta==0){
             raiz1 = (-b + raizdelta)/(2*a);
                raiz2 = (-b - raizdelta)/(2*a);
            printf("\nRaiz  única\n%.2f\n", raiz1);
          }
            if(delta > 0)
            {
                raiz1 = (-b + raizdelta)/(2*a);
                raiz2 = (-b - raizdelta)/(2*a);
                printf("\nRaízes: %.2f e %.2f\n ", raiz1, raiz2);
                
            }
            if(delta <0) {
             printf("\nNão existe raiz\n");
            }
            else if (delta == 0) {
        printf("\nHá uma solução\n");
    } else {
        printf("\nHá duas soluções\n");
    }
       

        }

  return 0;
}