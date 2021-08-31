#include <stdio.h>

int main()
{
  int x = 0;
  float termo = 0;

  scanf("%d",&x);

  for(int i = 1; i <= 20; i++)
  {
    termo = (float)1 / (x + i);
    printf("%f\n",termo);
   
  }
  return 0;  
}