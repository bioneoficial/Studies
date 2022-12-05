#include <stdio.h>
#include <string.h>

//  Exercício:
//  Criar um array com 13 registros de ALUNO (matr e nome)
//  Realizar a leitura dos registros,
//  Preencher o array mantendo-o ordenado,
//  Depois pedir a matr e listar o nome implementando uma
//  Busca binária.

#define TAM_NOME  40
#define TAM_ARRAY 5

// Definição de tipos
typedef struct {
    int  matr;
    char nome[TAM_NOME + 1];
} ALUNO;

// Variáveis Globais
ALUNO  registros[TAM_ARRAY];

//-----------------------------------------------------------------

void preencherArray() {
   
    for(int i = 0; i < TAM_ARRAY; i++) {
        printf("Entrando com o Registro #%d\n", (i+1));
        printf("Entre com a matr: ");
        scanf("%d",&registros[i].matr);
        fflush(stdin);
        printf("Entre com o nome: ");
        gets(registros[i].nome);
        printf("-------------------------------------\n");
    }    
}

//-----------------------------------------------------------------

void ordenarArray() {
    for(int i = 0; i < TAM_ARRAY-1; i++) {
        // Descobrindo o registro com a menor matr entre
        // a posição i e TAM_ARRAY-1
        int posMenor = i;
        for(int j = i + 1; j < TAM_ARRAY; j++) {
            if(registros[j].matr < registros[posMenor].matr)
                posMenor = j;
        }
        // Vamos trocar de posição o registros[posMenor]
        // com o registros[i]
        int auxMatr = registros[i].matr;
        char auxNome[TAM_NOME + 1];
        strcpy(auxNome, registros[i].nome);

        registros[i].matr = registros[posMenor].matr;
        strcpy(registros[i].nome, registros[posMenor].nome);

        registros[posMenor].matr = auxMatr;
        strcpy(registros[posMenor].nome, auxNome);
    }
}

//-----------------------------------------------------------------

void realizarBuscaBinaria() {
    int valor;
    printf("Entre com a matr: ");
    scanf("%d",&valor);
    int inicio = 0;
    int fim = TAM_ARRAY-1;
    while(1) {
        int meio = (inicio+fim)/2;
        if(registros[meio].matr == valor) {
            printf("O nome eh %s\n", registros[meio].nome);
            break;
        }
        if(registros[meio].matr < valor)
            inicio = meio + 1;
        else
            fim = meio - 1;
        if(inicio > fim) {
            printf("Registro não encontrado!");
            break;
        }
    }
}
//-----------------------------------------------------------------

int main() {
    preencherArray();
    ordenarArray();
    realizarBuscaBinaria();
}