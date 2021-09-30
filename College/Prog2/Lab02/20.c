#include <stdio.h>
#include <time.h>

/* Calcular a média das 3 notas bimestrais obtidas por cada aluno e a média da turma, Sabe-se que as notas estão registradas em
cada linha da matriz. Os 45 alunos estão codificados com valores seqüências, identificados pelo índice da linha da matriz */
int main(){
  srand(time(NULL));
  int al[45][3] = {0};
  float media[45] = {0};
  for(int i = 0; i< 45; i++){
    for(int k =0;k<3;k++){
      al[i][k] = rand() % 10;
    };
  };
  printf("%d,%d,%d\n",al[0][0],al[0][1],al[0][2]);
  for(int i = 0; i< 45; i++){
    for(int k =0;k<3;k++){
      media[i] += al[i][k];
    };
     media[i] /= 3;
  };
  printf("%.2f",media[0]);
  return 0;
}