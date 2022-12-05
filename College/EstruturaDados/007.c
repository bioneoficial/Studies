#include <stdio.h>
#include <string.h>

#define TRUE 1

int main() {
    FILE* arquivo;
    char matr[10];
    char nome[80];
   
    arquivo = fopen("c:\\Temp\\alunos.txt","w");    
    while(TRUE) {
        printf("Entre com os dados do aluno ou [ENTER] para terminar\n");
        printf("====================================================\n\n");
        printf("Matr: ");
        fflush(stdout);
        gets(matr);
        if(strlen(matr) == 0)
            break;
        printf("Nome: ");
        fflush(stdout);
        gets(nome);
        fprintf(arquivo,"%s\n",matr);
        fprintf(arquivo,"%s\n",nome);
    }
    fclose(arquivo);
}