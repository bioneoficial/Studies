#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/* Carregar o resultado dos jogos da loteria esportiva em um vetor RESUL [13], que estará preenchido com os valores 1 (coluna 1),
2 (coluna 2) e 0 (coluna do meio). O seu programa deverá totalizar os pontos de cada apostador. Para isto, leia o número do
cartão (flag: 0) e um vetor APOSTA [13]. Ao final, exiba o no do cartão, o total de pontos e, para o caso de 13 acertos, exibir

mensagem. */

int main(){
   srand(time(NULL));
  int RESUL[13], APOSTA[13], flag = 0,sum = 0,n;
  for(int i =0; i < 13;i++){
    RESUL[i] = rand() % 3;
  }
  printf("Quantos apostadores na pista?\n");
  scanf("%d", &n);
   for(int i =0; i < n;i++){
     int cont = 0;
     for(int j =0; j < 13;j++){
    APOSTA[j] = rand() % 3;
    if(APOSTA[j] == RESUL[j]){
      cont++;
     // sum += RESUL[j];
    }
     }
     if(cont == 13){
      printf("Cartão:%d do apostador %d fez %d pontos, são 13 acertos!\n",flag,i+1,cont);
    }else{
     printf("Cartão:%d do apostador %d fez %d pontos\n",flag,i+1,cont);
  }
  flag++;
   }



  
 
  

  return 0;
}