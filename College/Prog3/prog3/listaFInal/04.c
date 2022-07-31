#include <stdio.h>
int find_max(int  arr[2], int n);
void exchange(int  arr[2], int n);
int mdc( int numA, int numB);
int mmc(int numA, int numB, int numA2);
int main(void) {
  int numA = 40, numB = 60, resultado[2];
  resultado[1] = mdc(numA,numB);
  resultado[0] = mmc(numA,numB,numA);
  exchange(resultado, 2);
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
void exchange(int  arr[10],int n){
  int  temp, big, j;
  for ( j=n-1;  j>=1; j--){
    big =  find_max(arr,j);
    temp = arr[big];
    arr[big] = arr[j];
    arr[j] = temp;
  }
}
  int mdc( int numA, int numB){
    if (numB == 0)
      return numA;
    else
      return mdc(numB, numA % numB);
  }
int mmc(int numA, int numB, int numA2) {
    if ((numA % numB) == 0)
        return numA;
    else
        return mmc(numA + numA2, numB, numA2);
}