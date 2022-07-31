#include <stdio.h>

#define qtdEquipe 3
int main(int argc, char* argv[]){ 
  FILE *pontuacao = NULL;
  FILE *arq_final = NULL;
  char nomeEquipe[qtdEquipe][100];
  int primeiraRod[qtdEquipe];
  int segundaRod[qtdEquipe];
  int terceiraRod[qtdEquipe];

  pontuacao = fopen("pont.txt", "r");
  arq_final = fopen("arq_final.txt", "w+b");
  if(pontuacao == NULL ||arq_final == NULL){
    printf("\nArquivo pont.TXT nao pode ser aberto.");
  }else{
    int j = 0, index = 0;
    double pontFinal[qtdEquipe] = {0}, maior = 0.0;
    while(j < qtdEquipe){
      fscanf(pontuacao, "%s\n%d\n%d\n%d", &nomeEquipe[j],&primeiraRod[j], &segundaRod[j],&terceiraRod[j]);
      j++;
    }
    for(int i = 0; i < qtdEquipe; i++){
      pontFinal[i] = (double)((1 * primeiraRod[i]) + (2 * segundaRod[i]) + (3 * terceiraRod[i])) / 5;
      if(sizeof(pontFinal[i]) > sizeof(maior)){
        printf("%.2lf\n",pontFinal[i]);
        index = i;
      }
      fprintf(arq_final, "Equipe %s Pontuacao: %.2lf\n",nomeEquipe[i], pontFinal[i]);
      printf("Equipe %s Pontuacao: %.2lf\n",nomeEquipe[i], pontFinal[i]);
    }
    printf("Equipe %s campea", nomeEquipe[index]);
  }
  fclose(pontuacao);
  fclose(arq_final);
  return 0;
}