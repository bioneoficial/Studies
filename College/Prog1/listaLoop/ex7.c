#include <stdio.h>
#include <math.h>

int main()
{
  int termos,a;
  float termo=0, s=0;

  printf("Digite a Quantidade de Termos:\n");
  scanf("%d",&termos);
  printf("Digite o Valor de A:\n");
  scanf("%d",&a);

  for(int i=0;i < termos; i++)
  {
    termo = ((float)i+1) / (a - i); 
      if(isinf(termo))
      {
        termo = 0;
      }
    s += termo;
  }

  printf("S = %f",s+a);

  return 0;
  
}