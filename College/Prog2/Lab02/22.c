#include <stdio.h>
/* Desenvolva um programa para gerar uma matriz que corresponda a uma tabela de multiplicar de 1 até 9. */
int main(){
  int tabela[9][9];
  for(int i =0; i < 9; i++){
    for(int k = 0; k < 9; k++){
      tabela[i][k] = (i+1) * (k+1);
      printf("tabela[%d][%d] = %d\n",(i+1),(k+1),tabela[i][k]);
    };
  };
  return 0;
}