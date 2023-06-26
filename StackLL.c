#include <stdio.h>
#include <stdlib.h>

struct Node{
  struct Node * left;
  struct Node * right;
  int data;
};

void Display(struct Node** head){
  struct Node* ptr = *head;
  while(ptr->right != NULL){
      ptr=ptr->right;
  }
  printf("Stack is: ");
  while(ptr != NULL){
      printf("\n%d",ptr->data);
      ptr=ptr->left;
  }
}

void pop(struct Node* head){
    struct Node* ptr = head;
    while(ptr->right!=NULL)
        ptr=ptr->right;
    struct Node* temp = ptr->left;
    temp->right = NULL;
    //printf("\nRemoved Element: %d",ptr->data);
    free(ptr);
}

void push(struct Node* head,int data){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    struct Node* ptr = head;
    while(ptr->right!=NULL)
        ptr=ptr->right;

    ptr->right = new;
    new->left = ptr;
    new->right = NULL;
    new->data = data;
}

int main(){
    int c,d,x=0;
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->left = NULL;
    head->right = NULL;
    head->data = 0;
    printf("Enter 1 to push\nEnter 2 to pop\nEnter 3 to Display\nEnter 4 to Exit");
    do{
    printf("\nEnter Choice: ");
    scanf("%d",&c);
    switch(c){
        case 1:
            printf("\nEnter data to Push: ");
            scanf("%d",&d);
            if(x==0){
                head->data = d;
                x++;
            }
            else
                push(head,d);
            break;
        
        case 2:
            if(head == NULL){
                printf("\nStack Underflow");
            }
            else
                pop(head);
            break;

        case 3:
            Display(&head);
            break;
        case 4:
            exit(0);
        
        default:
            printf("\nInvalid Choice");
            break;
    }
    }while(1);
}