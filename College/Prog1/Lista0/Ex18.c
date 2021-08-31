#include <stdio.h>

int main() {
  int tipo;
  float salario;
  printf("Insira o salário:\n");
  scanf("%f",&salario);
  printf("\nInsira o Tipo do funcionário(1,2ou3):\n");
  scanf("%d",&tipo);
if(salario<0){
  printf("Aí é dívida, não salário\n");
  main("pause");
}
  if(tipo ==1){
    printf("\nO salario de $%.1f foi para $%.1f, um aumento de 10%%\n",salario,salario*1.1);
  }
  else if(tipo ==2){
    printf("\nO salario de $%.1f foi para $%.1f, um aumento de 20%%\n",salario,salario*1.2);
  }
  else if(tipo ==3){  
    printf("\nO salario de $%.1f foi para $%.1f, um aumento de 30%%\n",salario,salario *1.3);
  }
  else {
    printf("\nO salario de $%.1f foi para $%1.f, um aumento de 40%%\n",salario,salario * 1.4);
  }
  return 0;
}
