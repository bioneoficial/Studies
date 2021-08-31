#include <stdio.h>

int main(void) {
  int inf, inc, sup,resp,num=0;
  printf("Insira um num para lim inf:\n");
  scanf("%d",&inf);
  printf("Insira um num para lim sup:\n");
  scanf("%d",&sup);
  printf("Insira um num para incrementarmos no num inf:\n");
  scanf("%d", &inc);

  if(inf<sup){
    num = inf;
    printf("%d\n",inf);
    while(num<sup){
      num += inc;
      if(num <= sup){
      printf("%d\n",num);
      }
    }
    if(sup != num){
      printf("%d\n",sup);
      }
  }
    else if(inf == sup){
      printf("%d\n",sup);
      printf("%d\n",inf);
    }


    else{
    printf("%d\n",inf);
    num = inf;
    while(num<=inf && num > sup){
            num += inc;
            if(num<=inf && num >= sup){
      printf("%d\n",num);
          }           
    }
    if(sup != num){
    printf("%d\n",sup);
    }
   
  }
  
  return 0;
}