main.c
Earlier this month
Mar 12

You created an item in
Google Drive Folder
[2022.1] Programação de Computadores III SINF03MAG4A
C
main.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ex01(int *vetor1){
    short cont = 0;
while(cont < 9){
    for(int i = 0; i < 9; i++){
        if(cont == 0 && vetor1[i] == 5)
            printf("%d ", vetor1[i]);
        else if(cont == 1 && vetor1[i] == 2)
            printf("%d ", vetor1[i]);
        else if(cont == 2 && vetor1[i] == 7)
            printf("%d ", vetor1[i]);
        else if(cont == 3 && vetor1[i] == 4)
            printf("%d ", vetor1[i]);
        else if(cont == 4 && vetor1[i] == 9)
            printf("%d ", vetor1[i]);
        else if(cont == 5 && vetor1[i] == 3)
            printf("%d ", vetor1[i]);
        else if(cont == 6 && vetor1[i] == 6)
            printf("%d ", vetor1[i]);
        else if(cont == 7 && vetor1[i] == 8)
            printf("%d ", vetor1[i]);
        else if(cont == 8 && vetor1[i] == 0)
            printf("%d ", vetor1[i]);
    }
    cont++;
}
}
void ex02(int vetor2[7][7]){
    long somaD = 0, somaP = 0;
    for(int i = 0; i< 7; i++) {
        for (int k = 0; k < 7; k++) {
            if(vetor2[i][k] % 2 == 0)
                somaP += vetor2[i][k];
            if (i == k)
                somaD += vetor2[i][k];
        }
    }

    printf("\nSoma da diagonal principal = %d",somaD);
    printf("\nSoma dos pares = %d\n",somaP);
}
#define linha3 5
#define coluna3 5
void ex03(int vetor3[linha3][coluna3]){
    short cont = 0;
    for(int i = 0; i< linha3; i++) {
        for (int k = 0; k < coluna3; k++) {
             if(vetor3[i][k] != 0 && vetor3[i][k] != 1) {
                 cont++;
             }
        }
    }
    if(cont == 0)
        printf("\nMatriz no padrao de conjuntos 0 e 1");
    else
        printf("\nFora do padrao por %d valores", cont);

}
int main() {
    srand(time(NULL));
    int vetor1[9] = {5,7,6,9,2,8,4,0,3};
    ex01(vetor1);
    int vetor2[7][7];
    printf("\n");
    for(int i = 0; i< 7; i++) {
        for (int k = 0; k < 7; k++) {
            vetor2[i][k] = rand() % 10;
            printf("Vetor[%d][%d]: %d ",i,k,vetor2[i][k]);
        }
        printf("\n");
    }
    ex02(vetor2);
    int vetor3[linha3][coluna3];
    for(int i = 0; i< linha3; i++) {
        for (int k = 0; k < coluna3; k++) {
            vetor3[i][k] = rand() % 3;
            printf("Vetor[%d][%d]: %d ",i,k,vetor3[i][k]);
        }
        printf("\n");
    }
    ex03(vetor3);
   return 0;
}