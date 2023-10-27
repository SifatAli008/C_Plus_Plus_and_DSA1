//Remove duplicate element from sorted Linked List
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

    void AddToHead(string data){
     node* newNode = new node(data);
     if(head== nullptr){
         head=newNode;
         newNode->next= nullptr;
         return;
     }
        newNode->next= head;
        head=newNode;
    }

    void AddToTail(string data){
        node* newNode = new node(data);
        if(head== nullptr){
            head=newNode;
            newNode->next= nullptr;
            return;
        }

        node* currentNode = head;
        while (currentNode->next!= nullptr){
            currentNode=currentNode->next;
        }
        currentNode->next=newNode;
        newNode->next= nullptr;
    }

    void removeduplicate() {
        if (head == nullptr) {
            cout << "Empty List";
            return;
        }

        node *currentNode = head;
        while (currentNode->next != nullptr) {
            if(currentNode->data==currentNode->next->data){
              node* todelete= currentNode->next;
                currentNode->next=currentNode->next->next;
               delete  todelete;
            }
            else {
                currentNode = currentNode->next;
            }
        }
    }

    void printList(){
        if(head== nullptr){
            cout<<"Empty List";
            return;
        }

        node* currentNode=head;
        while(currentNode!= nullptr) {
            cout<<currentNode->data;
            if(currentNode->next!= nullptr){
                cout<<"->";
            }
            currentNode = currentNode->next;
        }
        cout<<endl;
    }
};

int main(){
    LL list;
    list.AddToHead("3");
    list.AddToHead("2");
    list.AddToHead("1");
    list.AddToTail("3");
    list.AddToTail("3");
    list.AddToTail("3");
    list.AddToTail("3");
    list.removeduplicate();

    list.printList();
}