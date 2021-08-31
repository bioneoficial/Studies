#include <stdio.h>
#include <stdlib.h>

int main() {

  float bterreno, hterreno, aterreno, bcasa, hcasa, acasa, alivre,pct,pctlivre;
  

  printf("Digite o comprimento e largura do terreno em metros respectivamente:\n");
  scanf("%f %f",&bterreno,&hterreno);

  printf("Digite o comprimento e largura da casa em metros respectivamente:\n");
  scanf("%f %f",&bcasa,&hcasa);

  if(bterreno == 0||hterreno == 0 || bcasa == 0 || hcasa == 0){
    printf("O comprimento ou a altura não pode ser 0.\n");
    main("pause");
    }
  else{
      aterreno = bterreno * hterreno;
      acasa = bcasa * hcasa;
      alivre = aterreno - acasa;

      pct = (100 * acasa) / aterreno;
      pctlivre = 100 - pct;

      if(alivre < 0){
        printf("A área da casa não pode ser maior que a do terreno...\n");
        main("pause");
    }else{
      printf("\nA área do terreno = %.1fm²\n",aterreno);
      printf("A área da casa = %.1fm²\n",acasa);
      printf("A área livre = %.1fm² ou %.f%%\n",alivre,pctlivre);
     
        }
    }

  return 0;
}