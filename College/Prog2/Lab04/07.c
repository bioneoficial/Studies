#include <stdio.h>
int main () {
int x = 10;
int *px = &x;
*px /= 5;
printf("%d == %d", *px, x);
return 0;
}