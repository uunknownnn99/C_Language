#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int n1;
int n2;
int n3=0;
struct Node{
    int data;
    struct Node* next;
};

void Display(struct Node* ptr,int n){
    while((ptr->next)->next!=NULL){
        printf("%dx^%d + ",ptr->data,n--);
        ptr = ptr->next;
    }
    printf("%dx + ",ptr->data);
    ptr = ptr->next;
    printf("%d\n",ptr->data);
}

void Insert(struct Node* head,int data){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    struct Node* ptr = head;
    while(ptr->next!=NULL)
        ptr = ptr->next;
    ptr->next = new;
    new->data = data;
    new->next = NULL;
}

void add(struct Node* head1, struct Node* head2,struct Node* head3){
    int a,c=0,b;
    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;
    if(n1>n2){
        n3=n1;
        while(n1!=n2){
            if(c==0){
                head3->data = ptr1->data;
                c++;
                ptr1 = ptr1->next;
            }
            else{
                Insert(head3,ptr1->data);
                ptr1 = ptr1->next;
            }
            n1--;
        }
        while(n1!=0){
            b = ptr1->data + ptr2->data;
            Insert(head3,b);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            n1--;
        }
    }
    else if(n1<n2){
        c=0;
        n3=n2;
        while(n1!=n2){
            if(c==0){
                head3->data = ptr2->data;
                c++;
                ptr2 = ptr2->next;
            }
            else{
                Insert(head3,ptr1->data);
                ptr1 = ptr1->next;
            }
            n2--;
        }
        while(n2!=0){
            b = ptr1->data + ptr2->data;
            Insert(head3,b);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            n2--;
        }
    }
    else{
        c=0;
        n3=n1;
        while(n2!=0){
            if(c==0){
                head3->data = (ptr2->data + ptr1->data);
                c++;
                ptr2 = ptr2->next;
                ptr1 = ptr1->next;
            }
            else{
                b = ptr1->data + ptr2->data;
                Insert(head3,b);
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
                n2--;
            }
        }
    }
}

int main(){
    int x,y,z;
    struct Node* head1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* head2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* head3 = (struct Node*)malloc(sizeof(struct Node));
    head1->next = NULL;
    head2->next = NULL;
    head3->next = NULL;
    printf("Enter Order Of Polynomial 1: ");
    scanf("%d",&n1);
    x=n1;
    for(int i=0;i<=n1;i++){
        printf("Enter Coeficient for Exponent %d: ",x--);
        scanf("%d",&y);
        if(i==0)
            head1->data = y;
        else   
            Insert(head1,y);
    }
    printf("Enter Order Of Polynomial 2: ");
    scanf("%d",&n2);
    z=n2;
    for(int i=0;i<=n2;i++){
        printf("Enter Coeficient for Exponent %d: ",z--);
        scanf("%d",&y);
        if(i==0)
            head2->data = y;
        else   
            Insert(head2,y);
    }
    Display(head1,n1);
    Display(head2,n2);
    add(head1,head2,head3);
    Display(head3,n3);
    return 0;
}