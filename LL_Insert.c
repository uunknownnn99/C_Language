#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node* next;
};

void Display(struct Node* ptr){
  while(ptr!=NULL){
    printf("%d ",ptr->data);
    if(ptr->next!=NULL)
        printf("-> ");
    ptr = ptr->next;
  }
}

void DeleteFirst(struct Node **head){
  struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
  temp = *head;
  *head = temp->next;
  free (temp);
}

void DeleteEnd(struct Node *head){
  struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
  temp = head;
  for(;(temp->next)->next!=NULL;){
    temp = temp->next;
  }
  struct Node *p = (temp->next);
  temp->next = NULL;
  free (p);
}

void DeleteAtIndex(struct Node *head,int index){
  struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
  temp = head;
  if(index==0)
      DeleteFirst(&head);
  for(int i=0;i!=index-1;i++){
    temp = temp->next;
  }
  struct Node * p= temp->next;
  temp->next = p->next;
  free (p);
}

void DeleteValue(struct Node* head,int value){
  struct Node *p = head;
  struct Node *q = head->next;
    while(q->data!=value && q->next!= NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
    else
        printf("Element Not Found\n");
}

void InAtFirst(struct Node** head,int data){
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = *head;
    *head = ptr;
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

void InAtIndex(struct Node* head,int data,int index){
  struct Node * new = (struct Node*)malloc(sizeof(struct Node));
  struct Node * ptr = head;
  for(int i=0; i!= index-1; i++){
    ptr = ptr->next;
  }
  new->next = ptr->next;
  ptr->next=new;
  new->data = data;
}

void InAfterNode(int data,struct Node *prevNode){
  struct Node * new = (struct Node*)malloc(sizeof(struct Node));
  new->data = data;
  new->next = prevNode->next;
  prevNode->next = new;
}

int Length(struct Node **head){
  int i;
  struct Node * new = *head;
  for(i=0; new!=NULL ;i++){
    new=new->next;
  }
  return i;
}

int main(){
  int c,d,x,l,hd;
  
  struct Node * head = (struct Node*)malloc(sizeof(struct Node));
  head->next = NULL;
  printf("Enter Data To be Inserted At Head: ");
  scanf("%d",&hd);
  head->data = hd;
  printf("\n");
  printf("For Insertion At Start Enter 1\n");
  printf("For Insertion At End Enter 2\n");
  printf("For Insertion At An Index Enter 3\n");
  printf("To Delete At First Enter 4\n");
  printf("To Delete At End Enter 5\n");
  printf("To Delete At Index Enter 6\n");
  printf("To Delete First Node with Value Enter 7\n");
  printf("To Display Enter 8\n");
  printf("To Calculate Length Enter 9\n");
  printf("To Exit Enter 0\n");
while(1){
  printf("Enter Choice: ");
  scanf("%d",&c);

  switch(c){
    case 1:
      printf("Enter data to be Inserted: ");
      scanf("%d",&d);
      InAtFirst(&head,d);
      break;
    
    case 2:
      printf("Enter data to be Inserted: ");
      scanf("%d",&d);
      InAtEnd(head,d);
      break;
    
    case 3:
      printf("Enter data to be Inserted: ");
      scanf("%d",&d);
      printf("Enter Index to be Inserted at: ");
      scanf("%d",&x);
      l=Length(&head);
      if((l-1)>=x)
        InAtIndex(head,d,x);
      else
        printf("Invalid Index\n");
      break;
    
    case 4:
      DeleteFirst(&head);
      break;

    case 5:
      DeleteEnd(head);
      break;

    case 6:
      printf("Enter Index To Be Deleted At: ");
      scanf("%d",&x);
      DeleteAtIndex(head,x);
      break;

    case 7:
      printf("Enter Value To Be Deleted: ");
      scanf("%d",&d);
      DeleteValue(head,d);
      break;
    
    case 8:
      Display(head);
      printf("\n");
      break;

    case 9:
      printf("\n%d",Length(&head));
      break;
    
    case 0:
      exit (0);
    
    default:
      printf("\nInvalid Choice");
      break;
  }
}
  return 0;
}