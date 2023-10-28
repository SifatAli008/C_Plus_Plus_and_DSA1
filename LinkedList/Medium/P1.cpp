//Convert singly linked list into circular linked list
// Created by Sifat Ali on 10/27/2023.
//
#include <iostream>
using namespace std;

class LL{
    class node{
    public:
        string data;
        node* next;
        node(string data){
            this->data=data;
            this->next= nullptr;
        }
    };
    node* head;
public:
    LL(){
        this->head= nullptr;
    }

    void AddLast(string data){
        node* newNode = new node(data);
        if(head== nullptr){
            head=newNode;
            return;
        }

        node* currentNode=head;
        while (currentNode->next!= nullptr){
            currentNode=currentNode->next;
        }
        currentNode->next=newNode;
    }

    void convertIntoCircular(){
        if(head== nullptr){
            cout<<"Empty List";
            return;
        }
        else{
            node* currentNode=head;
            while (currentNode->next!= nullptr){
                currentNode=currentNode->next;
            }
            currentNode->next=head;
        }
    }

    void PrintList(){
        if(head== nullptr){
            cout<<"Empty List";
            return;
        }
        node* currentNode=head;
        while(currentNode!= nullptr){
            cout<<currentNode->data;
            if(currentNode->next!= nullptr){
             cout<<"->";
            }
            currentNode=currentNode->next;
        }
    }

    void PrintCircularList(){
        if(head== nullptr){
            cout<<"Empty List";
            return;
        }

        node* currentNode=head;
        do{
            cout<<currentNode->data;
            if(currentNode->next!=head){
                cout<<"->";
            }
            currentNode=currentNode->next;
        }while(currentNode!=head);
    }
};

int main(){
   LL list;
   list.AddLast("1");
   list.AddLast("2");
   list.AddLast("3");
   list.AddLast("4");
   list.convertIntoCircular();
   list.PrintCircularList();
   list.PrintList();
}