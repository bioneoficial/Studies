#include <stdio.h>
int find_max(int  arr[6], int n);
void exchange(int  arr[6], int n);
int main(void) {
  int camboinhas = 8, icarai = 30, itaipu = 15, sf= 3, centro = 56, sr = 6,temp;
  int sistema[6] = {camboinhas,icarai,itaipu,sf,centro};
  exchange(sistema,4);
    printf("\n\n");
  
  //sistema[5] = sr;
  temp = sr;
  for(int i = 0; i< 6; i++){
    int tempAux;
    if (i == 5){
      sistema[i] = temp;
      printf("%d\t",sistema[i]);
      break;
    }
      if(sistema[i] > temp){
          tempAux = sistema[i];
          sistema[i] = temp; 
          temp = tempAux; 
        }
    printf("%d\t",sistema[i]);
}
  return 0;
}
int find_max(int arr[6], int n){
   int max=0,j;
   for(j = 1; j <=  n; j++){
     if ( arr[j] >  arr[max]){
       max =  j;
     }
   }
    return(max);
  }
void exchange(int  arr[6],int n){
  int  temp, big, j;
  for ( j=n-1;  j>=1; j--){
    big =  find_max(arr,j);
    temp = arr[big];
    arr[big] = arr[j];
    arr[j] = temp;
  }
  for(int i = 0; i< 6; i++){
    if(arr[i])
      printf("%d\t",arr[i]);
    }
}