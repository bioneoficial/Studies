#include <stdio.h>
#include <stdlib.h>

int main() {
  int hora,minuto,segundo,horasegundos,minutosegundos,segundostotal,segundosrestantes;

inicio:

  printf("Insira o horário em horas, minutos e segundos, respectivamente:\n");
  scanf("%d %d %d",&hora,&minuto,&segundo);

if(hora>24||minuto>59||segundo>59 || (hora>=24 && minuto>=0 && segundo>=0)){  
   main("pause");
}


else{
horasegundos=hora*3600;
minutosegundos=minuto*60;
segundostotal=horasegundos+minutosegundos+segundo;
segundosrestantes=86400-segundostotal;
  
  printf("%d Segundos se passaram desde que o dia começou e faltam %d segundos para o fim do dia.\n",segundostotal,segundosrestantes);

}
  return 0;
}