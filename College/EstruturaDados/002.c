#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE      1
#define TAM_MATR  10
#define TAM_NOME  80

typedef struct _A {
   char matr[TAM_MATR + 1];
   char nome[TAM_NOME + 1];
   struct _A* proximo;
} ALUNO;

int main() {
   ALUNO*  primeiro = NULL;
   ALUNO* atual;
   ALUNO* novo;

   FILE*  arquivo;
   arquivo = fopen("alunos.txt","rb");

   if(arquivo != NULL){
       while(TRUE){
           ALUNO registro;
           int tam = fread(&registro, sizeof(ALUNO), 1, arquivo);
           if(tam == 0){
               break;
           }
           ALUNO* novo = (ALUNO*) calloc(1, sizeof(ALUNO));
           strcpy(novo -> matr, registro.matr);
           strcpy(novo -> nome, registro.nome);
           novo -> proximo = NULL;
           if(primeiro == NULL)
               primeiro = novo;
           else
               atual -> proximo = novo;

           atual = novo;

       }

       fclose(arquivo);
   }

   while(TRUE) {
       char matr[TAM_MATR + 1];
       char nome[TAM_NOME + 1];

       printf("Entre com os dados do aluno ou [ENTER] para terminar\n");
       printf("====================================================\n");
       printf("Matr: ");
       fflush(stdout);
       gets(matr);
       if(strlen(matr) == 0)
           break;
       novo = (ALUNO*)malloc(sizeof(ALUNO));
       strcpy(novo->matr,matr);
       printf("Nome: ");
       fflush(stdout);
       gets(nome);
       strcpy(novo->nome,nome);
       novo->proximo = NULL;
       ALUNO* anterior = NULL;
       atual = primeiro;

       while(atual != NULL) {
           if(strcmp(atual->matr,novo->matr) > 0) {
               if(anterior == NULL)
                   primeiro = novo;
               else
                   anterior->proximo = novo;
               novo->proximo = atual;
               break;
           }
           anterior = atual;
           atual = atual->proximo;
       }
       if(atual == NULL){
           if(primeiro == NULL)
               primeiro = novo;
           else
               anterior->proximo = novo;
       }
   }
   arquivo = fopen("alunos.txt","wb");
   atual = primeiro;
   while(atual != NULL) {
       int tam = fwrite(atual, (TAM_MATR + 1 + TAM_NOME + 1), 1 ,arquivo);
       printf("Matr: %s\n",atual->matr);
       printf("Nome: %s\n",atual->nome);
       atual = atual->proximo;
   }
   fclose(arquivo);
   return 0;
}

