#include <stdio.h>
#include <stdlib.h>
#include<time.h>


int main(void) {
  int gab, cont=0,resp;
  srand(time(NULL));
  gab = rand()%1000;
  printf("Tenta acertar um número de 1 a 1000\n");
  printf("%d",gab);

  do{ scanf("%d",&resp);
  if(resp>gab){
    cont++;
    if(resp-gab> 100){
      printf("Muito alto, joga laaaa embaixo\n");
    }
    else if(resp-gab <= 100 && resp-gab >= 50){
      printf("pouquim alto ta chegando\n");
    }
    else if(resp-gab < 50){
      printf("ta muito(tipo mt msm) perto, vai pra baixo, dica melhor que essa n tem\n");
    }
  }
  else if(resp<gab){
    cont++;
    if(gab-resp > 100){
      printf("passou longe, joga la no teto de Deus\n");
    }
    else if(gab-resp<=100 && gab-resp>=50){
      printf("pouquin baixo, ta chegando bb\n");
    }
    else if(gab-resp<50){
      printf("ta muito(tipo mt msm) perto, vai pra cima, dica melhor que essa n tem\n");
    }
  }

  }while(resp != gab);
  if(cont==0){
    printf("de prima? G0D es tu?");
  }
  else{
  printf("em %d tentativa(s) tu conseguiste acertar",cont);}
  return 0;
}