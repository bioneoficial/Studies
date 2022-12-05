#include <stdio.h>
#include <stdlib.h>

#define TRUE 1

typedef struct _No {
    char caracter;
    int  peso;
    struct _No* direita;
    struct _No* esquerda;
} NO;

int main() {
    FILE* arquivo;
    NO*   array[256];
    int numCaracteres = 0;
    int i;    
   
    arquivo = fopen("C:/Users/26011042/Documents/Exemplo.txt","rb");    
    while(TRUE)    {

        int carac = fgetc(arquivo);
        if(carac == EOF)
            break;            
        for(i = 0; i < numCaracteres; i++) {
            if(carac == array[i]->caracter) {
                array[i]->peso++;
                break;
            }
        }
        // Se eu não encontrei o caracter no array,
        // então i == numCaracteres
        if(i == numCaracteres) {
            NO* novo = (NO*)malloc(sizeof(NO));
            array[i] = novo;
            array[i]->caracter = carac;
            array[i]->peso = 1;
            array[i]->direita = NULL;
            array[i]->esquerda = NULL;
            numCaracteres++;
        }
    }    
    fclose(arquivo);
    // Listando as ocorrências do arquivo
    printf("O arquivo tem %d caracteres diferentes!\n\n",numCaracteres);
    for(i = 0; i < numCaracteres; i++) {
        printf("O caracter %c (ASCII codigo %d) ocorreu %d vezes\n",
            array[i]->caracter,array[i]->caracter,array[i]->peso);        
    }
}