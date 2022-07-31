#include <stdlib.h>
#include <stdio.h>

typedef struct no{
  int value;
  struct no * next;
  struct no * prev;
}No;

void startInsert(No**list, int none){
  No * newValue = (No*)malloc(sizeof(No));
  
  if(newValue){
    newValue -> value = none;
    newValue -> next = *list;
    newValue -> prev = NULL;
    if(*list){
      (*list) -> prev = newValue;
    }
    *list = newValue;
  }
  else{
    printf("Memory error!\n");
  }
}

void theEndInsert(No ** list, int none){
  No *aux,* newValue = (No*)malloc(sizeof(No));

  if(newValue){
    newValue -> value = none;
    newValue -> next = NULL;
    if(*list == NULL){
      *list = newValue;
      newValue -> prev = NULL;
    }
    else{
      aux = *list;
      while(aux -> next != NULL){
        aux = aux -> next;
      }
      aux -> next = newValue;
      newValue -> prev = aux;
    }
  }
  else{
    printf("Memory error!\n");
  }
}

void insertMiddle(No ** list,int none,int ant){
  No *aux,* newValue = (No*)malloc(sizeof(No));

  if(newValue){
    newValue -> value = none;
    if(*list == NULL){
      newValue-> next = NULL;
      newValue -> prev = NULL;
      *list = newValue;
    }
    else{
      aux = *list;
      while(aux -> value != ant && aux->next){
        aux = aux -> next;
      }
      newValue -> next = aux -> next;
      aux -> next -> prev = newValue;
      newValue -> prev = aux;
      aux -> next = newValue;
    }
  }
  else{
    printf("Memory error!\n");
  }
}
void insertSorted(No ** list, int none){
  No *aux ,*newValue = (No*)malloc(sizeof(No));

  if(newValue){
    newValue -> value = none;
    if(*list == NULL){
      newValue -> next = NULL;
      newValue -> prev = NULL;
      *list = newValue;
    }
    else if(newValue -> value < (*list)-> value){
      newValue -> next = *list;
      (*list)-> prev = newValue;
      *list = newValue;
    }
    else{
      aux = *list;
      while(aux-> next && newValue -> value > aux -> next -> value){
        aux = aux -> next;
      }
      newValue -> next = aux -> next;
      if(aux -> next)
        aux -> next -> prev = newValue;
      newValue -> prev = aux;
      aux -> next = newValue;
    }
  }
  else
    printf("Memory Error.\n");
}

void prevPrint(No *no){
  printf("\nList: ");

  while(no){
    printf("%d ",no ->value);
    no = no -> prev;
  }
  printf("\n");
}

No * last(No **list){
  No  *aux = *list;

  while(aux -> next){
    aux = aux -> next;
  }
  return aux;
}
No * search(No ** list, int none){
  No *aux, *no = NULL;
  aux = *list;
  while(aux && aux -> value != none){
    aux = aux -> next;
  }
  if(aux)
    no = aux;
  return no;
}

No * del (No ** list, int none){
  No *aux, *remove = NULL;

  if(list){
    if((*list) -> value == none){
      remove = *list;
      *list = remove -> next;
      if(*list){
        (*list) -> prev = NULL;
      }
    }
    else{
      aux = *list;
      while(aux -> next && aux -> next -> value != none){
        aux = aux -> next;
      }
      if(aux -> next){
        remove = aux -> next;
        aux -> next = remove -> next;
        if(aux -> next){
          aux -> next -> prev = aux;
        }
      }
        
    }
  }
  return remove;
}
void print(No * no){
  printf("\nlist: ");

  while(no){
    printf("%d ",no ->value);
    no = no -> next;
  }
  printf("\n");
}
int  searchAnt(No ** list, int none){
  No *aux; int no = -1;

  aux = *list;

  while(aux && aux -> value != none){
    aux = aux -> next;
  }
  if(aux)
    no = aux -> prev-> value;
  return no;
}