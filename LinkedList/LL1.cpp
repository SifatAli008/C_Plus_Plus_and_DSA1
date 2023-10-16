#include <iostream>
using namespace std;

class LL {
    class node {
    public:
        string data;
        node* next;

         node(string data) {
            this->data = data;
            this->next = nullptr;
        }
    };

    node* head;
public:
    LL(){
        this->head=nullptr;
    }

    void addFirst(string data){
        node* newNode = new node(data);
        if(head==nullptr){
            head=newNode;
            return;
        }
        newNode->next=head;
        head=newNode;
    }

    void addlast(string data){
        node* newNode = new node(data);
        if(head==nullptr){
            head=newNode;
            return;
        }

        node* currentNode = head;
        while(currentNode->next!=nullptr){
            currentNode=currentNode->next;
        }
        currentNode->next=newNode;
    }

    void printList() {
        if (head == nullptr) {
            cout << "List is Empty" << endl;
            return;
        }
        node* currentNode = head;
        while (currentNode != nullptr) {
            cout << currentNode->data;
            if (currentNode->next != nullptr) {
                cout << "->";
            }
            currentNode = currentNode->next;
        }
        cout << endl;
    }

};

int main() {
    LL list;
    list.addFirst("a");
    list.addFirst("the");
    list.printList();
    return 0;
}
