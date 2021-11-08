#include <stdio.h>
int ultima (char *string, char c);
int primeira(char *string, char c);
int main () {
char str[ ]="teste";
int q=ultima(str, 't'); /* q recebe 3 */
printf("\n %d",q);
q=primeira(str, 'e'); /* q recebe 1 */
printf("\n %d",q);
return 0;
}
int ultima (char *string, char c){
short index,cont = 0;
while(*string){
if(*string == c){
index = cont;
}
cont++;
string++;
}
if(index){
return index;
}
return -1;
}
int primeira(char *string, char c){
short index = 0;
while(*string){
if(*string == c)
return index;
index++;
string++;
}
return -1;
}