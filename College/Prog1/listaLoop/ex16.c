#include <stdio.h>

int main(void) {
  printf("N das crias\n");
  int n,i,contM=0,contF=0,idade,contI=0;
  float percentF, percentM,percentI;
  char sexo;
  scanf("%d",&n);
  printf("agr vmos 1 por 1, gatinho:\n");
  for(i=0;i<n;i++){
    printf("'m' para macho e 'f' para femea:\n");
    scanf(" %c", &sexo);
    switch(sexo){
      case 'm': contM++;
      break;
      case 'f': contF++;
      break;
      default: printf("ta troll ne bro, vou resetar o programa só para deixar de ser bobao, leia e siga as regras!!! My program My rules!"); return 0;
    }
    printf("Insira qtd meses de vida antes de vir a óbito =(:\n");
    scanf("%d",&idade);
    if(idade <= 24){
      contI++;
    }
  }
  percentM = contF*100/n ;
  printf("a Percent de crianças M foi:%.1f percent\n",percentM);
  percentF = contM*100/n;
  printf("a percent de kids F foi: %.1f percent\n",percentF);
  percentI = contI*100/n;
  printf("La percent que viveram 24 ou - meses foi: %.1f percent\n",percentI);
  return 0;
}