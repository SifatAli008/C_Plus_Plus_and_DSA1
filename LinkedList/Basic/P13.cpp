//Deletion from a Circular Linked List
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
    void AddList(string data){
        node* newNode = new node(data);
        if(head== nullptr){
            head=newNode;
            newNode->next=head;
        }
        else {
            node *currentNode = head;
            while (currentNode->next != head) {
                currentNode = currentNode->next;
            }
            currentNode->next = newNode;
            newNode->next= head;
        }
    }

    void Deletion(string value){
        if(head== nullptr){
            cout<<"Empty List";
            return;
        }

        if (head->data == value) {
            node* toDelete=head;
            head=head->next;
            return;
        }

        node* currentNode =head;
        while (currentNode->next!= nullptr && currentNode->next->data!=value){
            currentNode=currentNode->next;
        }

        if(currentNode->next== nullptr){
            cout<<"Invalid Position";
            return;
        }

        node* toDelete=currentNode->next;
        currentNode->next=currentNode->next->next;
        delete toDelete;

    }

    void printList(){
       if(head== nullptr){
           cout<<"Empty List";
           return;
       }
        node *currentNode = head;
       do{
           cout<<currentNode->data;
           if(currentNode->next!=head){
                 cout<<"->";
           }
           currentNode=currentNode->next;
       } while(currentNode!=head);
    }
};

int main(){
  LL list;
  list.AddList("10");
  list.AddList("20");
  list.AddList("30");

  list.Deletion("40");
  list.printList();

}