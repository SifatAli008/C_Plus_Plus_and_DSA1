//Single LinkedLIST INSERTION,DELETION,Print,Revers Print,Print Mid Element.
// Created by Sifat Ali on 10/25/2023.
//
#include <iostream>
using namespace std;

class LL {
    class node {
    public:
        string data;
        node *next;

        node(string data) {
            this->data = data;
            this->next = nullptr;
        }
    };

    node* head;
public:
    LL() {
        this->head = nullptr;
    }

    //  INSERTION to head
    void AddToHead(string data) {
        node *newNode = new node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

   //  INSERTION to tail
    void AddToTail(string data) {
       node* NewNode = new node(data);
       if(head==nullptr){
           head=NewNode;
           return;
       }

       node* currentNode =head;
       while (currentNode->next!= nullptr){
           currentNode=currentNode->next;
       }
       currentNode->next=NewNode;
    }


    //  INSERTION After
    void InsertAfter(string value, string pos) {
        if (head == nullptr) {
            cout << "Empty LinkedList";
            return;
        }


        node *currentNode = head;
        while (currentNode != nullptr && currentNode->data != pos) {
            currentNode = currentNode->next;
        }

        if (currentNode == nullptr) {
            cout << "Invalid Position" << endl;
            return;
        }

        node *newNode = new node(value);
        node *temp;
        temp = currentNode->next;
        currentNode->next = newNode;
        newNode->next = temp;
    }

    //  INSERTION before
    void InsertBefore(string value, string pos) {
        if (head == nullptr) {
            return;
        }

        if (head->data == pos) {
            AddToHead(value);
            return;
        }

        node *currentNode = head;
        while (currentNode->next != nullptr && currentNode->next->data != pos) {
            currentNode = currentNode->next;
        }

        if (currentNode->next == nullptr) {
            cout << "Invalid Position" << endl;
            return;
        }

        node *newNode = new node(value);
        node *temp;
        temp = currentNode->next;
        currentNode->next = newNode;
        newNode->next = temp;
    }

    //  DELETION
    void Deletion(string value) {
            if (head == nullptr) {
                cout << "Empty List" << endl;
                return;
            }

            if (head->data == value) {
                node* ToDelete = head;
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
                return;
            }

            node *ToDelete = currentNode->next;
            currentNode->next = currentNode->next->next;
            delete ToDelete;
        }

    //Print Mid Element
     void printMid(){
        node* currentNode=head;
        int size=sizeof(LL);
        int mid=size/2;
        int count=1;
        while(mid!=count){
            currentNode=currentNode->next;
            count++;
        }
        cout<<endl<<"Mid Element : "<<currentNode->data<<endl;
    }

    //revresAndPrint
    void reverse(node* head) {
        if(head!= nullptr) {
            reverse(head->next);
            if (head->next != nullptr) {
                cout << "->";
            }
            cout << head->data;
        }
    }

    void revresAndPrint(){
        if(head==nullptr){
            cout<<"Empty List";
            return;
        }
        reverse(head);
    }

  //Print
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
    list.AddToHead("3");
    list.AddToHead("2");
    list.AddToHead("1");
    list.AddToTail("4");
    list.AddToTail("5");
//    list.InsertAfter("2.2","4");
//    list.InsertBefore("2.5","1");
   list.Deletion("1");

    list.printList();
   // list.printMid();
   // list.revresAndPrint();


    return 0;
}
