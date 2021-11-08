#include <stdio.h>
#include <time.h>
int leitura(int *param, const int n);
void calculo(int *param, const int n);
int main () {
srand(time(NULL));
int vetor[30] = {0};
leitura(vetor,30);
calculo(vetor,30);
return 0;
}
int leitura(int *param, const int n){
int *const end = param + n;
for( ;param < end; ++param ){
*param = (rand() % 999) + 1;
}
return param;
}
void calculo(int *param, const int n){
int maior = 0, menor = 1000;
int *const end = param + n;
for( ;param < end; ++param ){
if(*param > maior){
maior = *param;
}
if(*param < menor){
menor = *param;
}
}
printf("Maior:%d - Menor:%d",maior,menor);
};