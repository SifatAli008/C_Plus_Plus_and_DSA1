//Traversal of Circular Linked List
// Created by Sifat Ali on 10/26/2023.
//
#include <iostream>
using namespace std;
class LL{
    class node{
    public:
        string data;
        node* next;
        node(string data) {
            this->data=data;
            this->next= nullptr;
        }
    };
    node* head;
public:
    LL(){
        this->head= nullptr;
    }

    void AddToList(string data) {
        node *newNode = new node(data);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            node *currentNode = head;
            while (currentNode->next != head) {
                currentNode = currentNode->next;
            }
            newNode->next = head;
            currentNode->next = newNode;
        }
    }

    void PrintList(){
        if (head == nullptr) {
            cout<<"Empty List";
            return;
        }
        node* currentNode = head;
        do{
            cout<<currentNode->data;
            if(currentNode->next!= head){
                cout<<"->";
            }
            currentNode=currentNode->next;
        }
        while(currentNode!= head);

        cout<<endl;
    }
};

int main(){
  LL list;
  list.AddToList("1");
  list.AddToList("2");
  list.AddToList("3");
  list.PrintList();

    return 0;
}