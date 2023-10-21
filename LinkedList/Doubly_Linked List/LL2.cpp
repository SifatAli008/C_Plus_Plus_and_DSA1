//Doubly Linked List-> head insertion
// Created by Sifat Ali on 10/17/2023.
//
#include <iostream>
using namespace std;

class LL{
    class node{
    public:
        node* pervious;
        string data;
        node* next;

        node(string data){
            this->pervious = nullptr;
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

    void AddAtHead(string data){
        node* NewNode = new node(data);
        NewNode->next=head;
        if(head==nullptr){
            head=NewNode;
            tail= nullptr;
            return;
        }
        head->pervious=NewNode;
        head=NewNode;
    }

    void AddAtTail(string data){
        node* NewNode = new node(data);
        if(head == nullptr){
            head=NewNode;
            tail= nullptr;
            return;
        }

        node* currentNode = head;
        while (currentNode->next!= nullptr){
            currentNode=currentNode->next;
        }
        currentNode->next=NewNode;
        NewNode->pervious=currentNode;
    }

    void PrintList(){
        if(head == nullptr){
            cout<<"Empty List";
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

int main(){
    LL list;
    list.AddAtHead("5");
    list.AddAtTail("1");
    list.AddAtTail("2");
    list.AddAtTail("3");
    list.AddAtTail("4");
    list.PrintList();
    return 0;
}