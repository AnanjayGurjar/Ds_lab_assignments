#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* link;
};

struct Node* reverse(struct Node* head){
    struct Node *current, *next, *prev;
    current = head;
    prev = NULL;
    while(current != NULL){
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}