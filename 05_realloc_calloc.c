#include<stdio.h>
#include<stdlib.h>


void main(){
    int *p, i, n;
    printf("The initial size of the array is 4\n");
    p = (int *)calloc(4, sizeof(int));
    if(p == NULL){
        printf("memory allocation failed");
        exit(0);
    }
    for(i = 0; i < 4; i++){
        printf("Enter elemenat at idex %d  ", i);
        scanf("%d", p+i);
    }
    printf("\nIncreasing the size of the array by 5 elements\n");
    p = (int *) realloc(p, i*sizeof(int));
    if(p == NULL){
        printf("Memeroy allocation failed");
        exit(0);
    }
    printf("\nEnter 5 more integers\n");
    for(i = 4; i<9; i++){
        printf("Enter element at index %d: ", i);
        scanf("%d", p+i);
    }
    printf("\n Final array: \n");
    for(i = 0; i<9; i++){
        printf("%d  ", *(p+i));
    
    }



}
