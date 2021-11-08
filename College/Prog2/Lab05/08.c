#include <stdio.h>

float ln(void);
float cm(float p1, float p2);
void er(float med);


int main( )
{ 
  float n1, n2, med;
n1=ln();
n2=ln();
med=cm(n1, n2);
er(med);

printf("%.2f %.2f %.2f",n1,n2,med); /*RESPOSTA = 8, 2 , 5*/
return 0;
}


float ln(void)
{ 
  float n;
do{
scanf("%f", &n);
if(n<0.0 || n>10.0)
printf("Redigite...:");
}while(n<0.0 || n>10.0);
return(n);
}
float cm(float p1, float p2)
{ float res;
res = (p1 + p2) / 2.0;
return(res);
}
void er(float med)
{ printf("M=%.1f: ", med);
if(med < 3.0) puts("AR");
else if(med < 7.0)
puts("EF");
else puts("AP");
}
