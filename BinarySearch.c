#include<stdio.h>
int A[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

int NonRec(int num,int j,int i){
    int s=0,l=j,m;
    while(s < j){
        m=(s+l)/2;
        if(A[m]==num)
            return m;
        else if(num>A[m]){
            s=m+1;
            m = s+l/2;
        }
        else if(num<A[m]){
            l=m-1;
            m = s+l/2;
        }
    }
    return -1;
}

int Rec(int num,int l,int f){
    int m=(l+f)/2;
    if(m<=l && m>=f){
    if(A[m]==num)
        return m;
    else if(A[m]>num)
        return Rec(num,m-1,f);
    else if(A[m]<num)
        return Rec(num,l,m+1);
    }
    else return -1;
}

int main(){
    int n,k;
    int l = sizeof(A)/sizeof(int);
    printf("\nEnter Value to Search: ");
    scanf("%d",&n);
    k = Rec(n,l,0);
    if(k!=-1) printf("\nElement Found at Index: %d",k);
    else printf("\nElement Not Found");
}