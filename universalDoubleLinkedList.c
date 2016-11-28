#include<stdio.h>
#include<stdlib.h>

union Data {
   int i;
   float f;
   char str[20];
};

struct Node {
   union Data data;
   struct Node *next;
   struct Node *prev;
};
typedef struct Node Node; 

Node *head = NULL;
Node *last = NULL;

void insert(int position, union Data data) {
   Node *ptr = head; 
   Node *newNode = (struct Node*) malloc(sizeof(Node));

   if (position == 0){
	newNode->data = data;
		
	   if(head == NULL) {
	      last = newNode;
	   } else {
	      head->prev = newNode;
	   }
	   newNode->next = head;
	   head = newNode;
	}
   
   if(head == NULL) {
      return;
   }

   int a;
   for(a=0; a < position - 1; a=a+1 ){
      if(ptr == NULL) {
         return;
      } else {           
         ptr = ptr->next;
      }
   }
   newNode->data = data;

   if(ptr == last) {
      newNode->next = NULL; 
      last = newNode; 
   } else {
      newNode->next = ptr->next;         
      ptr->next->prev = newNode;
   }
	
   newNode->prev = ptr; 
   ptr->next = newNode; 
}
int main(){
	return 0;
}
