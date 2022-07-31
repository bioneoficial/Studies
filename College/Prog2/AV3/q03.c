#include <stdio.h>

void tempM( double *tempD);
#define qtdDias 4
int main(){
  double temp[qtdDias] = {1,2,3,4};
  tempM(temp);
  return 0;
}
void tempM( double *tempD){
  int i = 0,cont = 0;
  double media = 0.0;
  while(i < qtdDias){
    media += tempD[i];
    i++;
  }
  i = 0;
  media /= qtdDias;
  while(i < qtdDias){
    if(tempD[i] > media)
      cont++;
    i++;
  }
  printf("media temperatura dos dias = %.2lf e %d dias estavam acima da média",media,cont);
}