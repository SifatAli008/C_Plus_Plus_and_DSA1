//Circular Linked List Implementation of Circular Queue
// Created by Sifat Ali on 11/30/2023.
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

    void AddLast(string data){
        node* NewNode = new node(data);
        if(head==nullptr){
            head=NewNode;
            head->next=head;
            return;
        }

        node* currentNode =head;
        while (currentNode->next!= head){
            currentNode=currentNode->next;
        }
        currentNode->next=NewNode;
        NewNode->next=head;
    }

    void Deletion(){
        if(head == nullptr){
            cout << "Empty list";
            return;
        }

        node* temp = head;
        if(head->next == head){
            head = nullptr;
            return;
        }

         temp = head;
        while (temp->next != head){
            temp = temp->next;
        }
        temp->next = head->next;
        head = head->next;
    }

    void printList(){
        if(head==nullptr){
            cout<<"Empty list"<<endl;
            return;
        }
        node* currentNode =head;
        do{
            cout<<currentNode->data;
            if(currentNode->next!= head){
                cout<<"->";
            }
            currentNode = currentNode->next;
        }while(currentNode!= head);

        cout << endl;
    }
};


int main(){
    LL list;
    list.AddLast("1");
    list.AddLast("2");
    list.AddLast("3");
    list.Deletion();
    list.Deletion();
    list.printList();
}
