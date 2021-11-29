#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;
void enqueue(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = x;
    temp -> next = NULL;
    if(front == NULL && rear == NULL){
        front = rear = temp;
        return;
    }
    rear -> next = temp;
    rear = temp;
}
void dequeue(){
    if(front == NULL && rear == NULL){
        printf("Queue is empty, cannot dequeue\n");
        return;
    }
    struct Node* temp = front;
    if(front == rear){
        front = rear = NULL;
    }else{
        front = front -> next;
    }
    free(temp);
}
void print(){
    struct Node* temp = front;
    while(temp != rear){
        printf("%d  ", temp -> data);
        temp = temp -> next;
    }
    printf("%d  ", temp -> data);
    printf("\n");
}
int main(){
    enqueue(120);   //120
    print();
    enqueue(45);    //120 45
     print();
    enqueue(100);   //120 45 100
     print();
    dequeue();      //45 100
     print();
    enqueue(49);    //45 100 49
     print();
    enqueue(54);    //45 100 49 54
     print();
    dequeue();      //100 49 54
     print();
    dequeue();      //49 54
     print();
    dequeue();      //54
     print();
    dequeue();      //
     print();
     dequeue();      //
     print();

}
