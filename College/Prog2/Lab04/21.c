#include <stdio.h>
int contadepois(char *string, char let);
int main () {
int var;
var = contadepois("avaliando", 'a'); /*8 */
printf("%d\n",var);
var = contadepois("avaliando", 'o'); /*0 */
printf("%d\n",var);
var = contadepois("avaliando", 'x'); /*-1 */
printf("%d\n",var);
return 0;
}
int contadepois(char *string, char let){
int cont = 0, flag = 0;
while(*string){
if(flag != 0)
cont++;
if(*string == let)
flag++;
string++;
}
if(flag != 0)
return cont;
return -1;
}