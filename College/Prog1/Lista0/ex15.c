#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int i;
  float a,b,c;
  printf("Escreva 3 valores númericos em sequencia, gatinha\n");
  scanf("%f %f %f",&a,&b,&c);
  printf("Digite 1 ou 2 ou 3\n");
  scanf("%d",&i);
  
if(i<0 || i>3){
  printf("\n\tLEIA O ENUNCIADO E TENTE NOVAMENTE\n");
  main("pause");
}

   if (i == 1){

     printf("\nordem crescente\n");
     
if (a > b && a > c && b > c){
printf("\n%.f\n%.f\n%.f",c,b,a);
}

else if (a > b && a > c && c > b){
printf("\n%.f\n%.f\n%.f",b,c,a);
}

else if ( b > a && b > c && a > c){
printf("\n%.f\n%.f\n%.f",c,a,b);
}

else if ( b > a && b > c && c > a){
printf("\n%.f\n%.f\n%.f",a,c,b);
}

else if ( c > a && c > b && b > a){
printf("\n%.f\n%.f\n%.f",a,b,c);
}

else if ( c > a && c > b && a > b){
printf("\n%.f\n%.f\n%.f",b,a,c);
}
}


if ( i == 2){

printf("\nordem decrescente\n");

if (a < b && a < c && b < c){

printf("\n%.f\n%.f\n%.f",c,b,a);
}

else if (a < b && a < c && c < b){

printf("\n%.f\n%.f\n%.f",b,c,a);
}

else if ( b < a && b < c && a < c){

printf("\n%.f\n%.f\n%.f",c,a,b);
}

else if ( b < a && b < c && c < a){

printf("\n%.f\n%.f\n%.f",a,c,b);
}

else if ( c < a && c < b && b < a){

printf("\n%.f\n%.f\n%.f",a,b,c);
}

else if ( c < a && c < b && a < b){

printf("\n%.f\n%.f\n%.f",b,a,c);
}
}

if ( i == 3 ){
printf("\nOrdem com o maior no meio");

if (a < b && a < c && b < c){

printf("\n%.f\n%.f\n%.f",b,c,a);
}

else if (a < b && a < c && c < b){

printf("\n%.f\n%.f\n%.f",c,b,a);
}

else if ( b < a && b < c && a < c){

printf("\n%.f\n%.f\n%.f",a,c,b);
}

else if ( b < a && b < c && c < a){

printf("\n%.f\n%.f\n%.f",c,a,b);
}

else if ( c < a && c < b && b < a){

printf("\n%.f\n%.f\n%.f",b,a,c);
}

else if ( c < a && c < b && a < b){

printf("\n%.f\n%.f\n%.f",a,b,c);
}

}

  return 0;
}






