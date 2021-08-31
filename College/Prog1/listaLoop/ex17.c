#include <stdio.h>

int main(void) {
  float altC=1.50, altZ=1.10;
  int ano=0;
  do{ altC += 0.02;
  altZ += 0.03;
  ano++;

  }while(altC>altZ);
  printf("Levou %d anos, slc bixo", ano);
  return 0;
}