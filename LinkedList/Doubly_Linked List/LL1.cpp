// Doubly Linked List-> tail insertion
// Created by Sifat Ali on 10/17/2023.
//
#include <iostream>
using namespace std;

class LL{
    class node{
    public:
        node* previous;
        string data;
        node* next;

        node(string data){
            this->previous = nullptr;
            this->data = data;
            this->next = nullptr;
        }
    };

    node* head;
    node* tail;

public:
    LL(){
        this->head = nullptr;
        this->tail = nullptr;
    }

    void AddAtTail(string data){
       node* NewNode = new node(data);
       if(head== nullptr){
           head=NewNode;
           tail= nullptr;
           return;
       }

       node* currentNode = head;
       while(currentNode->next!= nullptr){
           currentNode=currentNode->next;
       }
        currentNode->next=NewNode;
        NewNode->previous=currentNode;
    }

    void PrintList(){
        if(head== nullptr){
            cout<<"Empty LinkedList";
            return;
        }
        node* currentNode = head;
        while(currentNode!= nullptr){
            cout<<currentNode->data;
            if(currentNode->next!= nullptr){
                cout<<"->";
            }
            currentNode=currentNode->next;
        }
        cout<<endl;
    }
};

int main()
{
  LL list;
  list.AddAtTail("1");
  list.AddAtTail("2");
  list.AddAtTail("3");
  list.AddAtTail("4");
  list.PrintList();
}
