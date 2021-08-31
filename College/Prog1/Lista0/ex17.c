#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main() {
char cod[5];
int qtd;
float total;
printf("Insira o Codigo do produto:\n");
scanf("%s",cod);
printf("Insira a quantidade comprada:\n");
scanf("%d",&qtd);

if ( strcmp(cod,"1001") == 0){
total = 5.32 * qtd;
printf("PRECO TOTAL = %.2f\n",total);
}
else if ( strcmp(cod,"1324") == 0){
total = 6.45 * qtd;
printf("PRECO TOTAL = %.2f\n",total);
}
else if ( strcmp(cod,"6548") == 0){
total = 2.37 * qtd;
printf("PRECO TOTAL = %.2f\n",total);
}
else if ( strcmp(cod,"0987") == 0){
total = 5.32 * qtd;
printf("PRECO TOTAL = %.2f\n",total);
}
else if ( strcmp(cod,"7623") == 0){
total = 6.45 * qtd;
printf("PRECO TOTAL = %.2f\n",total);
}

else {
printf("CODIGO INVALIDO\n");
}

    return 0;
}
/*
Um vendedor necessita de um programa que calcule o preço total devido por um cliente, que comprou um produto em sua loja. O programa deve receber o código do produto e a quantidade comprada, para então calcular e imprimir na tela o preço total, usando a tabela abaixo:
*/