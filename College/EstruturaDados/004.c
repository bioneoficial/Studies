#include <stdio.h>
#include <string.h>
#define TAM_MATR 10
#define TAM_NOME 10
#define TAM 9
typedef struct {
   char matr[TAM_MATR + 1];
   char nome[TAM_NOME + 1];
} ALUNO;

ALUNO vetor[TAM];
void lerAluno(int posicao);
void imprimir(int posicao);
void ordernar();
int main(void) {

   for(int posicao = 0;posicao<TAM;posicao++){
       lerAluno(posicao);
   };
   ordernar();
   int flag = 0;
   while(1) {
       printf("Insira a posição que deseja imprimir:\n");
       int temp;
       scanf("%d", &temp);
       imprimir(temp);
       printf("Deseja parar? 0 - Não. qlqr N - sim\n");
       scanf("%d", &flag);
       if(flag != 0)
           break;
   }
   return 0;
}

void lerAluno(int posicao){
   char matr[TAM_MATR + 1], nome[TAM_NOME + 1];
   printf("Ler Matr: \n");
   scanf("%s",matr);
   strcpy(vetor[posicao].matr, matr);
   printf("Ler Nome: \n");
   scanf("%s",nome);
   strcpy(vetor[posicao].nome,nome);
};

void imprimir(int posicao){
   //for(int i= 0;i<TAM;i++){
       //printf("Nome: %s Matr: %s\n",vetor[i].nome, vetor[i].matr);
       printf("Nome: %s Matr: %s\n",vetor[posicao].nome, vetor[posicao].matr);
  // };
};

void ordernar(){
   for(int i = 0; i < TAM; i++){
       int index = 0, flag = 0;
       char menor[TAM_MATR + 1], auxI[TAM_MATR + 1], nomeAux[TAM_NOME +1], nomeMenor[TAM_NOME + 1];
       strcpy(nomeAux, vetor[i].nome);
       strcpy(menor, vetor[i].matr);
       strcpy(auxI, vetor[i].matr);
       for(int j = i;j< TAM;j++){
           if(strcmp(vetor[j].matr, vetor[i].matr) < 0){
               flag = 1;
               strcpy(menor, vetor[j].matr);
               strcpy(nomeMenor, vetor[j].nome);
               index = j;
           }
       }
       if(strcmp(menor, vetor[i].matr) < 0 && flag != 0){
           strcpy(vetor[i].matr, menor);
           strcpy(vetor[i].nome, nomeMenor);
           strcpy(vetor[index].matr, auxI);
           strcpy(vetor[index].nome, nomeAux);
       }
       flag = 0;
   }
   for(int i= 0;i<TAM;i++)
       printf("Nome: %s Matr: %s\n",vetor[i].nome, vetor[i].matr);

}


