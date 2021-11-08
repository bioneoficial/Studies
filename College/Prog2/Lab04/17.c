#include <stdio.h>
#include <time.h>
int leitura(int *param, const int n);
void calculo(int *param, const int n);
int main () {
srand(time(NULL));
int vetor[20] = {0};
leitura(vetor,20);
calculo(vetor,20);
return 0;
}
int leitura(int *param, const int n){
int *const end = param + n;
for( ;param < end; ++param ){
*param = (rand() % 99) + 1;
}
return param;
}
void calculo(int *param, const int n){
int sum = 0, cont = 0, *aux = param;
int *const end = param + n;
for( ;param < end; ++param ){
sum += *param;
}
printf("sum = %d\n",sum);
if(sum % 2 == 0){
for( ;aux < end; ++aux ){
printf("Vetor[%d] = %d\n",cont ,*aux);
cont++;
}
} else{
for(cont = n - 1 ; cont >= 0; cont--){
param--;
printf("Vetor[%d] = %d\n",cont ,*param);
}
}
};