//Merge two sorted linked lists
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

 static LL MergedList(LL List1,LL List2){
     LL mergedList;
     node *p1 = List1.head;
     node *p2 = List2.head;
     node *p3 = mergedList.head;

     while (p1 != nullptr && p2 != nullptr) {
         if (p1->data <= p2->data) {
             if (p3 == nullptr) {
                 mergedList.head = p1;
                 p3 = p1;
             } else {
                 p3->next = p1;
                 p3 = p3->next;
             }
             p1 = p1->next;
         }

         else {
             if (p3 == nullptr) {
                 mergedList.head = p2;
                 p3 = p2;
             } else {
                 p3->next = p2;
                 p3 = p3->next;
             }
             p2 = p2->next;
         }
     }

     if (p3 == nullptr) {
         if (p1 != nullptr) {
             mergedList.head = p1;
         } else {
             mergedList.head = p2;
         }
     } else {
         while (p1 != nullptr) {
             p3->next = p1;
             p1 = p1->next;
             p3 = p3->next;
         }
         while (p2 != nullptr) {
             p3->next = p2;
             p2 = p2->next;
             p3 = p3->next;
         }
     }


     return mergedList;

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
    LL List1;
    List1.AddLast("1");
    List1.AddLast("3");
    List1.AddLast("5");

    LL List2;
    List2.AddLast("2");
    List2.AddLast("4");
    List2.AddLast("6");

    LL mergedList = LL::MergedList(List1, List2);
    mergedList.PrintList();
}