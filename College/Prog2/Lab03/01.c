#include <stdio.h>

int sum(int x,int y);

int main(){

int a = 1, b =2;
printf("%d",sum(a,b));
  
  return 0;
}
int sum(int x,int y){
  return x+y;
};