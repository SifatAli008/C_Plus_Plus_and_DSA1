//  Doubly Linked List
// Created by Sifat Ali on 10/25/2023.
//
#include <iostream>

using namespace std;

class LL{
       public:
    class node{
    public:
        node* pre;
        string data;
        node* next;
        node(string data){
            this->pre= nullptr;
            this->data= data;
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
       if(head==nullptr){
          head=newNode;
           tail = newNode;
           return;
       }
        head->pre=newNode;
        newNode->next=head;
        head=newNode;
    }

    void AddToTail(string data){
      node* newNode = new node(data);
        if(head==nullptr){
            head=newNode;
            tail = newNode;
            return;
        }
        tail->next=newNode;
        newNode->pre=tail;
        tail =newNode;
    }

    void InsterAfter(string value,string pos){
        if(head== nullptr){
            cout<<"Empty LinkedList";
            return;
        }

        node* currentNode = head;
        while(currentNode!= nullptr && currentNode->data!=pos){
            currentNode=currentNode->next;
        }

        if(currentNode== nullptr){
             cout<<"Invalid postion"<<endl;
            return;
        }
        node* newNode = new node(value);
        node* temp;
        temp=currentNode->next;
        currentNode->next=newNode;
        newNode->next=temp;
    };

    void InsterBefor(string value,string pos){
        if(head== nullptr){
            cout<<"Empty LinkedList";
            return;
        }

        if(head->data==pos){
            AddToHead(value);
            return;
        }

        node* currentNode = head;
        while(currentNode->next!= nullptr && currentNode->next->data!=pos){
            currentNode=currentNode->next;
        }

        if(currentNode->next== nullptr){
            cout<<"Invalid postion"<<endl;
            return;
        }
        node* newNode = new node(value);
        node* temp;
        temp=currentNode->next;
        currentNode->next=newNode;
        newNode->next=temp;
    };

    void  Deletion(string value){
        if(head== nullptr){
           cout<<"Empty List";
            return;
        }

        if(head->data== value){
          node* todelete= head;
          head=head->next;
          delete todelete;
        }

        node* currentnode = head;
        while (currentnode->next!= nullptr && currentnode->next->data!=value){
            currentnode=currentnode->next;
        }
        node* todelete = currentnode->next;
        currentnode->next= currentnode->next->next;
        delete todelete;
    }

    void printrevers(){
        if(tail== nullptr){
            cout<<"Empty List";
            return;
        }

        node* currentNode=tail;
        while (currentNode!= nullptr){
            cout<<currentNode->data;
            if (currentNode->pre != nullptr) {
                cout<<"->";
            }
            currentNode=currentNode->pre;
        }
    }

    void printList(){
        if(head== nullptr){
            cout<<"Empty List";
            return;
        }

        node* currentNode=head;
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
    list.AddToTail("5");

     list.printrevers();

    return 0;
}