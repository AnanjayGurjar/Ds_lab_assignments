#include<stdio.h>
int i = 10, j = 15;

int add_local(int a, int b){
    return a+b;
}
int add_global(){
    return i+j;
}

void main(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("The sum of local variables is %d and the sum of global variable is %d", add_local(a, b), add_global());
}