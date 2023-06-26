#include<stdio.h>
#include<stdlib.h>

struct Tree{
    int data;
    struct Tree *left,*right;
};

struct Tree* Create(){
    int x,d;
    struct Tree* new = (struct Tree*)malloc(sizeof(struct Tree));
    printf("\nEnter -1 for No Node Creation: ");
    scanf("\n%d",&x);
    if(x==-1)
        return 0;
    printf("\nEnter Data: ");
    scanf("%d",&d);
    new->data = d;
    printf("\nLeft Node Creation of %d\n",d);
    new->left = Create();
    printf("\nRight Node Creation of %d\n",d);
    new->right = Create();
    return new;
}

void PreOrder(struct Tree* root){
    struct Tree* ptr = root;
    if(ptr==0){
        return;
    }
    printf(" %d ",ptr->data);
    PreOrder(ptr->left);
    PreOrder(ptr->right);
}

void InOrder(struct Tree* root){
    struct Tree* ptr = root;
    if(ptr==0){
        return;
    }
    InOrder(ptr->left);
    printf(" %d ",ptr->data);
    InOrder(ptr->right);
}

void PostOrder(struct Tree* root){
    struct Tree* ptr = root;
    if(ptr==0){
        return;
    }
    PostOrder(ptr->left);
    PostOrder(ptr->right);
    printf(" %d ",ptr->data);
}

int main(){
    struct Tree* root = Create();
    printf("\nPreOrder Transversal: ");
    PreOrder(root);
    printf("\nInOrder Transversal: ");
    InOrder(root);
    printf("\nPostOrder Transversal: ");
    PostOrder(root);
    return 0;
}