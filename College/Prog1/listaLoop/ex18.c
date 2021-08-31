#include <stdio.h>

int main(void) {
float tanqueA=82,tanqueB=37;
int mint=0,hora=0,min=0;
do{
  for(int i=1;i<=60;i++){
    if(tanqueA>0 && tanqueB>0){
      mint += i;
    tanqueA += 0.3 - 0.5;
  tanqueB -= 0.2 + 0.13;
  }
  }

}while(tanqueA>0 && tanqueB>0);
if(tanqueA<0){
printf("TanqueA\n";
}
else{
printf("TanqueB\n");
}
hora = mint / 60;
min = mint % 60;
printf("%d horas %d minutos esvaziando\n",hora,min);
  return 0;
}
/*
hora
tanqueA -= 30;
tanqueB += 8;

minuto
tanqueA += 0.3;
tanqueB -= 0.2;
*/