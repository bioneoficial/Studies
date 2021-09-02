#include <stdio.h>

int main(){
float salary[20] = {0},cash = 0;
char firstName[20][50],lastName[20][50];
int cont = 0,fim = 0;

while(cont < 20){
 printf("Insira o primeiro nome do funcionário %d\n",cont + 1);
scanf("%s", firstName[cont]);
 printf("Insira o sobrenome do funcionário %d\n",cont + 1);
scanf("%s", lastName[cont]);
printf("Insira o salário do funcionário %d\n",cont);
scanf("%f", &salary[cont]);
if(salary[cont] > cash){
    cash = salary[cont];
  };
cont++;
};
for(int i =0;i < 20;i++){
  printf("O funcionário %s %s tem R$%.2f de salário\n",firstName[i],lastName[i],salary[i]);
};
for(int i =0;i < 20;i++){
  if(cash/2 > salary[i]){
  printf("O funcionário %s recebe menos que metade do maior salário\n",lastName[i]);
  }
  
};
for(int i =0;i < 20;i++){
  if(strstr(firstName[i],"Maria") || strstr(firstName[i],"maria")){
    if(fim == 0){printf("Salários de funcionários com 1 nome Maria:\n");}
    fim++;
    printf("%.2f\n",salary[i]);
  };
  
};
  return 0;
}
/* Faça um programa que armazene os dados de 2 funcionários de uma empresa em 2 arranjos: um com os nomes dos
funcionários e outro com seus salários. Índices iguais nos arranjos indicam informações relativas ao mesmo funcionário. Depois:
a) exibir os dados lidos (nome e salário correspondente);
b) exiba o ultimo sobrenome dos funcionários com salário inferior à metade do maior salário pago na empresa;
c) escrever os salários de todos os funcionários cujo primeiro nome é Maria. */