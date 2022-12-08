ARRAY
1. SORT
void sort() {
  for (int i = 0; i < SIZE - 1; i++) {
    int min = i;
    for (int j = (i + 1); j < SIZE; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    if (min != i) {
      int aux = arr[i];
      arr[i] = arr[min];
      arr[min] = aux;
    }
  }
}
2. BINARY SEARCH
void binSearch(int value, int start, int end) {
  if (start > end) {
    printf("Não Existente!");
  } else {
    int middle = (start + end) / 2;

    if(arr[middle] == value) {
      printf("%d", middle);
    } else if(value > arr[middle]) {
      return binSearch(value, middle + 1, end);
    } else {
      return binSearch(value, start, middle - 1);
    }
  }
}
LINKED LIST
1. SORT ADD
void sortAdd(char registration[], char name[]) {
  Node newElement = (Node)calloc(1, sizeof(struct _n));
  if (newElement) {
    strcpy(newElement->registration, registration);
    strcpy(newElement->name, name);
    if (!head) {
      newElement->next = NULL;
      head = newElement;
    } else if (strcmp(head->registration, newElement->registration) > 0) {
      newElement->next = head;
      head = newElement;
    } else {
      Node i = head;
      while (i->next &&
             strcmp(i->next->registration, newElement->registration) < 0) {
        i = i->next;
      }
      newElement->next = i->next;
      i->next = newElement;
    }
  }
}
2. REMOVE
void remove(char registration[]) {
  Node i = head;
  Node prev = NULL;
  while (i && strcmp(i->registration, registration) != 0) {
    prev = i;
    i = i->next;
  }
  if (!i) {
    printf("Não Existente!");
  } else if (!prev) {
    head = i->next;
  } else {
    prev->next = i->next;
  }
  free(i);
  printf("Removido!");
}
3. SEARCH
void search(char registration[]) {
  Node i = head;
  while (i && strcmp(i->registration, registration) != 0) {
    i = i->next;
  }

  if (!i) {
    printf("Não Existente!");
  } else {
    printf("%s - %s", i->registration, i->name);
  }
}
3. PRINT
void print() {
  Node i = head;
  while (i) {
    printf("%s - %s ", i->registration, i->name);
    i = i->next;
  }
}




BINARY SEARCH TREE

1. ADD

Node add(int num) {
  if (!root) {
    Node newElement = (Node)calloc(1, sizeof(struct _n));

    newElement->value = num;

    newElement->lt = NULL;
    newElement->rt = NULL;

    return newElement;
  } else {
    if (num > root->value) {
      root->rt = add(root->rt, num);
    } else {
      root->lt = add(root->lt, num);
    }
    return root;
  }
}

2. DEPTH SEARCH (PRINT)

void DepthSearch() {
  if(root->lt){
    print(root->lt);
  }
  
  printf("%d\n", root->value);
  
  if(root->rt){
    print(root->rt);
  }
}
2.BREADTH SEARCH (PRINT)

void breadthSearch() {
  int lvl = 0, thisLvlElements = 1, nextLvlElements = 0;
  Node auxThisLvl[128], auxNextLvl[128];

  auxThisLvl[0] = root;

  while (thisLvlElements) {
    nextLvlElements = 0;

    for (int i = 0; i < thisLvlElements; i++) {
      Node aux = auxThisLvl[i];

      printf("%d ", aux->value);

      if (aux->lt) {
        auxNextLvl[nextLvlElements++] = aux->lt;
      }

      if (aux->rt) {
        auxNextLvl[nextLvlElements++] = aux->rt;
      }
    }
    printf("\n");
    
    for (int i = 0; i < nextLvlElements; i++) {
      auxThisLvl[i] = auxNextLvl[i];
    }
    thisLvlElements = nextLvlElements;
    lvl++;
  }
}


BINARY FILE

FILE *file;

file = fopen("data.dat", "wb");
fwrite(aux, sizeof(struct _n), 1, file);
fclose(file);
