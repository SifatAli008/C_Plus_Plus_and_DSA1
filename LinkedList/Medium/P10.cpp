//Find pairs with given sum in doubly linked list
// Created by Sifat Ali on 10/28/2023.
//
#include <iostream>
using namespace std;
class LL{
    class Node{
    public:
        Node* pre;
        int data;
        Node* next;
         Node(int data){
            this->pre= nullptr;
            this->data=data;
            this->next= nullptr;
        }
    };

    Node* head;
    Node* tail;

public:
    LL(){
        this->head= nullptr;
        this->tail= nullptr;
    }

    void AddToList(int data){
        Node* newNode = new Node(data);
        if(head== nullptr){
            head=newNode;
            tail=newNode;
            return;
        } else{
            tail->next=newNode;
            newNode->pre=tail;
            tail= newNode;
        }
    }

    void SumOfPair(int value){
        if(head== nullptr){
           cout<<"Emprty List";
           return;
        }

        Node* FirstNode=head;
       while(FirstNode!= nullptr){
           Node* SecondNode = head->next;
           while(SecondNode!= nullptr){
               if(FirstNode->data+SecondNode->data==value){
                   cout<<"("<<SecondNode->data<<"+"<<FirstNode->data<<")";
               }
               SecondNode=SecondNode->next;
           }
           FirstNode=FirstNode->next;
       }

    }

    void Print(){
        if(head== nullptr){
            cout<<"Empty List";
            return;
        }
        Node* currentNode=head;
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
  LL list;
  list.AddToList(1);
  list.AddToList(2);
  list.AddToList(3);
  list.AddToList(4);
  list.AddToList(5);
  list.AddToList(6);
  list.SumOfPair(7);

}