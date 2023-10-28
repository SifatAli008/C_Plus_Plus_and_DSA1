//Detect and Remove Loop in a Linked List
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
    void AddList(string data){
        node* newNode=new node(data);
        if(head== nullptr){
            head=newNode;
            return;
        }
        node* currentNode=head;
        while(currentNode->next!= nullptr){
            currentNode=currentNode->next;
        }
        currentNode->next=newNode;
    }

    void DetectandDeleteLoop(){
        
    }

    void printList(){
        if(head== nullptr){
         cout<<"Empty list";
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

};

int main(){
  LL list;
  list.AddList("1");
  list.AddList("2");
  list.printList();

    return 0;

}