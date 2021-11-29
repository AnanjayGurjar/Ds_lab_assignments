#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;


struct Node* createNewNode(int x){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = x;
    newNode -> next = NULL;
    return newNode;
}


void insertBegin(int x){
    struct Node* temp1 = createNewNode(x);
    temp1 -> next = head;
    head = temp1;
}


void insertEnd(int x){
    struct Node* temp1 = createNewNode(x);
    struct Node* temp2;
    if(head == NULL){
        head = temp1;
        return;
    }
    temp2 = head;
    while(temp2 -> next != NULL){
        temp2 = temp2 -> next;
    }
    temp2 -> next = temp1;
}


void insertAny(int x, int pos){
    struct Node* temp1 = createNewNode(x);
    struct Node* temp2 = head;
    if(pos == 1){
        insertBegin(x);
        return;
    }
    for(int i = 0; i < pos - 2; i++){
        temp2 = temp2 -> next;
    }
    temp1 -> next = temp2 -> next;
    temp2 -> next = temp1;
    
}


void delete(int pos){
    struct Node* temp = head;
    if(pos <= 2){
        
    }
    for(int i = 0; i < pos -2; i++){
        temp = temp -> next;
    }
    struct Node* temp2 = temp->next;
    int deletedElement = temp2 -> data;
    temp -> next = temp2 -> next;
    free(temp2);
    printf("Element deleted is: %d\n", deletedElement);

}
void print(){
    
    struct Node* temp = head;
    printf("The list is  :  ");
    while (temp != NULL){
        printf("%d   ", temp -> data);
        temp = temp->next;
    }
    printf("\n");
}
int search(int index){
    struct Node* temp = head;
    for(int i = 0; i < index - 1; i++){
        temp = temp -> next;
    }
    return temp -> data;
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
    insertAny(32, 8);
    print();    //15 45 10 13 12 54 23 32
    printf("the element is %d\n", search(4));
    delete(3);
    print();    //15 45 13 12 54 23 32
    delete(7);
    delete(1);

    print();

    return 0;
}