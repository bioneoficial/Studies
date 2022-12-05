#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE         0
#define TRUE         1
#define TAM_MATR     4
#define TAM_NOME     80
#define PATH_ARQUIVO "c:\\Temp\\alunos.dat"

#define modulo(x) ((x)>=0?(x):-(x))

/***************************
 * DECLARAÇÃO DO TIPO ALUNO
 ***************************/
typedef struct _A {
    int        matr;
    char       nome[TAM_NOME + 1];
    int        peso;
    struct _A* esquerda;
    struct _A* direita;
} ALUNO;

/*
 * VARIÁVEIS GLOBAIS
 */
ALUNO*  raiz = NULL;

//----------------------------------------------------------//

void buscaEmLargura() {    
    int nivel = 0;

    ALUNO*  nosDoNivelAtual[128];
    int     numElemNivelAtual = 1;    
    ALUNO*  nosDoNivelSeguinte[128];
    int     numElemProximoNivel = 0;    

    printf("\n\n\nBUSCA EM LARGURA\n\n\n");
    // Inicializo a busca em largura com a raiz
    nosDoNivelAtual[0] = raiz;
   
    while(numElemNivelAtual != 0) {
        numElemProximoNivel = 0;
        printf("\nNIVEL %d | ", nivel++);
        // Listar os elementos do nível corrente
        for(int i = 0; i < numElemNivelAtual; i++) {
            ALUNO* atual = nosDoNivelAtual[i];            
            printf("Matr: %d  | ", atual->matr);
            if(atual->esquerda != NULL)
                nosDoNivelSeguinte[numElemProximoNivel++] = atual->esquerda;
            if(atual->direita != NULL)
                nosDoNivelSeguinte[numElemProximoNivel++] = atual->direita;
        }
        // Colocando os nós do nível seguinte para serem os do
        // nível atual na próxima iteracao
        for(int i = 0; i < numElemProximoNivel; i++)
            nosDoNivelAtual[i] = nosDoNivelSeguinte[i];
        numElemNivelAtual = numElemProximoNivel;                        
    }
}

//----------------------------------------------------------//

void listar(ALUNO* atual, int nivel) {

    if(atual->direita != NULL)
        listar(atual->direita, nivel + 1);

    printf("\n");
    for(int i = 0; i < nivel; i++)
        printf("\t");
    printf("Matr: %d Nome: %s Peso: %d\n\n", atual->matr, atual->nome, atual->peso);    

    if(atual->esquerda != NULL)
        listar(atual->esquerda, nivel + 1);    
}

//----------------------------------------------------------//

ALUNO* balancear(ALUNO* atual) {
    int pesoEsquerda = 0;
    int pesoDireita = 0;    

    // Verificando se precisamos de balanceamento
    if(atual->direita != NULL)
        pesoDireita = atual->direita->peso;
    if(atual->esquerda != NULL)
        pesoEsquerda = atual->esquerda->peso;
    int diferenca = pesoDireita - pesoEsquerda;
    if(modulo(diferenca) < 2)
        return atual; // Posso retornar pois está balanceado!
   
    // Se o balanceamento é necessário à direita
    ALUNO* pivot;
    if(diferenca >= 2) {
        // ROTAÇÃO À DIREITA. Descobrindo qual é o pivot.
        if(atual->direita->direita != NULL) {
            // o pivot é o atual->direita
            pivot = atual->direita;
            atual->direita = NULL;
            pivot->esquerda = atual;
            atual->peso -= 2;            
        } else {
            // o pivot é o atual->direita->esquerda
            pivot = atual->direita->esquerda;
            pivot->direita = atual->direita;
            pivot->esquerda = atual;
            atual->direita = NULL;
            pivot->direita->esquerda = NULL;
            pivot->esquerda->peso -= 2;
            pivot->peso++;
            pivot->direita->peso--;
        }                
    } else {
        // ROTAÇÃO À ESQUERDA. Descobrindo qual é o pivot.
        if(atual->esquerda->esquerda != NULL) {
            // o pivot é o atual->esquerda
            pivot = atual->esquerda;
            atual->esquerda = NULL;
            pivot->direita = atual;
            atual->peso -= 2;            
        } else {
            // o pivot é o atual->esquerda->direita
            pivot = atual->esquerda->direita;
            pivot->esquerda = atual->esquerda;
            pivot->direita = atual;
            atual->esquerda = NULL;
            pivot->esquerda->direita = NULL;
            pivot->direita->peso -= 2;
            pivot->peso++;
            pivot->esquerda->peso--;
        }    
    }        
    return pivot;            
}


//----------------------------------------------------------//

