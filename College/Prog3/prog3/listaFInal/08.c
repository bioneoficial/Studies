#include <stdio.h>
int find_max(int  arr[4], int n);
void exchange(int  arr[4], int n);
int main(void) {
  int vetor[4] = {43,96,39,1};
  exchange(vetor,4);
  for(int i = 0; i< 4; i++)
    printf("%d \t",vetor[i]);
  return 0;
}
int find_max(int arr[4], int n){
   int max=0,j;
   for(j = 1; j <=  n; j++){
     if ( arr[j] >  arr[max]){
       max =  j;
     }
   }
    return(max);
  }
void exchange(int  arr[4],int n){
  int  temp, big, j;
  for ( j=n-1;  j>=1; j--){
    big =  find_max(arr,j);
    temp = arr[big];
    arr[big] = arr[j];
    arr[j] = temp;
  }
}