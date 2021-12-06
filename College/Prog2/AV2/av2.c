#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Funcionarios{
  char nome[20];
  int idade;
  int salarioBase;
  int nDep;
};
#define length 3
int main(int argc, char* argv[]){
  FILE *cadastro = NULL;
  FILE *folhaEsp = NULL;
  FILE *folha = NULL;
  struct Funcionarios funcionario[length];
   strcpy(funcionario[0].nome,"João da Silva");
  funcionario[0].idade = 33;
  funcionario[0].salarioBase =900;
  funcionario[0].nDep =3;  
  strcpy(funcionario[1].nome,"Maria de Andrade");
  funcionario[1].idade = 40;
  funcionario[1].salarioBase =980;
  funcionario[1].nDep =2;
   strcpy(funcionario[2].nome,"Joao Bione");
  funcionario[2].idade = 27;
  funcionario[2].salarioBase =40000;
  funcionario[2].nDep =0;
  cadastro = fopen("cadastro.txt", "w+");
  folhaEsp = fopen("folhaesp.txt", "w+");
  folha = fopen("folha.txt", "w+");
  if(cadastro == NULL){
    printf("\nArquivo CLIENTE.TXT nao pode ser aberto.");
  printf("\nOcorreu um Erro Grave ! Use alguma tecla para finalizar !");
  }else{
    short i = 0;
    while(i < length){
  funcionario[i].salarioBase =funcionario[i].salarioBase +  (funcionario[i].salarioBase * 0.05) * (funcionario[i].nDep);
    fprintf(cadastro,"%s %d %d %d\n\n",funcionario[i].nome,funcionario[i].idade,funcionario[i].salarioBase,funcionario[i].nDep);
    if(funcionario[i].salarioBase < 20000)
      fprintf(folha,"%s %d %d %d\n\n",funcionario[i].nome,funcionario[i].idade,funcionario[i].salarioBase,funcionario[i].nDep);

    else{
      fprintf(folhaEsp,"%s %d %d %d\n\n",funcionario[i].nome,funcionario[i].idade,funcionario[i].salarioBase,funcionario[i].nDep);

    }
    i++;
    }
  }
  //C:\CADASTRO.txt ‘C:\FOLHAESP.bin’ e ‘C:\FOLHA.bin’.
  fclose(cadastro);
  fclose(folha);
  fclose(folhaEsp);
  return 0;
}