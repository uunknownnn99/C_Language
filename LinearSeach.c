#include<stdio.h>
int A[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

int LS_non(int num,int l){
    for(int i=0;i<l;i++){
        if(A[i]==num)
            return i;
    }
    return -1;
}

int LS_rec(int num,int l,int i){
    if(i==l)
        return -1;
    else if(A[i]==num)
        return i;
    else
        return LS_rec(num,l,++i);
}

int main(){
    int n,k;
    int l = sizeof(A)/sizeof(int);
    printf("\nEnter Value to Search: ");
    scanf("%d",&n);
    k = LS_rec(n,l,0);
    if(k!=-1) printf("\nElement Found at Index: %d",k);
    else printf("\nElement Not Found");
}