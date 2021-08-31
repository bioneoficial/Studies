#include <stdio.h>

int main(void) {
 float dia1, dia2, dia3, dia4, dia5, packtotal;
 float litro1, litro2, litro3, litro4, litro5, litrototal, preço1, preço2, preço3, preço4, preço5, preçototal;
 float pack = 4.2, preço = 18;

  printf("Digite Quantos Packs Foram Consumidos Durante o 5 Dias,respectivamente:\n");
  scanf("%f %f %f %f %f",&dia1, &dia2, &dia3, &dia4, &dia5);

  litro1 = dia1 * pack;
  preço1 = dia1 * preço;
  litro2 = dia2 * pack;
  preço2 = dia2 * preço;
  litro3 = dia3 * pack;
  preço3 = dia3 * preço;
  litro4 = dia4 * pack;
  preço4 = dia4 * preço;
  litro5 = dia5 * pack;
  preço5 = dia5 * preço;

  packtotal = dia1 + dia2 + dia3 + dia4 + dia5;
  litrototal = litro1 + litro2 + litro3 + litro4 + litro5;
  preçototal = preço1 + preço2 + preço3 + preço4 + preço5;

  printf(" DIA 1:\n");
  printf("Foram Consumidos %.1f Pack(s) e %.1f Litros de Cerveja.Foram Gastos R$%.2f.\n\n",dia1,litro1,preço1);

  printf(" DIA 2:\n");
  printf("Foram Consumidos %.1f Pack(s) e %.1f Litros de Cerveja.Foram Gastos R$%.2f.\n\n",dia2,litro2,preço2);

  printf("DIA 3:\n");
  printf("Foram Consumidos %.1f Pack(s) e %.1f Litros de Cerveja.Foram Gastos R$%.2f.\n\n",dia3,litro3,preço3);

  printf("DIA 4:\n");
  printf("Foram Consumidos %.1f Pack(s) e %.1f Litros de Cerveja.Foram Gastos R$%.2f.\n\n",dia4,litro4,preço4);

  printf("DIA 5:\n");
  printf("Foram Consumidos %.1f Pack(s) e %.1f Litros de Cerveja.Foram Gastos R$%.2f.\n\n",dia5,litro5,preço5);
  
  printf("Durante o Carnaval Foram Consumidos %.1f Pack(s) e %.1f Litros de Cerveja.Foram Gastos R$%.2f.",packtotal,litrototal,preçototal);

  return 0;
}