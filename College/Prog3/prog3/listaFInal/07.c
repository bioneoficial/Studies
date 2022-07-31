#include <stdio.h>
int find_max(int  arr[6], int n);
void exchange(int  arr[6], int n, int new[6]);
int main(void) {
  int cafifaCabresto[2] = {1,1},cafifaCabrestoNew[2] = {2,2}, cafifaSemC[2] = {0,0},total[6],filaNova[6];
  for(int queViagem = 0; queViagem < 6; queViagem += 2){
    total[queViagem] = cafifaCabresto[queViagem];
    total[queViagem + 1] = cafifaSemC[queViagem];
    if(queViagem == 2){
    total[queViagem] = cafifaCabresto[queViagem-1];
    total[queViagem + 1] = cafifaSemC[queViagem-1];
    }else if(queViagem == 4){
    total[queViagem] = cafifaCabrestoNew[queViagem-3];
    total[queViagem + 1] = cafifaCabrestoNew[queViagem-4];
    }
  }
  exchange(total, 6,filaNova);
    int contN = 0;
    for(int i =0; i < 6;i++){
      if(filaNova[i] == 2)
        contN++;
    }
  printf("\n%d Pipas Novas com Cabresto", contN);
  return 0;
}
int find_max(int arr[10], int n){
   int max=0,j;
   for(j = 1; j <=  n; j++){
     if ( arr[j] >  arr[max]){
       max =  j;
     }
   }
    return(max);
  }
void exchange(int  arr[10],int n, int new[6]){
  int  temp, big, j, contC = 0, contS= 0;
  for ( j=n-1;  j>=1; j--){
    big =  find_max(arr,j);
    temp = arr[big];
    arr[big] = arr[j];
    arr[j] = temp;
  
  }
  int aux = 0;
  for(int i =0; i < n;i++){
    arr[i] == 0 ? contS++ : contC++;
    if(arr[i] == 2){
      new[aux] = arr[i];
      aux++;
    }
  }
  printf("Total de %d Sem cabresto e %d com cabresto\n",contS,contC);
}