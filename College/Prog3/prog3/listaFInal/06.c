#include <stdio.h>
void bubbleSort(int arr[5], int n);
int main(void) {
int arr[5] = {21,94,12,45,33};
  bubbleSort(arr, 5);
  return 0;
}
void bubbleSort(int arr[5], int n){
    int temp;   
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i; j++){    
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j + 1] = temp;
            }
        }
    }
    for( int i = 0; i < n; i++){
      printf("%d\t", arr[i]);
    }
    }