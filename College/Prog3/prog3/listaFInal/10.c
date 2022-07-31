#include <stdio.h>
#include <string.h>
struct client  
{  
    char name[20];  
    double value;  
};  
int find_max(struct client paramS[7], int n);
void exchange(struct client paramS[7], int n);

int main(void) {
  struct client clients[7] = {{"Marcelo", 4500},{"Maria", 4500} , {"Ana", 6700}, {"Antonio", 8000}, {"Ferdinando", 4800}, {"Zardo", 5670}, {"Arnoldo", 6700}}; 
  exchange(clients, 7);
   // printf("Enter the name and value ");  
    //scanf("%s %lf",s1.name,&s1.value);  
    //printf("Enter the name and value ");   
    //scanf("%s %lf",s2.name,&s2.value);   
   // printf("Printing the details....\n");  
   // printf("%s %.2lf\n",s1.name,s1.value);  
    //printf("%s %.2lf\n",s2.name,s2.value);  
   // printf("\n\n");
  return 0;
}
int find_max(struct client paramS[7], int n){
   int max=0,j;
   for(j = 0; j <=  n; j++){
     if ( paramS[j].value >  paramS[max].value){
       max =  j;
     }
   }
    return(max);
  }
void exchange(struct client paramS[7],int n){
  int  temp, big, j;
  char str1[20];
  for ( j=n-1;  j>=0; j--){
    big =  find_max(paramS,j);
    temp = paramS[big].value;   
    paramS[big].value = paramS[j].value;
    paramS[j].value = temp;
    strcpy(str1, paramS[big].name); 
    strcpy(paramS[big].name, paramS[j].name);
    strcpy(paramS[j].name, str1);
  }
  for(int i = 0; i< 7; i++){
      printf("%s %.2lf\n",paramS[i].name,paramS[i].value);
    }
}
//maria ok
// marcelo ok change cima
// ferdinando ok
// zardo ok
// arnoldo ok
// ana ok
//antonio ?