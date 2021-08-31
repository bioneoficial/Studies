#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  float salario,emp;
  printf("Digite o seu salário e o valor da prestação desejado, respectivamente:\n");
  scanf("%f%f",&salario,&emp);
  if(salario<0 || emp<0) {
    main("pause");
  }

  if(emp > salario * 0.2){
    printf("\nEmpréstimo recusado!\n");
  }
  else {
    printf("\nEmpréstimo aprovado\n");
  }
  return 0;
}

/*  se a prestação for maior que 20% do salário imprima: Empréstimo não concedido, caso contrário imprima: Empréstimo concedido 
*/