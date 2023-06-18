#include <stdio.h>
#include <stdlib.h>

struct Node{
  struct Node * left;
  struct Node * right;
  int data;
};

void Display(struct Node** head){
  struct Node* ptr = *head;
  printf("Right Transversal: ");
  while(ptr->right != NULL){
      printf("%d ",ptr->data);
      ptr=ptr->right;
  }
  printf("%d",ptr->data);
  printf("\n");
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

struct Node* DeleteFirst(struct Node* head){
  struct Node* ptr = head->right;
  ptr->left = NULL;
  free(head);
  return ptr;
}

void DeleteAtPos(struct Node* head,int pos){
  struct Node* ptr = head;
  struct Node* prev = NULL;
  if(pos==0)
    DeleteFirst(ptr);
  else{
    for(int i=0;i!=pos;i++){
      ptr = ptr->right;
    }
    prev = ptr->right;
    (ptr->left)->right = prev;
    prev->left = ptr->left ;
    free(ptr);
  }
}

void InsertAtPos(struct Node *head, int pos, int data){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = data;
    struct Node* ptr = head;
    for(int i=0;i!=pos-1;i++){
        ptr = ptr->right;
    }
    struct Node* q= ptr->right;
    ptr->right = new;
    q->left = new;
    new->right = q;
    new->left = ptr;
}

void DeleteEnd(struct Node* head){
  struct Node* ptr = head;
  while(ptr->right!=NULL)
    ptr=ptr->right;
  struct Node* q = ptr->left;
  q->right = NULL;
  free(ptr);
}

void InsertEnd(struct Node* head,int data){
  struct Node* new = (struct Node*)malloc(sizeof(struct Node));
  struct Node* ptr = head;
  new->data = data;
  new->right = NULL;
  while(ptr->right!=NULL)
    ptr=ptr->right;
  ptr->right = new;
  new->left = ptr ;
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
  //DisplayRight(&head);
  //InsertAtPos(head,3,9);
  //DisplayRight(&head);
  //DeleteEnd(head);

  //InsertEnd(head,10);
  //DisplayRight(&head);
  //DeleteAtPos(head,4);

  //head = DeleteFirst(head);

  Display(&head);
  return 0;
}