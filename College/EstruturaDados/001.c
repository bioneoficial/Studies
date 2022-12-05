#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int value;
    struct no *next;
}No;

void insertNode(No **paramNode, int value);
void insertNodeEnd(No **paramNode, int value);
void printList(No *paramNode);

int main() {
    No *root = malloc(sizeof(No));
    root->value = 1;
    root->next = NULL;
    insertNode(&root,2);
    insertNode(&root,3);
    insertNode(&root,4);
    insertNodeEnd(&root, 5);
    printList(root);
    return 0;
}
void insertNode(No **paramNode, int value){
    No *newNode = malloc(sizeof(No));
    if(newNode){
        newNode->value = value;
        newNode->next = *paramNode;
        *paramNode = newNode;
        //printf("%d\n",newNode->value);
    }else{
        printf("No Memory Alloc\n");
    }
}

void insertNodeEnd(No **paramNode, int value){
    No  *aux, *newNode = malloc(sizeof(No));
    if(newNode){
        newNode->value = value;
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

void printList(No *paramNode){
    printf("OIE\n");
    while(paramNode) {
        printf("%d\n", paramNode->value);
        paramNode = paramNode->next;
    }
    printf("OIE\n");

}


