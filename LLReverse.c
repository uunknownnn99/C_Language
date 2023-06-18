#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
	struct Node *next;
};

int Length(struct Node *head){
  int i;
  struct Node * new = head;
  for(i=0; new!=NULL ;i++){
    new=new->next;
  }
  return i;
}

void Display(struct Node* ptr){
  while(ptr!=NULL){
    printf("%d ",ptr->data);
    if(ptr->next!=NULL)
        printf("-> ");
    ptr = ptr->next;
  }
}

void InAtEnd(struct Node* head,int data){
  struct Node * ptr = head;
  struct Node * new = (struct Node*)malloc(sizeof(struct Node));
  for(;ptr->next!=NULL;){
    ptr=ptr->next;
  }
  new->data = data;
  new->next = NULL;
  ptr->next=new;
}

void Reverse(struct Node* head){
  struct Node* ptr = head;
  struct Node* prev = head;
  struct Node* p = head;
  int l,s,n;
  l = Length(ptr);
  for(int i=0;i<l/2;i++){
    s = ptr->data;
    n = l-i-1;
    while(n--){
      prev = prev->next;
    }
    // printf("%d ",ptr->data);
    // printf("%d ",prev->data);
    ptr->data = prev->data;
    prev->data = s;
    // printf("\n%d ",ptr->data);
    // printf("%d ",prev->data);
    ptr = ptr->next;
    prev = p;
  }
  //Display(head);
  // printf("%d ",ptr->data);
  // Display(ptr);
}

int main(){
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    head->next = NULL;
    head->data = 0;
    InAtEnd(head,1);
    InAtEnd(head,2);
    InAtEnd(head,3);
    InAtEnd(head,4);
    InAtEnd(head,5);
    
    Display(head);
    Reverse(head);
    printf("\nReversed Linked List: ");
    Display(head);
}