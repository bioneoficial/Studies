#include <stdio.h>
#include <stdlib.h>

int Busca_Sequencial_1 (int L[], int v, int N)
{
  printf("entrei");
for(int i = 0; i< N; i++)
if (v==L[i])
return i;
return -1;
}
int Busca_Sequencial_2 (int L[], int v, int N)
{
int pos = -1;
for(int i = 0; i< N; i++)
if (v==L[i])
pos = i;
return(pos);
}

int Busca_Sequencial_Ord_1 (int a[], int v, int N)
{
for(int i = 0; i< N; i++){
if (v==a[i])
    return i;
else if (a[i]>v) 
    return (-1);
}
return 1;
}
int Busca_Sequencial_Ord_2 (int a[], int v, int N)
{ int pos = 0;
while ( v < a[pos])
pos = pos+1;
if (v == a[pos])
return(pos);
return(-1);
}

int busca_binaria (int vet[], int elem, int n)
{
//no início consideramos todo o vetor
int ini=0, fim= n-1, meio;
while (ini<=fim)
{
meio=(ini+fim)/2;
if (elem < vet[meio])
fim = meio-1; //ajusta posição final
else
if (elem > vet [meio])
ini = meio+1; //ajusta posição inicial
else
return meio; //elemento encontrado
}
//Não encontrou: restou parte de tamanho zero
return -1;
}

void Ord_Selecao(int a[ ], int n)
{ int t, i, j,min;
for (i=0;i<= n-2; i++)
{
min = i;
for (j=i+1; i<= n-1; j++)
if (a[j]<a[min]) min = j;
/* troca */
t = a[min];
a[min]=a[i];
a[i] = t;
}
}

void Bubble_Sort(int a[ ], int n)
{
int i, t, trocas=1;
while (trocas!=0)
{
trocas = 0;
for (i = 0; i < n-1 ; i++)
{ t = a[i];
if (a[i] > a[i+1])
{ /* troca */
a[i]=a[i+1];
a[i+1]=t;
trocas++;
}
}
}
}

typedef struct no{
  int value;
  struct no * next;
  struct no * prev;
}No;

int main() {
    No *remove, * list = NULL;
int op, value, prev, resp;
  int v = 1, N = 1, elem = 1, n = 1;
 // scanf("%d %d %d %d",&v,&N, &n,&eleme);
  int vet[4] = {8,9,10,11};
  int L[4] = {0,1,2,3};
  int a[4] = {4,5,6,7};
  while(op != 7)
  {
    printf("\t 0 - Busca_Sequencial_1 \t 1 -Busca_Sequencial_2 \t 2 - Busca_Sequencial_Ord_1\t 3 - Busca_Sequencial_Ord_2\t 4 -  busca_binaria\t 5 - Ord_Selecao\t 6 - Bubble_Sort\t 7- Sair");
    scanf("%d",&op);
    if( op == 0){
        printf("\n%d\n",Busca_Sequencial_1 (L,v,N));
    }else if( op == 1){
        Busca_Sequencial_2 (L,v,N);
    }else if( op == 2){
        Busca_Sequencial_Ord_1 (a,v, N);
    }else if( op == 3){
        Busca_Sequencial_Ord_2 ( a, v, N);
    }else if( op == 4){
        busca_binaria ( vet, elem, n);
    }else if( op == 5){
        Ord_Selecao( a, n);
    }else if( op == 6){
       Bubble_Sort( a, n);
    }

  }
  return 0;
}