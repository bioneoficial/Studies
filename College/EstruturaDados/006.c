#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1
#define TAM_MATR 4
#define modulo(x) ((x) >= 0 ? (x) : -(x))
typedef struct _A {
  int matr;
  int peso;
  struct _A *esquerda;
  struct _A *direita;
} ALUNO;
ALUNO *raiz = NULL;
void buscaEmLargura() {
  int nivel = 0;

  ALUNO *nosDoNivelAtual[128];
  int numElemNivelAtual = 1;
  ALUNO *nosDoNivelSeguinte[128];
  int numElemProximoNivel = 0;

  printf("\n\n\nBUSCA EM LARGURA\n\n\n");
  nosDoNivelAtual[0] = raiz;

  while (numElemNivelAtual != 0) {
    numElemProximoNivel = 0;
    printf("\nNIVEL %d |", nivel++);
    for (int i = 0; i < numElemNivelAtual; i++) {
      ALUNO *atual = nosDoNivelAtual[i];
      int k;
        for (k = 0; k < atual->peso; k++)
          printf("\t");
      printf("Matr: %d  | ", atual->matr);
      if (atual->esquerda != NULL)
        nosDoNivelSeguinte[numElemProximoNivel++] = atual->esquerda;
      if (atual->direita != NULL)
        nosDoNivelSeguinte[numElemProximoNivel++] = atual->direita;
    }
    for (int i = 0; i < numElemProximoNivel; i++)
      nosDoNivelAtual[i] = nosDoNivelSeguinte[i];
    numElemNivelAtual = numElemProximoNivel;
  }
}
void listar(ALUNO *atual, int nivel) {

  if (atual->direita != NULL)
    listar(atual->direita, nivel + 1);

  printf("\n");
  for (int i = 0; i < nivel; i++)
    printf("\t");
  printf("Matr: %d Peso: %d\n\n", atual->matr, atual->peso);

  if (atual->esquerda != NULL)
    listar(atual->esquerda, nivel + 1);
}
ALUNO *balancear(ALUNO *atual) {
  int pesoEsquerda = 0;
  int pesoDireita = 0;

  // Verificando se precisamos de balanceamento
  if (atual->direita != NULL)
    pesoDireita = atual->direita->peso;
  if (atual->esquerda != NULL)
    pesoEsquerda = atual->esquerda->peso;
  int diferenca = pesoDireita - pesoEsquerda;
  if (modulo(diferenca) < 2)
    return atual; // Posso retornar pois está balanceado!

  // Se o balanceamento é necessário à direita
  ALUNO *pivot;
  if (diferenca >= 2) {
    // ROTAÇÃO À DIREITA. Descobrindo qual é o pivot.
    if (atual->direita->direita != NULL) {
      // o pivot é o atual->direita
      pivot = atual->direita;
      atual->direita = NULL;
      pivot->esquerda = atual;
      atual->peso -= 2;
    } else {
      // o pivot é o atual->direita->esquerda
      pivot = atual->direita->esquerda;
      pivot->direita = atual->direita;
      pivot->esquerda = atual;
      atual->direita = NULL;
      pivot->direita->esquerda = NULL;
      pivot->esquerda->peso -= 2;
      pivot->peso++;
      pivot->direita->peso--;
    }
  } else {
    // ROTAÇÃO À ESQUERDA. Descobrindo qual é o pivot.
    if (atual->esquerda->esquerda != NULL) {
      // o pivot é o atual->esquerda
      pivot = atual->esquerda;
      atual->esquerda = NULL;
      pivot->direita = atual;
      atual->peso -= 2;
    } else {
      // o pivot é o atual->esquerda->direita
      pivot = atual->esquerda->direita;
      pivot->esquerda = atual->esquerda;
      pivot->direita = atual;
      atual->esquerda = NULL;
      pivot->esquerda->direita = NULL;
      pivot->direita->peso -= 2;
      pivot->peso++;
      pivot->esquerda->peso--;
    }
  }
  return pivot;
}
ALUNO *inserirNaArvore(ALUNO *novo, ALUNO *atual) {
  if (novo->matr > atual->matr) {
    if (atual->direita == NULL) {
      atual->direita = novo;
      if (atual->esquerda == NULL)
        atual->peso++;
    } else {
      atual->direita = inserirNaArvore(novo, atual->direita);
      int pesoRetornado = atual->direita->peso;
      if (pesoRetornado == atual->peso)
        atual->peso++;
    }
  } else {
    if (atual->esquerda == NULL) {
      atual->esquerda = novo;
      if (atual->direita == NULL)
        atual->peso++;
    } else {
      atual->esquerda = inserirNaArvore(novo, atual->esquerda);
      int pesoRetornado = atual->esquerda->peso;
      if (pesoRetornado == atual->peso)
        atual->peso++;
    }
  }
  if (atual->peso >= 3)
    atual = balancear(atual);
  return atual;
}
void criarRegistro(int m) {
  ALUNO *novo = (ALUNO *)calloc(1, sizeof(ALUNO));
  novo->esquerda = NULL;
  novo->direita = NULL;
  novo->peso = 1;
  novo->matr = m;
  if (raiz == NULL)
    raiz = novo;
  else
    raiz = inserirNaArvore(novo, raiz);
  printf("-------------------------------\n\n");
  listar(raiz, 0);
}
int lerRegistro() {
  int matr;

  printf("Entre com os dados do aluno ou [0] para terminar\n");
  printf("Matr: ");
  fflush(stdout);
  scanf("%d", &matr);
  fflush(stdin);
  if (matr == 0)
    return FALSE;
  criarRegistro(matr);
  return TRUE;
}
int main() {

  while (TRUE) {
    if (!lerRegistro())
      break;
  }
  buscaEmLargura();
}


