// Delete a Node from linked list without head pointer
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
            this->data=data;
            this->next= nullptr;
        }
    };
    node* head;
public:
    LL(){
        this->head= nullptr;
    }

    void AddToList(string data){
        node* newNode = new node(data);
        if(head== nullptr){
           head=newNode;
            return;
        } else{
            node* currentNode = head;
            while(currentNode->next!= nullptr){
                currentNode=currentNode->next;
            }
            currentNode->next=newNode;
            newNode->next= nullptr;
        }
    }

    void Deletion(string value){
        if(head== nullptr){
            cout<<"Empty List";
            return;
        }

        if(head->data==value){
            node* todelete=head;
            head=head->next;
            delete todelete;
            return;
        }


    }


    void printList(){
        if(head== nullptr){
            cout<<"Empty";
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
    }
};
int main(){
     LL list;
     list.AddToList("1");
     list.AddToList("2");
     list.AddToList("3");
     list.printList();

}