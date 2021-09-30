#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int dia, mes, ano;
  int meses[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int loop;

                         
do
  {
    printf("\nInsira  a data  em DD/MM/AAAA:\n");
    scanf("%d/%d/%d",&dia,&mes,&ano);
  if ((ano%4 == 0 && ano%100 != 0) ||ano%400 == 0){
      meses[2]=29;
    printf("\nAno bissexto!\n");
      }
      else {
        printf("\nAno não bissexto!\n");
      }
    
    if (dia <= 0 || dia>31 || mes>12 || ano > 9999  || mes <= 0 || ano< 0){
      printf("\nData fora dos padroes.\n");
    }
      else if ( dia > meses[mes] ) {
        printf("Mês com %d dias... ", meses[mes]);
        printf("\nEsse mes tem menos dias, data invalida...");
      }
    
    else {
      printf("\nData válida");
    }
    
  } 
  
while (((dia > 31) || (dia < 1)) || ((mes > 12) || (mes < 1)) || ((ano < 0) || (ano > 9999)) );

}


