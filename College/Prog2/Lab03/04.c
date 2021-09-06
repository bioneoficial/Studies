#include <stdio.h>

void triangle(float a, float b, float c);

int main(){
  float c1,c2,h;
  printf("Insira 2 catetos e depois a hipotenusa\n");
  scanf("%f %f %f",&c1,&c2,&h);
  triangle(c1,c2,h);
  return 0;
}
void triangle(float c1,float c2,float h){
if(h*h < (c1*c1) + (c2 * c2)){
    printf("Game Over\n");
  }else{
    printf("é um triangulo retangulo\n");
  }
}

/*Escreva uma função que determina se três valores floateiros fornecidos
como parâmetros representam medidas de um triângulo retângulo. Suponha que
os parâmetros são fornecidos em ordem decrescente. */