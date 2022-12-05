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
   
    //
    // Montando a lista encadeada de modo que fique sempre ordenada
    //
    while(TRUE) {
        char matr[TAM_MATR + 1];
        char nome[TAM_NOME + 1];
        ALUNO* novo;
       
        printf("Entre com os dados do aluno ou [ENTER] para terminar\n");
        printf("====================================================\n");
        printf("Matr: ");
        fflush(stdout);
        gets(matr);
        if(strlen(matr) == 0)
            break;
        novo = (ALUNO*)calloc(sizeof(ALUNO));
        strcpy(novo->matr,matr);            
        printf("Nome: ");
        fflush(stdout);
        gets(nome);
        strcpy(novo->nome,nome);
        novo->proximo = NULL;
       
       
        //
        // Descobrindo onde inserir o registro na lista encadeada
        // de tal forma que ela permaneça ordenada.
        //
        ALUNO* anterior = NULL;
        ALUNO* atual = primeiro;
       
        while(atual != NULL) {
            // se a matr do novo vem antes que a matr do atual
            // então devemos inserir o registro ANTES do atual
            if(strcmp(atual->matr,novo->matr) > 0) {
                // se verdadeiro, então novo deve ser o primeiro da lista
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
   
   
    //
    // Gravando os registros no arquivo
    //
    FILE*  arquivo;
    arquivo = fopen("c:\\Temp\\alunos.dat","wb");    
    ALUNO* atual = primeiro;
    while(atual != NULL) {
        int tam = fwrite(atual, (TAM_MATR + 1 + TAM_NOME + 1), 1 ,arquivo);
        printf("Matr: %s\n",atual->matr);
        printf("Nome: %s\n",atual->nome);    
        atual = atual->proximo;    
    }
    fclose(arquivo);
}
