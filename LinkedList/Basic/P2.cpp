//Circular LinkedList INSERTION,DELETION,Print,Print Mid Element.
// Created by Sifat Ali on 10/25/2023.
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

    void InsertAfter(string value, string pos){
        if(head==nullptr){
            cout<<"Empty LinkedList";
            return;
        }

        node* currentNode =head ;
        while (currentNode!= nullptr && currentNode->data!=pos){
            currentNode=currentNode->next;
        }

        if(currentNode->next==head){
            cout<<"Invalid Postion";
            return;
        }

        node* newNode = new node(value);
        node* temp;
        temp=currentNode->next;
        currentNode->next=newNode;
        newNode->next=temp;
    }

    void InsertBefor(string value, string pos){
        if(head==nullptr){
            cout<<"Empty LinkedList";
            return;
        }

        node* currentNode =head ;
        while (currentNode->next!= nullptr && currentNode->next->data!=pos){
            currentNode=currentNode->next;
        }

        if(currentNode->next == head) {
            cout << "Position not found" << endl;
            return;
        }

        node* newNode = new node(value);
        node* temp;
        temp=currentNode->next;
        currentNode->next=newNode;
        newNode->next=temp;

    }
    void reverse(node* head) {
        if(head!= nullptr) {
            reverse(head->next);
            if (head->next != nullptr) {
                cout << "->";
            }
            cout << head->data;
        }
    }


    void Deletion(string value) {
        if (head == nullptr) {
            cout << "Empty List" << endl;
            return;
        }
        if (head->data == value) {
            node *ToDelete = head;
            head = head->next;
            delete ToDelete;
            return;
        }

        node *currentNode = head;
        while (currentNode->next != nullptr && currentNode->next->data != value) {
            currentNode = currentNode->next;
        }

        if (currentNode->next == nullptr) {
            cout << "Invalid input";
        }

        node *ToDelete = currentNode->next;
        currentNode->next = currentNode->next->next;
        delete ToDelete;
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
    list.Deletion("4");
    list.printList();


    return 0;
}