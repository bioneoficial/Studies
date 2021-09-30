#include<stdio.h>
#include<stdlib.h>
#include <time.h>
int main()
{
  int a,b,soma,resposta,i,acertos;
    srand(time (NULL));
    for(i=0;i<5;i++){
 a = (rand() % 99) + 1;
 b = (rand() % 99) + 1;
 
    printf("\nFaça a operação de soma:\n\t %d + %d=? \n", a,b);
 scanf("%d",&resposta);

soma = a+b;
 
 if (resposta != soma)
  printf("\nResposta errada. a resposta certa é:%d\n",soma);
 else{
   printf("\nResposta correta!Muito bem!!\n");
 acertos ++;
}
}
printf("\nVoce acertou:%d questões\n",acertos);
return 0;

}