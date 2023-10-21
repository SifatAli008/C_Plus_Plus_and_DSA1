//Doubly Linked List-> DELETION
// Created by Sifat Ali on 10/17/2023.
//
#include<iostream>
using namespace std;
class LL{
    class node{
    public:
        node* pre;
        string data;
        node* next;

        node(string data){
            this->pre=nullptr;
            this->data=data;
            this->next=nullptr;
        }
    };

    node* head;
    node* tail;

public:
    LL(){
        this->head= nullptr;
        this->tail= nullptr;
    }

    void AddAtHead(string data){
        node* newNode = new node(data);
        newNode->next=head;
        if(head==nullptr){
            head=newNode;
            tail=nullptr;
            return;
        }

        head->pre=newNode;
        head=newNode;
    }

    void AddAtTail(string data){
        node* newNode = new node(data);
        if(head==nullptr){
            head=newNode;
            tail=nullptr;
            return;
        }

        node* currentNode = head;
        while(currentNode->next!=nullptr){
            currentNode=currentNode->next;
        }
        currentNode->next=newNode;
        newNode->pre=currentNode;
    }

    void headDeletion(){
        node* todelet =head;
        head = head->next;
        if (head != nullptr) {
            head->pre = nullptr;
        } else {
            tail = nullptr;
        }
        delete todelet;
    }

    void Deletion(string value){
        if(head==nullptr){
            cout<<"Empty String";
        }
        if(head->next!=nullptr){
            headDeletion();
        }

        node* cureentNode = head;
        while(cureentNode->data!=value){
            cureentNode=cureentNode->next;
        }
        node* todelet =cureentNode;
        cureentNode->pre->next = cureentNode->next;
        cureentNode->next->pre = cureentNode->pre;

        delete todelet;
    }

    void printList(){
        if(head == nullptr){
            cout<<"Empty List";
            return;
        }

        node* currentNode = head;
        while(currentNode!=nullptr){
            cout<<currentNode->data;
            if(currentNode->next!=nullptr){
                cout<<"->";
            }
            currentNode=currentNode->next;
        }
        cout<<endl;
    }

};

int main(){
    LL list;
    list.AddAtTail("1");
    list.AddAtTail("2");
    list.AddAtTail("3");
    list.AddAtTail("4");
    list.headDeletion();
    list.printList();
    return 0;
}