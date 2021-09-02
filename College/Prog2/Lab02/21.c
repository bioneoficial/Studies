#include <stdio.h>
/* Uma matriz 20 x 20 representa o estoque de matéria-prima no pátio de uma indústria. Cada elemento representa o código do
produto e a quantidade disponível no estoque. Calcule e imprima quantas toneladas de cada produto existe no pátio.
Exemplo: 2813 281 toneladas de Chumbo
CÓDIGOS:
1 – COBRE 2 – CARVÃO 3 – CHUMBO 4 – FERRO 5 – ALUMÍNIO 6 – NÍQUEL */
int main(){
  int mat[20][20], cont = 0;
  char op,produto[10];
  printf("CÓDIGOS:1 – COBRE 2 – CARVÃO 3 – CHUMBO 4 – FERRO 5 – ALUMÍNIO 6 – NÍQUEL\n");
  printf("Insira estoque e codigo da materia.Exemplo: 2813 => 281 toneladas de Chumbo\n");
  printf("Insira somente numeros positivos e inteiros:\n");
  for(int i=0;i<1;i++){
    for(int k=0;k<1;k++){
    scanf("%d",&mat[i][k]);
    cont++;
    }
  }
  int lastDigit;
  for(int i=0;i<cont;i++){
    for(int k=0;k<cont;k++){
      lastDigit = mat[i][k] % 10;
      mat[i][k] /= 10;
      if(lastDigit == 1){
        strcpy(produto,"Cobre");
      }else if(lastDigit == 2){
        strcpy(produto,"Carvao");
      }else if(lastDigit == 3){
        strcpy(produto,"Chumbo");
      }else if(lastDigit == 4){
        strcpy(produto,"Ferro");
      }else if(lastDigit == 5){
        strcpy(produto,"Aluminio");
      }else if(lastDigit == 6){
        strcpy(produto,"Niquel");
      }
      printf("%d toneladas de %s",mat[i][k],produto);
    }
  }
  return 0;
}