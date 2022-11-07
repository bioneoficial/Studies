#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  NAME_LEN 11

typedef struct no{
    int id;
    char name[NAME_LEN];
    struct no *next;
    struct no *prev;
}No;

void printList( No *node);
void getValues(char newName[NAME_LEN], int *newId);
void menu(No **root);
void insertNodeStart(No **paramNode, char newName[NAME_LEN], int newId);
void insertNodeEnd(No **paramNode, char newName[NAME_LEN], int newId);

int main() {
    No *root = malloc(sizeof(No));
    root->prev = NULL;
    root->next = NULL;
    root->id = 1;
    strcpy(root->name, "Inicial");
    menu(&root);
    printList(root); // 2 joao 1 Inicial
    return 0;
}

void printList( No *node){
    if(node){
        while(node){
            printf("Id: %d Name: %s\n",node->id,node->name);
            node = node->next;
        }
    }else{
        printf("Error\n");
    }
}

void getValues(char newName[NAME_LEN], int *newId){
    printf("Insira nome:\n");
    gets(newName);
    printf("Insira novo Id:\n");
    scanf("%d", newId);
    fflush(stdin);
}

void menu(No **root){
    char nameInput[NAME_LEN];
    int newId,op;
    do{
        printf("Deseja inserir no inicio (1) ou final(2) da lista? Deseja Breakar?Digite qlqr numero q n seja 1 ou 2\n");
        scanf("%d", &op);
        fflush(stdin);
        if(op == 1){
            getValues(nameInput, &newId);
            insertNodeStart(&*root, nameInput, newId);
        }
        else if(op == 2){
            printf("Insira nome:\n");
            gets(nameInput);
            printf("Insira novo Id:\n");
            scanf("%d", &newId);
            fflush(stdin);
            insertNodeEnd(&*root, nameInput, newId);
        }
        else{
            break;
        }

    }while(op);
}
void insertNodeStart(No **paramNode, char newName[NAME_LEN], int newId){
    No *newNode = malloc(sizeof(No));
    if(newNode){
    strcpy(newNode->name, newName);
    newNode->id = newId;
    newNode->next = *paramNode;
        *paramNode = newNode;
    }else{
        printf("error\n");
    }
}

void insertNodeEnd(No **paramNode, char newName[NAME_LEN], int newId){
     No  *aux, *newNode = malloc(sizeof(No));
     if(newNode){
         newNode->id = newId;
         strcpy(newNode->name, newName);
         newNode->next = NULL;
         if(*paramNode == NULL){
             *paramNode = newNode;
         }else{
             aux = *paramNode;
             while(aux->next != NULL){
                 aux = aux->next;
             }
             aux->next = newNode;
         }
     }else{
         printf("No Memory Alloc\n");
     }
}
