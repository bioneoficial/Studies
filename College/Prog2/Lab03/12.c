#include <stdio.h>
void pesquisa(int arr[], int index, int param){
  int i = 0;
  while(i < index){
    if(param == arr[i]){
      printf("Índice:%d\n",i);
      break;
    }else{
      i++;
    }
  }
  i == index ? printf("Elemento ñ pertence ao vetor."):0;
}
int main(){
  int arr[10] = { 1,2,3,4,5,6,7,8,9,0};
  printf("Chute um numero de 0 a 15:\n");
  int num;
  scanf("%d",&num);
  pesquisa(arr,10,num);

  return 0;
}
/* Faça um modulo que, pesquisando num vetor ordenado fornecido por
parâmetro, obtenha o índice de um dado elemento. O elemento a pesquisar é
também fornecido por parâmetro. Se o elemento não existir o módulo deve
sinalizar.
*/