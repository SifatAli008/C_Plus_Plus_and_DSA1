//
// Created by Sifat Ali on 10/29/2023.
//
#include <iostream>

using namespace std;

class LL{
        class Node{
        public:
            Node* pre;
            string data;
            Node* next;
            Node(string data){
                this->pre = nullptr;
                this->data = data;
                this->next = nullptr;
            }
        };
        Node* head;
        Node* tail;
public:
        LL(){
            this->head = nullptr;
            this->tail = nullptr;
        }

        void AddToList(string data){
            Node* newNode = new Node(data);
            if(head== nullptr){
                head=newNode;
                tail=newNode;

                head->pre=tail;
                head->next=tail;

                tail->pre=head;
                tail->next=head;
            }

            else{
                Node* currentNode =head;
                while(currentNode->next!=head){
                    currentNode=currentNode->next;
                }
                currentNode->next=newNode;
                newNode->pre=currentNode;

                newNode->next=head;
                head->pre=newNode;
            }

        }

        void InsertAfter(string value,string pos){
            if(head== nullptr){
                cout<<"Empty List";
                return;
            }

            Node* currentNode =head;
            while(currentNode->next!=head && currentNode->data!=pos){
                currentNode=currentNode->next;
            }

            if(currentNode->data!=pos){
                cout<<"Invalid Postion"<<endl;
                return;
            }

            Node* newNode = new Node(value);
            Node* temp=  currentNode->next;
            currentNode->next=newNode;
            newNode->next=temp;
            newNode->pre=currentNode;

        }

    void InsertBefore(string value,string pos){
        Node* newNode = new Node(value);
        if(head== nullptr){
            cout<<"Empty List";
            return;
        }

        if(head->data==pos){
            Node* temp= head->pre;
            head->pre=newNode;
            newNode->next=head;
            head=newNode;
            newNode->pre=temp;
            temp->next = newNode;
            return;
        }

        Node* currentNode =head;
        while(currentNode->next!=head && currentNode->next->data!=pos){
            currentNode=currentNode->next;
        }

        if(currentNode->next->data!=pos){
            cout<<"Invalid Postion"<<endl;
            return;
        }

        Node* temp=  currentNode->next;
        currentNode->next=newNode;
        newNode->next=temp;
        newNode->pre=currentNode;

    }


    void Deletion(string value) {
        if (head == nullptr) {
            cout << "Empty List" << endl;
            return;
        }

        Node* currentNode = head;
        if (currentNode->data == value) {
            if (currentNode->next == head) {
                delete head;
                head = nullptr;
            } else {
                Node* lastNode = head->pre;
                head = head->next;

                lastNode->next = head;
                head->pre = lastNode;

                delete currentNode;
            }
            return;
        }

        currentNode = head;
        do {
            if (currentNode->data == value) {
                Node* toDelete = currentNode;
                Node* previousNode = currentNode->pre;
                Node* nextNode = currentNode->next;

                previousNode->next = nextNode;
                nextNode->pre = previousNode;

                delete toDelete;
                return;
            }
            currentNode = currentNode->next;
        } while (currentNode != head);
    }


    void printList(){
            if(head== nullptr){
                cout<<"Empty List";
                return;
            }

            Node* currentNode=head;
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
      list.AddToList("1");
      list.AddToList("2");
      list.AddToList("3");
      list.AddToList("4");
      list.AddToList("5");
       list.InsertBefore("x","3");
        list.InsertAfter("y","3");
      list.Deletion("3");
list.printList();
}