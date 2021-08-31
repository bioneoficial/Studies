#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  float salario,inss;
  start:
  printf("Insira o salário:\n");
  scanf("%f",&salario);

if(salario<0){
  main("pause");
}

if(salario<=600){
  inss = salario ;
printf("\n%.f é o salário com desconto do INSS, foi isento\n",inss);
}
else if(600<salario && salario<=1200){
   inss = salario - (salario * 0.2) ;
printf("%.f é o salário com desconto do INSS em 20%%\n",inss);
}
else if(1200<salario && salario<=2000){
   inss = salario - (salario * 0.25) ;
printf("%.f é o salário com desconto do INSS em 25%%\n",inss);
}
else if(salario > 2000){
  inss =salario - (salario * 0.3) ;
printf("%.f é o salário com desconto do INSS em 30%%\n",inss);
}
goto start;
  return 0;
}

/* 
- maior que R$ 600,00 e menor ou igual a R$ 1200,00 – 20%
- maior que R$ 1200,00 e menor ou igual a R$2000,00 – 25%
- maior que R$ 2000,00 – 30%  */