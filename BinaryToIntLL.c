#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
char B[100];

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

int Length(struct Node **head){
  int i;
  struct Node * new = *head;
  for(i=0; new!=NULL ;i++){
    new=new->next;
  }
  return i;
}

// int BInt(struct Node* head){
//     int sum = 0,d,i;
//     struct Node * ptr = head;
//     i=Length(&ptr);
//     for(int j=0;j<i;j++){
//         d=ptr->data;
//         sum+=(pow(2,i))*d;
//         ptr=ptr->next;
//     }
//     return sum;
// }

int BInt(struct Node* head){
    int sum = 0,d,i;
    struct Node * ptr = head;
    i=Length(&ptr);
    for(;i--;){
        d=ptr->data;
        sum+=(pow(2,i))*d;
        ptr=ptr->next;
    }
    return sum;
}

int main(){
    int n,k,l;
    struct Node * head = (struct Node*)malloc(sizeof(struct Node));
    head->next = NULL;
    printf("Enter Binary Number: ");
    scanf("%s",B);
    n=strlen(B);
    //printf("%d  ",n);
    for(int i=0;i<n;i++){
        k=B[i]-48;
        if(i==0){
            head->data = k;
            continue;
        }
        InAtEnd(head,k);
    }
    //Display(head);
    printf("Integer: %d",BInt(head));
    return 0;
}