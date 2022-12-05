#include <stdio.h>
#include <string.h>

#define TRUE      1
#define TAM_MATR  10
#define TAM_NOME  80

typedef struct {
    char matr[TAM_MATR + 1];
    char nome[TAM_NOME + 1];
} ALUNO;


int main() {
    FILE*  arquivo;
    ALUNO  registro;
   
    //
    // Abrindo um arquivo binário para Append e inserção de novos registros
    //
    arquivo = fopen("c:\\Temp\\alunos.dat","ab");    
    while(TRUE) {
        printf("Entre com os dados do aluno ou [ENTER] para terminar\n");
        printf("====================================================\n");
        printf("Matr: ");
        fflush(stdout);
        gets(registro.matr);
        if(strlen(registro.matr) == 0)
            break;
        printf("Nome: ");
        fflush(stdout);
        gets(registro.nome);
        fwrite(&registro, sizeof(ALUNO), 1, arquivo);
    }
    fclose(arquivo);
   
   
    //
    // Mostrando todos registros presentes no arquivo
    //
    printf("====================================================\n");
    int tam;
    arquivo = fopen("c:\\Temp\\alunos.dat","rb");
    while(TRUE) {
        tam = fread(&registro, sizeof(ALUNO),1,arquivo);
        if(tam == 0)
            break;
        printf("Matr: %s\n",registro.matr);
        printf("Nome: %s\n",registro.nome);        
    }
    //
    // Verificando o tamanho do arquivo e descobrindo quantos registros
    // há nele
    //
    fseek(arquivo, 0L, SEEK_END);
    int tamArq = ftell(arquivo);
    printf("O arquivo tem %d bytes, logo tem %d registros\n\n", tamArq, tamArq/sizeof(ALUNO));
   
    //
    // Listando um determinado registro
    //
    int posicao;    
    printf("Entre com o número do registro a ser listado: ");
    scanf("%d",&posicao);
    fseek(arquivo, sizeof(ALUNO) * posicao, 0);
    tam = fread(&registro, sizeof(ALUNO),1,arquivo);
    printf("Matr: %s\n",registro.matr);
    printf("Nome: %s\n",registro.nome);        
    fclose(arquivo);
}
