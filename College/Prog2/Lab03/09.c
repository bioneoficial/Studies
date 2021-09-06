#include <stdio.h>

void triangle(float a, float b, float c);
int main(){
  float c1,c2,h;
  printf("Insira a hipotunesa e 2 catetos:\n");
  scanf("%f %f %f",&h,&c1,&c2);
  triangle(h,c1,c2);
  return 0;

}
void triangle(float h,float c1,float c2){
if(h*h < (c1*c1) + (c2 * c2)){
    printf("Game Over\n");
  }else{
    printf("é um triangulo retangulo\n");
  }
}
/*
Escreva uma função que determina se três valores inteiros fornecidos
como parâmetros representam medidas de um triângulo retângulo. Suponha que
os parâmetros são fornecidos em ordem decrescente. */