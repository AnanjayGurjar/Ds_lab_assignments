#include<stdio.h>
#include<ctype.h>
#include<math.h>

double operation(char symbol, double op1, double op2){
    switch (symbol)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1/op2;
    case '^':
    case '$':
        return pow(op1, op2);
    }
}
void push(double x, double s[], int* top){
    (*top++);
    s[*top] = x;
}
double pop(int* top, double s[]){
    double toBeDeleted = s[*top--];
    return toBeDeleted;
}
int isDigit(char x){
    return (x >= '0' && x <= '9');
}
void main(){
    char exp[20];
    double s[20], result;
    int top = -1;
    scanf("%s", exp);
    for(int i = 0; i < strlen(exp); i++){
        char x = exp[i];
        if(isDigit(x)){
            push(x - '0',s ,&top);
        }else{
            double op1 = pop(&top, s);
            double op2 = pop(&top, s);
            result = operation(s[top], op1, op2);
            push(result, s, &top);
        }
    }
    result = pop(&top, s);
    printf("The result of evaluated postfix expression is:\t%lf\n", result);
}