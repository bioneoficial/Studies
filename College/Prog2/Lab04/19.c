#include <stdio.h>
int substitui(char *string, char c1, char c2);
int main () {
char txt[ ] = "recupera";
int num;
num = substitui(txt, 'e', 'X');
printf("%d - %s", num, txt); /* 2 - rXcupXra */
return 0;
}
int substitui(char *string, char c1, char c2){
int cont = 0;
while(*string){
if(*string == c1){
*string = c2;
cont++;
}
string++;
}
return cont;
}