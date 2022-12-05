#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM_MATR 8
#define TAM_CPF 14
#define TAM_NOME 41
#define TAM_MAX 80
typedef struct _a {
	char matr[TAM_MATR + 1];
	char cpf[TAM_CPF + 1];
	char nome[TAM_NOME + 1];
	struct _a* prev;
	struct _a* next;
} Arvore;

typedef struct _b {
	char matr[TAM_MATR + 1];
	char cpf[TAM_CPF + 1];
	char nome[TAM_NOME + 1];
	struct _b* prev;
	struct _b* next;
} Aluno;
int numAlunos = 3;
int arr[TAM_CPF];
Arvore* head = NULL;

void binSearch(char cpf[TAM_CPF], int start, int end) { // Desisti do array
	Arvore* newElement = (Arvore*)malloc( sizeof(Arvore));
	newElement = head;
  if (start > end) {
    printf("Não existe!\n");
  } else {
    int middle = (start + end)/2;

    if(strcmp(newElement->cpf, cpf) == 0) {
      printf("%d", middle);
    }// else if(cpf > arr[middle]) {
      //return binSearch(cpf, middle+1, end);
 // }else{
  //	return binSearch(cpf, middle-1, end);
//  }
}
}


//
//*** Você sempre vai montar uma lista encadeada. Nunca 
// será uma árvore (nunca usa prev)
//
void sortAdd(char newMatr[TAM_MATR], char newCpf[TAM_CPF], char newNome[TAM_NOME]) { // Sort n ta fufando?
  Arvore* newElement = (Arvore*)malloc( sizeof(Arvore));
  if (newElement) {
  	strcpy(newElement->matr, newMatr);
    strcpy(newElement->cpf, newCpf);
    strcpy(newElement->nome, newNome);

    if (!head) {
      newElement->next = NULL;
      head = newElement;
    } else if (strcmp(head->cpf, newElement->cpf) > 0) {
      newElement->next = head;
      head = newElement;
    } else {
      Arvore* i = head;
      while (i->next &&
             strcmp(i->next->cpf, newElement->cpf) < 0) {
        i = i->next;
      }
      newElement->next = i->next;
      i->next = newElement;
    }
  }
}

void search(char cpf[]) { // Isso é uma busca linear!!!
  Arvore* i = head;
  while (i && strcmp(i->cpf, cpf) != 0) {
    i = i->next;
  }

  if (!i) {
    printf("Nao Existe!");
  } else {
    printf("%s - %s - %s", i->matr, i->cpf, i->nome);
  }
}

void print() { // OK
  Arvore* i = head;
  while (i) {
    printf("%s - %s - %s ",i->matr, i->cpf, i->nome);
    i = i->next;
  }
}



int main(int argc, char** argv) {
	char nome[TAM_NOME+1] = "default";
	char matr[TAM_MATR+1];
	char cpf[TAM_CPF+1];
	Arvore* teste = (Arvore*)malloc(sizeof(Arvore) * numAlunos);
	FILE *arquivo;
	arquivo = fopen("provinha.txt", "r");
	int temp = 0;
	while(fgets(matr,TAM_MATR+1,arquivo) != NULL && fgets(cpf,TAM_CPF+1,arquivo) != NULL && fgets(nome,TAM_NOME+1,arquivo) != NULL && temp < numAlunos-1){
		if(temp == 0){
			sortAdd(matr,cpf,nome);
		}
		temp++;
		fgets(matr,TAM_MATR+1,arquivo);  //*** Por que ler de novo???
		fgets(cpf,TAM_CPF+1,arquivo);
		fgets(nome,TAM_NOME+1,arquivo);
		sortAdd(matr,cpf,nome);
	}
	teste = head->next;
	search(teste->cpf);
	search(head->cpf);
	print();
	return 0;
}