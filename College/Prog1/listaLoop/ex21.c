#include <stdio.h>

int main(){
  int hora,min,seg,segu=0,restoH,restoM;
float massa,massaI;

printf("Insira massa em gramas:\n");
scanf("%f",&massaI);
massa = massaI;
while(massa>0.5){
massa = massa / 2;
segu += 50;
}
hora = segu / 3600;
restoH = segu % 3600;
min = restoH / 60;
restoM = restoH % 60;
seg = restoM;

printf("Massa inicial: %.f\nMassa final: %.2f\n Tempo total gasto no formato 'HH:MM:SS':\n%02d:%02d:%02d",massaI,massa,hora,min,seg);
return 0;
}
