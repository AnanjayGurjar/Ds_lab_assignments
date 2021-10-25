#include<stdio.h>
int passByValue(int a, int b){
    return a + b;
}
int passByRefrence(int *a, int *b){
    return *a + *b;
}

void main(){
    int a = 10;
    int b = 15;
    int resultByValue = passByValue(a, b);
    int resultByRefrence = passByRefrence(&a, &b);
    printf("Result for pass by value: %d \n", resultByValue);
    printf("Result for pass by refrence: %d \n", resultByRefrence);
    
}