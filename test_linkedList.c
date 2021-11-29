#include<stdio.h>
#include<stdlib.h>
#include "linkedList.h"

int main(){
    insertEnd(12);
    print();    //12
    insertBegin(10);
    print();    //10 12
    insertBegin(45);
    print();    //45 10 12
    insertBegin(15);
    print();    //15 45 10 12
    insertEnd(23);
    print();    //15 45 10 12 23
    insertAny(13, 3);
    print();    //15 45 10 13 12 23
    insertAny(54, 6);
    print();    //15 45 10 13 12 54 23
    insertAny(32, 8);
    print();    //15 45 10 13 12 54 23 32
    // printf("the element is %d\n", search(4));   //10
    // printf("the element is %d\n", search(1));   //15
    // printf("the element is %d\n", search(8));   //32
    // delete(3);
    // print();    //15 45 13 12 54 23 32
    // delete(7);
    // delete(1);
    head = reverse(head);

    print();
}
