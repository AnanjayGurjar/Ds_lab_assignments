#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 6
int top = -1;
int stack[MAX_SIZE];
void push(int x){
    if(top == MAX_SIZE - 1){
        printf("Stack Overflow");
        return;
    }
    stack[++top] = x;
}
void pop(){
    if(top == -1){
        printf("Stack Underflow");
        return;
    }
    int toBeDelted = stack[top];
    top--;
    printf("%d delted from the stack", toBeDelted);
}
void diplay(){
    for(int i = 0; i <= top; i++){
        printf("%d  ", stack[i]);
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
            push(element);
            break;
        case 2:
            pop();
            break;
        case 3:
            printf("The elements in the stack are: \n");
            diplay();
            break;
        case 4: 
            exit(0);
        default:
            break;
        }
    }
    return 0;
}
