#include <stdio.h> 
#include <stdlib.h>
 
typedef struct node {  
 int data;  
 struct node* next;  
} node;  
 
void markEven(node* head) { 
    node * next = head;
    node * prev = NULL;

    while(next != NULL)
    {
        //Naviagtes to the next node in the list
        prev = next; 
        next = next->next; 

        //If the node holds an even number
        if(prev->data % 2 == 0)
        {
            //New node is made that holds -1
             node * newNode = (node*)malloc(sizeof(node));
             newNode->next = NULL;
             newNode->data = -1;
             
             //If the linked list is not empty
             if(prev != NULL)
             {  
                //The node is added to the linked list
                newNode->next = next; //newNode is before the "next" node
                prev->next = newNode; //newNode is after the "prev" node
             }
             
        }

    }

 

} 
 
void deallocateList(node** head) 
{ 
 node* tmp = *head; 
  
 while (tmp != NULL) 
 { 
  *head = tmp->next; 
  free(tmp); 
  tmp = *head; 
 } 
  
 *head = NULL; 
} 
 
int insertList(node** head, int data) 
{ 
 node* newNode = (node*) malloc(sizeof(node)); 
  
 if (newNode == NULL) 
  return -1; 
  
 newNode->data = data; 
 newNode->next = NULL; 
  
 newNode->next = *head; 
 *head = newNode; 
  
 return 1; 
} 
 
 
void printList(node* head) 
{ 
 node* tmp = head; 
  
 while (tmp != NULL) 
 { 
  printf("%d",tmp->data); 
  if (tmp->next != NULL) 
  { 
   printf(", "); 
  } 
  else 
  { 
   printf(".\n"); 
  } 
  tmp = tmp->next; 
 } 
} 
 
int main(void) 
{ 
 node* head = NULL; 
  
 insertList(&head, 8); 
 insertList(&head, 3); 
 insertList(&head, 1); 
 insertList(&head, 7); 
 insertList(&head, 6); 
 insertList(&head, 2); 
  
 printf("Initial List:\n"); 
 printList(head); 
 markEven(head); 
 printf("Marked List:\n"); 
 printList(head); 
  
 deallocateList(&head); 
  
} 