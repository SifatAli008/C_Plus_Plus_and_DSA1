#include <iostream>
#include <stdlib.h>

using namespace std;

struct list {
    int data;
    struct list* next;
};

typedef struct list node;

void printList(node* start){
    if(start== nullptr){
        cout<<"Empty List";
    }

    node* temp=start;
    while(temp!=nullptr){
        cout<<temp->data;
        if(temp->next!= nullptr){
            cout<<"->";
        }
        temp=temp->next;
    }
}

int main() {
    node* start = (node*)malloc(sizeof(node));
    start->data = 10;
    start->next = nullptr;


    node* temp=start;
    for (int i = 20; i <= 60; i=i+10) {
        temp->next = new node;
        temp = temp->next;
        temp->data=i;
        temp->next = nullptr;
    }

    printList(start);


    return 0;
}
