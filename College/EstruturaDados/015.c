#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define PIOR_CASO  256
#define MAX_CODIGO 15

typedef struct _No {
    int  caracter;
    char codigo[MAX_CODIGO];
    int  peso;
    struct _No* direita;
    struct _No* esquerda;
} NO;

FILE* arquivoOriginal;
FILE* arquivoCompactado;
NO* arrayOcorrencias[PIOR_CASO];
int numCaracteres = 0;

int buffer = 0;
int posBit = 0;

//--------------------------------------------------------------------
void verificarOcorrencias() {
    int i;        
    arquivoOriginal = fopen("C:/Users/26011042/Documents/Exemplo.txt","rb");    
    while(TRUE)    {
        int carac = fgetc(arquivoOriginal);
        if(carac == EOF) //EOF --> End of File
            break;            
        for(i = 0; i < numCaracteres; i++) {
            if(carac == arrayOcorrencias[i]->caracter) {
                arrayOcorrencias[i]->peso++;
                break;
            }
        }
        // Se eu não encontrei o caracter no array, então i == numCaracteres
        if(i == numCaracteres) {
            NO* novo = (NO*)malloc(sizeof(NO));
            arrayOcorrencias[i] = novo;
            arrayOcorrencias[i]->caracter = carac;
            arrayOcorrencias[i]->peso = 1;
            arrayOcorrencias[i]->direita = NULL;
            arrayOcorrencias[i]->esquerda = NULL;
            numCaracteres++;
        }
    }    
    fclose(arquivoOriginal);
}
//--------------------------------------------------------------------
void ordenar() {
    for(int i = 0; i < numCaracteres; i++) {
        int posMenor = i;
        for(int j = i + 1; j < numCaracteres; j++) {
            if(arrayOcorrencias[j]->peso > arrayOcorrencias[posMenor]->peso)
                posMenor = j;
        }
        // Vamos trocar de posição o registros[posMenor] com o registros[i]
        NO* aux = arrayOcorrencias[i];
        arrayOcorrencias[i] = arrayOcorrencias[posMenor];
        arrayOcorrencias[posMenor] = aux;
    }
}
//--------------------------------------------------------------------    
void imprimir(int tamanho) {
    // Listando as ocorrências do arquivo
    printf("---------------------------------------\n");
    printf("O arquivo tem %d caracteres diferentes!\n\n",tamanho);
    for(int i = 0; i < tamanho; i++) {
        printf("O caracter %c (ASCII codigo %d) ocorreu %d vezes\n",
            arrayOcorrencias[i]->caracter,
            arrayOcorrencias[i]->caracter,
            arrayOcorrencias[i]->peso);        
    }
}
//--------------------------------------------------------------------
void gerarArvoreHuffman() {
    int tamanho = numCaracteres;
   
    while(tamanho > 1) {
        ordenar();    
        NO* novo = (NO*)malloc(sizeof(NO));
        novo->direita  = arrayOcorrencias[tamanho - 1];
        novo->esquerda = arrayOcorrencias[tamanho - 2];
        novo->caracter = -1;
        novo->peso = arrayOcorrencias[tamanho-1]->peso + arrayOcorrencias[tamanho-2]->peso;
        arrayOcorrencias[tamanho-2] = novo;
        tamanho--;    
        //imprimir(tamanho);
    }
}
//--------------------------------------------------------------------
void atribuirCodigo(NO* atual, char* codigoBase) {
    char codigo[12];
   
    if(atual->direita != NULL) {
        char codigo[MAX_CODIGO];
       
        strcpy(codigo,codigoBase);
        strcat(codigo,"0");
        atribuirCodigo(atual->esquerda, codigo);
       
        strcpy(codigo,codigoBase);
        strcat(codigo,"1");
        atribuirCodigo(atual->direita, codigo);
    }
    else {
        printf("Caracter %c (%d) tem o codigo huffman = %s\n",atual->caracter,atual->caracter,codigoBase);    
        strcpy(atual->codigo,codigoBase);
    }    
}
//--------------------------------------------------------------------
char* obter(NO* atual, char c) {
    if(atual->caracter == c)
        return atual->codigo;
    if(atual->esquerda == NULL)
        return NULL;
    char* resultado = obter(atual->esquerda,c);
    if(resultado == NULL)
        resultado = obter(atual->direita,c);
    return resultado;
}
//--------------------------------------------------------------------
char* obterCodigo(char c) {
    NO* atual = arrayOcorrencias[0];
    return obter(atual,c);
}
//--------------------------------------------------------------------
void escreveBits(char* codigo) {
    for(int i = 0; i < strlen(codigo); i++) {
        int base = codigo[i] == '0'    ? 0 : 1 << posBit;
        buffer = buffer | base;
        posBit++;
        if(posBit == 8)    {
            fputc(buffer, arquivoCompactado);
            buffer = 0;
            posBit = 0;
        }        
    }    
}
//--------------------------------------------------------------------
void escreverCompactacao() {
    int i;        
    arquivoOriginal   = fopen("C:/Users/26011042/Documents/Exemplo.txt","rb");    
    arquivoCompactado = fopen("C:/Users/26011042/Documents/Exemplo.huffman","wb");    
    while(TRUE)    {
        int carac = fgetc(arquivoOriginal);
        if(carac == EOF) // EOF --> End of File
            break;                    
        char* codigoCarac = obterCodigo(carac);
        printf("%s",codigoCarac);
        escreveBits(codigoCarac);
    }    
    fclose(arquivoOriginal);
    fclose(arquivoCompactado);
}
//--------------------------------------------------------------------
int main() {
    verificarOcorrencias();
    imprimir(numCaracteres);
    gerarArvoreHuffman();
    atribuirCodigo(arrayOcorrencias[0],"");
    escreverCompactacao();
}