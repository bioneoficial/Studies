#include <stdio.h>
  int find_max(int  arr[10], int n);
  void exchange(int  arr[10], int n);
  void print(int arr[10], int n);
  int contador(int arr[10], int arr2[10], int n);
  int totalRegIncome = 0, totalRegOutcome = 0, totalIncome = 0, totalOutcome = 0;
  int main(){
  int arr[10], arr2[10], i, j, k, n, temp;
  do{
    printf("\n Insira numero de registros corretamente: ");
    scanf("%d",&n);
    if( n > 0 && n <= 10)
      break;
    }while(1);
  for(i=0; i<n ;  i++){
    printf("\nInsira valor do registro: ");
    scanf("%d",&arr[i]);
    if(arr[i] < 0){
      i--;
      continue;
    }
    again:
    printf("\nInsira 0 para outcome 1 para income: ");
    scanf("%d",&arr2[i]);
    if(arr2[i] != 0 && arr2[i] != 1){
      printf("\nValor invalido, 0 ou 1: ");
      goto again;
    }
  }
  contador(arr,arr2,n);
  exchange(arr,n);
  printf("Array dos valores:\n");
  print(arr,n);
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
  void exchange(int  arr[10],int n){
    int  temp, big, j;
    for ( j=n-1;  j>=1; j--){
      big =  find_max(arr,j);
      temp = arr[big];
      arr[big] = arr[j];
      arr[j] = temp;
    }
    return ;
  }
  void print(int arr[10], int n){
    for(int i=0; i< n ;  i++){
      printf("$%d\n",arr[i]);
    }
  }
  int contador(int arr[10], int arr2[10], int n){
      if(arr2[n] == 1){
      totalRegIncome++;
      totalIncome += arr[n];
      }else if(arr2[n] == 0){
      totalRegOutcome++;
      totalOutcome += arr[n];
    }
    n--;
    if(n < 0){
    printf("Total reg income = %d \n", totalRegIncome);
    printf("Valor total income = $%d \n", totalIncome);
    printf("Total reg outcome = %d \n", totalRegOutcome);
    printf("Valor total outcome = $%d \n", totalOutcome);
    printf("Valor total = $%d \n", (totalIncome - totalOutcome)); 
      return -1;
    }else{
    return contador(arr,arr2,n);
    }
  }
