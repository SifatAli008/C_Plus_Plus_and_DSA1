#include <iostream>
#include <stdlib.h>

using namespace std;

struct list{
    int data;
    struct list *next;
};


typedef struct list node;

void PrintList(node* start){
    if(start== nullptr){
        cout<<"Empty lIST";
    }

    node* current =start;
    while (current!= nullptr){
        cout<<current->data<<"->";
        current=current->next;
    }
    cout<<"nullptr"<<endl;
}

int main(){
    node *start;
    start=(node*)malloc(sizeof(node));
    start->data=10;
    start->next= nullptr;

    node *temp;
    temp=(node*)malloc(sizeof(node));
   temp->data=20;
   temp->next= nullptr;
   start->next=temp;

  PrintList(start);

}