#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* link;
};
struct Node* front = NULL;
struct Node* rear = NULL;
void enqueue(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = x;
    temp -> link = NULL;
    if(front == NULL && rear == NULL){
        front = rear = temp;
        return;
    }
    rear -> link = temp;
    rear = temp;
}
void dequeue(){
    struct Node* temp = front;
    if(front == NULL && rear == NULL){
        printf("Queue is empty\n");
        return;
    }
    if(front == rear){
        front = rear = NULL;
    }else{
        front = front -> link;
    }
    free(temp);
}
void display(){
    struct Node* temp = front;
    while(temp != rear){
        printf("%d  ", temp -> data);
        temp = temp -> link;
    }
    printf("%d", temp -> data);
    printf("\n"); 
}
int main(){
    enqueue(12);
    display();  //12
    enqueue(32);
    display();  //12 32
    enqueue(43);
    display();  //12 32 43
    enqueue(54);
    display();  //12 32 43 54
    dequeue();
    display();  //32 43 54
    enqueue(98);
    display();  //32 43 54 98

    return 0;
}
