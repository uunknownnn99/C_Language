#include<stdio.h>
int A[]={1,6,7,8,12,10,11,12,2,3,4,5,13,14,15};

void print(int l){
    for(int i=0;i<l;i++)
        printf("%d ",A[i]);
    printf("\n");
}

void sort(int l){
    for(int i=1;i<l;i++){
        int key = A[i];
        int j = i-1;
        for(;j>=0 && A[j]>key;){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    }
}

int main(){
    int l = sizeof(A)/sizeof(int);
    print(l);
    sort(l);
    printf("Sorted Array: ");
    print(l);
}