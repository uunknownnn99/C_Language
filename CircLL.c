#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node* next;
};

void Display(struct Node* head){
  struct Node *ptr = head;
  do{
    printf(" %d ",ptr->data);
    ptr = ptr->next;
  }while(ptr != head);
}

struct Node * InsertFirst (struct Node** head,int data) {
  struct Node *new = (struct Node*)malloc(sizeof(struct Node));
  new->data = data;
  struct Node *p = *head;
  while(p->next != *head){
    p = p->next;
  }
  p->next = new;
  new->next = *head;
  return new;
}


int main(){
  struct Node * head = (struct Node*)malloc(sizeof(struct Node));
  struct Node * first = (struct Node*)malloc(sizeof(struct Node));
  struct Node * second = (struct Node*)malloc(sizeof(struct Node));
  struct Node * third = (struct Node*)malloc(sizeof(struct Node));

  head->next = first;
  head->data = 2;
  first->next = second;
  first->data = 4;
  second->next = third;
  second->data = 6;
  third->next = head;
  third->data = 8;

  head = InsertFirst(&head,9);
  // printf("%d",head->data);
  Display(head);
  return 0;
}