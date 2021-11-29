#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head = NULL;

struct Node* createNode(int x){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = x;
    
	newNode->prev = NULL;
	newNode->next = NULL;
    return newNode;
}

void insertBegin(int x){
    struct Node* temp1 = createNode(x);
    if(head == NULL){
        head = temp1;
        return;
    }
    head -> prev = temp1;
    temp1 -> next = head;
    head = temp1;
}

void insertEnd(int x){
    struct Node* temp1 = createNode(x);
    if(head == NULL){
        head = temp1;
        return;
    }
    struct Node* temp2 = head;
    while (temp2-> next != NULL){
        temp2 = temp2 -> next;
    }
    temp1 -> prev = temp2;
    temp2 -> next = temp1;
    
    
}
int search(int index){
    struct Node* temp = head;
    for(int i = 0; i < index - 1; i++){
        temp = temp -> next;
    }
    return temp -> data;
}
void insertAny(int x, int pos){
    struct Node* temp1 = createNode(x);
    if(pos == 1){
        insertBegin(x);
        return;
    }
    struct Node* temp2 = head;
    for(int i = 0; i < pos -2; i++){
        temp2 = temp2 -> next;
    }
    temp1 -> next = temp2 -> next;
    temp2 -> next = temp1;
    temp1 -> prev = temp2;
}
void delete(int pos){
    struct Node* temp = head;
    for(int i = 0; i< pos - 2; i++){
        temp = temp -> next;
    }
    struct Node* item = temp -> next;
    temp -> next = item -> next;
    (item -> next) -> prev = temp;
    printf("%d deleted\n", item -> data);
    free(item);

}
void print(){
    struct Node* temp = head;
	printf("Forward: ");
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
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
    insertBegin(56);
    print();
    insertAny(13, 3);
    print();    //15 45 10 13 12 23
    insertAny(54, 6);
    print();    //15 45 10 13 12 54 23
    insertAny(32, 8);
    print();    //15 45 10 13 12 54 23 32
    delete(3);
    print();    //15 45 13 12 54 23 32
    printf("element at index 4 is: %d\n" , search(4));

    delete(5);
    print();
    return 0;
}