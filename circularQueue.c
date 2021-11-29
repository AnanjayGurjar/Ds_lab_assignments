#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5
int start = -1;
int rear = -1;
int queue[MAX_SIZE];
void enqueue(int x){
    if(start = rear + 1 || (start == 0 && rear == MAX_SIZE - 1)){
        printf("Queue is full");
        return;
    }
    if(start == -1){
        start = 0;
    }
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = x;

}
void dequeue(){
    if(start == -1){
        printf("Queue is empty");
        return;
    }
    int tobedel = queue[start];
    if(start == rear){
        start = rear = -1;
    }else{
        start = (start + 1)%MAX_SIZE;
    }
    printf("%d delted", tobedel);

}
void display(){
    if(start == -1){
        printf("Queue is empty");
        return;
    }
    for(int i = start; i != rear; i = (i + 1)%MAX_SIZE){
        printf("%d  \n", queue[i]);
    }
    printf("%d  \n", queue[rear]);
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
