#include <stdio.h>




int main(){
  int v1[4] = {1,2,3,4},v2[4] = {0,2,5,3},arrayLength = 4, count = 0;

  for(int i = 0; i<arrayLength;i++){
    for(int j = 0; j<arrayLength;j++){
      if(v1[i] == v2[j]){
      count++;
      }
    }
  }
  printf("%d",count);
  return 0;
}