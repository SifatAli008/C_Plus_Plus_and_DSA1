//
// Created by Sifat Ali on 11/8/2023.
//
#include <iostream>


using namespace std;

struct list{
    int data;
    struct list* next;
};

typedef struct list node;
node* top = nullptr;

void push(int x) {
    node *temp;
    temp = (node *) malloc(sizeof(node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

void pop( ){
    if(top== nullptr){
        cout<<"stack empty";
    }
    else{
        node* temp=top;
        top=top->next;
        free(temp);
    }
}

void printstack(){
    if(top== nullptr){
        cout<<"stack empty";
    }

    node* temp = top;
    while(temp!= nullptr){
        cout<<temp->data;
        if (temp->next!= nullptr){
            cout<<"->";
        }
        temp=temp->next;
    }
}

int main(){
    push(1);
    push(2);
    push(3);

    pop();

    printstack();



}