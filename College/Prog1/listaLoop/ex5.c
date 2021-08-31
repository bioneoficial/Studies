#include <stdio.h>

int main(void) {
  printf("Quantos alunos tem:\n");
  int alunos;
  scanf("%d", &alunos);
  
  int i;
  float media=0,nota;
  for(i=0;i<alunos;i++){
    printf("entre a nota do aluno %d\n",i+1);
    scanf("%f", &nota);
    media += nota;

  }
  media = media / i;
  printf("a médoa foi:%.1f", media);
  
  return 0;
}