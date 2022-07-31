#include <stdio.h>
  int find_max(int agencias[40], int n);
  void exchange(int agencias[40], int premium[40], int n);
  void print(int agencias[40], int n);
  void addAgency(int agencias[40]);
  int main(){
  int i, j, k, n = 40, temp;
  int premium[40];
    
    int agencias[40] = {2812, 9730, 4088, 4794, 3513, 1162, 526, 2619, 5025, 6947, 2236, 1424,
3582, 1432, 1561, 2918, 2759, 4826, 9376, 4718, 3877, 912, 2338, 6086, 411, 126, 1376,
8922, 2066, 4343};
// 30 agencias
  addAgency(agencias);
  exchange(agencias,premium,n);


    
}
  int find_max(int agencias[40], int n){
    int max=20,j;
    for(j = 20; j <=  n; j++){
      if ( agencias[j] >  agencias[max]){
        max =  j;
      }
    }
    return(max);
  }
  void exchange(int agencias[40],int premium[40],int n){
    int  temp, big, j,index = 0; //4718 a partir
    for ( j=n-1;  j>=1; j--){
      if(j <= 20){
        break;
      }
      big =  find_max(agencias,j);
      temp = agencias[big];
      agencias[big] = agencias[j];
      agencias[j] = temp;
    }
    for(int i = 0; i< n;i++){
      if(agencias[i] % 10 == 6){
        premium[index] = agencias[i];
        index++;
      }
    }
    printf("Array dos valores:\n");
    print(agencias,n);
    printf("Array dos valores:\n");
    print(premium,index);
    return ;
  }
  void print(int agencias[40], int n){
    for(int i=0; i< n ;  i++){
      printf("%d ",agencias[i]);
    }
    printf("\n");    
  }
  void addAgency(int agencias[40]){
    int adicionar[10] = {6113, 4696, 6192, 1606, 3261, 9809, 4132, 6427, 4224, 6136},j, i = 0;
    for(j = 30; j <  40; j++){
      agencias[j] = adicionar[i];
      i++;
    }
  }