//Delete N nodes after M nodes of a linked list
// Created by Sifat Ali on 10/26/2023.
//
#include <iostream>
using namespace std;

class  LL{
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
    void AddToList(string data){
        node *newNode = new node(data);
        if (head == nullptr) {
            head = newNode;
            newNode->next = nullptr;
            return;
        }

        node *currentNode = head;
        while (currentNode->next != nullptr) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
        newNode->next = nullptr;
    }

    void MandNdeletion(string pos, int value){
        if(head==nullptr){
            cout<<"Empty List";
            return;
        }
        node* currentNode=head;
        while (currentNode->next!= nullptr) {
            if(currentNode->next->data!=pos){
                int count =value;
                if(count!=0) {
                    node *toDelet = currentNode->next;
                    currentNode->next = currentNode->next->next;
                    delete toDelet;
                }
                count--;
            }
            currentNode = currentNode->next;
        }

    }

    void printList(){
        if(head==nullptr){
            cout<<"Empty List";
            return;
        }
        node* currentNode=head;
        while(currentNode!= nullptr){
            cout<<currentNode->data;
            if(currentNode->next!= nullptr){
                cout<<"->";
            }
            currentNode=currentNode->next;
        }
        cout<<endl;
    }
};

int main(){
  LL list;
  list.AddToList("1");
  list.AddToList("2");
  list.AddToList("3");
  list.AddToList("4");
  list.AddToList("5");
  list.AddToList("6");
  list.AddToList("7");
  list.AddToList("8");
  list.MandNdeletion("2",2);
  list.printList();
}
