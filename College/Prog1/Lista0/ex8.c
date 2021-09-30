#include <stdio.h>
#include <stdlib.h>

int main() {
  float pesoi, N;
  printf("Escreve seu peso em KG\n");
scanf("%f",&pesoi);
if(pesoi<0){
  main("pause");
}
N = pesoi * 0.3649337410;
printf("\nSeu peso em Newton no planeta Mercúrio é:%.2f\n\n",N);
N = pesoi * 0.9041794087;
printf("Seu peso em Newton no planeta Vênus é:%.2f\n\n",N);
N = pesoi * 0.3812436289;
printf("Seu peso em Newton no planeta Marte é:%.2f\n\n",N);
 N = pesoi * 0.1651376146;
printf("Seu peso em Newton no planeta Lua(luaéplanetaagr?) é:%.2f\n\n",N);
N= pesoi * 1;
printf("Seu peso em Newton no planeta Terra é:%.2f\n\n",N);
N = pesoi * 2.6513761467;
printf("Seu peso em Newton no planeta Júpiter é:%.2f\n\n",N);
 N = pesoi * 1.1386340468;
printf("Seu peso em Newton no planeta Saturno é:%.2f\n\n",N);
N = pesoi * 1.0693170234;
printf("Seu peso em Newton no planeta Urano é:%.2f\n\n",N);
N = pesoi * 1.3506625891;
printf("Seu peso em Newton no planeta Netuno é:%.2f\n\n",N);
 N = pesoi * 0.2252803261;
printf("Seu peso em Newton no planeta Plutão é:%.2f\n\n",N);
 
  return 0;
}



/*8.  Você resolveu dar uma força para a NASA, que deseja calcular o peso das pessoas em diferentes planetas do sistema solar. (Isso vai ter importantes consequências na colonização dos planetas pela humanidade: os gordinhos vão preferir planetas onde baixem de peso, os magrinhos vão querer o contrário). Escreva um programa que recebe o peso de uma pessoa (em newtons) e calcula o novo peso nos corpos celestes, de acordo com as constantes gravitacionais de cada planeta (estas constantes estão normalizadas em relação à constante da Terra), dadas abaixo:

    Corpo celeste Fator de conversão
    Mercúrio 0.3649337410
    N = pesoi * 0.3649337410
    Vênus 0.9041794087
    N = pesoi * 0.9041794087
    Marte 0.3812436289
    N = pesoi * 0.3812436289
    Lua 0.1651376146
    N = pesoi * 0.1651376146
    Terra 1
    N = pesoi * 1
    Júpiter 2.6513761467
    N = pesoi * 2.6513761467
    Saturno 1.1386340468
    N = pesoi * 1.1386340468
    Urano 1.0693170234
    N = pesoi * 1.0693170234
    Netuno 1.3506625891
    N = pesoi * 1.3506625891
    Plutão 0.2252803261
    N = pesoi * 0.2252803261

    Depois de fazer as conversões, imprima o quanto as pessoas pesariam se estivessem em cada planeta.
     N = kg * m/s2*/