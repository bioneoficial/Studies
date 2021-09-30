#include <stdio.h>
#include <stdlib.h>
int main() {
int R,cem,cinquenta,dez,cinco,um,resto;
  printf("Insira o valor que deseja sacar em reais, não possuimos moedas:\n");
  scanf("%d",&R);
if(R<0){
  main("pause");
}
cem= (R/100);
R= R % 100;
cinquenta=(R/50);
R=R%50;
dez=(R/10);
R=R%10;
cinco=(R/5);
R=R%5;
um=(R/1);

printf("O valor %d foi sacado em  %d nota(s) de 100\n%d Nota(s) de 50\n%d Nota(s) de 10\n%d Nota(s) de 5\n%d Nota(s) de 1.",R,cem,cinquenta,dez,cinco,um);
  return 0;
}






/* 5.  Escreva um programa para um terminal de banco, que recebe um valor inteiro R e determina o número de notas de 100, 50, 10, 5 e 1 reais necessárias para pagar a quantia R. Faça de forma que o número de notas usado seja o menor possível. 

    Exemplo: para R ⇒ 45 deve dar: 

    0 notas de 100

    0 notas de 50

    4 notas de 10

    1 notas de 5

    0 notas de 1

    ps: lembre-se das propriedades de divisão e de resto! 

    - Ainda com dúvida? Clique na seta a esquerda para desbloquear uma dica 
    Exemplo: para R ⇒ 45 deve dar: 
    0 notas de 100

0 notas de 50

4 notas de 10

1 notas de 5

0 notas de 1*/