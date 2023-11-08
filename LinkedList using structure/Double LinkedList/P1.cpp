//
// Created by Sifat Ali on 11/8/2023.
//
#include <iostream>
#include <stdlib.h>

using namespace std;

struct list{
    int data;
    struct list *next;
    struct list *back;
};

typedef  struct list node;

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
    node* start;
    node* temp;
    int i;
    start=(node*) malloc(sizeof (node));
    start->data=10;
    start->next= nullptr;
    start->back= nullptr;

    node* prev=start;
    for (int i = 20; i <= 30; i=i+10) {
        temp=(node*) malloc(sizeof(node));
        temp->data=i;
        temp->next= nullptr;
        temp->back=prev;
        prev->next=temp;
        prev=temp;
    }

    printList(start);

    return 0;
}