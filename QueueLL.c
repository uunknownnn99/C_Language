#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node* next;
};

void Display(struct Node* ptr){
  while(ptr!=NULL){
    printf("%d ",ptr->data);
    ptr = ptr->next;
  }
}

struct Node* Dequeue(struct Node* head){
    struct Node* temp = head;
    printf("Removed Element: %d",temp->data);
    temp = temp->next;
    free(head);
    return temp;
}

void Enqueue(struct Node* head,int data){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    struct Node* ptr = head;
    while(ptr->next!=NULL)
        ptr = ptr->next;
    ptr->next = new;
    new->data = data;
    new->next = NULL;
}

int main(){
    int c,d,x=0;
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->next = NULL;
    printf("Enter 1 to Enqueue\nEnter 2 to Dequeue\nEnter 3 to Display\nEnter 4 to Exit");
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
                Enqueue(head,d);
            break;
        
        case 2:
            if(head==NULL){
                printf("\nQueue Empty");
                x--;
            }
            else
                head = Dequeue(head);
            break;

        case 3:
            Display(head);
            break;
        
        case 4:
            exit(0);
        
        default:
            printf("\nInvalid Choice");
            break;
    }
}while(1);
}