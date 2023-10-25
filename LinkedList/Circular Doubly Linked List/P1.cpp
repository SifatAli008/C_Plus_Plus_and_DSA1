// Insertion to head
// Created by Sifat Ali on 10/22/2023.
//
#include <iostream>
using namespace std;
class LL{
    class node{
    public:
        node* pre;
        string data;
        node* next;

        node(string data){
            this->pre = nullptr;
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

    void AddtoTail(string data){
        node* newNode = new node(data);
        if(tail== nullptr){
            head=newNode;
            tail=newNode;
            newNode->next=newNode;
            newNode->pre=newNode;
        }

        newNode->next = head;
        newNode->pre = tail;
        tail->next = newNode;
        head->pre = newNode;
        tail = newNode;
    }

    void printlist(){
        if(tail== nullptr){
            cout<<"No element in the list";
            return;
        }

        node* currentNode=head;
        do{
            cout<<currentNode->data;
            if(currentNode->next!= head){
                cout<<"->";
            }
            currentNode=currentNode->next;
        }while(currentNode!=head);
        cout<<endl;
    }

};
int main(){
    LL list;
    list.AddtoTail("2");
    list.AddtoTail("3");
    list.AddtoTail("4");
    list.Addtohead("1");
    list.printlist();
    return 0;
};
