#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 6
int front = -1;
int rear = -1;
int queue[MAX_SIZE];
void enqueue(int x){
    if(rear == MAX_SIZE - 1){
        printf("Queue is full, cannot enqueue");
        return;
    }
    if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = x;
        return;
    }
    queue[++rear] = x;
}
void dequeue(){
    if(front == rear == -1 ){
        printf("queue is empty, cannot dequeue");
        return;
    }
    if(front == rear || front == MAX_SIZE - 1){

        printf("%d deleted from the queue\n", queue[front]);
        front = rear = -1;
        printf("Queue is empty and free to use\n");
        return;        
    }
    int toBeDeleted = queue[front];
    front++;
    printf("%d delted from the queue", toBeDeleted);
}
void display(){
    for(int i = front; i <= rear; i++){
        printf("%d  ", queue[i]);
    }
    printf("\n");
}
int main(){
    int choice, element;
    printf("1. pushing element in the stack\n");
    printf("2. poping the element out of the stack\n");
    printf("3. display the elements in the stack\n");
    printf("4. Exit the program\n");
    while(1){
        
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter the element you want to push into the stack");
            scanf("%d", &element);
            enqueue(element);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            printf("The elements in the stack are: \n");
            display();
            break;
        case 4: 
            exit(0);
        default:
            break;
        }
    }
    return 0;
}
