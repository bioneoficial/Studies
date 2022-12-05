#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE         0
#define TRUE         1
#define TAM_MATR     4
#define TAM_NOME     80
#define PATH_ARQUIVO "c:\\Temp\\alunos.dat"

/***************************
 * DECLARAÇÃO DO TIPO ALUNO
 ***************************/
typedef struct _A {
    int  matr;
    char nome[TAM_NOME + 1];
    struct _A* esquerda;
    struct _A* direita;
} ALUNO;

/*
 * VARIÁVEIS GLOBAIS
 */
ALUNO*  raiz = NULL;

//----------------------------------------------------------//

void carregarDadosDeArquivo() {
    FILE*  arquivo;
    ALUNO  registro;
   
    arquivo = fopen(PATH_ARQUIVO,"rb");    
/***
ADAPTAR O CÓDIGO ABAIXO PARA LER OS REGISTROS DO ARQUIVO E INSERI-LOS
NA ÁRVORE.

    if(arquivo != NULL) {
          int tam = fread(&registro, (TAM_MATR + TAM_NOME + 1), 1, arquivo);
          // se tam == 0, cheguei ao final do arquivo
        if(tam == 0) {
            free(novo);
               break;        
        }
        criarRegistro(registro.matr, registro.nome);
    }    
***/
    fclose(arquivo);
}

//----------------------------------------------------------//

void listar(ALUNO* atual) {
    if(atual->esquerda != NULL)
        listar(atual->esquerda);        
    printf("Matr: %d Nome: %s\n", atual->matr, atual->nome);    
    if(atual->direita != NULL)
        listar(atual->direita);
}

//----------------------------------------------------------//

void inserirNaArvore(ALUNO* novo, ALUNO* atual) {
    // A matrícula do novo registro é maior
    // que matrícula do registro atual???
    if(novo->matr > atual->matr) {
        // Então vamos seguir à direita!!!
        // A posição do atual à direita está nula?
        if(atual->direita == NULL)
            // Faço com que o atual à direita aponte
            // para o novo e finalizo a função
            atual->direita = novo;
        else
            // Se não for nula, então vou repetir essa
            // função, mas o atual passará a ser o
            // atual->direita
            inserirNaArvore(novo, atual->direita);
       
    } else {
        // Então vamos seguir à esquerda!!!
        // A posição do atual à esquerda está nula?
        if(atual->esquerda == NULL)
            // Faço com que o atual à esquerda aponte
            // para o novo e finalizo a função
            atual->esquerda = novo;
        else
            // Se não for nula, então vou repetir essa
            // função, mas o atual passará a ser o
            // atual->esquerda
            inserirNaArvore(novo, atual->esquerda);
       
    }
}

//----------------------------------------------------------//

void criarRegistro(int m, char* n) {
    // Aloco memória para o novo registro a ser inserido na árvore
    ALUNO* novo = (ALUNO*)calloc(1, sizeof(ALUNO));

    // Defino que o novo registro não tem elementos à esquerda
    // nem à direita
    novo->esquerda = NULL;
    novo->direita = NULL;
   
    // Colocando os dados de matr e nome no novo registro
    novo->matr = m;
    strcpy(novo->nome, n);
    // Não pode fazer novo->nome = nome, pois dá erro.
           
    // Se não há raiz, o novo passa a ser a raiz e saio da função
    if(raiz == NULL)
        raiz = novo;
    else
        inserirNaArvore(novo, raiz);
}

//----------------------------------------------------------//

int lerRegistro() {
    int matr;
    char nome[TAM_NOME + 1];
       
    printf("Entre com os dados do aluno ou [0] para terminar\n");
    printf("=================================================\n");
    printf("Matr: ");
    fflush(stdout);
    scanf("%d",&matr);
    if(matr == 0)
        return FALSE;
    printf("Nome: ");
    gets(nome);
    criarRegistro(matr, nome);
    return TRUE;
}

//----------------------------------------------------------//

void gravarArquivo() {
    FILE* arquivo = fopen(PATH_ARQUIVO,"wb");    

/***

ADAPTAR O CÓDIGO ABAIXO PARA GRAVAR OS REGISTROS DA ÁRVORE EM ORDEM

    atual = primeiro;

    while(atual != NULL) {
        // Escreve o registro no arquivo binário
        int tam = fwrite(atual, (TAM_MATR + TAM_NOME + 1), 1 ,arquivo);
        // Aproveito e listo os dados na tela
        printf("Matr: %s\n",atual->matr);
        printf("Nome: %s\n",atual->nome);    
        atual = atual->proximo;    
    }
***/
    fclose(arquivo);

}

//----------------------------------------------------------//

int main() {
    //
    // Carregando os dados do arquivo, caso exista
    //
    carregarDadosDeArquivo();
   
    //
    // Montando a lista encadeada de modo que fique sempre ordenada
    //
    while(TRUE) {
        if(!lerRegistro())
            break;
    }
   
    //
    // Gravando os registros no arquivo
    //
    gravarArquivo();
}