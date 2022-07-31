#include <stdio.h>
#include <stdlib.h>
typedef struct node{
  int data;
   struct node* next;
}node;
  struct node* head;
void insert(int x);
void print();
int main(void) {
  head = NULL; // empty list
  printf("Insert N\n");
  int n,x;
  scanf("%d",&n);
  for(int i = 0;i<n;i++){
    printf("Enter the number \n");
    scanf("%d", &x);
    insert(x);
    print();
  }
  return 0;
}
void insert(int x){
  node * temp = (node *)malloc(sizeof( node));
  temp->data = x;
  temp->next = head;
  head = temp;
}
void print(){
  node* temp = head;
  printf("List is: ");
  while(temp != NULL){
  printf(" %d",temp->data);
    temp = temp->next;
  }
  printf("\n");
}