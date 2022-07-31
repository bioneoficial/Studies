#include <stdio.h>
#include "ap2.h"
//CLang
int main(void) {

  No *remove, * list = NULL;
  int op, value, prev, resp;
  
  while(op != 0)
  {
    printf("\t 0 - Exit\t 1 -Prev Number \t 2 - Print Reverse\t 3 - Remove\t 4 - Insert Ordered\t 5 - Print\t 6 - Search\t 7 - Insert in middle\t 8 - Insert in end\t 9 - Insert Start");
    scanf("%d",&op);


    switch(op){
      case 1:
        printf("\nType value prev: ");
        scanf("%d",&value);
        resp = searchAnt(&list,value);
        (resp != -1) ? printf("\nO value prev a %d é %d.",value, resp): printf("non ecziste.\n");
        break;

      case 2:
        prevPrint(last(&list));
        break;

      case 3:
        printf("Type one value to be removed: \n");
        scanf("%d",&value);
        remove = del(&list,value);
        if(remove){
          printf("Element to be removed: %d\n",remove->value);
          free(remove);
        }
        else
          printf("non ecziste.\n");
        break;
      case 4:
        printf("Type one value: \n");
        scanf("%d",&value);
        insertSorted(&list, value);
        break;
      case 5:
        print(list);
        break;

      default:
        printf("Option invalid.\n");
        break;

      case 6:
        printf("Type 1 value to search: \n");
        scanf("%d",&value);
        remove = search(&list,value);
        if(remove){
          printf("Found Element : %d\n",remove->value);
        }
        else
          printf("Element not found.\n");
        break;
      case 7:
        printf("Type one value and the value of reference: \n");
        scanf("%d %d",&value,&prev);
        insertMiddle(&list, value, prev);
        break;
      case 8:
        printf("Type one value: \n");
        scanf("%d",&value);
        theEndInsert(&list,value);
        break;
      case 9:
        printf("Type one value: \n");
        scanf("%d",&value);
        startInsert(&list,value);
        break;
    }
  }

  return 0;
}