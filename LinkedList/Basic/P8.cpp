//Detect loop or cycle in a linked list
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
    void Add(string data){
        node* newNode = new node(data);
        if(head== nullptr){
            head=newNode;
            newNode->next=head;
            return;
        }
        else{
            node *currentNode = head;
            while (currentNode->next != head) {
                currentNode = currentNode->next;
            }
            newNode->next = head;
            currentNode->next = newNode;
        }
    }

    bool DetectLoop(){
        if(head== nullptr){
            return false;
        }

        node* point1 = head;
        node* point2 = head;
        while(point1!= nullptr && point1->next!=nullptr){
            point2 = point2->next;
            point1 = point1->next->next;
            if(point2==point1){
                return true;
            }
        }
        return false;
    }

    void PrintList() {
        if (head == nullptr) {
            cout << "Empty LinkedList";
            return;
        }
        node* currentNode = head;
        do {
            cout << currentNode->data;
            if (currentNode->next != head) {
                cout << "->";
            }
            currentNode = currentNode->next;
        }
            while (currentNode != head);

        cout<<endl;
    }
};

int main(){
        LL list;
         list.Add("1");
         list.Add("2");
         list.Add("3");
    if (list.DetectLoop()) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

    return 0;
}