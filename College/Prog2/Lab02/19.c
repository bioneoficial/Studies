#include <stdio.h>
/* Faça um programa em C, que leia um TABULEIRO DE XADREZ (TAB – 8X8), calcule e exiba quantas peças de cada tipo
existem no tabuleiro em um determinado momento do jogo. Considere a a seguinte convenção:
1 – PEÃO 2 - TORRE 3 – REI 4 – BISPO 5 – RAINHA 6 - CAVALO 7 - VAGO */
int main(){
  int TAB[8][8] = {0},branco[8][8], preto[8][8], peao = 1,torre = 2, rei = 3, bispo = 4, rainha = 5, cavalo = 6, vago = 7;
    for(int i =0; i < 8; i++){
    for(int k = 0; k < 8; k++){
      if(i == 0){ // backline preto
        branco[i][k] = vago;
        if(k == 0 || k == 7){
          preto[i][k] = torre;
        }else if(k == 1 || k == 6){
          preto[i][k] = cavalo;
        }else if( k == 2 || k ==5){
          preto[i][k] = bispo;
        }else if( k == 3){
          preto[i][k] = rei;
        }else if(k == 4){
          preto[i][k] = rainha;
        }
      }else if(i == 1){ // peao preto
        branco[i][k] = vago;
        preto[i][k] = peao;
      }else if( i == 6){ //  peao branco
        branco[i][k] = peao;
        preto[i][k] = vago;
      }else if( i == 7){ // backline branco
        preto[i][k] = vago; 
        if(k == 0 || k == 7){
          branco[i][k] = torre;
        }else if(k == 1 || k == 6){
          branco[i][k] = cavalo;
        }else if( k == 2 || k ==5){
          branco[i][k] = bispo;
        }else if( k == 3){
          branco[i][k] = rei;
        }else if(k == 4){
          branco[i][k] = rainha;
        }
      }else{
        preto[i][k] = vago;
         branco[i][k] = vago;
      }
    }
  }
  /*
  for(int i =0; i < 8; i++){
    for(int k = 0; k < 8; k++){
      printf("preto[%d][%d]:%d\t",i,k,preto[i][k]);
    }
    printf("\n");
  }  debug  pecas preto
   
  for(int i =0; i < 8; i++){
    for(int k = 0; k < 8; k++){
      printf("branco[%d][%d]:%d\t",i,k,branco[i][k]);
    }
    printf("\n");
  }  debug pecas branca
  */ 
    for(int i =0; i < 8; i++){ //preencher TAB
      for(int k = 0; k < 8; k++){
        if( i == 0){
          TAB[i][k]  = preto[i][k];
        }else if(i == 1){
          TAB[i][k]  = preto[i][k];
        }else if(i ==6){
          TAB[i][k]  = branco[i][k];
        }else if(i == 7){
          TAB[i][k]  = branco[i][k];
        }else{
          TAB[i][k] = vago;
        }
      }
    }
    /*
    for(int i =0; i < 8; i++){ //DEBUG TABULEIRO
    for(int k = 0; k < 8; k++){
      printf("TAB[%d][%d]:%d\t",i,k,TAB[i][k]);
    }
    printf("\n");
  } */
    int torreCont = 0, peaoCont = 0, bispoCont = 0, reiCont = 0, rainhaCont = 0, cavaloCont = 0;
    for(int i =0; i < 8; i++){ 
      for(int k = 0; k < 8; k++){
        if(TAB[i][k] == 1){
          peaoCont++;
        }else if(TAB[i][k] == 2){
          torreCont++;
        }else if(TAB[i][k] == 3){
          reiCont++;
        }else if(TAB[i][k] == 4){
          bispoCont++;
        }else if(TAB[i][k] == 5){
          rainhaCont++;
        }else if(TAB[i][k] == 6){
          cavaloCont++;
        }
      }
    } //1 – PEÃO 2 - TORRE 3 – REI 4 – BISPO 5 – RAINHA 6 - CAVALO
    printf("No momento de partida do jogo, possuimos:%d Peao(oes), %d Torre(s), %d Rei(s),%d Bispo(s), %d Rainha(s), %d cavalo(s)\n"
    ,peaoCont,torreCont,reiCont,bispoCont,rainhaCont,cavaloCont);
  return 0;
}