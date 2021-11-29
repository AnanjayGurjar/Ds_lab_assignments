#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head = NULL;

struct Node* createNode(int x){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = x;
    newNode -> next = NULL;
    return newNode;
}
struct Node insertBegin(int x){
    struct Node* temp = createNode(x);
    temp -> next = head;
    head = temp;
}
void insertEnd(int x){
    struct Node* temp = createNode(x);
    if(head == NULL){
        head = temp;
        return;
    }
    struct Node* temp2 = head;
    while(temp2->next != NULL){
        temp2 = temp2 -> next;
    }
    temp2->next = temp;
}
void insertAny(int x, int index){
    struct Node* temp = createNode(x);
    if(index == 1){
        insertBegin(x);
        return;
    }
    struct Node* temp2 = head;
    for(int i = 0; i < index - 2; i++){
        temp2 = temp2 -> next;
    }
    temp -> next = temp2 -> next;
    temp2 -> next = temp;

}
int search(int pos){
    if(pos == 1){
        return head -> data;
    }
    struct Node* temp = head;
    for(int i = 0; i < pos - 1; i++){
        temp = temp -> next;
    }
    return temp -> data;

}
struct Node* reverse(){
    struct Node *current, *next, *prev;
    current = head;
    prev = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}
void deleteSomething(int pos){
    struct Node* temp = head;
    if(pos == 1){
        head = head -> next;
        printf("item %d is delted\n", temp -> data);
        free(temp);
    }else{
        for(int i = 0; i < pos - 2; i++){
            temp = temp -> next;
        }
        struct Node* toBeDeleted = temp -> next;
        temp -> next = toBeDeleted-> next;
        printf("item %d is deleted\n", toBeDeleted -> data);
        free(toBeDeleted);
    }
}
void print(){
    struct Node* temp = head;
    while(temp!= NULL){
        printf("%d    ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}