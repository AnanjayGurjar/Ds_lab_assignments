#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 5

int s[STACK_SIZE];
int item;
int top = -1;

void push(){
    if(top == STACK_SIZE - 1){
        printf("Stack overflow \n");
        return;
    }
    scanf("%d", &item);
    s[++top] = item;
    
    
}
int pop(){
    int item_deleted;
    if(top == -1){
        return 0;
    }
    item_deleted = s[top];
    top--;
    return item_deleted;

}
void display(){
    int i;
    if(top == -1){
        printf("Stack is empty\n");
        return;
    }
    printf("Contents of the stack are: \n");
    for(i = 0; i<= top; i++){
        printf("%d\n", s[i] );
    }
}

void main(){
    int item_deleted, choice;
    top = -1;
    for(;;){
        printf("Enter the choice\n");
        printf("1: Push \n2: Pop\n3: Display\n4: Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter the item to be inserted\n");
            push();
            break;
        
        case 2:
            item_deleted = pop();
            if(item_deleted == 0){
                printf("Stack is empty\n");
            }else{
                printf("Item deleted: %d\n", item_deleted);
            }
            break;
        
        case 3:
            display();
            break;
        default:
            exit(0);
        }
    }
}