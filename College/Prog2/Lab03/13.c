#include <stdio.h>

#define numVoo 37
#define lugar 10
int reserva[numVoo] = {0},voo[numVoo][lugar] = {0}; // voo[numerovoo] = idcliente;
void teste(int solicitacao, int numCliente);

int main(){
int numCliente, solicitacao;
char op;
for(int i =0; i < numVoo;i++){
  reserva[i] = lugar; //Index é o numdovoo e o valor é lugares disponiveis;
} // numCliente = 9999 => BREAK;
  printf("Faça reserva, insira numero do voo(1 ate 37) seguido de 'espaço' e IDCliente:\n");
  scanf("%d  %d",&solicitacao, &numCliente);
  teste(solicitacao,numCliente);
  return 0;
}

void teste(int solicitacao, int numCliente){
  while(1){
if(solicitacao > numVoo || solicitacao < 1){
    break;
  }
  if(reserva[solicitacao -1] > 0){
    reserva[solicitacao -1] -= 1;
    printf("O cliente %d reservou um lugar no voo numero:%d\n",numCliente,solicitacao);
    for(int i =0;i<lugar;i++){
      if(voo[solicitacao -1][i] == 0){
      voo[solicitacao -1][i] = numCliente;
     // printf("o voo %d tem %d lugaresDispo e clienteID %d\n",solicitacao,reserva[solicitacao -1],voo[solicitacao -1][0]);
      }
    }
  }else{
    printf("Voo indisponivel\n");
  }
  printf("Faça reserva, insira numero do voo(1 ate 37) seguido de 'espaço' e IDCliente:\n");
  scanf("%d  %d",&solicitacao, &numCliente); // numCliente = 9999 => BREAK;
  if(numCliente == 9999){
    break;
  }
}
}
/* faça uma reserva de passagens aéreas de uma companhia. Além de leitura do número dos vôos e quantidade de lugares disponíveis, 
ler vários pedidos de reserva, constituídos do número da carteira de identidade do cliente e do número do vôo desejado.
Para cada cliente, verificar se há disponibilidade no vôo desejado. Em
caso afirmativo, imprimir o número da identidade do cliente, e o número
do vôo, atualizando o número de lugares disponíveis. Caso contrário,
avisar ao cliente da inexistência de lugares.
Indicando o fim dos pedidos de reserva, existe um passageiro cujo número
da carteira de identidade é 9999. Considerar fixo e igual 37 o número de
vôos da companhia.
Estrutura de dados necessária:*/