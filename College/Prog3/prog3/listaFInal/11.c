#include <stdio.h>
int find_min(int  arr[6], int n);
void exchange(int  arr[6], int n);
int main(void) {
  int A[3] = {38,963,938}, B[3] = {725,157,382}, AB[6], d = 3;
  for(int i = 0; i < 3; i++)
    AB[i] = A[i];
  for(int i = 0; i < 3; i++){
    AB[d] = B[i];
    d++;
  }
exchange(AB, 6);
    
  return 0;
}
int find_min(int arr[6], int n){
   int min=0,j;
   for(j = 1; j <=  n; j++){
     if ( arr[j] <  arr[min]){
       min =  j;
     }
   }
    return(min);
  }
void exchange(int  arr[6],int n){
  int  temp, small, j;
  for ( j=n-1;  j>=1; j--){
    small =  find_min(arr,j);
    temp = arr[small];
    arr[small] = arr[j];
    arr[j] = temp;
  }
  for(int i = 0; i< 6; i++){
    if(arr[i])
      printf("R$%d \t",arr[i]);
    }
}