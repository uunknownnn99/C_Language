#include<stdio.h>
int A[]={1,6,7,8,9,10,11,12,2,3,4,5,13,14,15};

void print(int l){
    for(int i=0;i<l;i++)
        printf("%d ",A[i]);
}

void sort(int l){
    for(int i=0;i<l-1;i++){
        for(int j=0;j<l-i-1;j++){
            if(A[j]>A[j+1]){
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

int main(){
    int l= sizeof(A)/sizeof(int);
    print(l);
    printf("\nSorted Array : ");
    sort(l);
    print(l);
}