#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define NAME_LEN 80
#define MATR_LEN 4
#define FILE_PATH "students.txt"
 
FILE* file;
 
typedef struct _a{
 int matr;
 char name[NAME_LEN + 1];
 struct _a * prev;
 struct _a * next;
}STUDENT;
 
void insertTree(STUDENT* new, STUDENT* actual);
void createReg(int matr, char name[]);
void fileToTree();
void recordFile(STUDENT* actual, FILE* file);
void list(STUDENT* actual);
int readReg();
STUDENT* root = NULL;
STUDENT* delete(STUDENT *actual, int mat);
 
int main(void) {
   fileToTree();
   int myVar,flag=1,ans=0;
  
   while(myVar != 4){
   printf("1 - Insert\t2- Delete\t3 - List\t4 - Exit\n");
   scanf("%d",&myVar);
  
       switch(myVar){
           case 1:
               flag = readReg();
               break;
           case 2:
               printf("\nMatr:\n");
               scanf("%d",&ans);
               fflush(stdin);
               delete(root, ans);
               break;
          
           case 3:
           root ? list(root) : printf("Empty Reg.\n");
               break;
           case 4:
               printf("Exit!\n");
               file = fopen(FILE_PATH, "wb");
               if(file){
                   recordFile(root, file);
                   fclose(file);
               }
               else{
                   printf("O file esta vazio. :(");
               }
               myVar = 4;
               break;
           default:
               printf("Invalid OP\n");
               break;
       }
  
   }
 return 0;
}
 
void insertTree(STUDENT* new, STUDENT* actual){
 if(new -> matr > actual -> matr){
   if(actual -> next == NULL){
     actual -> next = new;
   }else{
     insertTree(new, actual -> next);
   }
 }else{
   if(actual -> prev == NULL){
     actual -> prev = new;
   }
   else{
     insertTree(new, actual -> prev);
   }
 }
}
 
void createReg(int matr, char name[]){
 STUDENT* newReg = (STUDENT*)malloc(sizeof(STUDENT));
 
 newReg -> matr = matr;
 strcpy(newReg -> name, name);
 newReg -> next = NULL;
 newReg -> prev = NULL;
 
 if(root == NULL){
   root = newReg;
 }
 else{
   insertTree(newReg, root);
 }
}
 
int readReg (){
   int matr = 0;
   char name [NAME_LEN + 1];
  
   printf("\nInsert student data or 0 to exit.\n");
  
   printf("Matr: ");
   scanf("%d",&matr);
   fflush(stdin);
   if(matr == 0){
     printf("Students reg closed.\n");
     return 0;
   }
   printf("name:");
   gets(name);
   fflush(stdout);
  
   createReg(matr, name);
    return 1;
}
 
void fileToTree(){
   STUDENT reg;
  
   file = fopen(FILE_PATH, "rb");
 
 int tam = 0;
 
   if(file != NULL){
       while(1){
           tam = fread(&reg, sizeof(STUDENT),1,file);
           if(tam == 0){
               fclose(file);
               break;
           }
           createReg(reg.matr, reg.name);
       }
   }
}
 
void recordFile(STUDENT* actual, FILE* file) {
  
   if(actual -> prev != NULL){
       recordFile(actual -> prev, file);
   }
  
   fwrite(actual, (sizeof(struct _a)),1, file);
  
   if(actual -> next != NULL){
       recordFile(actual -> next, file);
   }  
}
 
void list(STUDENT* actual) {
  
   if(actual -> prev != NULL){
       list(actual -> prev);
   }
  
   printf("Matr: %d\tname: %s\n",actual -> matr, actual -> name);
  
   if(actual -> next != NULL){
       list(actual -> next);
   }
}
 
 
STUDENT* delete(STUDENT *actual, int mat){
  
   if(actual == NULL){
       return NULL;
   }
   if(mat < actual -> matr){
       actual -> prev = delete( actual -> prev, mat);
   }
   else if(mat > actual -> matr){
       actual -> next = delete(actual -> next, mat);
   }
   else{
       if(actual -> prev == NULL && actual -> next == NULL){
           free(actual);
           return NULL;
       }
       else if(actual -> prev == NULL || actual -> next == NULL){
           STUDENT* temp = actual -> prev ? actual -> prev  : actual -> next;
           free(actual);
           return temp;
       }
       else if (actual -> prev != NULL && actual ->  next != NULL){
           STUDENT* temp = actual -> next;
           while(temp -> prev != NULL){
               temp = temp -> prev;
           }
           actual -> matr = temp -> matr;
           actual -> next = delete(actual -> next, actual -> matr);
       }
   }
   return actual;
}
 

