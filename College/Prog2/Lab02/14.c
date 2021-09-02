#include <stdio.h>
#include <time.h>


//Leia uma matriz 40 X 50, de caracteres não ordenados. Pesquisar e imprimir o maior caracter e sua posição.
int main(){
  srand(time(NULL));
  int matriz[40][50], maior = 0, indexLinha = 0, indexColuna = 0;
  for(int i =0; i < 40 ; i++){
     for(int k = 0; k < 50;k++){
       matriz[i][k] = rand() % 3000;
       if(matriz[i][k] > maior){
         maior = matriz[i][k];
         indexLinha = i;
         indexColuna = k;
       }
     };
  };
    printf("a matriz[%d][%d]:%d é o maior valor.\n",indexLinha,indexColuna,maior);


  return 0;
}