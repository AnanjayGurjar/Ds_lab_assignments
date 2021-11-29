#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* link;
};
struct Node* top = NULL;
void push(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = x;
    temp -> link = top;
    top = temp;
}
void pop(){
    if(top == NULL){
        printf("Stack is empty,cannot pop");
        return;
    }
    struct Node* temp = top;
    top = top -> link;
    free(temp);
}
void display(){
    if(top == NULL){
        printf("Stack is empty");
        return;
    }
    struct Node* temp = top;
    while (temp != NULL){
        printf("%d   ", temp -> data);
        temp = temp -> link;
    }
    printf("\n");
}
int main(){
    push(10);   //10
    display();
    push(15);   //15 10
    display();
    push(78);   //78 15 10
    display();
    push(11);   //11 78 15 10
    display();
    pop();      //78 15 10 
    display();
    pop();      //15 10
    display();
    push(65);   //65 15 10
    display();
    push(12);   //12 65 15 10 
    display();
    pop();      //65 15 10
    display();
    return 0;
}