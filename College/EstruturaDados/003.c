#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_MATR 10
#define TAM_NOME 10
#define TAM 9
typedef struct {
  char matr[TAM_MATR + 1];
  char nome[TAM_NOME + 1];
} ALUNO;

int main(void) {
  ALUNO meuArray[TAM];
  	strcpy(meuArray[0].matr, "10");
  	strcpy(meuArray[1].matr, "20");
  	strcpy(meuArray[2].matr, "30");
  	strcpy(meuArray[3].matr, "40");
  	strcpy(meuArray[4].matr, "50");
  	strcpy(meuArray[5].matr, "60");
  	strcpy(meuArray[6].matr, "70");
  	strcpy(meuArray[7].matr, "80");
  	strcpy(meuArray[8].matr, "90");
  	strcpy(meuArray[0].nome, "Welton");
  	strcpy(meuArray[1].nome, "Matheus");
  	strcpy(meuArray[2].nome, "Nathan");
  	strcpy(meuArray[3].nome, "Bione");
  	strcpy(meuArray[4].nome, "Carlos");
  	strcpy(meuArray[5].nome, "Gabriel");
  	strcpy(meuArray[6].nome, "Pedro");
  	strcpy(meuArray[7].nome, "Lohan");
  	strcpy(meuArray[8].nome, "Leandro");
  int i = 0, j = 0, limI = 0, limS = 8, metadeArray = limS/2;
  
  while(1){
  	j = 0;
  	char tempMatr[TAM_MATR +1];
  	printf("Insira matr pesquisar:\n");
  	gets(tempMatr);
  	if(strcmp(tempMatr, meuArray[metadeArray].matr) == 0){
  		printf("%s", meuArray[metadeArray].nome);
  		break;
	  }else if(strcmp(tempMatr, meuArray[metadeArray].matr) > 0){
	  	i = metadeArray+1;
	  	for(i; i <= limS; i++){
	  		if(strcmp(tempMatr, meuArray[i].matr) == 0){
	  			printf("%s", meuArray[i].nome);
	  			j++;
  				break;
			}
		}
	  }else{
	  		i = metadeArray-1;
	  	for(i; i >= limI; i--){
			if(strcmp(tempMatr, meuArray[i].matr) == 0){
	  			printf("%s", meuArray[i].nome);
	  			j++;
  				break;
			}
	  	}
	  }
	if(j > 0){
		break;
	}
	i = 0;
  }

  return 0;
}


