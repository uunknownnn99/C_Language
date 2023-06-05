#include <stdio.h>
#include <stdlib.h>

struct Node{
  struct Node * left;
  struct Node * right;
  int data;
};

void DisplayRight(struct Node** head){
  struct Node* ptr = *head;
  printf("Right Transversal: ");
  while(ptr != NULL){
      printf("%d ",ptr->data);
      ptr=ptr->right;
  }
  printf("\n");
}

void DisplayLeft(struct Node** head){
  struct Node* ptr = *head;
  while(ptr->right!= NULL)
    ptr=ptr->right;
  printf("Left Transversal: ");
  while(ptr != NULL){
      printf("%d ",ptr->data);
      ptr=ptr->left;
  }
  printf("\n");
}

struct Node * InsertFirst(struct Node *head,int data){
  struct Node* new = (struct Node *)malloc(sizeof(struct Node));
  new->data = data;
  new->left = NULL;
  new->right = head;
  head->left= new;
  return new;
}

int main(void) {
  struct Node * head = (struct Node *)malloc(sizeof(struct Node));
  head->data = 1;
  head->left = NULL;
  head->right = NULL;

  head = InsertFirst(head,2);
  head = InsertFirst(head,3);
  head = InsertFirst(head,4);
  head = InsertFirst(head,5);
  
  DisplayRight(&head);
  DisplayLeft(&head);
  return 0;
}