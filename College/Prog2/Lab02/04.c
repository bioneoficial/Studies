#include <stdio.h>
#include <time.h>
int main(){
  srand(time(NULL));
  int A[40], B[50], C[50],push,cont =0;
    for(int i = 0; i < 50;i++){
      if( i < 40){
      A[i] = rand() % 1000;
      }
      B[i] = rand() % 1000;
    };
      for(int i =0; i<50;i++){
        push = rand() % 1000;
        cont = 0;
        for(int j=0; j<50;j++){
          if(j < 40){
            if(push == A[j] || push == B[j]){
            cont++;
            };
          };
        };
       if( cont == 0 ){
         C[i] = push;
       }else{
         i -= 1;
         };      
      };
  return 0;
}