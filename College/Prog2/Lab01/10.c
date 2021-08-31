#include <stdio.h>

int main(){
  int nota[30],sum = 0, cont = 0,acima = 0;
  float media;
  for(int i = 0; i<3;i++){
    printf("Insira uma nota:\n");
    scanf("%d", &nota[i]);
    sum += nota[i];  
    cont++;  
  };
    media = (float)sum / cont;
    for(int i =0; i < cont;i++){
      printf("nota %d e %d \n",i, nota[i]);
      if(nota[i] > media){
        acima++;
      };
    }
    printf("a media foi %.2f e as acima dela foram %d", media,acima);
  return 0;
}