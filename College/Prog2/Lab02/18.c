#include <stdio.h>
#include <time.h>

/* Carregar uma matriz MAT 30 X 30, inteiros, gerar um vetor LIN, cujos elementos serão a soma dos elementos de cada linha da
matriz e um vetor COL, cujos elementos serão a soma dos elementos de cada coluna da matriz. */
int main(){
  srand(time(NULL));
  int MAT[30][30],LIN[30] = {0},COL[30] = {0};
  for(int i = 0; i< 30; i++){
    for(int k =0;k<30;k++){
      MAT[i][k] = rand() % 10;
    };
  };
  for(int i = 0; i< 30; i++){
    for(int k =0;k<30;k++){
      LIN[i] += MAT[i][k];
    };
  };
  for(int i = 0; i< 30; i++){
    for(int k =0;k<30;k++){
      COL[i] += MAT[k][i];
    };
  };
  return 0;
}