ALUNO* inserirNaArvore(ALUNO* novo, ALUNO* atual) {
    if(novo->matr > atual->matr) {
        if(atual->direita == NULL) {        
            atual->direita = novo;
            if(atual->esquerda == NULL)
                atual->peso++;
        }
        else {    
            atual->direita = inserirNaArvore(novo, atual->direita);                    
            int pesoRetornado = atual->direita->peso;
            if(pesoRetornado == atual->peso)
                atual->peso++;
        }
    } else {
        if(atual->esquerda == NULL) {    
            atual->esquerda = novo;
            if(atual->direita == NULL)
                atual->peso++;
        }
        else {        
            atual->esquerda = inserirNaArvore(novo, atual->esquerda);                    
            int pesoRetornado = atual->esquerda->peso;
            if(pesoRetornado == atual->peso)
                atual->peso++;
        }
    }
    if(atual->peso >= 3)
        atual = balancear(atual);
    return atual;
}

//----------------------------------------------------------//

void criarRegistro(int m, char* n) {
    // Aloco memória para o novo registro a ser inserido na árvore
    ALUNO* novo = (ALUNO*)calloc(1, sizeof(ALUNO));

    // Defino que o novo registro não tem elementos à esquerda
    // nem à direita
    novo->esquerda = NULL;
    novo->direita = NULL;
    novo->peso = 1;
   
    // Colocando os dados de matr e nome no novo registro
    novo->matr = m;
    strcpy(novo->nome, n);
    // Não pode fazer novo->nome = nome, pois dá erro.
           
    // Se não há raiz, o novo passa a ser a raiz e saio da função
    if(raiz == NULL)
        raiz = novo;
    else
        raiz = inserirNaArvore(novo, raiz);
   
    printf("-------------------------------\n\n");
    listar(raiz,0);
    //char aux[10];
    //gets(aux);
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
    fflush(stdin);
    if(matr == 0)
        return FALSE;
    printf("Nome: ");
    gets(nome);
    criarRegistro(matr, nome);
    return TRUE;
}

//----------------------------------------------------------//

void carregarDadosDeArquivo() {
    FILE*  arquivo;
    ALUNO  registro;
   
    arquivo = fopen(PATH_ARQUIVO,"rb");    

    if(arquivo != NULL) {
        while(TRUE) {
            int tam = fread(&registro, (TAM_MATR + TAM_NOME + 1), 1, arquivo);          
            if(tam == 0) // se tam == 0, cheguei ao final do arquivo
                break;                
            criarRegistro(registro.matr, registro.nome);
        }    
        fclose(arquivo);
    }
}

//----------------------------------------------------------//

void gravarRegistro(ALUNO* atual, FILE* arquivo) {
    if(atual->esquerda != NULL)
        gravarRegistro(atual->esquerda, arquivo);        
   
    int tam = fwrite(atual, (TAM_MATR + TAM_NOME + 1), 1 ,arquivo);  
   
    if(atual->direita != NULL)
        gravarRegistro(atual->direita, arquivo);
}

//----------------------------------------------------------//


void gravarArquivo() {
    FILE* arquivo = fopen(PATH_ARQUIVO,"wb");  


    //----------gravarRegistro(raiz, arquivo);


    ALUNO*  nosDoNivelAtual[128];
    int     numElemNivelAtual = 1;    
    ALUNO*  nosDoNivelSeguinte[128];
    int     numElemProximoNivel = 0;    

    // Inicializo a busca em largura com a raiz
    nosDoNivelAtual[0] = raiz;
   
    while(numElemNivelAtual != 0) {
        numElemProximoNivel = 0;
        // Listar os elementos do nível corrente
        for(int i = 0; i < numElemNivelAtual; i++) {
            ALUNO* atual = nosDoNivelAtual[i];            
       
            int tam = fwrite(atual, (TAM_MATR + TAM_NOME + 1), 1 ,arquivo);  
           
            if(atual->esquerda != NULL)
                nosDoNivelSeguinte[numElemProximoNivel++] = atual->esquerda;
            if(atual->direita != NULL)
                nosDoNivelSeguinte[numElemProximoNivel++] = atual->direita;
        }
        // Colocando os nós do nível seguinte para serem os do
        // nível atual na próxima iteracao
        for(int i = 0; i < numElemProximoNivel; i++)
            nosDoNivelAtual[i] = nosDoNivelSeguinte[i];
        numElemNivelAtual = numElemProximoNivel;                        
    }




   
    fclose(arquivo);

}



//----------------------------------------------------------//

int main() {
    //
    // Carregando os dados do arquivo, caso exista
    //
    carregarDadosDeArquivo();
 
     if(raiz != NULL)
         listar(raiz,0);
   
    //
    // Montando a lista encadeada de modo que fique sempre ordenada
    //
    while(TRUE) {
        if(!lerRegistro())
            break;
    }


     listar(raiz,0);
     buscaEmLargura();
    //
    // Gravando os registros no arquivo
    //
    gravarArquivo();
}