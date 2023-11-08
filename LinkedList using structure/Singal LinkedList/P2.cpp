#include <iostream>
#include <stdlib.h>
using namespace std;

struct list{
    int data;
    struct list *next;
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


int main(){
    node *start;
    start=(node*)malloc(sizeof(node));
   start->data=10;
   start->next->data=20;
   start->next->next->data=30;
   start->next->next->next= nullptr;

    printList(start);

    return 0;
}