//
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
            this->pre= nullptr;
            this->data=data;
            this->next= nullptr;
        }
    };
    node* head;
    node* tail;
public:
    LL(){
        this->head= nullptr;
        this->tail= nullptr;
    }

    void AddToHead(string data){
        node* newNode = new node(data);
        if(head== nullptr){
            head=newNode;
            tail=newNode;
            newNode->next=newNode;
            newNode->pre=newNode;
        }
        else {
            newNode->pre = tail;
            newNode->next = head;
            tail->next = newNode;
            head->pre = newNode;
            head = newNode;
        }
    }

    void AddToTail(string data){
        node* newNode = new node(data);
        if(tail== nullptr){
            head=newNode;
            tail=newNode;
            newNode->next=newNode;
            newNode->pre=newNode;
        }
        else {
            newNode->pre = tail;
            newNode->next = head;
            tail->next = newNode;
            head->pre = newNode;
            tail = newNode;
        }
    }

    void InsertAfter(string value,string pos){
        if (tail == nullptr) {
            cout << "List is empty";
            return;
        }
        if(tail->data ==pos){
            AddToTail(value);
            return;
        }

        node  *currentNode = head;
        while (currentNode != nullptr && currentNode->data != pos) {
            currentNode = currentNode->next;
        }

        node *newNode = new node(value);
        newNode->next = currentNode->next;
        newNode->pre = currentNode;

        if (currentNode->next != nullptr) {
            currentNode->next->pre = newNode;
        } else {
            tail = newNode;
        }
        currentNode->next = newNode;
    }

    void InsertBefor( string value, string pos){
        if(head== nullptr){
            cout<<"List is empty";
            return;
        }

        if(head->data==pos){
            AddToHead(value);
            return;
        }


        node *currentNode = head;
        while(currentNode != nullptr && currentNode->data != pos){
            currentNode = currentNode->next;
        }

        node* newNode = new node(value);
        newNode->next = currentNode;
        newNode->pre = currentNode->pre;

        if (currentNode->pre != nullptr) {
            currentNode->pre->next = newNode;
        } else {
            head = newNode;
        }
        currentNode->pre = newNode;
    }

    void HeadDeletion(){
        if (head == nullptr) {
            return;
        }
        node* toDeleteNode = head;
        if (head->next == head) {
            head = nullptr;
        } else {
            head->next->pre = head->pre;
            head->pre->next = head->next;

            head = head->next;
        }

        delete toDeleteNode;
    }

    void Deletion(string value){
        if(tail== nullptr){
            return;
        }

        node* currentNode = head;
        while(currentNode->next->data!=value){
            currentNode = currentNode->next;
        }

        node* toDeletNode = currentNode->next;
        currentNode->next =currentNode->next->next;
        currentNode->pre=currentNode->pre->pre;

        delete toDeletNode ;
    }


    void printList(){
        if(tail== nullptr){
            cout<<"Empty List";
        }
        node* currentNode = head;
        do{
            cout<<currentNode->data;
            if(currentNode->next!=head){
                cout<<"->";
            }
            currentNode=currentNode->next;
        } while (currentNode!= head);
        cout<<endl;
    }
};


int main(){
    LL list;
    list.AddToTail("1");
    list.AddToTail("2");
    list.AddToTail("3");
   list.InsertBefor("4","1");
   list.printList();

}
