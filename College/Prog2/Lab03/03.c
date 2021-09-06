#include <stdio.h>

float media(float m1, float m2, float m3, char op);

int main(){
  char op;
  float nota1,nota2,nota3;
  printf("De as 3 notas:\n");
  scanf("%f %f %f",&nota1,&nota2,&nota3);
  printf("Digite 'A' para calcular media simples ou 'P' para média ponderada");
  scanf(" %c", &op);
  printf("%.2f",media(nota1,nota2,nota3,op));
  return 0;
}

float media(float m1, float m2, float m3, char op){
  float mt;
  if(op == 'A' || op == 'a'){
     mt = (m1+m2+m3) / 3;
  }else if(op =='P' || op == 'p'){
     mt = ((m1*5)+(m2*3)+(m3*2)) / 10;
  }else{
    return printf("Trolla n parça\n");
  }
  return mt;
}
/* Faça uma função que receba três notas de um aluno com parâmetros e uma
letra. Se a letra for A o procedimento calcula a média das notas do aluno,
se for P o procedimento calcula a média ponderada com pesos 5,3 e 2. A
média calculada deve ser devolvida ao programa principal para, então ser
mostrada. */