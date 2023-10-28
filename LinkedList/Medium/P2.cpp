//Reverse a Linked List in groups of given size
// Created by Sifat Ali on 10/27/2023.
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

    void AddToList(string data){
        node* newNode = new node(data);
        if(head== nullptr){
            head=newNode;
            return;
        }
        node* currentNode=head;
        while (currentNode->next!= nullptr){
            currentNode=currentNode->next;
        }
        currentNode->next=newNode;
    }

    void reverseInGroups(int groupSize) {
        if (head == nullptr) {
            cout << "Empty List" << endl;
            return;
        }

        node* prevGroupTail = nullptr;
        node* currentGroupHead = head;

        while (currentGroupHead != nullptr) {
            node* prev = nullptr;
            node* current = currentGroupHead;
            int count = 0;

            while (current != nullptr && count < groupSize) {
                node* next = current->next;
                current->next = prev;
                prev = current;
                current = next;
                count++;
            }

            while (current != nullptr && count > groupSize) {
                node* next = current->next;
                current->next = prev;
                prev = current;
                current = next;
                count++;
            }

            if (prevGroupTail != nullptr) {
                prevGroupTail->next = prev;
            } else {
                head = prev;
            }

            prevGroupTail = currentGroupHead;
            currentGroupHead = current;
        }
    }


    void printList(){
        if(head== nullptr){
           cout<<"Empty List";
            return;
        }
        node* currentNode=head;
        while(currentNode!=nullptr){
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
  list.AddToList("1");
  list.AddToList("2");
  list.AddToList("3");
  list.AddToList("4");
  list.AddToList("5");
  list.reverseInGroups(3);
  list.printList();
}