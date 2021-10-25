#include<stdio.h>
#include<stdlib.h>

struct student{
    char name[20];
    int age;
};
void main(){
    struct student *s;
    s = (struct person*)malloc(sizeof(struct student));
    printf("Please enter the name and the age of the student\n");
    scanf("%s %d", (s)-> name, &(s)-> age);
    printf("Name is %s and age is %d",(s)-> name, (s)-> age );
}