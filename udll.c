#include<stdio.h>
#include<stdlib.h>

union Data { //union to hold node data
   int i;
   float f;
   char str[20];
};

struct Node {
   int length; //the length of the list
   union Data data; //data value
   struct Node *next; //pointer to the next node
   struct Node *prev; //pointer to the previous node
};
typedef struct Node Node; //type definition

Node *head = NULL; //initialize pointer to the head node
Node *last = NULL; //initialize pointer to the last node

void insert(int position, union Data data) { //instert function
   Node *ptr = head; 
   Node *newNode = (Node*) malloc(sizeof(Node));

   if (position == 0){
      newNode->data = data;
      
      if(head == NULL) {
         newNode->length = 1;
         last = newNode;
      } else {
         newNode->length = head->length + 1;
         head->length = 1;
         head->prev = newNode;
      }
      newNode->next = head;
      head = newNode;
      return;
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

   if(ptr->next == NULL) {
      newNode->next = NULL; 
      last = newNode; 
   } else {
      newNode->next = ptr->next;         
      ptr->next->prev = newNode;
   }
   
   head->length = head->length+1;
   newNode->prev = ptr; 
   ptr->next = newNode; 
}

int length(){ //return the length value stored in the head node
   return head->length;
}

int main(){ //main stub
	return 0;
}
