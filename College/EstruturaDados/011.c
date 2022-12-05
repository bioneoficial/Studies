#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 




char* caracterParaBinario(int caracter) {
    static char binarioDeCaracter[9];
    sprintf(binarioDeCaracter,"%c%c%c%c%c%c%c%c",BYTE_TO_BINARY(caracter));
    return binarioDeCaracter;    
}


void buscaEmLargura() {    
    int nivel = 0;

    ALUNO*  nosDoNivelAtual[128];
    int     numElemNivelAtual = 1;    
    ALUNO*  nosDoNivelSeguinte[128];
    int     numElemProximoNivel = 0;    

    printf("\n\n\nBUSCA EM LARGURA\n\n\n");
    // Inicializo a busca em largura com a raiz
    nosDoNivelAtual[0] = raiz;
   
    //  Enquanto tenho algum nível para listar
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

int inserirNaArvore(ALUNO* novo, ALUNO* atual) {
    if(novo->matr > atual->matr) {
        if(atual->direita == NULL) {        
            atual->direita = novo;
            if(atual->esquerda == NULL)
                atual->peso++;
        }
        else {    
            int pesoRetornado = inserirNaArvore(novo, atual->direita);                    
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
            int pesoRetornado = inserirNaArvore(novo, atual->esquerda);
            if(pesoRetornado == atual->peso)
                atual->peso++;
        }
    }
    return atual->peso;
}

int buf;
int  posBit = -1;

int leBit() {
    if(posBit == -1)    {
        buf = fgetc(arquivoCompactado);
        if(buf == EOF)
            return -1;
        posBit = 7;
    }        
    int base = 1 << posBit;
    posBit--;
    return (buf & base) == base ? 1 : 0; // retorna 0 ou 1
}