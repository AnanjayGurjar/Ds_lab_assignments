#include<stdio.h>
struct student{
    char name[20];
    int age;
}s1;

void main(){
    printf("Enter the name of the student\n");
    scanf("%s", s1.name);
    printf("Enter the age of the student\n");
    scanf("%d", s1.age);
    printf("The name of the student is %s and the age is %d", s1.name, s1.age);
}
