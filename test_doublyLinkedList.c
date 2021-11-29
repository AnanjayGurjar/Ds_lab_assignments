#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node*  head = NULL;
struct Node* rear = NULL;
struct Node* createNode(int x){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = x;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    return newNode;
}

void insertBegin(int x){
    struct Node* temp = createNode(x);
    if(head == NULL){
        temp -> next = head;
        head = rear = temp;
    }
    temp -> next = head;
    head = temp;
    
}
void insertEnd(int x){
    struct Node* temp = createNode(x);
    if(head == NULL){
        head = rear = temp;
        return;
    }
    temp -> prev = rear;
    rear -> next = temp;
    rear = temp;
}
void insertAny(int x, int pos){
    if(pos == 1){
        insertBegin(x);
        return;
    }
    struct Node* temp = createNode(x);
    struct Node* temp2 = head;
    for(int i = 0; i < pos - 2; i++){
        temp2 = temp2 -> next;
    }
    if(temp2 -> next == NULL){
        insertEnd(x);
        return;
    }
    temp -> next = temp2 -> next;
    temp2 -> next = temp;
    temp -> prev = temp2;

}
void print(){
    struct Node* temp = head;
    while(temp != rear){
        printf("%d   ", temp -> data);
        temp = temp -> next;
    }
    printf("%d   ", temp -> data);
    printf("\n");
}
void delete(int pos){
    struct Node* temp = head;
    if(head == NULL && rear == NULL){
        printf("List is empty, cannot delete");
        return;
    }
    if(pos == 1){
        if(head == rear){
            printf("item %d is delted\n", head -> data);
            head = rear = NULL;
            free(temp);
            return;
        }
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
    delete(1);
    delete(5);
    delete(5);
    print();
    insertAny(32, 8);
    print();    //15 45 10 13 12 54 23 32
    

    return 0;
}