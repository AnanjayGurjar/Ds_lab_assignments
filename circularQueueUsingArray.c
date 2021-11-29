#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 5
int front = -1;
int rear = -1;
int circularQueue[MAX_SIZE];
int isEmpty(){
    if(front == -1){
        return 1;
    }
    return 0;
}

void enqueue(int x){
    if(front == rear + 1 || (front == 0 && rear == MAX_SIZE -1)){
        printf("Queue is full, cannot enqueue\n");
        return;
    }
    if(front == -1){
        front = 0;
    }
    rear = (rear + 1) % MAX_SIZE;
    circularQueue[rear] = x;
    printf("%d is inserted in the queue", x);
}
void dequeue(){
    if(isEmpty()){
        printf("Queue is empty!!!");
        return;
    }
    int toBeDeleted = circularQueue[front];
    if(front == rear){
        front = rear = -1;
    }else{
        front = (front + 1)%MAX_SIZE;
    }
    printf("\n Delted element is %d\n", toBeDeleted);
    

}
void display(){
    if(isEmpty()){
        printf("Queue is empty");
        return;
    }
    for(int i = front; i != rear; i = (i+1) % MAX_SIZE){
        printf("%d  ", circularQueue[i]);
    }
    printf("%d  ", circularQueue[rear]);
    printf("\n");
}

void main(){
    int choice, element;
    printf("1. enqueue\n 2. dequeue\n 3. display\n 4. Exit");
    while(1){
        printf("Enter the choice");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted\n");
            scanf("%d", &element);

            enqueue(element);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalide input");
            break;
        }
    }
}
