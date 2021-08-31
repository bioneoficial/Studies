#include <stdio.h>
#include <string.h>

int main() {
  int a;
  printf("\nDigite um numero de 1 a 7 para receber um dia\n");
  scanf("%d",&a);

  if(a<1 || a>7){
    printf("\ntente novamente com um numero valido\n");
    main("pause");
  }
switch(a) {
  case 1:
  if(a==1){
    printf("\nO dia é: Domingo\n");
  }
  break;
  case 2:
  if(a==2){
   printf("\nO dia é:Segunda Feira\n");
  }
  break;
   case 3:
  if(a==3){
    printf("\nO dia é: Terça Feira\n");
  }
  break;
 case 4:
  if(a==4){
    printf("\nO dia é: Quarta Feira\n");
  }
  break;
   case 5:
  if(a==5){
    printf("\nO dia é: Quinta Feira\n");
  }
break;
   case 6:
  if(a==6){
    printf("\nO dia é: Sexta Feira\n");
  }
  break;
 case 7:
  if(a==7){
    printf("\nO dia é: Sabado\n");
  }
  break;
}
  return 0;
}