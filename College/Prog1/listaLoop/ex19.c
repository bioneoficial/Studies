#include <stdio.h>

int main(void) {
  float numC,maiorC,menorC,preco,qtdK,pague,pagueT=0,media;
  printf("Price pl0x:\n");
  scanf("%f", &preco);
  printf("Insert the number of customers in this city, pal:\n");
  scanf("%f",&numC);
  if(numC<=0){
    goto aqui;
  }
  for(int i=0;i<numC;i++){
    printf(" About customer %d, how much kWh did he/she consumed this month?\n",i+1);
    scanf("%f",&qtdK);
    if(i==0){
      maiorC= qtdK;
      menorC = qtdK;
    } else{
      if(maiorC<qtdK){
        maiorC = qtdK;
      }
      if(menorC>qtdK){
        menorC = qtdK;
      }

    }
    pague = preco * qtdK;
    printf("This customer need to pay %.2f $\n",pague);
    pagueT += pague;
  }
  if(numC<=0){
  aqui: printf("sem consumidores o capitalismo não vai pra frente parceiro\n");}
  media = pagueT / numC;
  printf("O maior consumo foi %.2f e o menor foi %.2f\n A média geral de consumo foi %.2f",maiorC,menorC,media);
  return 0;
}