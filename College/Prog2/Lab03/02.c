#include <stdio.h>

int secondsToTime(int x);
int main(){
  int sec;
  printf("De segundos:\n");
  scanf("%d",&sec);
  printf(secondsToTime(sec));

  return 0;
};
int secondsToTime(int x){
  int min,hour;
  min = x / 60;
  x = x % 60;
  hour = min/60;
  min = min % 60;
  if(hour < 10){
    if(min < 10){
      if(x<10){
        return printf("Horário:0%d:0%d:0%d\n",hour,min,x);
      }
      return printf("Horário:0%d:0%d:%d\n",hour,min,x);
    }
    if(x<10){
        return printf("Horário:0%d:%d:0%d\n",hour,min,x);
      }
      return printf("Horário:0%d:%d:%d\n",hour,min,x);
  }

  return printf("Horário:%d:%d:%d\n",hour,min,x);
};
