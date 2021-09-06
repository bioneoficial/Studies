#include <stdio.h>
void reverse(int arr[], int index)
{
  int temp;
    for (int i = 0; i < index/2; i++) {
        temp = arr[i];
        arr[i] = arr[index-1-i];
        arr[index-1-i] = temp;
    }
    for(int i=0;i<index;i++){
      printf("%d\t",arr[i]);
    };
}
int main(){
  int arr[7] = {1,4,2,3,5,6,7};

  reverse(arr,7);
  //testei com par(6)e impar(7)

  return 0;
}
/*Escrever um procedimento, que inverta a ordem dos elementos de um vetor
sem usar um vetor auxiliar

 */