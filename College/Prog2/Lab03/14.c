#include <stdio.h>
#include <time.h>
#define nQestoes 10
#define nAlunos 15
void corretor(int prova[nQestoes], int provaAluno[nAlunos][nQestoes], int aluno[nAlunos] );
int main(){
  srand(time(NULL));
  int prova[nQestoes], provaAluno[nAlunos][nQestoes],aluno[nAlunos];
  for(int i = 0; i < 10; i++){
  prova[i] = rand() % 2;
  }
  for(int i = 0; i < 15; i++){
    for(int k = 0; k < 10; k++){
      provaAluno[i][k] = rand() % 2;
    }
  }
  corretor(prova,provaAluno,aluno);
  return 0;
}
void corretor(int prova[nQestoes], int provaAluno[nAlunos][nQestoes], int aluno[nAlunos] ){
  int ponto = 0;
  float  aprovados = 0;
  for(int i = 0; i < 15; i++){
    ponto = 0;
    for(int k = 0; k < 10; k++){
      provaAluno[i][k] == prova[k] ? ponto++:0; 
    }
    aluno[i] = ponto;
    printf("Aluno[%d] tirou %d\n",i,aluno[i]);
    if(aluno[i] >= 6){
      aprovados++;
    }
  }
  printf("Tivemos %.0f aprovados de 15, O indice de aprovação foi:\n",aprovados);
  aprovados = (aprovados * 100) / 15;
   printf("%.2f%%\n",aprovados);

}
/* Faça um programa modularizado para corrigir provas de múltipla escolha.
Cada prova tem dez questões e cada questão vale 1 ponto. O primeiro
conjunto de dados a ser lido é o gabarito da prova. Os outros dados serão
os números dos alunos e suas respectivas respostas. Existem 15 alunos
matriculados. Calcule e mostre:
● Para cada aluno seu número e sua nota;
● A percentagem de aprovação, sabendo-se que a nota mínima é 6,0. */