#include <stdio.h>
int totalpos(char *string, char let);
int main () {
int num;
num = totalpos("internet", 'e'); /*retorna 9 (3+6) */
printf("%d\n",num);
num = totalpos("internet", 'i'); /*retorna 0 (0) */
printf("%d\n",num);
num = totalpos("internet", 'a'); /*retorna -1 */
printf("%d\n",num);
return 0;
}
int totalpos(char *string, char let){
int cont = 0, sum = 0, flag = 0;
while(*string){
if(*string == let){
sum += cont;
flag++;
}
cont++;
string++;
}
if(flag != 0)
return sum;
return -1;
}