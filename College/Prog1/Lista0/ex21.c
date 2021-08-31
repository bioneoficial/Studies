#include <stdio.h>

int main() {
float km,litros,consumokml;
printf("\nInsira a quantidade de litros de gasolina consumidos pelo carro no percurso:\n");
scanf("%f",&litros);
printf("\nAgora insira a quantidade de KM percorridos pelo carro no percurso:\n");
scanf("%f",&km);
if(litros<0||km<0){
  printf("\nDigite um valor válido\n");
  main("pause");
}

 if ((litros>=0 && km==0) || (litros==0 && km>=0)){
  printf("\nImpossível isso acontecer, kakaroto!\n");
}
else{
consumokml= km/litros;
printf("\nO consumo do carro foi %.2f Km/l\n ",consumokml); }
if(consumokml<8){
  printf("Venda o carro!\n");
}
if(consumokml>=8 && consumokml<=14){
   printf("Econômico\n");
}
if(consumokml>14){
   printf("Super econômico!\n");
}
  return 0;
}