#include <stdio.h>
#include <time.h>

#define qtdCand 20
int main(int argc, char* argv[]){ 
  srand(time(NULL));
  int votos[qtdCand + 1];
  FILE *votosAntes = NULL;
  FILE *votosAdd = NULL;
  FILE *votosDepois = NULL;
  votosAntes = fopen("votosAntes.txt","w+b");
  votosAdd = fopen("votosAdd.txt" , "rb");
  votosDepois = fopen("votosDepois.txt" , "w+b");
  if(votosAntes == NULL || votosAdd == NULL || votosDepois == NULL){
    printf("\nArquivo TXT nao pode ser aberto.");
  }else{
    int i = 0,add[qtdCand+1],codAdd[qtdCand+1];
    char buffer[100];
    size_t linha = 0;
    while ((fgets(buffer, sizeof buffer, votosAdd) != NULL)) {
        sscanf(buffer, "%d %d", &codAdd[linha], &add[linha]);
        ++linha;
    }
    while(i < qtdCand){
      i++;
      votos[i] = rand() % 1000;
      fprintf(votosAntes,"Candidato Codigo %d tem %d votos\n",i,votos[i]);
     fprintf(votosDepois,"Candidato Codigo %d tem %d votos\n",i,(votos[i] + add[i -1]));
    }
    fclose(votosAntes);
    fclose(votosDepois);
    fclose(votosAdd);
  }
  return 0;
}