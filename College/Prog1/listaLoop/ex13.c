#include <stdio.h>

int main(void) {
  char sexo,olho,cabelo;
  int i,age,maiorI=0,contM=0,contF=0,contFT=0;
  float percentF;


  for(i=0;i<5;i++){
  printf("Sexo? 'm' ou 'f'\n");
  scanf(" %c", &sexo);
  printf("Olho: 'a' ou 'v' ou 'c':\n");
  scanf(" %c", &olho);
  printf("Cabelo: 'l' ou 'c' ou 'p'\n");
  scanf(" %c", &cabelo);
  printf("idade: '15' ou '20' ou outro número:\n");
  scanf("%d", &age);

  if(age>maiorI){
    maiorI= age;
  }

  switch(sexo){
    case 'm':
    if(age<18){
      contM++;
    } break;

    case 'f':
    contFT++;
    if(age>18 && age<35 && cabelo == 'l' && olho == 'v'){
      contF++;
    }
    break;
    default:
    printf("invalido, comece do 0 pra deixar de ser bobao");
    return 0;
  }
  }
  percentF = contF*100 / contFT;
  printf("maior idade:%d\n",maiorI);
  printf("%% das femeas seguindo as regras do enunciado:%.2f percent hehe\n",percentF);
  printf("%d meninos -18\n",contM);
  
  return 0;
}