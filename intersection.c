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
  printf("\n");
}

void Instersection(struct Node* ptr1,struct Node* ptr2){
    struct Node* p2 = ptr2;
    struct Node* p1;
    while(p2!=NULL){
        p1 = ptr1;
        while(p1!=NULL){
            if(p1==p2){
                printf("\nMerge At : %d",p1->data);
                break;
            }
            p1=p1->next;
        }
        if(p1==p2)
            break;
        p2=p2->next;
    }
    if(p1!=p2)
        printf("Do Not Merge\n");
}

int main(){
    struct Node* head1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* head2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* first = (struct Node*)malloc(sizeof(struct Node));
    struct Node* first2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    head1->data = 10;
    head1->next = first;
    first->data = 15;
    first->next = second;
    second->data = 30;
    second->next = NULL;
    head2->data = 3;
    head2->next = first2;
    first2->data = 6;
    first2->next = second2;
    second2->data = 9;
    second2->next = first;
    //Display(head1);
    //Display(head2);
    Instersection(head1,head2);
}