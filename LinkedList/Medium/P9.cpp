//Split a Circular Linked List into two halves
// Created by Sifat Ali on 10/28/2023.
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


    void Add(string data){
        node* newNode = new node(data);
        if(head==nullptr){
            head=newNode;
            newNode->next= head;
        }
        else {
            node *currentNode = head;
            while (currentNode->next != head) {
                currentNode = currentNode->next;
            }
            newNode->next = head;
            currentNode->next = newNode;
        }
    }


    void printList(){
        if(head==nullptr){
            cout<<"Empty LinkedList";
            return;
        }
        node* currentNode =head;
        do{
            cout<<currentNode->data;
            if(currentNode->next!= head){
                cout<<"->";
            }
            currentNode=currentNode->next;
        }
        while(currentNode != head);

        cout<<endl;
    }
};

int main(){
    LL list;
    list.Add("1");
    list.Add("2");
    list.Add("3");
    list.Add("4");
    list.Add("5");

    list.printList();


    return 0;
}
