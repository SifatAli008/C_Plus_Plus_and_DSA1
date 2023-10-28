//Intersection of two Sorted Linked Lists
// Created by Sifat Ali on 10/28/2023.
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

    void AddLast(string data){
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

    static LL Insert(LL list1,LL list2){
        LL InsertList;

        node* p1=list1.head;
        node* p2=list2.head;
        node* p3=InsertList.head;

        if(p1== nullptr&&p2== nullptr){
            cout<<"One of the list is Empty";
            return InsertList;
        }

        while(p1!= nullptr&&p2!= nullptr) {
            if (p1->data == p2->data) {
                    InsertList.AddLast(p1->data);
                    p1 = p1->next;
                    p2 = p2->next;
                } else if (p1->data < p2->data) {
                  p1 = p1->next;
                } else {
                 p2 = p2->next;
                 }
            }


        return InsertList;

    }

    void PrintList(){
        if(head== nullptr){
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
    }

};

int main(){
    LL list1;
    list1.AddLast("1");
    list1.AddLast("2");
    list1.AddLast("3");
    list1.AddLast("4");
    LL list2;
    list2.AddLast("2");
    list2.AddLast("3");

    LL intersection = LL::Insert(list1, list2);
    intersection.PrintList();
}