#include <stdio.h>
  int find_max(char  ar[16], int n);
  void exchange(char  ar[16], int n);
  void print(char ar[16], int n);
  int main(){
  int i, j, k, n = 16, temp;
    char ar[16] = {'W','N','G','F','G','W','N','F','G','N','N','F','W','F','W','G'};

  exchange(ar,n);
}
  int find_max(char ar[16], int n){
    int max=0,j;
    for(j = 1; j <=  n; j++){
      if ( ar[j] >  ar[max]){
        max =  j;
      }
    }
    return(max);
  }
  void exchange(char  ar[16],int n){
    int  temp, big, j, w = 0, nes = 0, g = 0, f = 0,auxAr[16];
    for ( j=n-1;  j>=1; j--){
      big =  find_max(ar,j);
      temp = ar[big];
      ar[big] = ar[j];
      ar[j] = temp;
    }
    temp = 0;
    for(int i=n-1; i>= 0 ;  i--){
      auxAr[temp] = ar[i];
      temp++;
    }
    for(int i=0; i< n ;  i++){
      ar[i] = auxAr[i];
      ar[i] == 'W' ? w++: ar[i] == 'N' ? nes++: ar[i] == 'G' ? g++:f++;
      printf("%c ",ar[i]);
    }
    printf("\n");
    printf("A quantidade de Wafer foi %d, Nesfit %d,Goiabinha %d,Fandangos %d.\n",w,nes,g,f);
    return ;
  }
  void print(char ar[16], int n){
    int w = 0, nes = 0, g = 0, f = 0;
    for(int i=0; i< n ;  i++){
      ar[i] == 'W' ? w++: ar[i] == 'N' ? nes++: ar[i] == 'G' ? g++:f++;
      printf("%c ",ar[i]);
    }
    printf("\n");
    printf("A quantidade de Wafer foi %d, Nesfit %d,Goiabinha %d,Fandangos %d.\n",w,nes,g,f);
    
  }