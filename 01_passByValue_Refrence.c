#include<stdio.h>
int passByValue(int a, int b){
    return a + b;
}
int passByRefrence(int *a, int *b){
    return *a + *b;
}

int  main(){
    
    int *ptr;
    *ptr = 5;
    printf("%d", *ptr);
    
return 0;
    
}