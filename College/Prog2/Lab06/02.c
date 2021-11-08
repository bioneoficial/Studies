#include <stdio.h>

struct habitantes
{ char sexo;
char corOlhos[10];
char corCabelo[10];
int idade;
};
#define QTD 4
int main(){
  int indexHNew = 999, contM = 0;
    float mediaMulher = 0, contLouroAzul = 0;
  struct habitantes habitante[QTD];
  for(int i = 0; i < QTD; i++){
    printf("Insira sexo do entrevistado %d, 'M' ou 'F':\n", i);
    scanf(" %c", &habitante[i].sexo);
    printf("Insira cor dos olhos:\n");
    scanf(" %s", &habitante[i].corOlhos);
    printf("Insira Cor do Cabelo:\n");
    scanf(" %s", &habitante[i].corCabelo);
        if(strstr(habitante[i].corOlhos, "azul") && strstr(habitante[i].corCabelo, "louro")){
      printf("entrei 3 \n");
       contLouroAzul++;
     }
  }


 
   for(int i = 0; i <QTD ; i++){
    // printf("\n");
      printf("insira idade do entrevistado %d:\n", i);
    scanf("%d", &habitante[i].idade);
    printf("IDADE = %d\n", habitante[i].idade);
    if(habitante[i].sexo == 'M' && habitante[i].idade < indexHNew){
      indexHNew = habitante[i].idade;
    }
     if(habitante[i].sexo == 'F'){
       contM++;
       mediaMulher +=  habitante[i].idade;
     }
    }
    mediaMulher /=  contM;
    contLouroAzul =((float) contLouroAzul / (float)QTD) * 100;
  printf("Numero de pessoas entrevistadas = %d, homem mais novo = %d, media age women = %.2f, %% habitante louro olho azul = %.2f",
   QTD, indexHNew, mediaMulher,contLouroAzul);

  return 0;
}


/* 
homem mais novo OK;
 número de pessoas entrevistadas; OK
  idade média das mulheres; OK
 percentagem de habitantes de cabelos louros e olhos azuis. ERROR
*/