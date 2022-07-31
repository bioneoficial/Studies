#include <stdio.h>
int find_max(int  arr[5], int n);
void gerenteficoumaluco(int  arr[5], int n);
int main(void) {
  int array[5] = {1,2,3,4};
  gerenteficoumaluco(array, 4);
  return 0;
}
int find_max(int arr[5], int n){
   int max=0,j;
   for(j = 0; j <=  n; j++){
     if ( arr[j] <  arr[max]){
       max =  j;
     }
   }
    return(max);
  }
void gerenteficoumaluco(int  arr[5],int n){
  int  temp, big, j, aux= n;
  for ( j=n;  j>=0; j--){
      big =  find_max(arr,j);
      temp = arr[big];
      arr[big] = arr[j];
      arr[j] = temp;
    }
  for(int i = 0; i < n; i++){
    printf("%d\t", arr[i]);
  }
}