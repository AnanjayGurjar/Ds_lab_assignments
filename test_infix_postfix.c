#include<stdio.h>
#include<ctype.h>
#define SIZE 30
int top = -1;
char stack[SIZE];
void push(char x){
    if(top == SIZE - 1){
        printf("Stack Overflow!");
        return;
    }
    stack[++top] = x;
}
char pop(){
    if(top == -1){
        return -1;
    }
    return stack[top--];
}
int priority(char x){
    switch (x)
    {
    case '(':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    case '^':
    case '$':
        return 4;
    default:
        return -1;
    }
}
int main(){
    char exp[SIZE];
    char *e, x;
    printf("Enter the expression:  ");
    scanf("%s", exp);

    e = exp;

    while(*e != '\0'){
        if(isalnum(*e)){
            printf("%c ", *e);
        }else if(*e == '('){
            push(*e);
        }else if(*e == ')'){
            
            while((x = pop()) != '('){
                printf("%c ", x);
            }
            pop();
        }else{
            while(priority(*e) <= priority(stack[top])){
                printf("%c ", pop());
            }
            push(*e);
            
        }
        e++;
    }
    while (top != -1)
    {
        printf("%c ", pop());
    }
    

    return 0;
}
