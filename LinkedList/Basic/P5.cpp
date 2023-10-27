//Delete last occurrence of an item from linked list
// Created by Sifat Ali on 10/26/2023.
//
#include <iostream>
using namespace std;

class LL{
    class node{
    public:
        string data;
        node* next;

        node(string data){
            this->data= data;
            this->next= nullptr;
        }
    };

    node* head;

public:
    LL(){
        this->head= nullptr;
    }

    void AddToHead(string data){
        node* newNode= new node(data);
        if(head== nullptr){
            head=newNode;
            newNode->next= nullptr;
            return;
        }
        newNode->next=head;
        head=newNode;
    }

    void lastOccurrence(string value) {
        if(head== nullptr){
            cout<<"Empty List";
        }
        node* todelete;
        node* curreentNode = head;
        while(curreentNode!= nullptr){
            if(curreentNode->data==value){
                todelete=curreentNode;
            }
            curreentNode=curreentNode->next;
        }

        if (todelete== nullptr){
            return;
        }

        if (todelete == head) {
            head = head->next;
            delete todelete;
            return;
        }

        node* temp = head;
        while (temp->next != todelete) {
            temp = temp->next;
        }

        temp->next = todelete->next;
        delete todelete;

    }

    void AddToTail(string data){
        node* newNode= new node(data);
        if(head== nullptr){
            head=newNode;
            newNode->next= nullptr;
            return;
        }
        node* currentNode =head;
        while (currentNode->next!= nullptr){
            currentNode=currentNode->next;
        }
        currentNode->next = newNode;
        newNode->next = nullptr;

    }

    void printList(){
        if(head== nullptr){
            cout<<"Empty List";
            return;
        }

        node* currentNode =head;
        while (currentNode!= nullptr){
            cout<<currentNode->data;
            if(currentNode->next!= nullptr){
                cout<<"->";
            }
            currentNode=currentNode->next;
        }
    }

};

int main(){
   LL list;
   list.AddToHead("3");
   list.AddToHead("2");
    list.AddToHead("1");
    list.AddToTail("4");
    list.AddToTail("2");
    list.AddToTail("2");
    list.lastOccurrence("2");
    list.printList();
}