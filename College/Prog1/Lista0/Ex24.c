#include <stdio.h>

int main()
{ int hstart, hend , mstart, mend, htotal,mtotal;
float tarifa;

  printf("Insira o horário de entrada Ex:14:00 :\n");
  scanf("%d:%d", &hstart, &mstart);
  printf("Insira o horário de saída Ex:15:00  : \n");
  scanf("%d:%d",&hend,&mend);
 if(hstart ==24){
   hstart = 0;
 }
  if(hstart < 0 || hstart > 24 || mstart<0 || mstart>59 || mend<0  ||mstart>59 || hend < 0 || hstart > 24)
  {
    printf("Horário não válido.\n");
  }
if(hstart>hend){
   htotal = ((hstart*60) + mstart) - ((hend*60) + mend) - 1440;
}
else {
  htotal = ((hstart*60) + mstart) - ((hend*60) + mend);
}
if(htotal ==0){
htotal =1440;
  }
  if(htotal<0)
  {

    htotal = - htotal;
  }
  htotal = htotal/60;
  if(mstart>mend){
 mtotal = mstart - mend;
}
  else {
      mtotal = mend - mstart;
  }
 if(mtotal>0){
   htotal++;
 }

  
  if(htotal>0 && htotal <=2) {
   tarifa = htotal * 1;
 }
 else if(htotal==3){
   tarifa = 3.40; 
 }
 else if(htotal ==4){
   tarifa = 4.80;
 }
 else if (htotal>= 5){
   tarifa = 4.80 + ((htotal-4) *2) ;
 }
 
  printf("Tarifa de $%.2f a pagar pelo total de %d horas", tarifa,htotal);

  return 0;
}