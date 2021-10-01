#include <stdio.h>
#include <time.h>

int main(){
  srand(time(NULL));
  float func[4][2] = {0}, mediaS = 0, maiorS = 0,salTemp = 0;
  int funcLen = 4;

  for(int i =0; i < funcLen;i++){
    printf("Funcionario %d: ",i); //func atual
    for(int j = 0; j < 2;j++){
      if( j == 0){
      func[i][j] = (rand() % 10) + 3; // atribui carga horaria pesaaaada rs
      printf("Carga horaria %.1f\t",func[i][j]);
      }else{
      func[i][j] = 3.5;  // atribui o valor hora
      printf("Valor hora: %.1f\n",func[i][j]);
      salTemp = func[i][j -1] * func[i][j]; //salario func atual
      if(maiorS < salTemp)
        maiorS = salTemp;
      mediaS += salTemp;
      }
    }
  }
  mediaS /= funcLen;  // escravidao ne? Capitalismo!
  printf("Media Salarial = $%.2f\n Maior salario = %.2f\n", mediaS,maiorS); 

  return 0;
}