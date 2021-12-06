/*  A Secretaria de Transportes de uma determinada cidade controla os veículos através de registro contendo:
 Nome do Proprietário, Modelo, Cor, Ano, Tipo de Combustível, Número do Chassi e Placa. 
Um funcionário fará uma consulta para descobrir se alguns veículos estão cadastrados ou não, através do número do Chassi,
 no arquivo (C:\veiculo.txt). Caso esteja cadastrado, imprimir na impressora os dados do veículo. Caso contrário, cadastre-o */
#include <stdio.h>
#include <stdlib.h>

struct Veiculos
{
 char *name,*model,*color, *fuel, *plaque;
 int year,chassi;
  
};


int main(int argc, char* argv[]){
  FILE *city_cars = NULL;
  char *filename = "C:\\Downloads\\veiculo.txt";
  //char *filename = "C:\\veiculo.txt";
  city_cars = fopen(filename, "w+");
  if(city_cars == NULL){
    printf("\nArquivo nao pode ser aberto.");
    printf("\nOcorreu um Erro Grave ! Use alguma tecla para finalizar !");
  }else{
 struct Veiculos veiculo = {"nome", "modelo", "cor", "combustivel", "placa",2021,156};
 fprintf(city_cars,"%s %s %s %s %s %d %d", veiculo.name, veiculo.model, veiculo.color, veiculo.fuel,
  veiculo.plaque, veiculo.year, veiculo.chassi);
 
  while (city_cars != EOF) {
    
  }
   fclose(city_cars);
   }
  return 0;
}