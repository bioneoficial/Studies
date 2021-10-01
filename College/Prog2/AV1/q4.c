#include <stdio.h>
#include <time.h>

int main(){
  srand(time(NULL));
  int matriz[5][5] = {0}, matrizLength = 5,maior = 0,linha = 0, coluna = 0;

  for(int i = 0; i < matrizLength;i++){
    for(int j = 0; j < matrizLength;j++){
      matriz[i][j] = rand() % 50 + 1;
      printf("Linha %d Coluna %d: %d\n",(i+1),(j+1),matriz[i][j]);
      if(matriz[i][j] > maior){
        maior = matriz[i][j];
        linha = i;
        coluna = j;
        }
    }
  }
  printf("maior = %d,  linha = %d, col = %d",maior,(linha+1),(coluna+1));
  return 0;
}