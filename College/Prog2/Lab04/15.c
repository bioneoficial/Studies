#include <stdio.h>
int divisao(int a, int b, int *r);
int main () {
int r, d;
d = divisao(5, 2, &r);
printf("Resultado:%d - Resto:%d", d, r); /* Resultado:2 -
Resto:1 */
return 0;
}
int divisao(int a, int b, int *r){
*r = a % b;
return a / b;
}