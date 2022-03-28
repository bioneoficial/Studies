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

#define vetorlen 8
int function01(int a){ //ex01
    if(a <= 1)
        return -1;
    printf("%d\n",--a);
    return function01(a--);
}
int potenciaInt(int base, int expoente){ //ex02
    return expoente == 0 ? 1: base * potenciaInt(base, expoente -1);
}
int function03(int a){ //ex03
    return a<= 1 ? 1: a * function03(a - 1);

}
int omega(int a,int b,int c){ //ex04
    if(a == b){ //  c == soma
        int cont = 0;
        for( int i = 2 ; i <= 10000; i++){
             cont = 0;
            for(int j = 1; j <= i ; j++){
                if(i % j == 0)
                    cont++;
            }
            if(cont == 2)
                printf("Numero Primo: %d\n", i);
        }
        return c;
    }
    if(b <= a) { // vai somando
        return a % b == 0 ? omega(a, b + 1, c + b): omega(a,b+1,c);
    }
}
int function05(int *vetor5, int b, int c){ //ex05
    if(b == 0) {
        c = vetor5[b];
    }
    if(c < vetor5[b+1])
        c = vetor5[b+1];
   return ( b == vetorlen - 2) ? c:function05(vetor5,b+1,c);
}
int function06(int *vetor6, int el, int index){
    if(index == vetorlen)
        return -1;
    return vetor6[index] == el ? index: function06(vetor6,el,index+1);
}
int main() {
    srand(time(NULL));
    int a;
    printf("Insira 1 numero positivo!\n");
    scanf("%d",&a);
    if(a < 0)
        return 0;
    function01(a);
    int base, expoente;
    printf("Insira Base e Expoente!\n");
    scanf("%d %d", &base, &expoente);
    printf("%d\n",potenciaInt(base,expoente));
    printf(("Insira n para fatorial\n"));
    scanf("%d",&a);
    printf("%d\n",function03(a));
    printf("Insira N positivo para omega\n");
    scanf("%d",&a);
    printf("Os numeros primos e divisores de N sao:\n");
    printf("Soma: %d\n",omega(a,1,0));
   int vetor[vetorlen];
    for(int i = 0; i < vetorlen;i++) {
        vetor[i] = rand() % 1000;
        printf("vetor[%d] = %d\t",i,vetor[i]);
    }
   printf("\nMaior valor = %d\n", function05(vetor, 0, 0));
    printf("Digite elemento a ser encontrado\n");
    int el;
    scanf("%d",&el);
   if(function06(vetor,el,0) == -1)
       printf("\nNAO contem \n");
   else
     printf("\nIndex  = %d\n", function06(vetor,el,0));

   return 0;
}