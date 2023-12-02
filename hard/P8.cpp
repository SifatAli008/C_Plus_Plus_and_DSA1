//Reverse a doubly linked list in groups of given size
// Created by Sifat Ali on 11/30/2023.
//
#include <iostream>

class LL{
    class node{
    public:
        node* pre;
        int data;
        node* next;
        node(int data){
            this->pre= nullptr;
            this->data=data;
            this->next= nullptr;
        }
    };
    node* head;
    node* tail;
public:
    LL(){
        this->head= nullptr;
        this->tail= nullptr;
    }

    void Add(int x){
        node* NewNode = new node(x);
        if(head== nullptr){

        }

    }
};

int main(){

}