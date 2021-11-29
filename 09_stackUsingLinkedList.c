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
        printf("Stack is empty cannot pop");
        return;
    }
    struct Node* temp = top;
    top = top -> link;
    printf("The element %d is popped out of stack\n", temp -> data);
    free(temp);
}
int peek(){
    return top -> data;
}
void display(){
    struct Node* temp = top;
    while (temp != NULL){
        printf("%d  ", temp -> data);
        temp = temp -> link;
    }
    printf("\n");
    free(temp);
    
}
int main(){
    push(10);
    display();  //10
    push(23);
    display();  //23 10
    push(54);
    display();  //54 23 10
    push(43);
    display();  //43 54 23 10
    pop();      //54 23 10
    printf("The element at the top is %d\n " , peek());
    push(32);   
    display();  //32 54 23 10
    push(76);   
    display();  //76 32 54 23 10

    return 0;
}