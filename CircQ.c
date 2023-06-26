#include<stdio.h>
#define MAX 10
int Q[MAX];
int front = -1;
int rear = -1;

void Display(){
    printf("\n");
    if(front==-1 || front>rear)
        printf("\nQueue Is Empty");
    else{
        for(int i=front;i<=rear;i++)
            printf("%d ",Q[i]);
    }
    printf("\n");
}

void Dequeue(){
    int temp;
    if(front!=-1 && rear!=-1)
        for(int i=0;i<rear;i++){
            Q[i]=Q[i+1];
        }
    rear--;
    if(rear==-1)
        front = -1;
}

void Enqueue(int data){
    front = 0;
    rear++;
    if(rear==MAX){
        printf("\nQueue Is Full to Further Insert %d is Removed",Q[front]);
        Dequeue();
        Q[rear]=data;
        return;
    }
    Q[rear]=data;
}

int main(){
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Enqueue(5);
    Display();
}